#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void add(double num1, double num2) {
    double result = num1 + num2;
    printf("Hasil pertambahan: %.2lf\n", result);
}

void subtract(double num1, double num2) {
    double result = num1 - num2;
    printf("Hasil pengurangan: %.2lf\n", result);
}

void multiply(double num1, double num2) {
    double result = num1 * num2;
    printf("Hasil perkalian: %.2lf\n", result);
}

void divide(double num1, double num2) {
    if(num2 != 0) {
        double result = num1 / num2;
        printf("Hasil pembagian: %.2lf\n", result);
    } else {
        printf("Tidak dapat membagi dengan nol.\n");
    }
}

void modulus(double num1, double num2) {
    if(num2 != 0) {
        double result = fmod(num1, num2);
        printf("Hasil modulus: %.2lf\n", result);
    } else {
        printf("Tidak dapat melakukan modulus dengan nol.\n");
    }
}

int main() {
    double num1, num2;
    char operator, cont;

    do {
        while(1) {
            printf("Masukkan operator (+, -, *, /, %%): ");
            operator = getchar(); // Gets operator

            if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '%') {
                break;
            } else {
                printf("Operator tidak valid.\n");
                continue;
            }
        }

        printf("Masukkan angka pertama: ");
        scanf("%lf", &num1);

        printf("Masukkan angka kedua: ");
        scanf("%lf", &num2);

        switch(operator) {
            case '+':
                add(num1, num2);
                break;
            case '-':
                subtract(num1, num2);
                break;
            case '*':
                multiply(num1, num2);
                break;
            case '/':
                divide(num1, num2);
                break;
            case '%':
                modulus(num1, num2);
                break;
        }

        printf("Apakah ingin mengulangi proses? (yes/no): ");
        scanf(" %c", &cont);

        // Convert input to lowercase
        cont = tolower(cont);

        // If input is not 'y' or 'n', ask for input again
        while(cont != 'y' && cont != 'n') {
            printf("Masukkan input yang benar (yes/no): ");
            scanf(" %c", &cont);

            // Convert input to lowercase
            cont = tolower(cont);
        }

    } while(cont == 'y');

    return 0;
}
