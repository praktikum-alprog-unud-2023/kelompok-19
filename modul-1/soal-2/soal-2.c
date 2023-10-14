#include<stdio.h>
#include<math.h>

//Deklarasi
void Luas_Keliling_SegitigaSembarang(double SisiA,double SisiB,double SisiC)
{
double s = (SisiA+SisiB+SisiC)/2; //menghitung setengah keliling
double luas = sqrt(s*(s-SisiA)*(s-SisiB)*(s-SisiC)); // proses rumus heron
double keliling = SisiA + SisiB + SisiC; //proses


printf("\n");
printf("Luas Segitiga Sembarang : %.lf\n", luas); // Proses Rumus
printf("Keliling segitiga sembarang : %.lf\n", keliling); // Proses Rumus
}

void Luas_Keliling_BelahKetupat(double Diagonal1, double Diagonal2, double sisi)
{
double luas = (Diagonal1*Diagonal2)/2;
double keliling = 4 * sisi;

printf("\n");
printf("Luas Belah Ketupat : %.lf\n",luas); //Proses
printf("Keliling Belah Ketupat : %.lf\n", keliling); //Proses
}

// Deklarasi prosedur untuk menghitung luas dan keliling trapesium
void hitungLuasKeliling(float alas, float atas, float tinggi, float *luas, float *keliling) {
*luas = 0.5 * (alas + atas) * tinggi;
*keliling = alas + atas + 2 * tinggi;
}

// Fungsi untuk memvalidasi input (Fungsi untuk trapesium)
int isValidNumber(char *input) {
for (int i = 0; input[i] != '\0'; i++) {
if (!isdigit(input[i]) && input[i] != '.') {
return 0;
}
}
return 1;
}

// Prosedur untuk menghitung luas dan keliling lingkaran
void hitungLuasDanKelilingLingkaran(double radius, double *luas, double *keliling) 
{
    const double PI = 3.14159265359;
    *luas = PI * pow(radius, 2);
    *keliling = 2 * PI * radius;
}

// Struktur Penyimpanan (Untuk Scruct)
struct Tabung
{
double JariJari;
double tinggi;
};

int main()
{
int Program; // "Int" untuk memilih operator dalam switch
float alas, atas, tinggi, luas, keliling; //punya trapesium
double SisiA, SisiB, SisiC, Diagonal1, Diagonal2, sisi, bilangan1, bilangan2,radius, luaslingkaran, kelilinglingkaran;

// Input Operator
printf ("\n");
printf ("Pilih Program (1-7) : \n");
printf ("Pilih:\n\n 1. Segitiga Sembarang\n 2. Belah Ketupat\n");
printf("\n\nPilihan mu: ");
scanf("%d", &Program);

switch (Program) // Memilih operator dalam list
{
case 1 : //Segitiga Sembarang
printf("Input sisi A: ");
scanf("%lf", &SisiA);
printf("Input sisi B: ");
scanf("%lf", &SisiB);
printf("Input sisi C: ");
scanf("%lf", &SisiC);

Luas_Keliling_SegitigaSembarang(SisiA, SisiB, SisiC); //memanggil prosedur
break;
case 2 : //Belah Ketupat
printf("Input Panjang Diagonal 1: ");
scanf("%lf", &Diagonal1);
printf("Input Panjang Diagonal 2: ");
scanf("%lf", &Diagonal2);
printf("Input Panjang Sisi: ");
scanf("%lf", &sisi);

Luas_Keliling_BelahKetupat(Diagonal1,Diagonal2,sisi); //memanggil prosedur
break;

default : //Validasi
printf ("Pilihan tidak ada dalam list, silahkan restart");
break;
}
return 0;
}
