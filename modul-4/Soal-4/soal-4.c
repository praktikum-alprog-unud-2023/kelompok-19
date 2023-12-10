#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct mahasiswa{
	char no_indukm[255];
	char nama[255];
}mahasiswa;

void identity();
void menambahkan();
void mencari();
char keluar();
char validasi(char *masukan);
char validasi_isi(char *masukan);
char validasi_no_indukm(char *masukan);
char valid_nim();
int periksa_pil1();
int periksa_pil2();


char no_indukm[255],nama[255];


void identity(){
}


int periksa_pil1(){
    int input;
    while(1){
        input=valid_input();
        if(input>=1 && input<=3){
            return input;
        }
        printf("\t\t\t\t===================================\n");
        printf("\t\t\t\tInput tidak valid, mohon ulangi : ");
    }
}


int periksa_pil2(){
    int input;
    while(1){
        input=valid_input();
        if(input>=1 && input<=2){
            return input;
        }
        printf("\t\t\t===================================\n");
        printf("\t\t\tInput tidak valid, mohon ulangi : ");
    }
}


char keluar(){
    char masukan[100];
    while(1){
        int i=0;
        int salah;
        scanf("%[^\n]",&masukan);
        fflush(stdin);
        if(masukan [i+1] =='\0'){
            if(masukan[0]=='y'  || masukan[0]=='Y' && masukan[1]=='\0'){
                return masukan[0];
            }else if (masukan[0]=='n'  || masukan [0]=='N' && masukan[1]=='\0'){
                return masukan[0];
            }else{
                salah=1;
            }
        }
        salah=1;
        if(salah==1){
            printf("\t\t\t===================================\n");
            printf("\t\t\tInput tidak valid, mohon ulangi : ");

        }
    }
}


char validasi_isi(char *masukan){
    int i,salah;
    i=0;
    salah=0;
    scanf("%[^\n]", masukan);
    fflush(stdin);
    while(masukan[i] != '\0'){
        if(masukan[i] == '.'){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i] == ' '){
            if(masukan[0]==' '|| masukan[i+1]=='\0'|| masukan[0]=='\0'){
                salah = 1;
                masukan[i] = '\0';
            }else{
                i++;
            }
        }else if(masukan[i]>='a' && masukan[i]<='z' || masukan[i] >= 'A' && masukan[0] <= 'Z'){
            if(masukan[i]>='a' && masukan[i]<='z'|| masukan[i]>='A' && masukan[i]<='Z'){
                i++;
            }else{
                salah=1;
                masukan[i]='\0';
            }
        }else if(masukan[i]>='0'&& masukan[i]<='9'){
            salah=1;
            masukan[i]='\0';
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }if(masukan[0]=='\0'){
        salah=1;
        masukan[i]='\0';
    }if(salah == 1){
        printf("\t\t\t===================================\n");
        printf("\t\t\tInput tidak valid, mohon ulangi : ");
        return 0;
    }else{
        return masukan;
    }
}


char validasi(char *masukan){
    while(1){
        if(validasi_isi(masukan)){
            fflush(stdin);
            return masukan;
        }
    }
}


char validasi_no_indukm(char *no_indukms){

    while(1){
        if(valid_nim(no_indukms)){
            fflush(stdin);
            return no_indukms;
        }
    }
}


char valid_nim(char *masukan){
    int i,salah;
    i=0;
    salah=0;
    scanf("%[^\n]", masukan);
    fflush(stdin);
    while(masukan[i] != '\0'){
        if(masukan[i] == '.'){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i] == ' '){
            if(masukan[0]==' '|| masukan[i+1]=='\0'){
                salah = 1;
                masukan[i] = '\0';
            }else{
                i++;
            }
        }else if(masukan[i]>='0' && masukan[i]<='9'){
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }if(masukan[0]=='\0'){
        salah=1;
        masukan[i]='\0';
    }if(salah == 1){
        printf("\t\t\t===================================\n");
        printf("\t\t\tInput tidak valid, mohon ulangi : ");
        return 0;
    }else{
        return masukan;
    }
}


int valid_input(){
    char masukan[100];
    int i = 0;
    int belakang = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int titik = 0;
    int salah = 0;
    int minus = 0;
    int hasil;

    scanf("%[^\n]", &masukan);
    fflush(stdin);
    while(masukan[i] != '\0'){
        if(masukan[i] == '.'){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i] == ' '){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i]>='0' && masukan[i]<='9' ||  masukan[0] == '-'){
            if(masukan[i] == '-'){
                minus=minus + 1;
                if(minus >1 || masukan[i+1]=='\0'){
                    salah=1;
                    masukan[i]='\0';
                }
            }else if(masukan[i]>='0' && masukan[i]<='9'){
                if(masukan[0]=='0'){
                    salah=1;
                    masukan[i]='\0';
                }else{
                    isi_depan = (isi_depan * 10) + (masukan[i] - 48);
                }
            }else{
                salah=1;
                masukan[i]='\0';
            }
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }

    }
    if(masukan[0]=='\0'){
        salah=1;
    }
    hasil = isi_depan;
    if(minus == 1){
        hasil = hasil - (hasil * 2);
    }
    if(salah == 1){
        printf("\t\t\t===================================\n");
        printf("\t\t\tInput tidak valid, mohon ulangi : ");
    }else{
        return hasil;
    }
