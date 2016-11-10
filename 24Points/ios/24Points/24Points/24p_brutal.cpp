#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <map>

using namespace std;

typedef void (^SwiftCallbackFunc(unsigned char *)); 
SwiftCallbackFunc swiftFunc;

//------------------------------------------------------------算法1输出所有组合
//cards[i]的值是通过表达式expr[i]计算而来
//且expr的最后一个运算操作lastop[i]
bool GameRecur_all(double cards[], string expr[], char lastop[],
                   const int cardsNum, const int result)
{
    if(cardsNum == 1)
    {
        if(cards[0] == result)
        {
            cout<<"formular: "<<expr[0]<<endl;
            swiftFunc(expr[0].c_str());
            return true;
        }
        else return false;
    }
    //从已有数中任选两个,计算得到中间结果，并且和剩余的数一起存在cards数组的前
    //cardsNum-1个位置
    map<pair<double,double>,bool> selectedPair;
    bool res = false;
    for(int i = 0; i<cardsNum; i++)
    {
        for(int k  = i+1; k < cardsNum; k++)
        {
            if( selectedPair.find(pair<double, double>(cards[i], cards[k]))
               != selectedPair.end() || selectedPair.find(pair<double, double>
               (cards[k], cards[i])) != selectedPair.end() )
                break;
            else
            {
                selectedPair[pair<double,double>(cards[i], cards[k])] = 1;
                selectedPair[pair<double,double>(cards[k], cards[i])] = 1;
            }
            //上面的代码保证选出的数对不重复
            double a = cards[i], b = cards[k];
            cards[k] = cards[cardsNum-1];
            string expra = expr[i], exprb = expr[k];
            expr[k] = expr[cardsNum-1];
            char lastop_a = lastop[i], lastop_b = lastop[k];
            lastop[k] = lastop[cardsNum-1];

            cards[i] = a + b;
            expr[i] = expra + '+' + exprb;
            lastop[i] = '+';
            res = GameRecur_all(cards, expr, lastop, cardsNum-1, result)
                || res;

            cards[i] = a - b;
            if('+' == lastop_b || '-' == lastop_b)
                expr[i] = expra + '-' + '(' + exprb + ')';
            else expr[i] = expra + '-' + exprb;
            lastop[i] = '-';
            res = GameRecur_all(cards, expr, lastop, cardsNum-1, result) || res;

            if(a != b)
            {
                cards[i] = b - a;
                if('+' == lastop_a || '-' == lastop_a)
                    expr[i] = exprb + '-' + '(' + expra + ')';
                else expr[i] = exprb + '-' + expra;
                lastop[i] = '-';
                res = GameRecur_all(cards, expr, lastop, cardsNum-1, result)
                    || res;
            }

            cards[i] = a * b;
            if('-' == lastop_a || '+' == lastop_a)
                expr[i] = '(' + expra + ')' + '*';
            else expr[i] = expra + '*';
            if('*' == lastop_b || ' ' == lastop_b)
                expr[i] += exprb;
            else expr[i] += '(' + exprb + ')';
            lastop[i] = '*';
            res = GameRecur_all(cards, expr, lastop, cardsNum-1, result)
                || res;

            if(b != 0)
            {
                cards[i] = a / b;
                if('-' == lastop_a || '+' == lastop_a)
                    expr[i] = '(' + expra + ')' + '/';
                else expr[i] = expra + '/';
                if(' ' == lastop_b)
                    expr[i] += exprb;
                else expr[i] += '(' + exprb + ')';
                lastop[i] = '/';
                res = GameRecur_all(cards, expr, lastop, cardsNum-1, result)
                    || res;
            }

            if(a != 0 && a!= b)
            {
                cards[i] = b / a;
                if('-' == lastop_b || '+' == lastop_b)
                    expr[i] = '(' + exprb + ')' + '/';
                else expr[i] = exprb + '/';
                if(' ' == lastop_a)
                    expr[i] += expra;
                else expr[i] += '(' + expra + ')';
                lastop[i] = '/';
                res = GameRecur_all(cards, expr, lastop, cardsNum-1, result)
                     || res;
            }

            //把选出来的两个数放回原位
            cards[i] = a;
            cards[k] = b;
            expr[i] = expra;
            expr[k] = exprb;
            lastop[i] = lastop_a;
            lastop[k] = lastop_b;
        }
    }
    return res;
}

//cards 输入的牌
//cardsNum 牌的数目
//result 想要运算得到的结果
void PointGame_all(int cards[], const int cardsNum, const int result)
{
    string * expr = new string[cardsNum];
    char lastop[cardsNum];
    double cardsCopy[cardsNum];
    for(int i = 0; i < cardsNum; i++)
    {
        char buf[30];
        sprintf(buf, "%d", cards[i]);
        expr[i] = buf;
        lastop[i] = ' ';//表示cardsCopy[i]是不经过任何运算的原始数据
        cardsCopy[i] = cards[i];
    }
    if(GameRecur_all(cardsCopy, expr, lastop, cardsNum, result) == false)
        cout<<"-1\n";
    
    delete [] expr;
}

// extern "C" required to avoid implicit func rename for C++, which leads to link error 
extern "C" {
int generateCards(void)
{
  int cards[4] = { 0, 0, 0, 0 };
  int cardsNum = sizeof(cards)/sizeof(int);
  
  srand(time(NULL));
  for (int i=0;i<cardsNum;i++)
  {
    cards[i] = rand() % 10 + 1;
    printf ("%d ", cards[i]);
  }
  printf ("\n");

  PointGame_all (cards, cardsNum, 24);

  return 0;
}

void registerCallback(void (^callbackFunc(unsigned char *))
{
    swiftFunc = callbackFunc;
}


} /* end of extern "C" */
