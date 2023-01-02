#include <stdlib.h>
#include <stdio.h>

void historyIn_Conversion() { //Way to input conversion result to history
    FILE *Pointer;
    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/History_Conversion.txt", "a");
}

void historyIn_Simplification() { //Way to input simplification result to history
    FILE *Pointer;
    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/History_Simplification.txt", "a");
}

void historyDeletionMenu() {
    FILE *Pointer;
    int input;
    char inputYesNo;
    do {
        printf("Input:\n1 to delete conversion history\n2 to delete simplification history\n[Type -1 to end]\n|? - ");
        scanf("%d", &input);
        if (input == -1) {
            printf("\n");
            return 0;
        }
        printf("\n");
    } while ((input < 1) || (input > 2)); //Input method with cancel function

    switch(input) {
    case 1:
        do {
            printf("\nAre you sure you want to delete your conversion history? [y/n]\n|? - ");
            scanf(" %c", &inputYesNo);
        } while ((inputYesNo != 'y') && (inputYesNo != 'Y') && (inputYesNo != 'n') && (inputYesNo != 'N'));

        if ((inputYesNo == 'y') || (inputYesNo == 'Y')) {
            fclose(fopen("../Digital-Logic-Lazy-Caclulate/History_Conversion.txt", "w"));
            printf("History deleted!\n");
        }
        else
            break;

        break;

    case 2:
        do {
            printf("\nAre you sure you want to delete your simplification history? [y/n]\n|? - ");
            scanf(" %c", &inputYesNo);
        } while ((inputYesNo != 'y') && (inputYesNo != 'Y') && (inputYesNo != 'n') && (inputYesNo != 'N'));

        if ((inputYesNo == 'y') || (inputYesNo == 'Y')) {
            fclose(fopen("../Digital-Logic-Lazy-Caclulate/History_Simplification.txt", "w"));
            printf("History deleted!\n");
        }
        else
            break;

        break;
    }
}

void historyDisplayMenu() {
    int input;

    do {
        printf("Input history to be displayed\n1 Conversion History\n2 Simplification History\n[Type -1 to end]\n|? - ");
        scanf("%d", &input);
    if (input == -1) {
            printf("\n");
            return 0;
        }
        printf("\n");
    } while ((input < 1) || (input > 2)); //Input method with cancel function

    switch (input) {
    case 1:
        historyDisplayConversion();
        break;

    case 2:
        historyDisplaySimplification();
        break;
    }
}

void historyDisplayConversion() {
    FILE *Pointer;
    char character;
    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/History_Conversion.txt", "r");

    if (Pointer == NULL) { //File missing, end reading
        printf("Unable to open history file!\n\n");
        fclose(Pointer);
        system("pause");
        return 0;
    }

    character = fgetc(Pointer);
    if (character == EOF) { //File is empty, end reading
        printf("History is empty!\n\n");
        system("pause");
        return 0;
    }

    while (character != EOF) { //Print whole file
        printf("%c", character);
        character = fgetc(Pointer);
    }

    printf("\n");
    fclose(Pointer);

    system("pause");
    return 0;
}

void historyDisplaySimplification () {
    FILE *Pointer;
    char character;

    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/History_Simplification.txt", "r");

    if (Pointer == NULL) { //File missing, end reading
        printf("Unable to open history file!\n\n");
        fclose(Pointer);
        system("pause");
        return 0;
    }

    character = fgetc(Pointer);
    if (character == EOF) { //File is empty, end reading
        printf("History is empty!\n\n");
        system("pause");
        return 0;
    }

    while (character != EOF) { //Print whole file
        printf("%c", character);
        character = fgetc(Pointer);
    }

    printf("\n");
    fclose(Pointer);

    system("pause");
    return 0;
}

int main() {
    //historyDeletionMenu();
    //historyDisplayMenu();
    //historyDisplayConversion();
    //historyDisplaySimplification();

    system ("pause");
    return 0;
}
