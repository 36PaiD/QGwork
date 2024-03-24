#ifndef LINKLIST_DECLARATION_H
#define LINKLIST_DECLARATION_H
#define LEN sizeof (struct Node)
//定义链栈节点结构体
typedef struct Node{
    int num;
    struct Node *next;
}Node;
//定义栈
typedef struct LinkStack {  
    Node *top;  // 栈顶指针  
    int size;   // 栈中元素个数  
} LinkStack;  
    LinkStack s;
    int result;
    int data;
    int jud;
    int temp;
    int d;
//函数声明
int MENU();
//--------------------------------------------
void InitStack(LinkStack *s);
int isEmptyStack(LinkStack *s);
void pushStack(LinkStack *s,int data);
void popStack(LinkStack *s);
void printStack(LinkStack* s);
int Pop(LinkStack *s);
#endif //LINKLIST_DECLARATION_H
