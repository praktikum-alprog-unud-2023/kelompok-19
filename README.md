# REPOSITORI KELOMPOK 19

Repositori ini khusus dibuat untuk mata kuliah Praktikum Algoritma dan Pemrogram 2023 dan dikhususkan lagi untuk Kelompok 19. Struktur repositori ini adalah sebagai berikut:

```txt
.
├── README.md
├── modul-<no>
│   ├── README.md
│   └── soal-<no>
│       ├── main.c
│       ├── main.exe
│       └── ...
│   ...
...
```

## LAKUKAN DAN JANGAN LAKUKAN

Ada beberapa hal yang harus kalian lakukan dan jangan kalian lakukan dalam melakukan *push* dan *pull* pada repositori ini.

### LAKUKAN

Sebelum melakukan pull atau mengubah sesuatu (jika menggunakan Git), sebaiknya melakukan koordinasi atau melakukan pull terlebih dahulu.

```terminal
git pull <remote> <branch>
```

*Remote* yang kalian gunakan usahakan bernama origin dan *branch* yang kalian gunakan adalah "main" (tidak boleh yang lain).

Hal ini bertujuan agar tidak menghancurkan struktur dari repositori ini, atau jika kalian malas melakukan *pull* dan melakukan koordinasi antar anggota (aku harap tidak) kalian bisa mencari beberapa ekstensi dari Visual Studio yang berguna agar kalian bisa mengerjakan kode atau repositori bersama-sama tanpa takut menghancurkan struktur. Atau *upload* manual :v

NB: Kalian bisa mengubah struktur README ini sesuka hati, asalkan rapi dan tidak asal-asalan.

### JANGAN LAKUKAN

1. Tidak membuat tugas
2. Telat mengumpulkan
3. Tidak komunikasi
4. Minum susu coklat di pagi hari (opsional)

## CARA PAKAI GIT

```terminal
PS C:\PRATIKUM\pull-push> git --version
git version 2.42.0.windows.2
PS C:\PRATIKUM\pull-push> git init
Initialized empty Git repository in C:/PRATIKUM/pull-push/.git/
PS C:\PRATIKUM\pull-push> git remote add origin https://github.com/praktikum-alprog-unud-2023/kelompok-19.git
PS C:\PRATIKUM\pull-push> git pull origin main
remote: Enumerating objects: 91, done.
remote: Counting objects: 100% (91/91), done.
remote: Compressing objects: 100% (72/72), done.
remote: Total 91 (delta 31), reused 15 (delta 3), pack-reused 0
Unpacking objects: 100% (91/91), 44.87 KiB | 188.00 KiB/s, done.
From https://github.com/praktikum-alprog-unud-2023/kelompok-19
 * branch            main       -> FETCH_HEAD
 * [new branch]      main       -> origin/main
PS C:\PRATIKUM\pull-push> git add .
PS C:\PRATIKUM\pull-push> git commit -m "Update Volume."
Author identity unknown

*** Please tell me who you are.

Run

  git config --global user.email "you@example.com"
  git config --global user.name "Your Name"

to set your account's default identity.
Omit --global to set the identity only in this repository.

fatal: unable to auto-detect email address (got 'LENOVO@LENOVO-IDEAPAD3.(none)')
PS C:\PRATIKUM\pull-push> git config --global user.email "hopegekdea@gmail.com"
PS C:\PRATIKUM\pull-push> git config --global user.name "deaaalma" 
PS C:\PRATIKUM\pull-push> git commit -m "Update Volume."
[main f8f8c4b] Update Volume.
 1 file changed, 62 insertions(+), 110 deletions(-)
PS C:\PRATIKUM\pull-push> git push origin main
Writing objects: 100% (5/5), 1.08 KiB | 1.08 MiB/s, done.
Total 5 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/praktikum-alprog-unud-2023/kelompok-19.git
   2693fba..f8f8c4b  main -> main
PS C:\PRATIKUM\pull-push> git push origin main
Everything up-to-date
PS C:\PRATIKUM\pull-push>
```