return valid_input();
}


void menambahkan(){
    int cek,pilih,d;
    char no_indukm[10];
    FILE *cekdata;
    FILE * input;
    do{
        fflush(stdin);
        system("cls");
        printf("\t\t\tInput NIM dan Nama Mahasiswa\n\n");
        printf("\t\t\tInput Nomor Induk Mahasiswa : ");
        validasi_no_indukm(&mahasiswa.no_indukm);

        fflush(stdin);
        printf("\t\t\tInput Nama Mahasiswa : ");
        validasi(&mahasiswa.nama);

        cek=0;
        fflush(stdin);
        cekdata = fopen("sim.txt","r");
        if(cekdata == NULL){
            printf("\t\t\tFile txt Tidak Tersedia\n");
        }else{
            while(!feof(cekdata)){
                fscanf(cekdata,"%s\n#%s#\n",&no_indukm,&nama);
                if(strcmp(mahasiswa.no_indukm,no_indukm)==0){
                    fflush(stdin);
                    printf("\t\t\tNIM yang di-input Sudah Tersedia di dalam File txt!\n");
                    cek=1;
                }
            }
            fclose(cekdata);
        }
        fflush(stdin);
        if(cek !=1){
            input=fopen("sim.txt","a");
            fprintf(input,"%s\n#%s#\n",mahasiswa.no_indukm,mahasiswa.nama);
            fclose(input);
            cek=4;
        }
        if(cek==4){
            printf("\n\n\t\t\tSukses menambahkan data\n");
        }
        printf("\n\t\t\t 1 Untuk mengulang menambahkan data\n");
        printf("\t\t\t 2 Untuk keluar dari menu input data\n\n");
        printf("\t\t\t Apakah kamu ingin mengulang atau keluar? : ");
        pilih=periksa_pil2();
        }while(pilih==1);
}


void mencari(){
    char no_indukm[10];
    int pilih;
    int a,cek;
    do{
        fflush(stdin);
        system("cls");
        printf("\t\t\tInput Nomor Induk Mahasiswa (NIM)");
        cek=0;
        fflush(stdin);
        printf("\n\n\t\t\tMasukan NIM Anda :");
        validasi_no_indukm(&no_indukm);

        FILE *cekdata;

        cekdata=fopen("sim.txt","r");

        if(cekdata==NULL){
            printf("file txt tidak ada!");
        }else{
            while(!feof(cekdata)){
                fscanf(cekdata,"%s\n# %[^#] #\n",&mahasiswa.no_indukm,&mahasiswa.nama);
                if(strcmp(mahasiswa.no_indukm,no_indukm)==0){
                    fflush(stdin);
                    printf("\n\n\t\t\t Data Mahasiswa      \n\n");
                    printf("\t\t\t Nomor Induk Mahasiswa  : %s",mahasiswa.no_indukm);
                    printf("\n");
                    printf("\t\t\t Nama Mahasiswa: %s",mahasiswa.nama);
                    printf("\n\n");
                    cek=1;
                }
            }
            fclose(cekdata);
        }
        if(cek !=1){
            printf("\n\n\t\t\t Tidak dapat menemukan Nomor Induk Mahasiswa yang telah di-input\n\n");
        }
        printf("\t\t\t 1 Untuk mengulang mencari data\n");
        printf("\t\t\t 2 Untuk keluar dari menu input data\n\n");
        printf("\t\t\t Apakah kamu ingin mengulang atau keluar? : ");
        pilih=periksa_pil2();
    }while(pilih==1);
}


int main(){
    char cek;
    int pilih;
    identity();
    do{
        fflush(stdin);
        system("cls");
        printf("\t\t\t\t==============================================================================\n");
		printf("\t\t\t\t||                         Sistem Informasi Mahasiswa                       ||\n");
		printf("\t\t\t\t||                                           	                            ||\n");
		printf("\t\t\t\t||          1. Menambahkan  Data                                            ||\n");
		printf("\t\t\t\t||          2. Mencari Data                                                 ||\n");
		printf("\t\t\t\t||          3. Keluar                         	                            ||\n");
		printf("\t\t\t\t||                                           	                            ||\n");
		printf("\t\t\t\t==============================================================================\n\n");
		printf("\t\t\tInput pilihan : ");
        pilih=periksa_pil1();
        fflush(stdin);
        if(pilih==1){
            menambahkan();
            system("cls");
        }else if(pilih==2){
            mencari();
            system("cls");
        }else{
            printf("\t\t\t=====================================================\n");
            printf("\t\t\t     Terima kasih telah menggunakan program ini.    \n");
            printf("\t\t\t=====================================================");
            return 0;
        }
        printf("\n\t\t\t Y untuk mengulang program\n");
        printf("\t\t\t N untuk keluar dari program\n\n");
        printf("\t\t\t Apakah kamu ingin mengulang? : ");
        cek=keluar();
        }while(cek=='y'|| cek=='Y');
        printf("\t\t\t=====================================================\n");
        printf("\t\t\t     Terima kasih telah menggunakan program ini.    \n");
        printf("\t\t\t=====================================================");
return 0;
}
