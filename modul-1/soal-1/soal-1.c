#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_operator_valid(char operator) {
    return operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '%';
}

int main() {
    char operator;
    double bilangan1, bilangan2;
    char ulangi;

    do {
        printf("Praktikum ALPROG Kelompok 19\n");

        do {
            printf("Masukkan operator (+, -, *, /, %%): ");
            scanf(" %c", &operator);

            if (!is_operator_valid(operator)) {
                printf("Kesalahan: Operator tidak valid. Masukkan operator yang benar.\n");
            }
        } while (!is_operator_valid(operator));

        printf("Masukkan dua bilangan: \n");
        scanf("%lf %lf", &bilangan1, &bilangan2);

        double hasil;

        switch (operator) {
            case '+':
                hasil = bilangan1 + bilangan2;
                break;
            case '-':
                hasil = bilangan1 - bilangan2;
                break;
            case '*':
                hasil = bilangan1 * bilangan2;
                break;
            case '/':
                if (bilangan2 != 0) {
                    hasil = bilangan1 / bilangan2;
                } else {
                    printf("Kesalahan: Tidak dapat membagi dengan nol.\n");
                    return 1;
                }
                break;
            case '%':
                if (bilangan2 != 0) {
                    hasil = fmod(bilangan1, bilangan2);
                } else {
                    printf("Kesalahan: Tidak dapat menghitung modulus dengan nol.\n");
                    return 1;
                }
                break;
        }

        printf("Hasil kalkulasi: %.2lf\n", hasil);

        do {
            printf("Apakah Anda ingin mengulang? (1.yes/0.no): ");
            scanf(" %c", &ulangi);
        } while (ulangi != '1' && ulangi != '0');

    } while (ulangi == '1');

    return 0;
}
