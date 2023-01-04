#include <stdlib.h>
#include <stdio.h>

void main_menu() {
    int in_1, in_2;
    Point1:
    in_1 = 0;
    in_2 = 0;
    printf("Test");
    do {
        printf("1 Number Conversion\n2 Boolean Algebra Simplification\n3 History\n[-1 to end]\nMenu selection:\n| ? - ");
        scanf("%d", &in_1);
        if (in_1 == -1)
        return 0;
        printf("in_1=%d\n", in_1);
    } while((in_1 < 1) || (in_1 > 3));

    switch(in_1) {
        case 1:
        do {
            printf("1 ???\n[-1 to return]Menu selection:\n| ? - ");
            scanf("%d", &in_2);
            if (in_1 == -1)
            break;
        } while((in_1 < 1) || (in_1 > 3));
        break;
        
        case 2:
        do {
            printf("1 ???\n[-1 to return]Menu selection:\n| ? - ");
            scanf("%d", &in_2);
            if (in_1 == -1)
            break;
        } while((in_1 < 1) || (in_1 > 3));
        break;
        
        case 3:
        do {
            printf("1 ???\n[-1 to return]Menu selection:\n| ? - ");
            scanf("%d", &in_2);
            if (in_1 == -1)
            break;
        } while((in_1 < 1) || (in_1 > 3));
        break;
    }
    printf("\n");
    goto Point1;
}
