#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "functions.h"
#include "windows.h"
int main(){
    result = MENU();
    while (result!=8){
        switch (result) {
            case 1:
                initLinkQu(&q);
                printf("队列初始化完毕！\n");
                system("pause");
                system("cls");
                break;
            case 2:
                if(isEmptyQNode(&q)){
                    printf("队列不为空！\n");
                }else printf("队列为空！\n");
                system("pause");
                system("cls");
                break;
            case 3:
                printHeadEle(&q);
                system("pause");
                system("cls");
                break;
            case 4:
                clearQNode(&q);
                system("pause");
                system("cls");
                break;
            case 5:
                destroyQNode(&q);
                system("pause");
                system("cls");
                break;
            case 6:
                do{
                    printf("请输入要入队的数据：");
                    tem = scanf("%d",&data);
                    if(tem!=1){
                        while ((d = getchar())!='\n'&& d!=EOF);
                        printf("无效的输入，请重试\n");
                    }
                }while (tem!=1);
                //printf("请输入要入队的数据：");
                //scanf("%d",&data);
                pushQNode(&q,data);
                system("pause");
                system("cls");
                break;
            case 7:
                if(popQNode(&q)){
                    printf("出队完成！\n");
                }else {printf("队列为空，无法出队！\n");}
                system("pause");
                system("cls");
                break;
        }
        result=MENU();
    }
    printf("您选择了退出程序\n");
    printf("欢迎下次光临\n");
    system("pause");
    return 0;
}