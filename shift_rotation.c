#include <stdlib.h>
#include <stdio.h>


int x, y, mode, result;
int rota_shif(int num, int n, int mode);
char name[4][20] = {{"shift left"}, {"shift right"}, {"rotation left"}, {"rotation right"}};

int main(){
    printf("Please input the operand (1)shift left (2)shift right (3)rotaion left (4)rotation right: ");
    scanf("%d", &mode);
    printf("Please input the number(hex) num, n: ");
    scanf("%x%d", &x, &y);

    result = rota_shif(x, y, mode);
    printf("0x%x %s %dtimes = 0x%x\n", x, name[mode-1], y, result);
}

int rota_shif(int num, int n, int mode){
    switch(mode){
        case 1:
            return num<<n;
            break;

        case 2:
            return num>>n;
            break;

        case 3:
            return num<<n | num >> (32-n);
            break;

        case 4:
            return num>>n | num << (32-n);
            break;
    }
    return 0;
}
