#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int boolean_sigma[16] = {1, 5, 7, 9}; //ex. sigma(2, 5, 7, 9, 15)

int simplification(int sigma[]);  //使用SOP式

int main(){
    printf("test");
    simplification(boolean_sigma);
}

int  simplification(int sigma[]){
    printf("test");
    char num_type[5][12][4] = {""};
    char str[4] = {""};
    int one, index;
    
    for(int i=0; i<16; i++){
        one = 0;
        index = 0;
        printf("%d", sigma[i]);
        for(int j=sigma[i]; j>=0; j/=2){
            if(j % 2 != 0){
                one++;
                strcat(str, "1");
            }
            else{
                strcat(str, "0");
            }
        }
        printf("%s", str);
        printf("\n");
        //num_type[one][index] = str;
    }return 0;
}
