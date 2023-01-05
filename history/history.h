#include <stdlib.h>
#include <stdio.h>

//Removed Input History header, instead put individually into function, due to different data types

// Copy paste to main function
// #include "../Digital-Logic-Lazy-Caclulate/history.h"

//  Existing functions
//historyDeletionMenu();
//historyDisplayMenu();
//historyDisplayConversion();
//historyDisplaySimplification();

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
            fclose(fopen("../Digital-Logic-Lazy-Caclulate/history/History_Conversion.txt", "w"));
            printf("History deleted!\n\n");
        }
        break;

    case 2:
        do {
            printf("\nAre you sure you want to delete your simplification history? [y/n]\n|? - ");
            scanf(" %c", &inputYesNo);
        } while ((inputYesNo != 'y') && (inputYesNo != 'Y') && (inputYesNo != 'n') && (inputYesNo != 'N'));

        if ((inputYesNo == 'y') || (inputYesNo == 'Y')) { //Delete function by opening with write function and closing
            fclose(fopen("../Digital-Logic-Lazy-Caclulate/history/History_Simplification.txt", "w"));
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
    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/history/History_Conversion.txt", "r");

    if (Pointer == NULL) { //File missing, end reading
        printf("Unable to open history file!\n\n");
        fclose(Pointer);
        system("pause");
        return 0;
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
    return 0;
}

void historyDisplaySimplification () {
    FILE *Pointer;
    char character;

    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/history/History_Simplification.txt", "r");

    if (Pointer == NULL) { //File missing, end reading
        printf("Unable to open history file!\n\n");
        fclose(Pointer);
        system("pause");
        return 0;
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
    return 0;
}
