#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "functions.h"
#include "declaration.h"
#include "windows.h"
int main(){
    
    result = MENU();
    while (result!=8){
        switch (result) {
            case 1:
                InitStack(&s);
                printf("链栈初始化完成\n");
                system("pause");
                system("cls");
                break;
            case 2:
                jud=isEmptyStack(&s);
                if(jud) printf("栈不为空！\n");
                else printf("栈为空！\n");
                system("pause");
                system("cls");
                break;
            case 3:
                getTopStack(&s);
                system("pause");
                system("cls");
                break;
            case 4:
                clearStack(&s);
                system("pause");
                system("cls");
                break;
            case 5:
                destoryStack(&s);
                system("pause");
                system("cls");
                break;
            case 6:
                do {  
        printf("请输入要入栈的数据（整数）：");
        temp = scanf("%d", &data);  
        // 清除任何可能导致后续读取错误的残留输入  
        if (temp != 1) {    
            while ((d = getchar()) != '\n' && d != EOF);  
            printf("无效的输入，请重试。\n");  
        }  
    } while (temp != 1); 
                pushStack(&s,data);
                printf("入栈成功！\n");
                system("pause");
                system("cls");
                break;
            case 7:
                popStack(&s);
                system("pause");
                system("cls");
                break;
        }
        result=MENU();
    }
    printf("您选择了退出程序\n");
    destoryStack(&s);
    printf("欢迎下次光临\n");
    system("pause");
    return 0;
}
