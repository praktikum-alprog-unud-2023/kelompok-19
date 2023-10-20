#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

struct outcome
{
    double volume;
    double surfaceArea;
};

int numValidate(int minimum, int maximum)
{
    char buff[255], invalid;
    int valid;
    do {
        scanf("%[^\n]", buff);
        getchar();
        if (sscanf(buff, "%d%c", &valid, &invalid) == 1 && valid >= minimum && valid <= maximum)
            return valid;
        else
        {
            printf("The input you entered is wrong!\nPlease re-enter(1-5): ");
        }
    } while (1);
}

double doubleValidate(double minimum)
{
    char buff[255], invalid;
    double valid;
    do {
        scanf("%[^\n]", buff);
        getchar();
        if (sscanf(buff, "%lf%c", &valid, &invalid) == 1 && valid >= minimum)
            return valid;
        else
        {
            printf("The input you entered is wrong!\nPlease re-enter(1-5): ");
        }
    } while (1);
}

struct outcome tube(double radius, double height)
{
    struct outcome result;

    result.surfaceArea = 2 * M_PI * radius * (radius + height);
    result.volume = M_PI * pow(radius, 2) * height;
    return result;
}

struct outcome sphere(double radius)
{
    struct outcome result;

    result.surfaceArea = (4 * M_PI * pow(radius, 3)) / 3;
    result.volume = 4 * M_PI * pow(radius, 2);
    return result;
}

struct outcome cone(double radius, double height, double slant){
    struct outcome result;

    result.surfaceArea = (1 * M_PI * pow(radius, 2) * height) / 3;
    result.volume = M_PI * radius * (radius + slant);
    return result;
}

int main()
{
    int program;
    struct outcome result;
    double radius, height, slant;

    while (1) {
        // Input Operator
        printf("\n");
        printf("\t\t\t\tThree-Dimensional Shapes' Volume and Surface Area Calculation Program\n");
        printf("Choose a program (1-5) : \n");
        printf("\n 1. Tube\n 2. Sphere\n 3. Rectangular Pyramid\n 4. Triangular Prism\n 5. Cone\n");
        printf("\nYour Choice: ");
        program = numValidate(1, 5);

        switch (program) {
            case 1: // Tabung
                printf("Input the radius of the tube: ");
                radius = doubleValidate(0);
                printf("Input the height of the tube: ");
                height = doubleValidate(0);
                result = tube(radius, height);
                printf("Volume of the tube : %lf\n", result.volume);
                printf("Surface area of the tube : %lf\n", result.surfaceArea);
                break;

            case 2: // Bola
                printf("Input the radius of the sphere: ");
                radius = doubleValidate(0);
                result = sphere(radius);
                printf("Volume of the sphere : %lf\n", result.volume);
                printf("Surface area of the sphere : %lf\n", result.surfaceArea);
                break;

            case 3:
                break;

            case 4:
                break;

            case 5: // Kerucut
                printf("Input the radius of the cone: ");
                radius = doubleValidate(0);
                printf("Input the height of the cone: ");
                height = doubleValidate(0);
                printf("Input the slanted side of the cone: ");
                slant = doubleValidate(0);
                result = cone(radius, height, slant);
                printf("Volume of the cone= %lf\n", result.volume);
                printf("Surface area of the cone= %lf\n", result.surfaceArea);
                break;

            default:
                printf("The input you entered is wrong!\nPlease re-enter(1-5)\n");
        }
        
        printf("Do you want to run the program again? (1 for yes, 0 for no): ");
        int repeat = numValidate(0, 1);
        if (repeat == 0) {
            break;
        }
    }
    
    return 0;
}
