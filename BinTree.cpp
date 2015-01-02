// BinTree.cpp : Defines the entry point for the console application.
//


/*
Slyar
http://www.slyar.com
2009.5.16
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAXSIZE 200
 
/* define tree node */
typedef struct node
{
    char data;
    struct node *lchild, *rchild;
}BTNode;
 
/* func declaration */
BTNode* CreatBitTree();
void PreOrder(BTNode*);
void InOrder(BTNode*);
void PostOrder(BTNode*);
 
/* main */
int main(int argc, char* argv[])
{
    BTNode *root = NULL;
    root = CreatBitTree();
    PreOrder(root);
    InOrder(root);
    PostOrder(root);
    
    return 0;
}
 
/* create tree with preorder */
BTNode* CreatBitTree()
{
    char ch;
    BTNode *b;
    cout<<"input a char: ";
    cin>>ch;

    /* stop recursive when meet # */
    if (ch == '#')
    {
        b = NULL;
        cout<<"b = NULL"<<endl;
    }
    else
    {
        b = (BTNode*) malloc(sizeof(BTNode));
        /* create root */
        b->data = ch;
        printf("node: %c\n", ch);
        cout<<endl<<"creating left tree"<<endl;
        /* create left tree */
        b->lchild = CreatBitTree();
        cout<<"creating right tree"<<endl;
        /* create right tree */
        b->rchild = CreatBitTree();
        cout<<"exiting else..."<<endl;

    }
    return b;
}
 
/* non-recursive preorder traverse */
void PreOrder(BTNode* b)
{
    BTNode *stack[MAXSIZE], *p;
    int top = -1;
    if (b != NULL)
    {
        /* push root */
        top++;
        stack[top] = b;
        /* loop when stack is not empty */
        while (top > -1)
        {
            /* pop and access a node */
            p = stack[top];
            top--;
            printf("%c ", p->data);
            /* push rchild */
            if (p->rchild != NULL)
            {
                top++;
                stack[top] = p->rchild;
            }
            /* push lchild */
            if (p->lchild != NULL)
            {
                top++;
                stack[top] = p->lchild;
            }
        }
        printf("\n");
    }
}
 
/* non-recursive inorder traverse */
void InOrder(BTNode* b)
{
    BTNode *stack[MAXSIZE], *p;
    int top = -1;
    if (b != NULL)
    {
        p = b;
        while (top > -1 || p != NULL)
        {
            /* push all left nodes of p into stack */
            while (p != NULL)
            {
                top++;
                stack[top] = p;
                p = p->lchild;
            }
            if (top > -1)
            {
                /* pop & access a node */
                p = stack[top];
                top--;
                printf("%c ", p->data);
                /* scan right child of p */
                p = p->rchild;
            }
        }
        printf("\n");
    }
}
 
/* non-recursive post-order traverse */
void PostOrder(BTNode* b)
{
    BTNode *stack[MAXSIZE], *p;
    int sign, top = -1;
    if (b != NULL)
    {
        do
        {
            /* push lchild of p into stack */
            while (b != NULL)
            {
                top++;
                stack[top] = b;
                b = b->lchild;
            }
            /* set accessed node to NULL, because leaf node's both children are NULL */
            p = NULL;
            /* sign to quit while loop and push left child from start of do loop */
            sign = 1;
            while (top != -1 && sign)
            {
                /* access lchild first (pushed in previous while loop) */
                b = stack[top];
                /* check if right child has been accessed. if yes, access parent node */
                if (b->rchild == p)
                {
                    printf("%c ", b->data);
                    top--;
                    /* remember accessed right child */
                    p = b;
                }
                else
                {
                    /* right child has not been accessed */
                    b = b->rchild;
                    /* exit current while loop */
                    sign = 0;
                }
            }
        }while (top != -1);
        printf("\n");
    }
}