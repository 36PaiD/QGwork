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
    printf("|\t1.初始化栈\t\t|\n");
    printf("|\t2.判断栈是否为空\t|\n");
    printf("|\t3.查看栈顶元素\t\t|\n");
    printf("|\t4.清空栈\t\t|\n");
    printf("|\t5.销毁栈\t\t|\n");
    printf("|\t6.入栈\t\t\t|\n");
    printf("|\t7.出栈\t\t\t|\n");
    printf("|\t8.退出系统\t\t|\n");
    printf("*********************************\n");
    printf("实时的栈：\n");
    printf("栈底-");
    printStack(&s);
    printf("栈顶\n");
    printf("欢迎光临，");
    int result; 
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
//初始化栈
void InitStack(LinkStack *s) {  
    s->top = NULL;  // 栈顶指针指向空  
    s->size = 0;    // 栈中元素个数为0  
    
} 
//判断是否为空
int isEmptyStack(LinkStack *s){
    if (s->top==NULL) return 0;
    else return 1;
}
//入栈
void pushStack(LinkStack *s,int data){
    Node *newNode=(Node*)malloc(LEN);
    newNode->num=data;
    newNode->next=s->top;//新结点指向栈顶
    s->top=newNode;//更新栈顶
    s->size++;
}
//出栈
void popStack(LinkStack *s){
    if(!isEmptyStack(s)){
        printf("栈为空！无法出栈！\n");
        return;
    }
    Node *p1=s->top;
    s->top=p1->next;
    free(p1);
    s->size--;
    printf("出栈完成！\n");
}
//将当前栈的元素逆向复制到临时栈
void printStack(LinkStack* s) {  
    LinkStack temS;
    InitStack(&temS);
    Node *current=s->top;
    while(current!=NULL){
        pushStack(&temS,current->num);
        current=current->next;
    }
    while (isEmptyStack(&temS)) {  
        printf("%d-", Pop(&temS));  
    }  
}  
//输出栈
int Pop(LinkStack *s) {  
    if (!isEmptyStack(s)) {  
        printf("栈为空，无法出栈\n");  
        exit(EXIT_FAILURE);  
    }  
    Node *temp = s->top;  
    int poppedValue = temp->num;  
    s->top = temp->next;  
    free(temp);  
    s->size--;  
    return poppedValue;  
}  
//查看栈顶元素
void getTopStack(LinkStack *s){
    if (!isEmptyStack(s)) {  
        printf("栈为空！\n");  
        return;  
    }  
    Node *current=s->top;
    printf("栈顶元素为：%d",current->num);
}
//清空栈
void clearStack(LinkStack *s){
    Node *p1,*p2;
    p1=s->top;
    while(p1!=NULL){
        p2=p1;
        p1=p1->next;
        free(p2);
    }
    s->top=NULL;
    s->size=0;
    printf("栈已清空！\n");
}
//销毁栈
void destoryStack(LinkStack *s){
    clearStack(s);
    free(s);
    printf("栈已销毁！\n");
}
#endif //LINKLIST_FUNCTIONS_H
