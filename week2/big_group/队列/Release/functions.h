#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delcarations.h"
//主菜单
int MENU(){
    printf("**************主菜单*************\n");
    printf("|\t1.初始化队列\t\t|\n");
    printf("|\t2.判断队列是否为空\t|\n");
    printf("|\t3.查看队头元素\t\t|\n");
    printf("|\t4.清空队列\t\t|\n");
    printf("|\t5.销毁队列\t\t|\n");
    printf("|\t6.入队\t\t\t|\n");
    printf("|\t7.出队\t\t\t|\n");
    printf("|\t8.退出系统\t\t|\n");
    printf("*********************************\n");
    printf("实时的队：\n");
    printf("队头-");
    printQNode(&q);
    printf("队尾\n");
    printf("欢迎光临，");
    int success;  
    do {  
        printf("请输入你想要进行的操作编号（整数）: ");  
        success = scanf("%d", &result);  
        // 清除任何可能导致后续读取错误的残留输入  
        if (success != 1) {  
            int c;  
            while ((c = getchar()) != '\n' && c != EOF);  
            printf("无效的输入，请重试。\n");  
        }  
    } while (success != 1); 
    return result;
}
//链队初始化
void initLinkQu(linkQNode *q){
    q=(linkQNode*)malloc(sizeof(linkQNode));
    q->head=q->tail=NULL;
}
//清空链队
void clearQNode(linkQNode *q){
    dataQNode *p=q->head,*r;
    if(p!=NULL){
        r=p->next;
        while(r!=NULL){
            free(p);
            p=r;
            r=p->next;
        }
    }
    q->head=q->tail=NULL;
    printf("队列清空完毕！\n");
}
//销毁链队
void destroyQNode(linkQNode *q){
    dataQNode *p=q->head,*r;
    if(p!=NULL){
        r=p->next;
        while(r!=NULL){
            free(p);
            p=r;
            r=p->next;
        }
    }
    free(p);
    free(q);
}
//判断队列是否为空
int isEmptyQNode(linkQNode *q){
    if(q->tail==NULL){
        return 0;
    }else return 1;
}
//入队
void pushQNode(linkQNode *q,int e){
    dataQNode *newNode;
    newNode=(dataQNode*)malloc(sizeof(dataQNode));
    newNode->data=e;
    newNode->next=NULL;
    if(q->tail==NULL){
        q->head=q->tail=newNode;
    }
    else{
        q->tail->next=newNode;
        q->tail=newNode;
    }
    printf("入队成功！\n");
}
//出队
int popQNode(linkQNode *q){
    dataQNode *temp;
    if(q->tail==NULL) return 0;//0代表队为空
    temp=q->head;
    if(q->head==q->tail){
        q->head=q->tail=NULL;
    }
    else q->head=q->head->next;
    free(temp);
    return 1;//1表示出队完毕
}
//输出队列
void printQNode(linkQNode *q){
    dataQNode *pri;
    if(q->tail==NULL) return;
    pri=q->head;
    while(pri!=NULL){
        printf("%d-",pri->data);
        pri=pri->next;
    }
}
//查看队头元素
void printHeadEle(linkQNode *q){
    if(q->tail==NULL){
        printf("队列为空！\n");
        return;
    }
    printf("队列的首元素为：");
    printf("%d\n",q->head->data);
}