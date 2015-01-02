#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"
#include "Utils.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int llcFrame[256] = { 0x0F, 0xB7, 0x8B, 0x41, 0x00, 0x83, 0x04, 0x12, 0x10, 0x81, 0x00, 0x00, 0x00, 0x00, 0x94, 0xF9 };
    char cellString[256] = {};
    int len = llcFrame[0];

    ui->setupUi(this);

    QStandardItemModel * model = new QStandardItemModel(2,10,this);

    for (int col=0;col<len;col++)
    {
        QString * title = NULL;
        if (0 == col)
        {
            title = new QString("Len");
        }
        else if (len-1 == col || len-2 == col)
        {
            title = new QString("CRC");
        }
        else
        {
            title = new QString("LLC Payload");
        }

        model->setHorizontalHeaderItem(col, new QStandardItem(*title));
        snprintf(cellString, len, "0x%02x", llcFrame[col]);
        QStandardItem * qItem1 = new QStandardItem(QString(cellString));
        QStandardItem * qItem2 = new QStandardItem(QString(Utils::HexToBin(llcFrame[col])));
        model->setItem(1, col, qItem1);
        model->setItem(2, col, qItem2);
    }

    QStandardItem * qItem3 = new QStandardItem(QString("LLC Payload"));
    model->setItem(0, 1, qItem3);
    ui->tableView->setModel(model);

    ui->tableView->setSpan(0, 1, 1, len-3);
    ui->tableView->show();


    // setup treeview
    QStandardItemModel *goodsModel = new QStandardItemModel(0, 4,this);

    ui->treeView->setColumnWidth(0,50);
    ui->treeView->setColumnWidth(1,200);
    ui->treeView->setColumnWidth(2,200);
    ui->treeView->setColumnWidth(3,200);
    goodsModel->setHeaderData(0, Qt::Horizontal, tr("No"));
    goodsModel->setHeaderData(1, Qt::Horizontal, tr("name"));
    goodsModel->setHeaderData(2, Qt::Horizontal, tr("value1"));
    goodsModel->setHeaderData(3, Qt::Horizontal, tr("value2"));

    ui->treeView->setModel(goodsModel);

    // fill data into treeview
    for (int i = 0; i < 4; ++i)
    {
        QList<QStandardItem *> items;
        for (int i = 0; i < 3; ++i)
        {
            QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
            if (0 == i)
            item->setCheckable(true);
            items.push_back(item);
        }
        goodsModel->appendRow(items);

        for (int i = 0; i < 4; ++i)
        {
            QList<QStandardItem*> childItems;
            for (int i = 0; i < 3; ++i)
            {
                QStandardItem *item = new QStandardItem(QString("%0").arg(i));
                if (0 == i)
                item->setCheckable(true);

                childItems.push_back(item);
            }
            items.at(0)->appendRow(childItems);
        }
    }

    // set multi-selection
    ui->treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    typedef struct HCP_Message
    {
        int type : 2;
        int instruction : 6;
    } HCP_Message;

    typedef struct HCP_Package
    {
        int CB:1;
        int PID:7;
        HCP_Message message;
    } HCP_Package;

    QString val = ui->tableView->model()->data(index).toString();

    // define model for HCP table
    QStandardItemModel * modelHcp = new QStandardItemModel(2,10,this);
    char hcpFields[3][10] = { "CB", "PID", "Message" };

    for (int col=0;col<3;col++)
    {
#if 0
        ui->tableView->model()->setHorizontalHeaderItem(col, new QStandardItem(QString(hcpFields[col])));
        snprintf(cellString, 10, "0x%02x", llcFrame[col]);
        QStandardItem * qItem1 = new QStandardItem(QString(cellString));
        QStandardItem * qItem2 = new QStandardItem(QString(Utils::HexToBin(llcFrame[col])));
        model->setItem(0, col, qItem1);
        model->setItem(1, col, qItem2);
        model->setHorizontalHeaderItem(col, new QStandardItem(QObject::tr("BYTE")));
#endif
    }
    ui->tableViewHcp->setModel(modelHcp);
}
