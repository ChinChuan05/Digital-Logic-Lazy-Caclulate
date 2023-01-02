#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char boolean_sigma[16][5] = {"0000", "0100", "0011", "1100", "1111", "0101"}; //四位數字表ABCD 1:正 0:反向

int simplification(char sigma[16][5]);  //回傳SOP式

int main(){
    simplification(boolean_sigma);
}

int simplification(char sigma[16][5]){
    int one = 0, num;
    int flag[5] = {0, 0, 0, 0, 0};
    char* form[5][10] = {NULL};

    for(int i=0; i<16; i++){
        one = 0;
        if(sigma[i][0] == '\0') break;
        for(int j=0; j<4; j++){
            num = (int)sigma[i][j] - 48;
            printf("%d", num);
            if(num == 1){
                one++;
            }
        }
        printf("\n\tone: %d\n\t", one);
        
        //printf("%c", sigma[i][k]);
        form[one][flag[one]] = &sigma[i][0];
        
        printf("%c", *form[one][flag[one]]);
        printf("%c", *(form[one][flag[one]]+1));
        printf("%c", *(form[one][flag[one]]+2));
        printf("%c", *(form[one][flag[one]]+3));
        printf("\n\n");
        
        flag[one]++;
    }
    
   
    for(int i=0; i<5; i++){
        printf("%d個1的: ", i);
        for(int j=0; j<20;j++){
            if(form[i][j] != 0x0){
                printf("%c", *form[i][j]);
                printf("%c", *(form[i][j]+1));
                printf("%c", *(form[i][j]+2));
                printf("%c, ", *(form[i][j]+3));
            }
        }
        printf("\n");
    }
    return 0;
}
