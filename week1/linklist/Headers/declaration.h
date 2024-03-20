#ifndef LINKLIST_DECLARATION_H
#define LINKLIST_DECLARATION_H
#define LEN sizeof (struct Node)
//定义结构体
typedef struct Node{
    int num;
    struct Node *next;
}Node;
Node *head=NULL;
int cir=0;
//函数声明
int MENU();
void add_MENU();
void add_head(Node **head);
void add_tail(Node **head);
void add_Node(Node **head);
void deleteNode(Node **head);
struct Node *creat();//初始化链表
void freeList(struct Node *head);
void printList(Node *head);
void mid_list(Node **head);
void change_list(Node **head);
void searList(Node **head);
Node* reverse1(Node *head);
Node *new1(Node *head);
Node* reverse2(Node* head);
void Circular(Node *head);
#endif //LINKLIST_DECLARATION_H
