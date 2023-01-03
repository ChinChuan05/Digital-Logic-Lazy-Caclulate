#include <stdlib.h>
#include <stdio.h>

// Copy paste to main function
// #include "../Digital-Logic-Lazy-Caclulate/history.h"

//  Existing functions
//historyDeletionMenu();
//historyDisplayMenu();
//historyDisplayConversion();
//historyDisplaySimplification();

void historyIn_Conversion(char Type[100], unsigned long long int Input, unsigned long long int Output) { //Way to input conversion result to history
    FILE *Pointer;
    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/History_Conversion.txt", "a");
    fprintf(Pointer, "Type   : %s\n", Type);
    fprintf(Pointer, "Input  : %lld\n", Input);
    fprintf(Pointer, "Output : %lld\n\n", Output);
    fclose(Pointer);
}

void historyIn_Simplification() { //Way to input simplification result to history
    FILE *Pointer;
    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/History_Simplification.txt", "a");
}

void historyDeletionMenu() { //Menu for deleting history
    int input;
    char inputYesNo;
    do { //Input method with cancel function
        printf("Input:\n1 to delete conversion history\n2 to delete simplification history\n[Type -1 to end]\n|? - ");
        scanf("%d", &input);
        if (input == -1) {
            printf("\n");
        }
        printf("\n");
    } while ((input < 1) || (input > 2));

    switch(input) {
    case 1:
        do {
            printf("Are you sure you want to delete your conversion history? [y/n]\n|? - ");
            scanf(" %c", &inputYesNo);
            printf("\n");
        } while ((inputYesNo != 'y') && (inputYesNo != 'Y') && (inputYesNo != 'n') && (inputYesNo != 'N'));

        if ((inputYesNo == 'y') || (inputYesNo == 'Y')) { //Delete function by opening with write function and closing
            fclose(fopen("../Digital-Logic-Lazy-Caclulate/History_Conversion.txt", "w"));
            printf("History deleted!\n\n");
        }
        break;

    case 2:
        do {
            printf("\nAre you sure you want to delete your simplification history? [y/n]\n|? - ");
            scanf(" %c", &inputYesNo);
        } while ((inputYesNo != 'y') && (inputYesNo != 'Y') && (inputYesNo != 'n') && (inputYesNo != 'N'));

        if ((inputYesNo == 'y') || (inputYesNo == 'Y')) { //Delete function by opening with write function and closing
            fclose(fopen("../Digital-Logic-Lazy-Caclulate/History_Simplification.txt", "w"));
            printf("\nHistory deleted!\n\n");
        }

        break;
    }
}

void historyDisplayMenu() { //Display menu for history
    int input;

    do {
        printf("Input history to be displayed\n1 Conversion History\n2 Simplification History\n[Type -1 to end]\n|? - ");
        scanf("%d", &input);
    if (input == -1) {
            printf("\n");
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
    }

    character = fgetc(Pointer);
    if (character == EOF) { //File is empty, end reading
        printf("History is empty!\n\n");
        fclose(Pointer);
        system("pause");
    }

    while (character != EOF) { //Print whole file
        printf("%c", character);
        character = fgetc(Pointer);
    }

    printf("\n");
    fclose(Pointer);
}

void historyDisplaySimplification () {
    FILE *Pointer;
    char character;

    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/History_Simplification.txt", "r");

    if (Pointer == NULL) { //File missing, end reading
        printf("Unable to open history file!\n\n");
        fclose(Pointer);
    }

    character = fgetc(Pointer);
    if (character == EOF) { //File is empty, end reading
        printf("History is empty!\n\n");
        fclose(Pointer);
    }

    while (character != EOF) { //Print whole file
        printf("%c", character);
        character = fgetc(Pointer);
    }

    printf("\n");
    fclose(Pointer);

}
