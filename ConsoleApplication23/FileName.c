#include<stdio.h>
#include"FileName.h"
#include"FileName1.h"
#include"FileName2.h"

int main(void) {
    int num1=0,num2=0;
    while (1) {
        printf("0:車の情報を表示\n");
        for (int i = 1; i <= 7; i++)
            printf("%d:アルゴリズム%dの表示\n",i,i);
        scanf_s("%d", &num1);
        switch (num1)
        {
        case 0:
            set_car_show();
            break;
        case 1:
            algo_show();
            break;   
        case 2:
            algo2_show();
            break; 
        case 3:
            algo3_show();
            break;
        case 4:
            algo4_show();
            break; 
        case 5:
            algo5_show();
            break;
        case 6:
            algo6_show();
        case 7:
            algo7_show();
            break;
        }
        do {
            printf("続けますか。(-1以下:終了):(0以上 続行)");
            scanf_s("%d", &num2);
        } while (num2 <= -2);
        if (num2 <= -1)
            break;
    }
    return 0;
}