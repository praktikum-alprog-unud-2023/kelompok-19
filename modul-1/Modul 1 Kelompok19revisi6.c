#include<stdio.h>
#include<math.h>
#include<ctype.h>

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

// Fungsi menghitung Volume Tabung
double VolumeTabung (struct Tabung t)
{
return M_PI * pow(t.JariJari, 2)* t.tinggi;
}

//Fungsi menghitung Luas Permukaan Tabung
double LuasPermukaanTabung (struct Tabung t)
{
double luasAlas = 2 * M_PI * pow(t.JariJari, 2);
double luasSelimut = 2* M_PI * t.JariJari * t.tinggi;
return luasAlas + luasSelimut ;
}

struct bola 
{
double JariJari;
};

double VolumeBola(struct bola b) 
{
return (4 * M_PI * pow(b.JariJari, 3)) / 3;
}

double LuasPermukaanBola(struct bola b) 
{
return 4 * M_PI * pow(b.JariJari, 2);
}

int main()
{
int Program; // "Int" untuk memilih operator dalam switch
char operator; // punya kalukulator
struct Tabung Tabung;
struct bola bola;
char buffer[100];
float alas, atas, tinggi, luas, keliling; //punya trapesium

double SisiA, SisiB, SisiC, Diagonal1, Diagonal2, sisi, bilangan1, bilangan2,radius, luaslingkaran, kelilinglingkaran;

// Input Operator
printf ("\n");
printf ("Pilih Program (1-7) : \n");
printf ("Pilih:\n\n 1. Segitiga Sembarang\n 2. Belah Ketupat\n 3. Tabung\n 4. Bola\n 5. Kalkulator\n 6. Trapesium\n 7. Lingkaran\n");
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

case 3 : // Tabung (Tester)
printf("Masukan Jari_Jari Tabung: ");
scanf("%lf", &Tabung.JariJari);
printf("Masukan Tinggi Tabung: ");
scanf("%lf", &Tabung.tinggi);

//menghitung volume dan luas permukaan tabung
double volume = VolumeTabung(Tabung);
double luasPermukaan = LuasPermukaanTabung(Tabung);

//menampilkan hasil
printf ("Volume Tabung : %lf\n" , volume);
printf ("Luas Permukaan Tabung : %lf\n", luasPermukaan);
break;

case 4 : // Bola

printf("Masukkan nilai jari-jari: ");
scanf("%lf", &bola.JariJari);

double volumebola = VolumeBola(bola);
double luas = LuasPermukaanBola(bola);

printf("Volume bola= %.2lf\n", volumebola);
printf("Luas permukaan bola= %.2lf\n", luas);

break;

case 5 : // Kalkulator
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

break;
case 6 : //Trapesium
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

case 7 : //Lingkaran

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