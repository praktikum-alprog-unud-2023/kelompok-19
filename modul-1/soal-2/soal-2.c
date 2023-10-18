#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

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
// Deklarasi prosedur Segitiga Sembarang
void Luas_Keliling_SegitigaSembarang(double SisiA, double SisiB, double SisiC)
{
    double s = (SisiA + SisiB + SisiC) / 2;                          // menghitung setengah keliling
    double luas = sqrt(s * (s - SisiA) * (s - SisiB) * (s - SisiC)); // proses rumus heron
    double keliling = SisiA + SisiB + SisiC;                         // proses

    printf("\n");
    printf("Luas Segitiga Sembarang : %.lf\n", luas);         // Proses Rumus
    printf("Keliling segitiga sembarang : %.lf\n", keliling); // Proses Rumus
}

// Deklrasi prosedur Belah Ketupat
void Luas_Keliling_BelahKetupat(double Diagonal1, double Diagonal2, double sisi)
{
    double luas = (Diagonal1 * Diagonal2) / 2;
    double keliling = 4 * sisi;

    printf("\n");
    printf("Luas Belah Ketupat : %.lf\n", luas);         // Proses
    printf("Keliling Belah Ketupat : %.lf\n", keliling); // Proses
}
// Deklarasi Prosedur Jajargenjang
void hitungLuasDanKelilingJajarGenjang(double alas, double tinggi, double sisi)
{
    double luas, keliling;

    luas = alas * tinggi;
    keliling = 2 * (alas + sisi);

    printf("Luas jajar genjang: %.2lf\n", luas);
    printf("Keliling jajar genjang: %.2lf\n", keliling);
}

// Deklrasi Prosedur Trapesium
void hitungLuasDanKelilingTrapesium(double alas1, double alas2, double tinggiT, double sisi1, double sisi2)
{
    double luas, keliling;

    luas = 0.5 * (alas1 + alas2) * tinggiT;
    keliling = sisi1 + sisi2 + alas1 + alas2;

    printf("Luas Trapesium: %.2lf\n", luas);
    printf("Keliling Trapesium: %.2lf\n", keliling);
}

// Declare Circle Procedure
void calculateAreaAndCircumferenceOfCircle(double radius, double *area, double *circumference)
{
    const double PI = 3.14159265359;
    *area = PI * pow(radius, 2);
    *circumference = 2 * PI * radius;
}

int main()
{
    int program;                                            // "Int" untuk memilih operator dalam switch
    double SisiA, SisiB, SisiC, Diagonal1, Diagonal2, sisi; // Punya SegitigaSembarang dan Belah Ketupat
    double alas1, alas2, tinggiT, sisi1, sisi2;             // Punya Trapesium
    double radius, areaOfCircle, circumferenceOfCircle;     // Circle's
    double alasJ, tinggiJ, sisiJ;                           // Punya Jajargenjang

    // Input Operator
    printf("\n");
    printf("\t\t\t\tProgram Menghitung Luas dan Keliling Bangun Datar\n");
    printf("Pilih Program (1-5) : \n");
    printf("\n 1. Segitiga Sembarang\n 2. Belah Ketupat\n 3. Jajargenjang\n 4. Trapesium\n 5. Lingkaran\n");
    printf("\n\nPilihan mu: ");
    program = validasi_angka(1, 5);

    switch (program) // Memilih operator dalam list
    {
    case 1: // Segitiga Sembarang //Punya Nata
        printf("Input sisi A: ");
        SisiA = validasiDouble(0);
        printf("Input sisi B: ");
        SisiB = validasiDouble(0);
        printf("Input sisi C: ");
        SisiC = validasiDouble(0);

        Luas_Keliling_SegitigaSembarang(SisiA, SisiB, SisiC); // memanggil prosedur
        break;

    case 2: // Belah Ketupat // Punya Nata
        printf("Input Panjang Diagonal 1: ");
        Diagonal1 = validasiDouble(0);
        printf("Input Panjang Diagonal 2: ");
        Diagonal2 = validasiDouble(0);
        printf("Input Panjang Sisi: ");
        sisi = validasiDouble(0);

        Luas_Keliling_BelahKetupat(Diagonal1, Diagonal2, sisi); // memanggil prosedur
        break;

    case 3: // Jajargenjang //Punya Dea
        printf("Masukkan panjang alas: ");
        alasJ = validasiDouble(0);
        printf("Masukkan tinggi: ");
        tinggiJ = validasiDouble(0);
        printf("Masukkan panjang sisi: ");
        sisiJ = validasiDouble(0);

        // Memanggil prosedur untuk menghitung luas dan keliling jajar genjang
        hitungLuasDanKelilingJajarGenjang(alasJ, tinggiJ, sisiJ);
        break;

    case 4: // Trapesium //Punya Gusde
        printf("Masukkan panjang alas atas trapesium: ");
        alas1 = validasiDouble(0);

        printf("Masukkan panjang alas bawah trapesium: ");
        alas2 = validasiDouble(0);

        printf("Masukkan tinggi trapesium: ");
        tinggiT = validasiDouble(0);

        printf("Masukkan panjang sisi sejajar trapesium (sisi1): ");
        sisi1 = validasiDouble(0);

        printf("Masukkan panjang sisi sejajar trapesium (sisi2): ");
        sisi2 = validasiDouble(0);

        // Memanggil prosedur untuk menghitung luas dan keliling trapesium
        hitungLuasDanKelilingTrapesium(alas1, alas2, tinggiT, sisi1, sisi2);
        break;

    case 5: // Circle // Dea's
        printf("Enter The Radius of Circle: ");
        radius = validasiDouble(0);

        // Calls procedures to calculate area and circumference of circle
        calculateAreaAndCircumferenceOfCircle(radius, &areaOfCircle, &circumferenceOfCircle);

        printf("Area Of Circle: %lf\n", areaOfCircle);
        printf("Circumference of Circle: %lf\n", circumferenceOfCircle);
        break;

    default: // Validasi
        printf("Pilihan tidak ada dalam list, silahkan restart");
        break;
    }
    return 0;
}
