#include <iomanip>
#include <iostream>

using namespace std;

//这个函数将b[0]至b[right-left+1]拷贝到a[left]至a[right]
template <class T>
void Copy(T a[],T b[],int left,int right)
{
    int size=right-left+1;
    for(int i=0;i<size;i++)
    {
        a[left++]=b[i];
    }
}

//这个函数合并有序数组a[left:i],a[i+1:right]到b,得到新的有序数组b
template <class T>
void Merge(T a[],T b[],int left,int i,int right)
{
    int a1cout=left,//指向第一个数组开头
    a1end=i,//指向第一个数组结尾
    a2cout=i+1,//指向第二个数组开头
    a2end=right,//指向第二个数组结尾
    bcout=0;//指向b中的元素
    for(int j=0;j<right-left+1;j++)//执行right-left+1次循环
    {
        if(a1cout>a1end){b[bcout++]=a[a2cout++];continue;}//如果第一个数组结束，拷贝第二个数组的元素到b
        if(a2cout>a2end){b[bcout++]=a[a1cout++];continue;}//如果第二个数组结束，拷贝第一个数组的元素到b
        if(a[a1cout]<a[a2cout]){b[bcout++]=a[a1cout++];continue;}//如果两个数组都没结束，比较元素大小，把较小的放入b
        else
            {b[bcout++]=a[a2cout++];continue;}
    }
}

//对数组a[left:right]进行合并排序
template <class T>
void MergeSort(T a[],int left,int right)
{
    T *b=new int[right-left+1];
    if(left<right)
    {
        int i=(left+right)/2;//取中点
        MergeSort(a,left,i);//左半边进行合并排序
        MergeSort(a,i+1,right);//右半边进行合并排序
        Merge(a,b,left,i,right);//左右合并到b中
        Copy(a,b,left,right);//从b拷贝回来
    }
}

//from http://hi.baidu.com/zhangamxqun
int main()
{
    int n;
    cout<<"how many numbers to sort:";
    cin>>n;
    int *a=new int[n];
    cout<<"input "<<n<<" numbers:";
    for(int i=0;i<n;i++)
        {cin>>a[i];}
    MergeSort( a, 0, n-1);
    for(int j=0;j<n;j++)
    {
        cout<<setw(5)<<a[j];
    }
    return 1;
}