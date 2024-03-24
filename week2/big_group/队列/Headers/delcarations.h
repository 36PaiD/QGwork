#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//数据节点
typedef struct QNode{
    int data;
    struct QNode *next;
}dataQNode;
//链队节点
typedef struct {
    dataQNode *head;
    dataQNode *tail;
}linkQNode;

int result;
linkQNode q;
int data;
int tem,d;

void initLinkQu(linkQNode *q);
void destroyQNode(linkQNode *q);
void clearQNode(linkQNode *q);
int isEmptyQNode(linkQNode *q);
void pushQNode(linkQNode *q,int e);
int popQNode(linkQNode *q);
void printQNode(linkQNode *q);
void printHeadEle(linkQNode *q);
