#include <stdlib.h>
#include <stdio.h>

void historyIn_Conversion() { //Way to input conversion result to history
    FILE *Pointer;
    Pointer = fopen("../History_Conversion.txt", "a");
}

void historyIn_Simplification() { //Way to input simplification result to history
    FILE *Pointer;
}

void historyDeletionMenu() {
    FILE *Pointer;
    signed int input;
    char inputYesNo;
    do {
        printf("Input:\n1 to delete conversion history\n2 to delete simplification history\n[Type -1 to end]\n|? - ");
        scanf("%d", &input);
        if (input == -1) {
            printf("\n");
            return 0;
        }
    } while ((input < 1) || (input > 2)); //Input method with cancel function

    switch(input) {
    case 1:
        do {
            printf("\nAre you sure you want to delete your conversion history? [y/n]\n|? - ");
            scanf(" %c", &inputYesNo);
        } while (inputYesNo != 'y' || inputYesNo != 'n');

        break;

    case 2:
        printf("\nAre you sure you want to delete your simplification history? [y/n]\n|? - ");
        scanf(" %c", &inputYesNo);

        break;
    }
}

int main() {
    historyDeletionMenu();

    system ("pause");
    return 0;
}
