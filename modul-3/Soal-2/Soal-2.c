#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAKS 100

void hitung_perkalian();
void hitung_penjumlahan();
void hitung_tranpose();
void matriks_perkalian();
void matriks_penjumlahan();
int matriks1[MAKS][MAKS], matriks2[MAKS][MAKS];
int bil, i,j, baris1, kolom1, baris2, kolom2, isiMatriks2=0, isiOrdo=0;

int cek_input(int *jml){
char buff[1024];
char term;
if(fgets(buff, sizeof(buff), stdin) != NULL && sscanf(buff, "%d %c", jml, &term) == 1){
        if(isiOrdo==1){
            if(isiMatriks2==1){
                if(kolom1 != *jml){
                    printf("\n\n!!Jumlah Baris Matriks Ke-2 TIDAK BOLEH BERBEDA dengan Jumlah Kolom Matriks Ke-1!!\n");
                    printf("Mohon masukkan kembali JUMLAH BARIS dengan benar>> ");
                    printf("\n\n[Baris] >> ");
                    return 0;
                }
                else if(*jml<1){
                    printf("\n\n Ordo yang kamu inputkan TIDAK SESUAI >:(\n");
                    printf("Mohon masukkan kembali ORDO dengan benar: ");
                    return 0;
                }
                }
        }
        return 1;
}
printf("\n\nInput kamu salah >:(\n");
printf("Masukkan inputan dalam bentuk angka: ");
return 0;
}
void validasi_baca(int *var, char *prompt){
while(1){
printf(prompt);
if(cek_input(var))
break;
}
}
void range_Validasi_Int(int *var, int range1, int range2, char *nama){
    while(1){
        validasi_baca(var, nama);
        fflush(stdin);
        if(*var >= range1  &&*var <= range2)
        break;
        printf("\n\nInput kamu salah >:(\n");
        printf("!!Pilihlah Nomor yang Tersedia!!\n");
    }
}
void range_Validasi_Int_Baca(int *var, int range1, int range2, char *nama){
    while(1){
        validasi_baca(var, nama);
        fflush(stdin);
        if(*var == range1 || *var == range2)
        break;
        printf("Input kamu salah >:(\n");
        printf("!!Pilihlah Nomor yang Tersedia!!\n");
    }
}
void matriks_perkalian (void){
    isiOrdo=1;
    printf("Masukkan ORDO Matriks Ke-1: \n");
    printf("[Baris] >> ");
    validasi_baca(&baris1, "");
    printf("[Kolom] >> ");
    validasi_baca(&kolom1, "");
    isiOrdo=0;
    printf("Masukkan ELEMEN pada Matriks Ke-1: \n");
    for (i=0;i<baris1;i++){
        for (j=0;j<kolom1;j++){
            printf("Matriks [%d][%d] :",i,j);
            validasi_baca(&matriks1[i][j],"");
        }
    }
    printf("\n======================================\n\n");
    isiOrdo=1;
    printf("Masukkan ORDO Matriks Ke-2: \n");
    isiMatriks2=1;
    printf("[Baris] >> ");
    validasi_baca(&baris2, "");
    isiMatriks2=0;
    printf("[Kolom] >> ");
    validasi_baca(&kolom2, "");
    isiOrdo=0;
    printf("Masukkan ELEMEN pada Matriks Ke-2: \n");
    for (i=0;i<baris2;i++){
        for (j=0;j<kolom2;j++){
            printf("Matriks [%d][%d] : ",i,j);
            validasi_baca(&matriks2[i][j],"");
        }
    }
}
void hitung_perkalian (int baris1,int kolom1, int baris2, int kolom2, int matriks_1[MAKS][MAKS] , int matriks_2[MAKS][MAKS]){
    int i, j, k, matriks_3[MAKS][MAKS];
    system("cls");
    printf("=======================================\n");
    printf(">>         PERKALIAN MATRIKS         <<\n");
    printf("=======================================\n\n");
    printf("          ~ Matriks Pertama ~          \n");
    for(i=0 ; i<baris1 ; i++){
            for(j=0 ; j<kolom1 ; j++){
                printf("%d", matriks1[i][j]);
                if(j==(kolom1-1)) printf("\n");
                else printf(" ");
            }
    }
    printf("           ~ Matriks Kedua ~           \n");
    for(i=0 ; i<baris2 ; i++){
        for(j=0 ; j<kolom2 ; j++){
            printf("%d", matriks2[i][j]);
            if(j==(kolom2-1)) printf("\n");
            else printf(" ");
        }
    }
    printf("    ~ Hasil PERKALIAN Kedua Matriks ~    \n");
    for (i=0;i<baris1;i++){
        for (j=0;j<kolom2;j++){
            matriks_3[i][j] = 0;
            for (k=0;k<baris2;k++){
                matriks_3[i][j] =matriks_3[i][j]+(matriks_1[i][k] * matriks_2[k][j]);
            }
            printf("%d", matriks_3[i][j]);
            if (j == (kolom2-1)) printf("\n");
            else printf(" ");
        }
    }
}
void matriks_penjumlahan (void){
    isiOrdo=1;
    printf("Masukkan ORDO Matriks Ke-1: \n");
    printf("[Baris] >> ");
    validasi_baca(&baris1, "");
    printf("[Kolom] >> ");
    validasi_baca(&kolom1, "");
    isiOrdo=0;
    printf("Masukkan ELEMEN pada Matriks Ke-1: \n");
    for (i=0;i<baris1;i++){
            for (j=0;j<kolom1;j++){
            printf("Matriks [%d][%d] :",i,j);
            validasi_baca(&matriks1[i][j],"");
            }
    }
    printf(" \n===================================\n\n");
    isiOrdo=1;
    printf("Masukkan ORDO Matriks Ke-2: \n");
    printf("[Baris] >> ");
    validasi_baca(&baris2, "");
    printf("[Kolom] >> ");
    validasi_baca(&kolom2, "");
    printf("Masukkan ELEMEN pada Matriks Ke-2: \n");
    isiOrdo=0;
    for (i=0;i<baris2;i++){
        for (j=0;j<kolom2;j++){
            printf("Matriks [%d][%d] : ",i,j);
            validasi_baca(&matriks2[i][j],"");
        }
    }
}
void hitung_penjumlahan(int barisa, int koloma, int barisb, int kolomb, int matriks_1[MAKS][MAKS], int matriks_2[MAKS][MAKS]){
    int matriks_3[MAKS][MAKS], i, j, barisx, kolomx;
    if(barisa>barisb){
            barisx=barisa;
    }else{
            barisx=barisb;
    }
    if(koloma>kolomb){
        kolomx=koloma;
    }else{
        kolomx=kolomb;
    }
    system("cls");
    printf("=======================================\n");
    printf(">>        PENJUMLAHAN MATRIKS        <<\n");
    printf("=======================================\n\n");
    printf("          ~ Matriks Pertama ~          \n");
    for(i=0 ; i<baris1 ; i++){
        for(j=0 ; j<kolom1 ; j++){
            printf("%d", matriks1[i][j]);
            if(j==(kolom1-1)) printf("\n");
            else printf(" ");
        }
    }
    printf("           ~ Matriks Kedua ~           \n");
    for(i=0 ; i<baris2 ; i++){
        for(j=0 ; j<kolom2 ; j++){
        printf("%d", matriks2[i][j]);
        if(j==(kolom2-1)) printf("\n");
        else printf(" ");
        }
    }
    printf("   ~ Hasil PENJUMLAHAN Kedua Matriks ~   \n");
    for(i=0 ; i<barisx ; i++){
        for(j=0 ; j<kolomx ; j++){
            matriks_3[i][j]=matriks_1[i][j]+matriks_2[i][j];
            printf("%d", matriks_3[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
void hitung_tranpose(){
    int i, j, baris, kolom;
    isiOrdo=1;
    printf("Masukkan ORDO Matriks: \n");
    printf("[Baris] >> ");
    validasi_baca(&baris, "");
    printf("[Kolom] >> ");
    validasi_baca(&kolom, "");
    isiOrdo=0;
    int matriks_1[baris][kolom], matriks_2[kolom][baris];
    printf("Masukkan ELEMEN Matriks: \n");
    for (i=0;i<baris;i++){
            for (j=0;j<kolom;j++){
                printf("Matriks [%d][%d] : ",i,j);
                validasi_baca(&matriks_1[i][j],"");
            }
    }
    for(i=0 ; i<baris ; i++){
        for (j=0; j<kolom ; j++){
        matriks_2[j][i]=matriks_1[i][j];
        }
    }
    system("cls");
    printf("=======================================\n");
    printf(">>         TRANSPOSE MATRIKS         <<\n");
    printf("=======================================\n\n");
    printf("     ~ Matriks SEBELUM Transpose ~     \n");
    for(i=0 ; i<baris ; i++){
        for(j=0 ; j<kolom ; j++){
        printf("%d", matriks_1[i][j]);
        printf(" ");
        }
    printf("\n");
    }
    printf("     ~ Matriks SESUDAH Transpose ~     \n");
    for(i=0 ; i<kolom ; i++){
        for(j=0 ; j<baris ; j++){
            printf("%d", matriks_2[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
void kelompok(){
	printf("\t\t\t\t================================================\n");
	printf("\t\t\t\t|                                              |\n");
	printf("\t\t\t\t|       This Project Presented by Group 19     |\n");
	printf("\t\t\t\t|                                              |\n");
	printf("\t\t\t\t================================================\n");
	printf("\t\t\t\t|     Members:                                 |\n");
	printf("\t\t\t\t|     1. A. A. Ngurah Alit Suadnyana Wiratama  |\n");
	printf("\t\t\t\t|        2205551153                            |\n");
	printf("\t\t\t\t|     2. Ida Bagus Gede Zikye Artha Dwana      |\n");
	printf("\t\t\t\t|        2305551027                            |\n");
	printf("\t\t\t\t|     3. Putu Linda Suryantini                 |\n");
	printf("\t\t\t\t|        2305551039                            |\n");
	printf("\t\t\t\t|     4. Dewa Ayu Putri Paramita               |\n");
	printf("\t\t\t\t|        2305551060                            |\n");
	printf("\t\t\t\t|     5. Narto Frenlyn Aritonang               |\n");
	printf("\t\t\t\t|        2305551099                            |\n");
	printf("\t\t\t\t|     6. Putu Ayu Deanisa Alma Putri           |\n");
	printf("\t\t\t\t|        2305551108                            |\n");
	printf("\t\t\t\t|     7. Gede Yudhi Adinata Putra Kurniawan    |\n");
	printf("\t\t\t\t|        2305551142                            |\n");
	printf("\t\t\t\t================================================\n\n");
	system("pause");
	system("cls");
}
int main(){
    kelompok();
    int input, read;
	do{
		printf("\t\t\t====================================================================\n");
		printf("\t\t\t|                                                                  |\n");
		printf("\t\t\t|     Berikut adalah pilihan operasi matematika pada matriks:      |\n");
		printf("\t\t\t|                          1. Perkalian                            |\n");
		printf("\t\t\t|                          2. Penjumlahan                          |\n");
		printf("\t\t\t|                          3. Transpose                            |\n");
		printf("\t\t\t|                          0. Keluar                               |\n");
		printf("\t\t\t|                                                                  |\n");
		printf("\t\t\t====================================================================\n\n");
		range_Validasi_Int(&input, 0, 3, "\t\t\tMasukkan pilihan operasi yang ingin dilakukan: ");
		system("cls");
		switch(input){
		    case 1:
            system("cls");
            printf("=======================================\n");
            printf(">>         PERKALIAN MATRIKS         <<\n");
            printf("=======================================\n\n");
            matriks_perkalian();
            hitung_perkalian(baris1,kolom1,baris2,kolom2,matriks1,matriks2);
            break;
            case 2:
            system("cls");
            printf("=======================================\n");
            printf(">>        PENJUMLAHAN MATRIKS        <<\n");
            printf("=======================================\n\n");
            matriks_penjumlahan();
            hitung_penjumlahan(baris1,kolom1,baris2,kolom2,matriks1,matriks2);
            break;
            case 3:
            system("cls");
            printf("=======================================\n");
            printf(">>         TRANSPOSE MATRIKS         <<\n");
            printf("=======================================\n\n");
            hitung_tranpose();
            break;
            default:
            printf("        >>TERIMA KASIH<<        \n");
            printf("Telah Menggunakan Program Kami:)\n");
            }
            printf("\n\nApakah Anda Ingin Menggunakan Kembali Program Ini?\n");
            range_Validasi_Int_Baca(&read,0,9, "              (0 = tidak / 9 = iya):");
            system("cls");
	}while(read == 9);
system("pause");
return 0;
}
