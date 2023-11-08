#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int tower_of_hanoi_recursive(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Pindahkan cakram 1 dari %c ke %c\n", source, target);
        return 1;
    } else {
        int steps1 = tower_of_hanoi_recursive(n - 1, source, target, auxiliary);
        printf("Pindahkan cakram %d dari %c ke %c\n", n, source, target);
        int steps2 = tower_of_hanoi_recursive(n - 1, auxiliary, source, target);
        return steps1 + 1 + steps2;
    }
}

int tower_of_hanoi_iterative(int n) {
    int total_steps = (1 << n) - 1;
    return total_steps;
}

int main() {
    char input[100];
    int n;
    while (1) {
        printf("Masukkan jumlah cakram: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &n) == 1 && n > 0) {
            int total_steps_recursive = tower_of_hanoi_recursive(n, 'A', 'B', 'C');
            printf("Jumlah langkah minimum (metode rekursif): %d\n", total_steps_recursive);

            int total_steps_iterative = tower_of_hanoi_iterative(n);
            printf("Jumlah langkah minimum (metode iteratif): %d\n", total_steps_iterative);
        } else {
            printf("Masukkan angka yang valid.\n");
            continue;
        }

        char choice;
        printf("Apakah Anda ingin menghitung lagi? (y/n): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%c", &choice);
        if (tolower(choice) != 'y') {
            break;
        }
    }

    return 0;
}

