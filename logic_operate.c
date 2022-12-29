#include <stdlib.h>
#include <stdio.h>

unsigned int x = 0x00, y = 0x00, result;
int opnd;
char operand[6][5] = {{"and"}, {"or"}, {"nand"}, {"nor"}, {"xor"}, {"nxor"}};

//使用16進制進行輸入
int logic_calculate(char x, char y, int operand){ 
    switch(operand){
        case 1:
            return x & y;
            break;
        
        case 2:
            return x | y;
            break;

        case 3:
            return ~(x & y);
            break;

        case 4:
            return ~(x | y);
            break;

        case 5:
            return x^y;
            break;

        case 6:
            return ~(x^y);
            break;

        default:
            return 0;
    }
}


int main(){
    
    printf("Please input the number(hex) X, Y: ");
    scanf("%x%x", &x, &y);
    printf("Please input the operand (1)and (2)or (3)nand (4)nor (5)xor (6)nxor): ");
    scanf("%d", &opnd);
    result = logic_calculate(x, y, opnd);
    printf("\n%x %s %x = 0x%x\n", x, operand[opnd-1], y, result);
/*
    for(int s=1; s<=6; s++){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++)
                printf("(%d) %d, %d = %d\n", s, i, j, logic_calculate(i, j, s));
            }
        }
    }*/
}
