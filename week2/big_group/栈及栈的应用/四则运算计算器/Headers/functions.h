#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delcarations.h"
//输入表达式并且入栈
void inputformula(){
    char express[100];
    int i;
    printf("请输入数学表达式（不要带空格！）:");
    scanf("%s",express);
    for (i=0;i<strlen(express);i++){
        //判断该元素是否为符号
        if(express[i]=='+'||express[i]=='-'||express[i]=='*'||express[i]=='/'){
            //printf("%c\n",express[i]);
            //如果目前是空栈，则入栈
            if (isEmptyStack()){
                pushStack(express[i]);
                continue;
            }
            char topEle=getTopStack();//获取栈顶元素给topEle
            //若为左括号，入栈
            if(topEle=='('){
                pushStack(express[i]);
                continue;
            }
            //如果当前栈顶元素的优先级高于输入的元素，
            while (opt(topEle)>=opt(express[i])){
                test=PeekStack();
                printf("%c ",test);//*************************
                data2[k]=test;
                k++;
                topEle=getTopStack();
            }
            pushStack(express[i]);
        }
        else if (express[i]=='('){
            pushStack(express[i]);
        }
        //若为右括号，获取栈顶元素并让其出栈
        else if(express[i]==')'){
            char topEle=PeekStack();
            //当栈顶元素不为左括号时，不断循环出栈
            while(topEle!='('){
                test=topEle;
                printf("%c ",topEle);//**********************
                data2[k]=test;
                k++;
                topEle=PeekStack();
                //topEle=getTopStack();
            }
        }
        //若元素为数字
        else{
            //直接输出
            test=express[i];
            printf("%c",express[i]);//****************************
            data2[k]=test;
            k++;
            int j;
            //这里是为了输出连续的数字，从第i个元素开始往后遍历
            for (j=1;i+j<strlen(express);j++){
                //若后一个元素也为数字，输出它
                if (express[i+j]>='0'&&express[i+j]<='9'){
                    test=express[i+j];
                    printf("%c",express[i+j]);//************************
                    data2[k]=test;
                    k++;
                    //若下一个元素不是数字，跳出循环
                }else{
                    i=i+j-1;
                    printf(" ");
                    break;
                }
            }
        } 
    }
}
//入栈
int pushStack(char data){
    if(s.top==100){
        return -1;
    }
    s.data[s.top]=data;
    s.top++;
    return 1;
}
//出栈
int popStack(){
    if(s.top==0){
        return -1;
    }
    s.data[s.top-1]='\0';
    s.top--;
    return 1;
}
//获取栈顶元素并出栈
char PeekStack(){
    if(s.top==0){
        return '\0';
    }
    char e=s.data[s.top-1];
    s.data[s.top-1]='\0';
    s.top--;
    return e;
}
//获取栈顶元素
char getTopStack(){
    if(s.top==0){
        return '\0';
    }
    char e=s.data[s.top-1];
    return e;
}

int isEmptyStack(){
    if(s.top>0){
        return 0;
    }
    return 1;
}
//判断符号优先级
int opt(char signal){
    if (signal=='+'||signal=='-'){
        return 1;
    }
    else if (signal=='*'||signal=='/'){
        return 2;
    }
}
/****************/
//初始化计算栈
void initCalStack(linkStack *cal){
    cal->head=NULL;
}
//计算栈入栈
void pushCalStack(linkStack *cal,int data){
    Node1 *newNode=(Node1*)malloc(LEN);
    newNode->num=data;
    newNode->next=cal->head;
    cal->head=newNode;
}
//计算器出栈
void popCalStack(linkStack *cal){
    Node1 *p1=cal->head;
    cal->head=p1->next;
    free(p1);
}
//将后缀表达式入栈
void calculate(char *data2){
    int size2=sizeof(data2)/sizeof(data2[0]);
    int i,num2;
    for(i=0;i<size2;i++){
        //如果是数字
        if(data2[i]>'0'&&data2[i]<'9'){
            num2=data2[i];
            pushCalStack(&cal,num2);
        }
        //如果是符号
        else if(data2[i]=='+'||data2[i]=='-'||data2[i]=='*'||data2[i]=='/'){
            int first,second;
            getTopTwo(&cal,first,second);
            int result2=calculatorTopTwo(first,second,data2[i]);
            popCalStack(&cal);
            popCalStack(&cal);
            pushCalStack(&cal,result2);
        }
    }
}
//获取栈顶两个元素
void getTopTwo(linkStack *cal,int first,int second){
    Node1 *current=cal->head;
    first=current->num;
    second=current->next->num;
}
//计算头两个元素
int calculatorTopTwo(int first,int second,char signal){
    if(signal=='+'){
        return second + first;
    }
    else if(signal=='-'){
        return second - first;
    }
    else if(signal=='*'){
        return second * first;
    }
    else if(signal=='/'){
        return second / first;
    }
    return 0;
}
//获取最终结果
int getResult(linkStack *cal){
    Node1 *res=cal->head;
    return res->num;
}
/*****************/