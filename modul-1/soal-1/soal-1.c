#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isOperatorValid(char operator) {
    return operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '%';
}

int main() {
    char operator;
    double number1, number2;
    char repeat;

    do {
        printf("ALPROG Group 19 Practice\n");

        do {
            printf("Enter operator (+, -, *, /, %%): ");
            scanf(" %c", &operator);

            if (!isOperatorValid(operator)) {
                printf("Error: Invalid operator. Please enter a valid operator.\n");
            }
        } while (!isOperatorValid(operator));

        printf("Enter two numbers: \n");
        scanf("%lf %lf", &number1, &number2);

        double result;

        switch (operator) {
            case '+':
                result = number1 + number2;
                break;
            case '-':
                result = number1 - number2;
                break;
            case '*':
                result = number1 * number2;
                break;
            case '/':
                if (number2 != 0) {
                    result = number1 / number2;
                } else {
                    printf("Error: Cannot divide by zero.\n");
                    return 1;
                }
                break;
            case '%':
                if (number2 != 0) {
                    result = fmod(number1, number2);
                } else {
                    printf("Error: Cannot calculate modulus with zero.\n");
                    return 1;
                }
                break;
        }

        printf("Calculation result: %.2lf\n", result);

        do {
            printf("Do you want to repeat? (1.yes/0.no): ");
            scanf(" %c", &repeat);
        } while (repeat != '1' && repeat != '0');

    } while (repeat == '1');

    return 0;
}
