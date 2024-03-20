#ifndef LINKLIST_FUNCTIONS_H
#define LINKLIST_FUNCTIONS_H
#include<stdio.h>
#include "string.h"
#include "stdlib.h"
#include "declaration.h"
#define LEN sizeof (struct Node)
//初始化链表
struct Node *creat(){
    Node *head = (Node*)malloc(LEN);
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
        newNode->next = NULL;
        tail->next=newNode;
        tail=newNode;
    }
    return head;
}
//释放链表
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
//输出链表
void printList(Node *head) {
    if(head==NULL||head->next==NULL){
        printf("链表为空！！！\n");
        return;
    }
    Node *current = head->next;
    int i=1;
    while (current != NULL) {
        printf("%d->",current->num);
        current = current->next;
    }
    printf("NULL");
    printf("\n");
}
//主菜单
int MENU(){
    printf("**************主菜单*************\n");
    printf("|\t1.初始化链表\t\t|\n");
    printf("|\t2.插入新节点\t\t|\n");
    printf("|\t3.输出链表\t\t|\n");
    printf("|\t4.反转链表\t\t|\n");
    printf("|\t5.中间链表\t\t|\n");
    printf("|\t6.判断链表是否成环\t|\n");
    printf("|\t7.删除节点\t\t|\n");
    printf("|\t8.奇偶反转\t\t|\n");
    printf("|\t9.查询链表\t\t|\n");
    printf("|\t10.构建循环链表\t\t|\n");
    printf("|\t11.退出系统\t\t|\n");
    printf("*********************************\n");
    printf("欢迎光临，请输入你想要进行的操作编号：");
    int result;
    scanf("%d",&result);
    return result;
}
//增加节点菜单
void add_MENU(){
    while (1){

        printf("**************插入节点*************\n");
        printf("|\t1.在头部插入节点\t|\n");
        printf("|\t2.在尾部插入节点\t|\n");
        printf("|\t3.在指定位置插入节点\t|\n");
        printf("|\t4.返回上一级菜单\t|\n");
        printf("*********************************\n");
        printf("请输入你想要进行的操作编号：");
        int result2;
        scanf("%d",&result2);
        switch (result2) {
            case 1:
                add_head(&head);
                break;
            case 2:
                add_tail(&head);
                break;
            case 3:
                add_Node(&head);
                break;
            case 4:
                printf("您选择了返回上一级菜单\n");
                system("pause");
                system("cls");
                return;
            default:
                system("cls");
                printf("!!!您输入的选项不存在对应功能，请重新输入!!!\n");
                break;
        }
    }
}
//在首部增加节点
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
        newNode->next=current->next;
        current->next=newNode;
        current=newNode;
    }
    printf("节点添加成功！\n");
    printList(*head);
    system("pause");
    system("cls");
}
//在尾部增加节点
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
        current->next=newNode;
        newNode->next=NULL;
        current=newNode;
    }
    printf("节点添加成功！\n");
    printList(*head);
    system("pause");
    system("cls");
}
//在任意处增加节点
void add_Node(Node **head){
    int n,m,new_num;
    printList(*head);
    printf("请输入要插入位置的前一个节点的数据：");
    scanf("%d",&n);
    printf("请输入你要在第几个节点插入数据：");
    scanf("%d",&m);
    Node *current=*head;
    for (int i = 0; i < m; i++) {
        current=current->next;      //找到用户输入的m节点
    }
    if (current->num==n){
        Node *newNode = (Node*) malloc(LEN);
        printf("请输入新增加的节点的数据：");
        scanf("%d",&new_num);
        newNode->num=new_num;
        newNode->next=current->next;
        current->next=newNode;
        printf("节点添加成功！\n");
        printList(*head);
    } else {
        printf("未找到相应的节点！！！\n");
    }
    system("pause");
    system("cls");
}
//删除节点
void deleteNode(Node **head){
    Node *current=*head;
    if(current==NULL||current->next==NULL){
        printf("链表为空！！！\n");
        return;
    }
    int n,m;
    printList(*head);
    printf("请输入你要删除的节点的数据：");
    scanf("%d",&n);
    printf("请输入你要删除第几个节点：");
    scanf("%d",&m);
    for (int i = 0; i < m-1; i++) {
        current=current->next;//找到要删除的节点的上一个节点
    }
    if (current->next->num==n){
        Node *del=current->next;
        current->next=del->next;
        free(del);
        printf("成功删除第%d个节点\n",m);
        printList(*head);
    } else {
        printf("未找到相应的节点！！！\n");
    }
}
//中间节点
void mid_list(Node **head){
    Node *current=*head;
    if(current==NULL||current->next==NULL){
        printf("链表为空！！！\n");
        system("pause");
        return;
    }
    Node *p1=*head,*p2=*head;
    while (p2->next!=NULL){
        p1=p1->next;
        p2=p2->next;
        if(p2->next!=NULL){
            p2=p2->next;
        }
    }
    printf("链表的中间节点的数据为：%d\n",p1->num);
    system("pause");
}
//奇偶反转
void change_list(Node **head){
    Node *current=*head;
    if(current==NULL||current->next==NULL){
        printf("链表为空！！！\n");
        return;
    }
    printList(*head);
    Node *p1=*head;
    Node *p2=p1->next;
    while (p2->next!=NULL){
        p1->next=p2->next;
        p2->next=p1->next->next;
        p1->next->next=p2;
        p1=p1->next->next;
        if(p1->next!=NULL)
           p2=p1->next;
    }
    printf("反转完毕\n");
    printList(*head);
}
//查询链表
void searList(Node **head){
    Node *current = *head;
    if(current==NULL||current->next==NULL){
        printf("链表为空！！！\n");
        system("pause");
        return;
    }
    int n;
    printf("请输入你想查询第几个节点：");
    scanf("%d",&n);
    for (int i = 0; i <n-1; i++) {
        current=current->next;
        if(current->next==NULL){
            printf("你要查询的节点不存在！！！\n");
            system("pause");
            return;
        }
    }
    printf("第%d个节点的数据为：%d\n",n,current->next->num);
    system("pause");
}
//递归算法反转链表
Node *reverse1(Node *head){
    if(head==NULL||head->next==NULL)
        return head;
    Node *newhead= reverse1(head->next);
    Node *temp=head->next;
    temp->next=head;
    head->next=NULL;
    return newhead;
}
Node *new1(Node *head){
    Node *newHead=(Node*) malloc(LEN);
    newHead->next=head;
    return newHead;
}
//非递归算法反转链表
Node* reverse2(Node* head) {
    if(head==NULL||head->next==NULL)
        return head;
    Node* p1 = NULL;
    Node* current = head->next;  // 跳过头节点
    Node* p2 = NULL;
    while (current != NULL) {
        p2 = current->next;  // 保存下一个节点
        current->next = p1;  //
        p1 = current;        // 让current指向自己
        current = p2;        // 移动current到p2的位置，此时由A->B变成了A<-B
    }
    head->next = p1;  // 将头节点的p2指向新的链表尾部
    return head;
}
void Circular(Node *head) {
    if (head == NULL || head->next == NULL) {
        printf("链表为空，无法构建循环链表！！！\n");
        return;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head->next; // 将尾节点指向头节点的下一个节点，形成循环
    printf("循环链表构建完毕");
    cir++;
}
#endif //LINKLIST_FUNCTIONS_H
