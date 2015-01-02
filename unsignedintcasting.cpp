#include <stdio.h>
#include <iostream>

class A{int a; static int b;};

int main(void)  
{  
	/*
    unsigned int a = -10;  
    int b = -20;  
    unsigned char c = -10;  
    char d = -10;  
    printf("uint %d int %d uchar %d char %d/n",a,b,c,d);  
    printf("uint+int %d uchar+char %d/n",a+b,c+d);  

    std::cout<<"a="<<a<<std::endl;
    std::cout<<"a+b="<<a+b<<std::endl;

    int arr[][3] = {{0,1}, {2,3,4}, {5,6}, {7}};

    std::cout<<"arr[2][1]="<<arr[2][1]<<std::endl;
    */

    //int a=10, b=20, c=30;
    //printf("%d %d %d\n", a+b+c, b=(c*2), c=(c+b));

    int x=2,y=2,z=0,a,b,c;
    a=++x||++y&&z++;
    printf("%d,%d,%d,%d\n", x,y,z,a);

    int i = 10;
    printf("sizeof(i++) is: %lu\n", sizeof(i++));
    printf("i: %d\n", i);

    // http://zhidao.baidu.com/question/159479601.html
    struct MyStruct 
	{ 
		char dda; 
		double dda1;   
		int type; 
	};

    printf("sizeof(MyStruct) is: %lu\n", sizeof(MyStruct));

    x=1, y=2, a=3;//a=029;
    z=x,y,z;
    printf ("z=%d\n", z);
    a=2,b=5,b++,a+b;
    printf ("a=%d\n", a);

    float f = 12.5;
    printf("f=%d\n", f);

    printf("a=%2d\n", a=1);
    printf("a=%2d\n", a=11);
    printf("a=%2d\n", a=111);

    int arr[]={0,5,4,9};
    int *p=arr;
    b=*p++;
    c=*p++;
    printf("b=%2d\n", b);
    printf("c=%2d\n", c);    

    http://www.sogou.com
    printf("welcome\n");
    char str[] = "\\0211\"xab";
    printf("strlen=%d\n\n", strlen(str));

    double db=3.6;
    a=2;
    a*=db;
    printf("a*=db: ");
    std::cout<<a<<std::endl;

    a=3;
    int *pp=&a;
    std::cout<<"*pp="<<(*pp)<<std::endl;
  
}  