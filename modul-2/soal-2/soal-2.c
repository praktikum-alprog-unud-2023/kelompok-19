#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    int attendance, assignment1, assignment2, assignment3, quiz, midTerm, finalExam;
    double finalGrade;
    char letterGrade[] = "ab";
    char input[100];

    int validInput = 0;

    while (!validInput) {
        // Input course grades
        printf("\n\n\t\tCourse Grade Calculation Program\n\n");
        printf("Enter attendance score (0-15):");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &attendance) != 1 || attendance < 0 || attendance > 15) {
                printf("Invalid attendance input. Must be in the range of 0-15.\n");
                continue;
            }
        }

        printf("Enter assignment 1 score: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &assignment1) != 1 || assignment1 < 0 || assignment1 > 100) {
                printf("Invalid assignment 1 input. Must be in the range of 0-100.\n");
                continue;
            }
        }

        printf("Enter assignment 2 score: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &assignment2) != 1 || assignment2 < 0 || assignment2 > 100) {
                printf("Invalid assignment 2 input. Must be in the range of 0-100.\n");
                continue;
            }
        }

        printf("Enter assignment 3 score: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &assignment3) != 1 || assignment3 < 0 || assignment3 > 100) {
                printf("Invalid assignment 3 input. Must be in the range of 0-100.\n");
                continue;
            }
        }

        printf("Enter quiz score: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &quiz) != 1 || quiz < 0 || quiz > 100) {
                printf("Invalid quiz input. Must be in the range of 0-100.\n");
                continue;
            }
        }

        printf("Enter mid-term exam score: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &midTerm) != 1 || midTerm < 0 || midTerm > 100) {
                printf("Invalid mid-term exam input. Must be in the range of 0-100.\n");
                continue;
            }
        }

        printf("Enter final exam score: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &finalExam) != 1 || finalExam < 0 || finalExam > 100) {
                printf("Invalid final exam input. Must be in the range of 0-100.\n");
                continue;
            }
        }

        // Calculate final grade
        finalGrade = (attendance * 0.05) + ((assignment1 + assignment2 + assignment3) * 0.2) + (quiz * 0.15) + (midTerm * 0.3) + (finalExam * 0.3);

        // Determine letter grade
        if (finalGrade >= 80) {
            sprintf(letterGrade, "A ");
        } else if (finalGrade >= 75) {
            sprintf(letterGrade, "B+");
        } else if (finalGrade >= 70) {
            sprintf(letterGrade, "B ");
        } else if (finalGrade >= 65) {
            sprintf(letterGrade, "C+");
        } else if (finalGrade >= 60) {
            sprintf(letterGrade, "C ");
        } else if (finalGrade >= 55) {
            sprintf(letterGrade, "D+");
        } else if (finalGrade >= 50) {
            sprintf(letterGrade, "D ");
        } else {
            sprintf(letterGrade, "E ");
        }

        validInput = 1;
    }

    printf("\n\t\t\tFinal Grade: %.2f\n", finalGrade);
    printf("\t\t\t  Letter Grade: %s", letterGrade);
    // for(int i = 0; i <= 1; i++){
    //     printf("%c", letterGrade[i]);
    // }

    return 0;
}
