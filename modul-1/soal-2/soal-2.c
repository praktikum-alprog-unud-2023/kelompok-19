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

// Declare Triangle Procedure
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
// Declare Parallelogram Procedure
void calculateAreaAndCircumferenceOfParallelogram(double base, double height, double side)
{
    double area, circumference;

    area = base * height;
    circumference = 2 * (base + side);

    printf("Area of Parallelogram: %.2lf\n", area);
    printf("Circumference of Parallelogram: %.2lf\n", circumference);
}

// Deklrasi Prosedur Trapesium
void calculateAreaAndPerimeterofTrapezoid(double base1, double base2, double height, double side1, double side2)
{
    double area, circumference;

    area = 0.5 * (base1 + base2) * height;
    circumference = side1 + side2 + base1 + base2;

    printf("Area of Trapezoid: %.2lf\n", area);
    printf("Circumference of Trapezoid: %.2lf\n", circumference);
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
    int program;                                            // for switch
    int backToStart = 1;                                    // for validation
    double sideA, sideB, sideC, diagonal1, diagonal2, side; // Triangle's and Rhombus
    double base1, base2, height, side1, side2;              // Trapezoid's
    double radius, areaOfCircle, circumferenceOfCircle;     // Circle's
    double baseJ, heightJ, sideJ;                           // Parallelogram's

    // Input Operator
    do
    {

        printf("\n");
        printf("\t\t\t\tProgram to Calculate Area and Circumference of Two-Dimentional Figure\n");
        printf("Choose Program (1-5) : \n");
        printf("\n 1. Triangle\n 2. Rhombus\n 3. Parallelogram\n 4. Trapezoid\n 5. Circle\n");
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

        case 3: // Parallelogram // Dea's
            printf("Enter the base of parallelogram: ");
            baseJ = doubleValidation(0);
            printf("Enter the height of parallelogram: ");
            heightJ = doubleValidation(0);
            printf("Enter the side length of parallelogram: ");
            sideJ = doubleValidation(0);

            // Calls procedures to calculate area and circumference of parallelogram
            calculateAreaAndCircumferenceOfParallelogram(baseJ, heightJ, sideJ);
            break;

        case 4: // Trapezoid //Gusde
            printf("Enter the length of the top base of the trapezoid: ");
            base1 = doubleValidation(0);

            printf("Enter the length of the bottom base of the trapezoid: ");
            base2 = doubleValidation(0);

            printf("Enter the height of the trapezoid: ");
            height = doubleValidation(0);

            printf("Enter the length of the parallel side of the trapezoid (side1): ");
            side1 = doubleValidation(0);

            printf("Enter the length of the parallel side of the trapezoid (side 2): ");
            side2 = doubleValidation(0);

            // Calls the procedure to calculate the area and perimeter of a trapezoid
            calculateAreaAndPerimeterofTrapezoid(base1, base2, height, side1, side2);
            break;

        case 5: // Circle // Dea's
            printf("Enter The Radius of Circle: ");
            radius = doubleValidation(0);

            // Calls procedures to calculate area and circumference of circle
            calculateAreaAndCircumferenceOfCircle(radius, &areaOfCircle, &circumferenceOfCircle);

            printf("Area Of Circle: %lf\n", areaOfCircle);
            printf("Circumference of Circle: %lf\n", circumferenceOfCircle);
            break;

        default: // Validaation alternate
            printf("Your choice is not on list, please restart!");
            break;
        }
        if (backToStart == 1)
        {
            printf("Start Again?\n1. Yes\n0. No\n>>");
            backToStart = numberValidation(0, 1);
        }
    } while (backToStart == 1);
    return 0;
}
