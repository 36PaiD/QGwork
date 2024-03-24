#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(){
    initCalStack(&cal);
    inputformula();
    while(!isEmptyStack()){
        test=PeekStack();
        printf("%c ",test);
        data2[k]=test;
        k++;
    }
    printf("\n");
    printf("%s\n",data2);
    system("pause");
    calculate(data2);
    int Resu=getResult(&cal);
    printf("=%d\n",Resu);
    return 0;
}