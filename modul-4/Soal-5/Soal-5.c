#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH_LINE 255
#define MAX_ENTRIES 100

struct Student {
    char name[MAX_LENGTH_LINE];
    int score;
};

int n, wait;

int numberValidate(int range1, int range2) {
    char buff[1024], invalid;
    int valid;
    scanf("%[^\n]", buff);
    getchar();
    if (sscanf(buff, "%d%c", &valid, &invalid) == 1 && valid >= range1 && valid <= range2) {
        return valid;
    } else {
        printf("Your input is wrong!\nPlease re-enter!\n");
        return numberValidate(range1, range2);
    }
}

void choice() {
    printf("\nStudent's Ranks Sorting Program\n");
    printf("1. Create Data\n");
    printf("2. Display Raw Data\n");
    printf("3. Sort and Display Data\n");
}

void create() {
    struct Student assistant[MAX_ENTRIES];
    FILE *asin = fopen("assistantin.txt", "w");
    for (int i = 0; i < n; i++) {
        printf("Name: ");
        fgets(assistant[i].name, sizeof(assistant[i].name), stdin);
        strtok(assistant[i].name, "\n");
        printf("Score: ");
        assistant[i].score = numberValidate(0, 100);
    }
    for (int i = 0; i < n; i++) {
        if (i == n - 1) fprintf(asin, "%s\n%d", assistant[i].name, assistant[i].score);
        else fprintf(asin, "%s\n%d\n", assistant[i].name, assistant[i].score);
    }
    fclose(asin);
}

int checkfiles() {
    FILE *asin = fopen("assistantin.txt", "r");
    char ch;
    int lines = 1;
    if (asin == NULL) {
        printf("Sorry, couldn't open the file.\n");
    }
    do {
        ch = fgetc(asin);
        if ((lines % 2 == 1) && isalpha(ch) == 0 && ch != ' ' && ch != '\n') {
            printf("Invalid data on row - %d\n", lines);
        } else if (lines % 2 == 0 && isdigit(ch) == 0 && ch != '\n' && ch != EOF) {
            printf("Invalid data on row - %d\n", lines);
        }
        if (ch == '\n') {
            lines++;
        }
    } while (ch != EOF);
    fclose(asin);
    return lines;
}

void openDataIn() {
    struct Student assistant[MAX_ENTRIES];
    FILE *asin = fopen("assistantin.txt", "r");
    int read, i = 0;
    printf("Data is available in the file.\n\n");
    do {
        read = fscanf(asin, "%99[^\n]\n%d\n", assistant[i].name, &assistant[i].score);
        if (read == 2) {
            printf("%d. %s: %d\n", i + 1, assistant[i].name, assistant[i].score);
        } else printf("Sorry, your data is not available.\n");
        i++;
    } while (!feof(asin));
    fclose(asin);
    printf("\nFinished displaying the data ....\n");
}

void readData(struct Student assistant[MAX_ENTRIES], int limit) {
    FILE *asin = fopen("assistantin.txt", "r");
    for (int i = 0; i < limit; i++) {
        char score[4];
        fscanf(asin, "%[^\n]%*c", assistant[i].name);
        fscanf(asin, "%[^\n]%*c", score);
        assistant[i].score = atoi(score);
    }
    fclose(asin);
}

void bubbleSort(struct Student assistant[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (assistant[j].score < assistant[j + 1].score) {
                struct Student temp = assistant[j];
                assistant[j] = assistant[j + 1];
                assistant[j + 1] = temp;
            }
        }
    }

    FILE *asout = fopen("assistantout.txt", "w");
    if (asout == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            fprintf(asout, "%d. %s %d", i + 1, assistant[i].name, assistant[i].score);
        } else {
            fprintf(asout, "%d. %s %d\n", i + 1, assistant[i].name, assistant[i].score);
        }
    }

    fclose(asout);
}

void openDataOut() {
    FILE *asout = fopen("assistantout.txt", "r");
    char buffer[1024];
    printf("Data is available in the file.\n\n");

    while (fgets(buffer, 1024, asout) != NULL)
    {
        printf("%s", buffer);
    }
    
    fclose(asout);
    printf("\nFinished reading the data.\n");
}

int main() {
    int array = checkfiles() / 2;
    struct Student assistant[MAX_ENTRIES];
    int yourChoice;

    do {
        choice();
        printf("Input your choice: ");
        yourChoice = numberValidate(0, 3);
        system("cls"); // Menggantikan dengan karakter baris baru
        printf("\n");

        switch (yourChoice) {
            case 1:
                printf("Input the number of student's data: ");
                n = numberValidate(0, MAX_ENTRIES);
                system("cls"); // Menggantikan dengan karakter baris baru
                create();
                printf("\nYour data is successfully made.\nYou can check your data.\n");
                break;
            case 2:
                openDataIn();
                break;
            case 3:
                readData(assistant, array);
                bubbleSort(assistant, array);
                printf("Finished sorting the data.\n");
                system("cls"); // Menggantikan dengan karakter baris baru
                openDataOut();
                break;
            default:
                printf("Thank you :)\n");
        }

        printf("\nDo you want to repeat the program?\n");
        printf("1. Yes.\n");
        printf("0. No.\n");
        printf(">> ");
        wait = numberValidate(0, 1);
        system("cls"); // Menggantikan dengan karakter baris baru
    } while (wait == 1);

    return 0;
}
