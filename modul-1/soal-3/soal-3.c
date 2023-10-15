#include<stdio.h>
#include<math.h>

// Struktur Penyimpanan
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

struct kerucut 
{
float radius;
float tinggi;
float sisiMiring;
};

float hitungVolume(struct kerucut kerucut) {
return (1 * M_PI * pow(kerucut.radius, 2) * kerucut.tinggi) / 3;
}

float hitungLuasPermukaan(struct kerucut kerucut) {
return M_PI * kerucut.radius * (kerucut.radius + kerucut.sisiMiring);
}

int main()
{
int Program;
struct Tabung Tabung;
struct bola bola;
struct kerucut kerucut;
// Input Operator
printf ("\n");
printf ("\t\t\t\tProgram Menghitung Volume dan luas permukaan bangun ruang\n");
printf ("Pilih Program (1-5) : \n");
printf ("\n 1. Tabung\n 2. Bola\n 3. limas Segiempat\n 4. Prisma Segitiga\n 5. Kerucut\n");
printf("\n\nPilihan mu: ");
scanf("%d", &Program);

switch (Program) // Memilih operator dalam list
{
case 1 : //Tabung //Punya Linda
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

case 2 : //Bola //Punya Dewaayu
printf("Masukkan nilai jari-jari: ");
scanf("%lf", &bola.JariJari);

double volumebola = VolumeBola(bola);
double luas = LuasPermukaanBola(bola);

printf("Volume bola= %.2lf\n", volumebola);
printf("Luas permukaan bola= %.2lf\n", luas);
break;

case 3 : //limasSegiempat //Punya Alit

break;

case 4 : //prismaSegitiga //Punya Alit

break;

case 5 : //Kerucut //Punya Dewaayu
printf("Masukkan nilai jari-jari: ");
scanf("%f", &kerucut.radius);
printf("Masukkan nilai tinggi: ");
scanf("%f", &kerucut.tinggi);
printf("Masukkan nilai sisi miring: ");
scanf("%f", &kerucut.sisiMiring);

float volumeKerucut = hitungVolume(kerucut);
printf("Volume kerucut= %.2f\n", volumeKerucut);

float luasKerucut = hitungLuasPermukaan(kerucut);
printf("Luas permukaan kerucut= %.2f\n", volumeKerucut);

break;

default : //Validasi
printf ("Pilihan tidak ada dalam list, silahkan restart");
break;
}
return 0;
}
