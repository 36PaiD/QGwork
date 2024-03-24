#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof (struct Node1)

typedef struct{
    char data[100];
    int top;
}Stack1;
Stack1 s;
/***********/
//计算部分的栈链节点结构体
typedef struct Node1{
    int num;
    struct Node1 *next;
}Node1;
//计算部分的栈
typedef struct linkStack{
    Node1 *head;
}linkStack;
linkStack cal;
/**********************/
char data2[100];
char test;
int k=0;
/**********/
int pushStack(char data);
void inputformula();
int popStack();
char PeekStack();
char getTopStack();
int isEmptyStack();
int opt(char signal);
/***********************/
void initCalStack(linkStack *cal);
void pushCalStack(linkStack *cal,int data);
void popCalStack(linkStack *cal);
void calculate(char *data2);
void getTopTwo(linkStack *cal,int first,int second);
int calculatorTopTwo(int first,int second,char signal);
int getResult(linkStack *cal);