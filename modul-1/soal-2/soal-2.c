#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

//Deklarasi prosedur Segitiga Sembarang
void Luas_Keliling_SegitigaSembarang(double SisiA,double SisiB,double SisiC)
{
double s = (SisiA+SisiB+SisiC)/2; //menghitung setengah keliling
double luas = sqrt(s*(s-SisiA)*(s-SisiB)*(s-SisiC)); // proses rumus heron
double keliling = SisiA + SisiB + SisiC; //proses


printf("\n");
printf("Luas Segitiga Sembarang : %.lf\n", luas); // Proses Rumus
printf("Keliling segitiga sembarang : %.lf\n", keliling); // Proses Rumus
}

//Deklrasi prosedur Belah Ketupat
void Luas_Keliling_BelahKetupat(double Diagonal1, double Diagonal2, double sisi)
{
double luas = (Diagonal1*Diagonal2)/2;
double keliling = 4 * sisi;

printf("\n");
printf("Luas Belah Ketupat : %.lf\n",luas); //Proses
printf("Keliling Belah Ketupat : %.lf\n", keliling); //Proses
}
//Deklarasi Prosedur Jajargenjang
void hitungLuasDanKelilingJajarGenjang(double alas, double tinggi, double sisi) 
{
double luas, keliling;

luas = alas * tinggi;
keliling = 2 * (alas + sisi);

printf("Luas jajar genjang: %.2lf\n", luas);
printf("Keliling jajar genjang: %.2lf\n", keliling);
}

//Deklrasi Prosedur Trapesium
void hitungLuasKeliling(float alas, float atas, float tinggi, float *luas, float *keliling) {
*luas = 0.5 * (alas + atas) * tinggi;
*keliling = alas + atas + 2 * tinggi;
}

// Fungsi untuk memvalidasi input Trapesium
int isValidNumber(char *input) {
for (int i = 0; input[i] != '\0'; i++) {
if (!isdigit(input[i]) && input[i] != '.') {
return 0;
}
}
return 1;
}
//Deklarasi Prosedur Lingkaran
void hitungLuasDanKelilingLingkaran(double radius, double *luas, double *keliling) 
{
    const double PI = 3.14159265359;
    *luas = PI * pow(radius, 2);
    *keliling = 2 * PI * radius;
}

int main()
{
int Program; // "Int" untuk memilih operator dalam switch
double SisiA, SisiB, SisiC, Diagonal1, Diagonal2, sisi; // Punya SegitigaSembarang dan Belah Ketupat
char buffer[100]; //Punya Trapesium
float alas, atas, tinggi, luas, keliling; // Punya Trapesium
double radius, luaslingkaran, kelilinglingkaran; //Punya Lingkaran
double alasJ, tinggiJ, sisiJ;

// Input Operator
printf ("\n");
printf ("\t\t\t\tProgram Menghitung Luas dan Keliling Bangun Datar\n");
printf ("Pilih Program (1-5) : \n");
printf ("\n 1. Segitiga Sembarang\n 2. Belah Ketupat\n 3. Jajargenjang\n 4. Trapesium\n 5. Lingkaran\n");
printf("\n\nPilihan mu: ");
scanf("%d", &Program);

switch (Program) // Memilih operator dalam list
{
case 1 : //Segitiga Sembarang //Punya Nata
printf("Input sisi A: ");
scanf("%lf", &SisiA);
printf("Input sisi B: ");
scanf("%lf", &SisiB);
printf("Input sisi C: ");
scanf("%lf", &SisiC);

Luas_Keliling_SegitigaSembarang(SisiA, SisiB, SisiC); //memanggil prosedur
break;

case 2 : //Belah Ketupat // Punya Nata
printf("Input Panjang Diagonal 1: ");
scanf("%lf", &Diagonal1);
printf("Input Panjang Diagonal 2: ");
scanf("%lf", &Diagonal2);
printf("Input Panjang Sisi: ");
scanf("%lf", &sisi);

Luas_Keliling_BelahKetupat(Diagonal1,Diagonal2,sisi); //memanggil prosedur
break;

case 3 : //Jajargenjang //Punya Dea
printf("Masukkan panjang alas: ");
scanf("%lf", &alasJ);
printf("Masukkan tinggi: ");
scanf("%lf", &tinggiJ);
printf("Masukkan panjang sisi: ");
scanf("%lf", &sisiJ);

// Memanggil prosedur untuk menghitung luas dan keliling jajar genjang
hitungLuasDanKelilingJajarGenjang(alasJ, tinggiJ, sisiJ);
break;

case 4 : //Trapesium //Punya Gusde
do {
printf("Masukkan panjang alas trapesium: ");
scanf("%s", buffer);
if (isValidNumber(buffer)) {
alas = atof(buffer);
if (alas <= 0) {
printf("Panjang alas harus positif. Silakan masukkan nilai positif.\n");
continue;
}
} else {
printf("Masukkan tidak valid. Harus berupa angka positif.\n");
continue;
}
break;
} while (1);

do {
printf("Masukkan panjang atas trapesium: ");
scanf("%s", buffer);
if (isValidNumber(buffer)) {
atas = atof(buffer);
if (atas <= 0) {
printf("Panjang atas harus positif. Silakan masukkan nilai positif.\n");
continue;
}
} else {
printf("Masukkan tidak valid. Harus berupa angka positif.\n");
continue;
}
break;
} while (1);

do {
printf("Masukkan tinggi trapesium: ");
scanf("%s", buffer);
if (isValidNumber(buffer)) {
tinggi = atof(buffer);
if (tinggi <= 0) {
printf("Tinggi harus positif. Silakan masukkan nilai positif.\n");
continue;
}
} else {
printf("Masukkan tidak valid. Harus berupa angka positif.\n");
continue;
}
break;
} while (1);

// Memanggil prosedur untuk menghitung luas dan keliling
hitungLuasKeliling(alas, atas, tinggi, &luas, &keliling);

// Menampilkan hasil perhitungan
printf("Luas trapesium: %.2f\n", luas);
printf("Keliling trapesium: %.2f\n", keliling);
break;

case 5 : //Lingkaran //Punya Dea
printf("Masukkan jari-jari lingkaran: ");
scanf("%lf", &radius);

// Memanggil prosedur untuk menghitung luas dan keliling
hitungLuasDanKelilingLingkaran(radius, &luaslingkaran, &kelilinglingkaran);

printf("Luas lingkaran: %lf\n", luaslingkaran);
printf("Keliling lingkaran: %lf\n", kelilinglingkaran);
break; 

default : //Validasi
printf ("Pilihan tidak ada dalam list, silahkan restart");
break;
}
return 0;
}
