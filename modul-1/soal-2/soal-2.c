#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int numberValidation(int minimum, int maximum) // Number Validation.
{
    char buff[255], invalid;
    int valid;
    scanf("%[^\n]", buff);
    getchar();
    if (sscanf(buff, "%d%c", &valid, invalid) == 1 && valid >= minimum && valid <= maximum)
        return valid;
    else
    {
        printf("The input you entered is wrong!\nPlease re-enter!\n>> ");
        numberValidation(minimum, maximum);
    }
}

double doubleValidation(double minimum) // Number Validation.
{
    char buff[255], invalid;
    double valid;
    scanf("%[^\n]", buff);
    getchar();
    if (sscanf(buff, "%lf%c", &valid, invalid) == 1 && valid >= minimum)
        return valid;
    else
    {
        printf("The input you entered is wrong!\nPlease re-enter!\n>> ");
        doubleValidation(minimum);
    }
}

// Declare Triange Procedure
void calculateAreaAndCircumferenceOfTriangle(double sideA, double sideB, double sideC)
{
    double s = (sideA + sideB + sideC) / 2;                          // calculate half the circumference
    double area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC)); // Heron's formula process
    double circumference = sideA + sideB + sideC;                    // Process

    printf("\n");
    printf("Area of Triangle : %.lf\n", area);                   // Formula process
    printf("Circumference of Triangle : %.lf\n", circumference); // Formula process
}

// Declare Rhombus Procedure
void calculateAreaAndCircumferenceOfRhombus(double diagonal1, double diagonal2, double side)
{
    double area = (diagonal1 * diagonal2) / 2;
    double circumference = 4 * side;

    printf("\n");
    printf("Area of Rhombus : %.lf\n", area);                   // Process
    printf("Circumference of Rhombus : %.lf\n", circumference); // Process
}
// Deklarasi Prosedur Jajargenjang
void hitungLuasDanKelilingJajarGenjang(double alas, double tinggi, double sisi)
{
    double area, circumference;

    area = alas * tinggi;
    circumference = 2 * (alas + sisi);

    printf("Luas jajar genjang: %.2lf\n", area);
    printf("Keliling jajar genjang: %.2lf\n", circumference);
}

// Deklrasi Prosedur Trapesium
void hitungLuasDanKelilingTrapesium(double alas1, double alas2, double tinggiT, double sisi1, double sisi2)
{
    double area, circumference;

    area = 0.5 * (alas1 + alas2) * tinggiT;
    circumference = sisi1 + sisi2 + alas1 + alas2;

    printf("Luas Trapesium: %.2lf\n", area);
    printf("Keliling Trapesium: %.2lf\n", circumference);
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
    double sideA, sideB, sideC, diagonal1, diagonal2, side; // Triangle's and Rhombus
    double alas1, alas2, tinggiT, sisi1, sisi2;             // Punya Trapesium
    double radius, areaOfCircle, circumferenceOfCircle;     // Circle's
    double alasJ, tinggiJ, sisiJ;                           // Punya Jajargenjang

    // Input Operator
    printf("\n");
    printf("\t\t\t\tProgram to Calculate Area and Circumference of Two-Dimentional Figure\n");
    printf("Choose Program (1-5) : \n");
    printf("\n 1. Triangle\n 2. Rhombus\n 3. Jajargenjang\n 4. Trapesium\n 5. Circle\n");
    printf("\n\nYour Choice: ");
    program = numberValidation(1, 5);

    switch (program) // Choose operator on list
    {
    case 1: // Triangle //Nata's
        printf("Input side A: ");
        sideA = doubleValidation(0);
        printf("Input side B: ");
        sideB = doubleValidation(0);
        printf("Input side C: ");
        sideC = doubleValidation(0);

        calculateAreaAndCircumferenceOfTriangle(sideA, sideB, sideC); // Calling procedure
        break;

    case 2: // Rhombus // Nata's
        printf("Input lenght of Diagonal 1: ");
        diagonal1 = doubleValidation(0);
        printf("Input lenght of Diagonal 2: ");
        diagonal2 = doubleValidation(0);
        printf("Input lenght of side: ");
        side = doubleValidation(0);

        calculateAreaAndCircumferenceOfRhombus(diagonal1, diagonal2, side); // Calling procedure
        break;

    case 3: // Jajargenjang //Punya Dea
        printf("Masukkan panjang alas: ");
        alasJ = doubleValidation(0);
        printf("Masukkan tinggi: ");
        tinggiJ = doubleValidation(0);
        printf("Masukkan panjang sisi: ");
        sisiJ = doubleValidation(0);

        // Memanggil prosedur untuk menghitung luas dan keliling jajar genjang
        hitungLuasDanKelilingJajarGenjang(alasJ, tinggiJ, sisiJ);
        break;

    case 4: // Trapesium //Punya Gusde
        printf("Masukkan panjang alas atas trapesium: ");
        alas1 = doubleValidation(0);

        printf("Masukkan panjang alas bawah trapesium: ");
        alas2 = doubleValidation(0);

        printf("Masukkan tinggi trapesium: ");
        tinggiT = doubleValidation(0);

        printf("Masukkan panjang sisi sejajar trapesium (sisi1): ");
        sisi1 = doubleValidation(0);

        printf("Masukkan panjang sisi sejajar trapesium (sisi2): ");
        sisi2 = doubleValidation(0);

        // Memanggil prosedur untuk menghitung luas dan keliling trapesium
        hitungLuasDanKelilingTrapesium(alas1, alas2, tinggiT, sisi1, sisi2);
        break;

    case 5: // Circle // Dea's
        printf("Enter The Radius of Circle: ");
        radius = doubleValidation(0);

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
