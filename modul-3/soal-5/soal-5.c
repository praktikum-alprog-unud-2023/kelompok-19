#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>

void encryption(int key, char plain[255]) {
    for (int i = 0; i < strlen(plain); i++) {
        char cipher = plain[i];

        if (plain[i] == ' ') {
            cipher = ' ';
        } else if (plain[i] >= 'A' && plain[i] <= 'Z') {
            cipher = ((plain[i] + key - 'A') % 26) + 'A';
        } else if (plain[i] >= 'a' && plain[i] <= 'z') {
            cipher = ((plain[i] + key - 'a') % 26) + 'a';
        }

        printf("%c", cipher);
    }
}

void decryption(int key, char plain[255]) {
    for (int i = 0; i < strlen(plain); i++) {
        char cipher = plain[i];

        if (isalpha(plain[i])) {
            if (isupper(plain[i])) {
                cipher = (char)(((plain[i] - key - 'A' + 26) % 26) + 'A');
            } else {
                cipher = (char)(((plain[i] - key - 'a' + 26) % 26) + 'a');
            }
        }

        printf("%c", cipher);
    }
}

int main() {
    int key, repeat;
    char choiceStr[10];
    int choice;
    char plain[255];
    char buffer[100];
    
    do{
        printf("Choose Your Program:\n");
        printf("1. Encryption\n");
        printf("2. Decryption\n");
    
        while(1) {
            printf("Your Choice: ");
            fgets(choiceStr, 10, stdin);

            choice = atoi(choiceStr);

            if (choice == 1 || choice == 2) {
                break;
            } else {
                printf("Your input is wrong. Please re-enter(1-2)!\n");
            }
        } 
        
        while(1) {
            printf("Key: ");
            if (scanf("%d", &key) != 1) {
                printf("Invalid input. Please enter a valid number.\n");
                while (getchar() != '\n') {
                    // do nothing
                }
            } else if (key >= 0) {
                break; 
            } else {
                printf("Number must be greater than or equal to 0. Please re-enter.\n");
            }  
        }

        while (getchar() != '\n') {
            // do nothing
        }

    while(1) {
            printf("Plaintext: ");
            fgets(plain, sizeof(plain), stdin);

            plain[strcspn(plain, "\n")] = '\0';

            // Check if the input is empty
            if (plain[0] == '\0') {
                printf("Empty input. Please re-enter.\n");
            } else {
                int valid = 1; // Flag to track whether the input is valid
                for (int i = 0; plain[i] != '\0'; i++) {
                    if (!isalpha(plain[i]) && plain[i] != ' ') {
                        valid = 0; 
                        break; 
                    }
                }

                if (!valid) {
                    printf("Your input is wrong. Please re-enter.\n");
                } else {
                    break; // Exit the loop if the input is valid
                }
            }
        }

        switch(choice) {
            case 1:
            printf("Encryption Result: ");
            encryption(key, plain);
            break;

            case 2:
            printf("Decryption Result: ");
            decryption(key, plain);
            break;

            default:
            printf("Your input is not valid.");
        }

        while (1) {
            printf("\n\nDo you want to run the program again? (1 for yes, 0 for no): ");
            fgets(buffer, sizeof(buffer), stdin);

            int validInput = sscanf(buffer, "%d", &repeat);

            if(validInput == 1) {
                if(repeat == 0 || repeat == 1) {
                    break;
                } else {
                    printf("Your input is wrong. Please re-enter.");
                }
            } else {
                printf("Your input is wrong. Please re-enter.");
                getchar();
            }
        }

    } while (repeat == 1);

    return 0;
}
