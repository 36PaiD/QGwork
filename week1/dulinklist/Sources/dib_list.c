#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "functions.h"
#include "declaration.h"
int main(){
    int result;
    result = MENU();
    while (result!=11){
        switch (result) {
            case 1:
                system("cls");
                head=creat();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                add_MENU();
                break;
            case 3:
                system("cls");
                print_MENU();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                break;
            case 5:
                system("cls");
                break;
            case 6:
                system("cls");
                break;
            case 7:
                system("cls");
                deleteNode(&head);
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                break;
            case 9:
                system("cls");
                break;
            case 10:
                system("cls");
                break;
            default:
                system("cls");
                printf("!!!你选择的选项不存在对应功能，请重新选择!!!\n");
                break;
        }
        result=MENU();
    }
    printf("你选择了退出程序\n");
    freeList(head);          //�ͷ�����
    printf("欢迎下次光临\n");
    system("pause");
    return 0;
}
