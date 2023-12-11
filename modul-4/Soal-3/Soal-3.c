#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool result;
int baca;

int validateInt(int *var) {
    char buff[1024];
    char check;
    fflush(stdin);
    if (fgets(buff, sizeof(buff), stdin) != NULL) {
        if (sscanf(buff, "%d %c", var, &check) == 1) {
            return 1;
        }
    }
    return 0;
}

void reValidateInt(int *var, char *name) {
    while (1) {
        printf("%s", name);
        fflush(stdin);
        if (validateInt(var))
            break;
        printf("\n\t\t\t\t Sorry, the input you entered is invalid.\n");
        printf("\t\t\t\t Please select an available number: \n");
    }
}

void rangeValidateInt(int *var, int range1, int range2, char *name) {
    while (1) {
        reValidateInt(var, name);
        fflush(stdin);
        if (*var >= range1 && *var <= range2)
            break;
        printf("\n\t\t\t\t Sorry, the input you entered is invalid.\n");
        printf("\t\t\t\t Please select an available number: \n");
    }
}

bool palindrome(char string[]) {
    int len = strlen(string) - 1;
    int mid = len / 2;
    int wrong = 0;
    for (int i = 0; i < strlen(string) - 1; i++) {
        if (i == mid - 1)
            break;
        else if (string[i] != string[len - 1])
            wrong++;
        len--;
    }
    if (wrong > 0)
        return false;
    else
        return true;
}

int frequency(char *string, int frequency[]) {
    char c;
    int len = strlen(string) - 1;
    printf("len = %d\n", len);
    int whitespace = 0;
    if (len < 2)
        printf("\t\t\t\t Sorry, only letters are allowed!\n");
    for (int i = 0; i < len; i++) {
        if ((int)string[i] == 32 || (int)string[i] == 10 || (int)string[i] == 9)
            whitespace++;
        c = tolower(string[i]);
        if ((int)c >= 97 && (int)c <= 122)
            frequency[c - 97]++;
        else
            printf("\t\t\t\t Sorry, only letters are allowed!\n");
    }
}

int display(char *string, int frequency[]) {
    int redundancy;
    char a[100];
    int len = strlen(string) - 1;
    FILE *f = fopen("dictionary.txt", "ab");
    fprintf(f, "%s(%d): ", string, len);
    for (int i = 0; i < len; i++) {
        a[i] = string[i];
        redundancy = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] == string[j])
                redundancy++;
        }
        if (redundancy == 0)
            fprintf(f, "%c = %d ", string[i], frequency[string[i] - 97]);
    }
    if (result == true)
        fprintf(f, "Palindrome\n");
    else
        fprintf(f, ": Not a Palindrome\n");
    fclose(f);
}

void greetings() {
    printf("\t\t\t\t================================================\n");
    printf("\t\t\t\t|                                              |\n");
    printf("\t\t\t\t|               Palindrome Program              |\n");
    printf("\t\t\t\t|                                              |\n");
    printf("\t\t\t\t================================================\n\v");
    system("pause");
    system("cls");
}

void read() {
    
    printf("      Finish or Continue?         \n");
    
    printf("         0. Finish                \n");
    printf("         1. Continue              \n");
    rangeValidateInt(&baca, 0, 1, "\t\t\t\t >>> ");
    system("cls");
}

int main() {
    int choice;
    char string[255] = "";
    greetings();
    do {
        int letter[26] = {0};
        printf("\t\t\t\t Enter a word: ");
        fgets(string, sizeof(string), stdin);
        result = palindrome(string);
        frequency(string, letter);
        display(string, letter);
        system("cls");
        printf("\t\t\t\t Program executed successfully.\n");
        printf("\t\t\t\t Please check the dictionary.txt file for results.\n");
        system("pause");
        system("cls");
        read();
    } while (baca == 1);
}

