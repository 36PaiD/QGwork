#ifndef LINKLIST_FUNCTIONS_H
#define LINKLIST_FUNCTIONS_H
#include<stdio.h>
#include "string.h"
#include "stdlib.h"
#include "declaration.h"
#define LEN sizeof (struct Node)
struct Node *creat(){
    Node *head = (Node*)malloc(LEN);
    head->prev=NULL;
    head->next=NULL;
    Node *tail = head;
    int n, num;
    printf("请输入链表节点的数量：");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("请输入第%d个节点的值：", i + 1);
        scanf("%d", &num);
        Node *newNode = (Node*)malloc(LEN); // 创建新节点
        newNode->num = num;
        newNode->prev=tail;
        newNode->next=NULL;
        tail->next=newNode;
        tail=newNode;

    }
    return head;
}
void freeList(Node *head) {
    Node *current = head;
    if(head==NULL) return;
    while (current->next != NULL) {
        Node *next = current->next; // 保存下一个节点的指针
        free(current); // 释放当前节点的内存
        current = next; // 移动到下一个节点
    }
    printf("链表释放完毕\n");
}
void printList(Node *head) {
    Node *current = head->next;
    int i=1;
    while (current != NULL) {
        printf("节点%3d：%d\n",i++, current->num);
        current = current->next;
    }
    printf("\n");
}
int MENU(){
    printf("**************主菜单*************\n");
    printf("|\t1.初始化链表\t\t|\n");
    printf("|\t2.插入新节点\t\t|\n");
    printf("|\t3.输出链表\t\t|\n");
    printf("|\t4.反转链表\t\t|\n");
    printf("|\t5.中间链表\t\t|\n");
    printf("|\t6.判断链表是否成环\t|\n");
    printf("|\t7.删除节点\t\t|\n");
    printf("|\t8。奇偶反转\t\t|\n");
    printf("|\t9。查询链表\t\t|\n");
    printf("|\t10.构建循环链表\t\t|\n");
    printf("|\t11.退出系统\t\t|\n");
    printf("*********************************\n");
    printf("欢迎光临，请输入你想要进行的操作编号：");
    int result;
    scanf("%d",&result);
    return result;
}
void add_MENU(){
    while (1){

        printf("**************主菜单*************\n");
        printf("|\t1.在头部插入节点\t\t|\n");
        printf("|\t2.在尾部插入节点\t\t|\n");
        printf("|\t3.返回上一级菜单\t\t|\n");
        printf("*********************************\n");
        printf("请输入你想要进行的操作编号：");
        int result2;
        scanf("%d",&result2);
        switch (result2) {
            case 1:
                system("cls");
                add_head(&head);
                break;
            case 2:
                system("cls");
                add_tail(&head);
                break;
            case 3:
                printf("您选择了返回上一级菜单\n");
                system("cls");
                return;
            default:
                system("cls");
                printf("!!!您输入的选项不存在对应功能，请重新输入!!!\n");
                break;
        }
    }
}
void add_head(Node **head){
    Node *current = *head;
    int num2,n2;
    printf("请输入要添加的节点数量：");
    scanf("%d",&n2);
    for (int i = 0; i < n2; i++) {
        printf("请输入添加的第%d个节点的值：", i + 1);
        scanf("%d", &num2);
        Node *newNode = (Node*)malloc(LEN);
        newNode->num=num2;
        newNode->prev=current;
        newNode->next=current->next;
        current->next->prev=newNode;
        current->next=newNode;
        current=newNode;
    }
}
void add_tail(Node **head){
    Node *current = *head;
    while (current->next!=NULL){
        current=current->next;
    }
    int num3,n3;
    printf("请输入要添加的节点数量：");
    scanf("%d",&n3);
    for (int i = 0; i < n3; i++) {
        printf("请输入添加的第%d个节点的值：", i + 1);
        scanf("%d", &num3);
        Node *newNode = (Node*)malloc(LEN);
        newNode->num=num3;
        newNode->prev=current;
        current->next=newNode;
        newNode->next=NULL;
        current=newNode;
    }
}
void deleteNode(Node **head){
    Node *current=*head;
    int n;
    printf("请输入你要删除第几个节点：");
    scanf("%d",&n);
    for (int i = 0; i < n-1; i++) {
        current=current->next;
    }
    Node *del=current->next;
    current->next=del->next;
    free(del);
    printf("成功删除第%d个节点\n",n);
}
void print_MENU(){
    while (1){
        printf("**************主菜单*************\n");
        printf("|\t1.正向输出\t\t|\n");
        printf("|\t2.反向输出\t\t|\n");
        printf("|\t3.返回上一级菜单\t\t|\n");
        printf("*********************************\n");
        printf("请输入你想要进行的操作编号：");
        int result2;
        scanf("%d",&result2);
        switch (result2) {
            case 1:
                system("cls");
                print1(head);
                break;
            case 2:
                system("cls");
                print2(head);
                break;
            case 3:
                printf("您选择了返回上一级菜单\n");
                system("cls");
                return;
            default:
                system("cls");
                printf("!!!您输入的选项不存在对应功能，请重新输入!!!\n");
                break;
        }
    }
}
void print1(Node *head){
    Node *current = head->next;
    int i=1;
    while (current != NULL) {
        printf("节点%3d：%d\n",i++, current->num);
        current = current->next;
    }
    printf("\n");
}
void print2(Node *head){
    Node *current = head;
    int i=1;
    while (current->next!=NULL){
        current=current->next;
        i++;
    }
    while (current->prev != NULL) {
        printf("节点%3d：%d\n",i--, current->num);
        current = current->prev;
    }
    printf("\n");
}
#endif //LINKLIST_FUNCTIONS_H
