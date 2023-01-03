#include <stdlib.h>
#include <stdio.h>
#include "./logic_operate.h"
#include "./logic_simplication.h"
#include "./shift_rotation.h"


int main(){
    printf("0x%d\n", logic_calculate(0x01, 0x02, 2));
    //simplication();
    printf("0x%d", rota_shif(0x01, 2, 1));
    
}

