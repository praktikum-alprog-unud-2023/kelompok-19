# PERBAIKAN

Yang pertama aku sangat apresiasi pada Gusde karena berhasil men-*develop* validasinya sendiri, tapi validasimu belum terlalu sempurna, masih banyak membuang-buang *line*. *But that's ok, I approved*.

Berikut adalah beberapa perbaikan yang perlu kalian lakukan:

## BEST PRACTICE

Gunakan *camel case* untuk membuat sebuah program dan gunakan bahasa Inggris di setiap variabel karena itu memudahkan kalian dalam memahami program tersebut.

Contoh:

```c

#include <stdio.h>
int integerValidate(int minimum); //menggunakan camel case
int main(){
    int number = integerValidate(0);
    printf("The number is %d", number); //gunakan bahasa Inggris
    return 0;
}

```

## PERULANGAN DO-WHILE

Ketika program sudah selesai, alias hasil dari volume dan luas permukaan keluar, kalian harus memberikan pilihan ke pengguna antara dia ingin menjalankan programnya kembali atau tidak dengan beberapa pilihan inputan. Seperti ini outpunya:

```terminal

Press "0" for exit, press "1" for continue.
>> 

```

Ketika pengguna memasukkan "1" maka dia akan kembali ke awal dan ketika pengguna memasukkan "0" maka dia akan keluar dari program alias program selesai. Gunakan variasi, bebas. Kalian bisa gunakan perulangan "while" atau "do-while" terserah yang mana menurut kalian nyaman.

## PROGRAM

Yang pertama rapikan program yang kalian buat, yang kedua ....

```c
hitungLuasDanKelilingLingkaran(radius, &luaslingkaran, &kelilinglingkaran);
```

Itu maksudnya apa? Kenapa bisa ada input lagi dengan "&" bisa saja terjadi *bug*.

```c
Luas_Keliling_SegitigaSembarang(SisiA, SisiB, SisiC)
```

Jangan mengawali apa pun dengan huruf kapital pada sebuah program. Gunakan huruf kapital di tengah-tengah saja seperti yang ada pada *camel case*. Jadi seperti punggung unta gitu, dari rendah ke tinggi, terus rendah ke tinggi, terus rendah lagi. rendahTinggirendahTinggirendah.

## PESAN

Jangan sungkan-sungkan nanya DUDEK, ya ....
