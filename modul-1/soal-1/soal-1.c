#include <stdio.h>
#include <stdlib.h>  // For the exit function

int main() {
    int operator;
    double num1, num2, result;
    char again;

    do {
        // Requesting an operator and performing validation
        while (1) {
            printf("Enter the operator (1 for addition(+), 2 for subtraction(-), 3 for multiplication(*), 4 for division(/), 5 for modulo): ");
            if (scanf("%d", &operator) == 1 && operator >= 1 && operator <= 5) {
                break;
            }
            printf("Invalid operator. Please enter an operator from 1 to 5.\n");
            // Clearing the stdin buffer
            while (getchar() != '\n');
        }

        // Requesting num1 and performing validation
        while (1) {
            printf("Enter num1: ");
            if (scanf("%lf", &num1) == 1) {
                break;
            }
            printf("Invalid input for num1. Please enter a number.\n");
            // Clearing the stdin buffer
            while (getchar() != '\n');
        }

        // Requesting num2 and performing validation
        while (1) {
            printf("Enter num2: ");
            if (scanf("%lf", &num2) == 1) {
                break;
            }
            printf("Invalid input for num2. Please enter a number.\n");
            // Clearing the stdin buffer
            while (getchar() != '\n');
        }

        // Validating division or modulo by zero
        if ((operator == 4 || operator == 5) && num2 == 0) {
            printf("Cannot perform division or modulo by zero.\n");
        } else {
            // Using a switch-case structure to calculate the result
            switch (operator) {
                case 1:
                    result = num1 + num2;
                    break;

                case 2:
                    result = num1 - num2;
                    break;

                case 3:
                    result = num1 * num2;
                    break;

                case 4:
                    if (num2 != 0) {
                        result = num1 / num2;
                    } else {
                        printf("Cannot perform division by zero.\n");
                    }
                    break;

                case 5:
                    if (num2 != 0) {
                        result = (int)num1 % (int)num2;
                    } else {
                        printf("Cannot perform modulo operation by zero.\n");
                    }
                    break;
            }

            // Displaying the result with two decimal places
            printf("Result: %.2lf\n", result);
        }

        while (1) {
            printf("Do you want to calculate again? (y/n): ");
            scanf(" %c", &again);  // Extra space before %c to handle newline
            if (again == 'y' || again == 'Y' || again == 'n' || again == 'N') {
                break;
            }
            printf("Invalid input. Please enter 'y' or 'n'.\n");
            // Clearing the stdin buffer
            while (getchar() != '\n');
        }
        
    } while (again == 'y' || again == 'Y');

    return 0;
}
