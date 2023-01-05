#include "include.h"

int select = 0, type = 0, num, select1 = 0;
char operand[6][5] = {{"and"}, {"or"}, {"nand"}, {"nor"}, {"xor"}, {"nxor"}};

int main(){
    while(select != -1){
        printf("請選擇使用功能: (1)邏輯計算機 (2)布林代數化簡 (3)進制轉換 (4)歷史查詢 (-1跳出程式)\n");
        scanf("%d", &select);

        switch(select){
            case 1:
                printf("Please input the number(hex) X, Y: ");
                scanf("%x%x", &x, &y);
                printf("Please input the operand (1)and (2)or (3)nand (4)nor (5)xor (6)nxor): ");
                scanf("%d", &opnd);
                result = logic_calculate(x, y, opnd);
                printf("\n%x %s %x = 0x%x\n", x, operand[opnd-1], y, result);
                break;

            case 2:
                 simplication();
                 break;

            case 3:
                printf("請輸入進制轉換種類: (1)十進制轉二進制 (2)十進制轉十六進制 (3)十六進制轉十進制 (4)十六進制轉二進制 (5)二進制轉十進制\n");
                scanf("%d",&type);

                switch(type){
                    case 1:
                        D2B();
                        break;
                    
                    case 2:
                        printf("請輸入欲轉換的數: ");
                        scanf("%d",&num);
                        printf("%d的十六進位為%x", num, num);
                        break;

                    case 3:
                        X2D();
                        break;

                    case 4:
                        X2B();
                        break;

                    case 5:
                        B2D();
                        break;
                }
                break;

            case 4:
                printf("Please input to access: (1)Display History (2)Delete History");
                scanf("%d", &select1);

                switch(select1) {
                    case 1:
                        historyDisplayMenu();
                        break;

                    case 2:
                        historyeDeletionMenu();
                        break;
                }
        }
    }
}

