#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
struct Hasil
{
    double volume;
    double luaspermukaan;
};

int validasi_angka(int minimum, int maximum) // Hanya sebuah validasi angka biasa.
{
    char buff[255], invalid;
    int valid;
    scanf("%[^\n]", buff);
    getchar();
    if (sscanf(buff, "%d%c", &valid, invalid) == 1 && valid >= minimum && valid <= maximum)
        return valid;
    else
    {
        printf("Input yang kamu masukkan salah!\nHarap masukkan kembali!\n>> ");
        validasi_angka(minimum, maximum);
    }
}

double validasi_tabung(double minimum) // Hanya sebuah validasi angka biasa.
{
    char buff[255], invalid;
    double valid;
    scanf("%[^\n]", buff);
    getchar();
    if (sscanf(buff, "%lf%c", &valid, invalid) == 1 && valid >= minimum)
        return valid;
    else
    {
        printf("Input yang kamu masukkan salah!\nHarap masukkan kembali!\n>> ");
        validasi_tabung(minimum);
    }

}

struct Hasil tabung(double jarijari, double tinggi)
{
    struct Hasil hasil;

    hasil.luaspermukaan = 2 * M_PI * jarijari * (jarijari + tinggi);
    hasil.volume = 2 * M_PI * jarijari * (jarijari + tinggi);
    return hasil;
}

int main()
{
    int program;
    struct Hasil hasil;
    double jarijari, tinggi;

    // Input Operator
    printf("\n");
    printf("\t\t\t\tProgram Menghitung Volume dan luas permukaan bangun ruang\n");
    printf("Pilih Program (1-5) : \n");
    printf("\n 1. Tabung\n 2. Bola\n 3. limas Segiempat\n 4. Prisma Segitiga\n 5. Kerucut\n");
    printf("\n\nPilihan mu: ");
    program = validasi_angka(1,5);
    switch (program) //  Memilih operator dalam list
    {
    case 1: // Tabung //Punya Linda

        printf("Masukan Jari_Jari Tabung: ");
        jarijari= validasi_tabung(0);
        printf("Masukan Tinggi Tabung: ");
        tinggi = validasi_tabung(0);
        hasil = tabung(jarijari, tinggi);
        // menampilkan hasil
        printf("Volume Tabung : %lf\n", hasil.volume);
        printf("Luas Permukaan Tabung : %lf\n", hasil.luaspermukaan);
        break;
    }
    return 0;
}