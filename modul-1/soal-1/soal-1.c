//Punya Narto
#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double bilangan1, bilangan2;
   
    printf("Praktikum ALPROG Kelompok 19\n"); // Pesan tambahan
    printf("Masukkan operator (+, -, *, /, %): ");
    scanf(" %c", &operator);

    printf("Masukkan dua bilangan: ");
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
                return 1; // Keluar dari program dengan kode kesalahan
            }
            break;
        case '%':
            if (bilangan2 != 0) {
                hasil = fmod(bilangan1, bilangan2);
            } else {
                printf("Kesalahan: Tidak dapat menghitung modulus dengan nol.\n");
                return 1; // Keluar dari program dengan kode kesalahan
            }
            break;
        default:
            printf("WOIIII you ada buat Kesalahan : Operator tidak valid. Jangan ngawur, masukin data dan operasi  sesuai petunjuk,Jangan sampai salah  :)\n");
            return 1; // Keluar dari program dengan kode kesalahan
    }

    printf("Hasil kalkulasi: %.2lf\n", hasil);

    return 0;
}

