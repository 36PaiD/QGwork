#ifndef LINKLIST_DECLARATION_H
#define LINKLIST_DECLARATION_H
#define LEN sizeof (struct Node)
//定义结构体
typedef struct Node{
    int num;
    struct Node *prev;
    struct Node *next;
}Node;
Node *head=NULL;
//函数声明
int MENU();
void add_MENU();
void add_head(Node **head);
void add_tail(Node **head);
void print_MENU();
void print1(Node *head);
void print2(Node *head);
void deleteNode(Node **head);
struct Node *creat();//初始化链表
void freeList(struct Node *head);
void printList(Node *head);
#endif //LINKLIST_DECLARATION_H
