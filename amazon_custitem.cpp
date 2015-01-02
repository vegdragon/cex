/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include <cstring>
#include <cstdio>

using namespace std;

char* findMostlyBroughtItem(char* shippingRecordArray[], int length, char* givenItem);

inline bool isSpace(char x){
    return x == ' ' || x == '\r' || x == '\n' || x == '\f' || x == '\b' || x == '\t';
}

char * rightTrim(char *str){
    int len = strlen(str);
    while(--len>=0){
        if(isSpace(str[len])){
            str[len] = '\0';
        }else{
            break;
        }
    }
    return str;
}

char * getInputLine(char *buffer, int length){
    if(fgets(buffer,length, stdin)==NULL){
        return NULL;
    }
    rightTrim(buffer);
    if(strlen(buffer)<=0){
        return NULL;
    }
    return buffer;
}

int splitAndConvert(char* strings,char* array[]){
    char*tokenPtr = strtok(strings," ");
    int i=0;
    while(tokenPtr!=NULL){
        array[i] = tokenPtr;
        i++;
        tokenPtr=strtok(NULL," ");
    }
    return i;
}

int main()
{
    char givenItem[1000] = {0} ;
    while(getInputLine(givenItem, 1000)){
    char line[1000];
    getInputLine(line, 1000);
        
    char* shoppingRecordArray[1000] = {0};
        
        int length = splitAndConvert(line,shoppingRecordArray);
        if(length==0){
            break;
        }
        

        char * item = findMostlyBroughtItem(shoppingRecordArray, length, givenItem);
        if (NULL != item)
        {   // 原来系统提供的代码。这里没有NULL判断
            cout<<item<<endl;
            free(item);  // 自己加的
        }
    }
    return 0; 
}

void
print(pair<string, int> p) {
    cout << p.first << p.second << endl;
}

//your code is here 
//下面才是让写代码的地方，其他的系统已经自动给出。主函数，只有一点点修改。

char* findMostlyBroughtItem(char* shoppingRecordArray[], int length, char* givenItem)
{
    if (NULL == shoppingRecordArray || NULL == givenItem)
        return NULL;
    
    string obj_item(givenItem);
    // 将用户信息 与 购买商品信息 存入multimap record
    multimap<string, string> record;
    for (int i = 0; i < length; i += 2)
    {
        string customer(shoppingRecordArray[i]);
        string item(shoppingRecordArray[i+1]);

        record.insert(pair<string, string>(customer, item));
    }

    // 提取出购买了obj_item商品的客户名称集合 customers
    set<string> customers;
    for (map<string, string>::iterator it = record.begin(); it != record.end(); it++)
    {
        if (0 == (*it).second.compare(obj_item))
        {
            customers.insert((*it).first);
        }
    }
    // 遍历购买记录 multimap record
    // 若客户名称 在 集合set customers 存在，则将商品插入map result
    map<string, int> result;
    for (map<string, string>::iterator it = record.begin(); it != record.end(); it++)
    {
        for (set<string>::iterator ic = customers.begin(); ic != customers.end(); ic++)
        {
            if (0 == (*it).first.compare(*ic))
            {
                /*
                if (result.end() != result.find((*it).second))
                {
                    result[(*it).second] += 1;
                }
                else
                    result.insert(pair<string, int>((*it).second, 1));
                    */
                result[(*it).second] += 1;
                break;
            }
        }

    }


    pair<string, int> top("None", 0);
    // 遍历map result, 寻找最大，而非obj_item的商品名称
    for (map<string, int>::iterator it = result.begin(); it != result.end(); it++)
    {
        if (0 == (*it).first.compare(obj_item))
            continue;
        if ((*it).second > top.second)
            top = make_pair((*it).first, (*it).second);
    }

    //cout << "Top: " << top.first << "\t" << top.second << endl;
    
    char *p = (char *)malloc(top.first.length() + 1);
    if (NULL != p)
    {
        strcpy(p, top.first.c_str());
        return p;
    }

    return NULL;
}
