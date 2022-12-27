#include <stdlib.h>
#include <stdio.h>

int x, y, opnd;

//使用16進制進行輸入
int logic_calculate(int x, int y, int operand){ 
    switch(operand){
        case 1:
            return x & y;
            break;
        
        case 2:
            return x | y;
            break;

        case 3:
            return !(x & y);
            break;

        case 4:
            return !(x | y);
            break;

        case 5:
            return x^y;
            break;

        case 6:
            return !(x^y);
    }
}


int main(){
    /*
    printf("Please input the number X, Y: ");
    scanf("%d%d", &x, &y);
    printf("Please input the operand (1)and (2)or (3)nand (4)nor (5)xor (6)nxor): ");
    scanf("%d", &opnd);
    printf("\n\n%d\n", logic_calculate(x, y, op));*/

    for(int s=1; s<=6; s++){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++)
                printf("(%d) %d, %d = %d\n", s, i, j, logic_calculate(i, j, s));
            }
        }
    }
}
