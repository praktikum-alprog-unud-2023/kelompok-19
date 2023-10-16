#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
struct Hasil
{
    double volume;
    double luaspermukaan;
};

int validasiAngka(int minimum, int maximum) // Hanya sebuah validasi angka biasa.
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
        validasiAngka(minimum, maximum);
    }
}

double validasiDouble(double minimum) // Hanya sebuah validasi angka biasa.
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
        validasiDouble(minimum);
    }

}

struct Hasil tabung(double jarijari, double tinggi)
{
    struct Hasil hasil;

    hasil.luaspermukaan = 2 * M_PI * jarijari * (jarijari + tinggi);
    hasil.volume = M_PI * pow(jarijari, 2) * tinggi;
    return hasil;
}

struct Hasil bola(double jarijari)
{
    struct Hasil hasil;

    hasil.luaspermukaan = (4 * M_PI * pow(jarijari, 3)) / 3;
    hasil.volume = 4 * M_PI * pow(jarijari, 2);
    return hasil;
}

struct Hasil kerucut(double jarijari, double tinggi, double sisimiring){
    struct Hasil hasil;

    hasil.luaspermukaan = (1 * M_PI * pow(jarijari, 2) * tinggi) / 3;
    hasil.volume = M_PI * jarijari * (jarijari + sisimiring);
    return hasil;
}

int main()
{
    int program;
    struct Hasil hasil;
    double jarijari, tinggi, sisimiring;

    // Input Operator
    printf("\n");
    printf("\t\t\t\tProgram Menghitung Volume dan luas permukaan bangun ruang\n");
    printf("Pilih Program (1-5) : \n");
    printf("\n 1. Tabung\n 2. Bola\n 3. limas Segiempat\n 4. Prisma Segitiga\n 5. Kerucut\n");
    printf("\n\nPilihan mu: ");
    program = validasiAngka(1,5);

    switch (program) // Memilih operator dalam list
    {
    case 1: // Tabung //Punya Linda

        printf("Masukan Jari_Jari Tabung: ");
        jarijari = validasiDouble(0);
        printf("Masukan Tinggi Tabung: ");
        tinggi = validasiDouble(0);

        hasil = tabung(jarijari, tinggi);

        // menampilkan hasil
        printf("Volume Tabung : %lf\n", hasil.volume);
        printf("Luas Permukaan Tabung : %lf\n", hasil.luaspermukaan);
        break;

    case 2: // Bola

        printf("Masukan Jari_Jari Bola: ");
        jarijari = validasiDouble(0);
        hasil = bola(jarijari);

        // menampilkan hasil
        printf("Volume Bola : %lf\n", hasil.volume);
        printf("Luas Permukaan Bola : %lf\n", hasil.luaspermukaan);
        break;

    case 3: //
        break;

    case 4: //
        break;

    case 5: //
        printf("Masukkan nilai jari-jari: ");
        jarijari = validasiDouble(0);
        printf("Masukkan nilai tinggi: ");
        tinggi = validasiDouble(0);
        printf("Masukkan nilai sisi miring: ");
        sisimiring = validasiDouble(0);

    
        printf("Volume kerucut= %lf\n", hasil.volume);
        printf("Luas permukaan kerucut= %lf\n", hasil.luaspermukaan);
        break;
    }
    return 0;
}