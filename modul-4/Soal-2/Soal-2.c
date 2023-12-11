#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int side, surface_area_cube, volume_cube;
} CubeStruct;

typedef union {
    int side, surface_area_cube, volume_cube;
} CubeUnion;

int check_input() {
    char check_char;
    int check_number;
    if (scanf("%d%c", &check_number, &check_char) != 2 || check_number < 0 || check_number > 1 || check_char != '\n') {
        fflush(stdin);
        printf("\n\t\t\t\tYour input is invalid >:(\n");
        printf("\t\t\t\tPlease enter a valid input!\n\n");
        printf("\t\t\t\tEnter the input option again: ");
        return check_input();
    } else {
        return check_number;
    }
}

int check_side() {
    int check_number;
    char check_char;
    if (scanf("%d%c", &check_number, &check_char) != 2 || check_number < 0 || check_char != '\n') {
        fflush(stdin);
        printf("\n\t\t\t\tYour input is invalid >:(\n");
        printf("\t\t\t\tPlease enter a valid input!\n\n");
        printf("\t\t\t\tEnter a valid number: ");
        return check_side();
    } else {
        return check_number;
    }
}

int check_read() {
    char check_char;
    int check_number;
    if (scanf("%d%c", &check_number, &check_char) != 2 || (check_number != 9 && check_number != 0) || check_char != '\n') {
        fflush(stdin);
        printf("\n\t\t\t\tYour input is invalid >:(\n");
        printf("\t\t\t\tPlease enter a valid input!\n\n");
        printf("\t\t\t\tEnter the input option again: ");
        return check_read();
    } else {
        return check_number;
    }
}

int main() {
    int input, read, sideLength;
    do {
        printf("\t\t\t====================================================================\n");
        printf("\t\t\t|                                                                  |\n");
        printf("\t\t\t|                    Here are the menu options:                    |\n");
        printf("\t\t\t|                  1. Cube STRUCT and Cube UNION                   |\n");
        printf("\t\t\t|                  0. Exit                                         |\n");
        printf("\t\t\t|                                                                  |\n");
        printf("\t\t\t====================================================================\n\n");
        printf("\t\t\t\t    Enter the menu option you want to perform: ");
        input = check_input();
        system("cls");
        if (input == 1) {
            system("cls");
            printf("\n\t\t\t\tEnter the size of the SIDE:");
            sideLength = check_side();
            CubeStruct structs = {.side = sideLength, .surface_area_cube = 6 * sideLength * sideLength, .volume_cube = sideLength * sideLength * sideLength};
            CubeUnion unions[3];
            unions[0].side = sideLength;
            unions[1].surface_area_cube = 6 * sideLength * sideLength;
            unions[2].volume_cube = sideLength * sideLength * sideLength;
            printf("\n\t\t\t\t=======================================\n");
            printf("\t\t\t\t>>              Cube STRUCT          <<\n");
            printf("\t\t\t\t=======================================\n\n");
            printf("\t\t\t\tSide Length: %d\n", structs.side);
            printf("\t\t\t\tSurface Area: %d\n", structs.surface_area_cube);
            printf("\t\t\t\tVolume: %d\n\n", structs.volume_cube);
            printf("\t\t\t\t=======================================\n");
            printf("\t\t\t\t>>               Cube UNION          <<\n");
            printf("\t\t\t\t=======================================\n\n");
            printf("\t\t\t\tSide Length: %d\n", unions[0].side);
            printf("\t\t\t\tSurface Area: %d\n", unions[1].surface_area_cube);
            printf("\t\t\t\tVolume Cube: %d\n\n", unions[2].volume_cube);
            printf("\t\t\t\t=======================================\n");
            printf("\t\t\t\t>>           Memory Size            <<\n");
            printf("\t\t\t\t=======================================\n\n");
            printf("\t\t\t\tMemory Size of Cube STRUCT: %d\n", sizeof(structs));
            printf("\t\t\t\tMemory Size of Cube UNION: %d\n\n", sizeof(unions[0]));
        } else {
            printf("\n\n\t\t\t\t                 >>THANK YOU<<          \n");
            printf("\t\t\t\t   For Using Our Program :)\n");
        }
        printf("\n\n\t\t\t\tDo You Want to Use This Program Again?\n");
        printf("\t\t\t\t              (0 = no / 9 = yes):");
        read = check_read();
        system("cls");
    } while (read == 9);

    // Thank you message
    printf("\n\n\t\t\t\t   >>THANK YOU FOR USING THIS PROGRAM<<   \n");

    return 0;
}
