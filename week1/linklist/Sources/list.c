#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "functions.h"
#include "declaration.h"
#include "windows.h"
int main(){
    int result;
    result = MENU();
    while (result!=11){
        switch (result) {
            case 1:
                if(cir!=0){
                    printf("链表已成环！！！\n");
                    break;
                }
                head=creat();
                system("pause");
                system("cls");
                break;
            case 2:
                if(cir!=0){
                    printf("链表已成环！！！\n");
                    break;
                }
                if(head==NULL||head->next==NULL) {
                    printf("链表为空！！！\n");
                    system("pause");
                    system("cls");
                    break;
                }
                system("cls");
                add_MENU();
                system("cls");
                break;
            case 3:
                if(cir!=0){
                    printf("链表已成环！！！\n");
                    break;
                }
                printList(head);
                system("pause");
                system("cls");
                break;
            case 4:
                if(cir!=0){
                    printf("链表已成环！！！\n");
                    break;
                }
                if(head==NULL||head->next==NULL){
                    printf("链表为空！！！\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printList(head);
                head = reverse2(head);
                printf("链表反转完成\n");
                printList(head);
                system("pause");
                system("cls");
                break;
            case 5:
                if(cir!=0){
                    printf("链表已成环！！！\n");
                    break;
                }
                mid_list(&head);
                system("cls");
                break;
            case 6:
                if(cir!=0){
                    printf("链表已成环！！！\n");
                    break;
                }
                if(head==NULL||head->next==NULL) {
                    printf("链表为空！！！\n");
                    system("pause");
                    system("cls");
                    break;
                }
                system("cls");
                break;
            case 7:
                if(cir!=0){
                    printf("链表已成环！！！\n");
                    break;
                }
                deleteNode(&head);
                system("pause");
                system("cls");
                break;
            case 8:
                if(cir!=0){
                    printf("链表已成环！！！\n");
                    break;
                }
                change_list(&head);
                system("pause");
                system("cls");
                break;
            case 9:
                if(cir!=0){
                    printf("链表已成环！！！\n");
                    break;
                }
                searList(&head);
                system("cls");
                break;
            case 10:
                Circular(head);
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                printf("!!!您输入的选项不存在对应功能，请重新输入!!!\n");
                break;
        }
        result=MENU();
    }
    printf("您选择了退出程序\n");
    freeList(head);          //释放链表
    printf("欢迎下次光临\n");
    system("pause");
    return 0;
}
