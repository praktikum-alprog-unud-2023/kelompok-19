#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Student
{
    char registrationNumber[255];
    char name[255];
} student;

void identity();
void addStudent();
void searchStudent();
char exitProgram();
char validate(char *input);
char validateContent(char *input);
char validateRegistrationNumber(char *input);
char validateNIM();
int checkChoice1();
int checkChoice2();

char registrationNumber[255], name[255];

void identity()
{
}

int checkChoice1()
{
    int input;
    while (1)
    {
        input = validInput();
        if (input >= 1 && input <= 3)
        {
            return input;
        }
        printf("\t\t\t\t===================================\n");
        printf("\t\t\t\tInvalid input, please try again: ");
    }
}

int checkChoice2()
{
    int input;
    while (1)
    {
        input = validInput();
        if (input >= 1 && input <= 2)
        {
            return input;
        }
        printf("\t\t\t===================================\n");
        printf("\t\t\tInvalid input, please try again: ");
    }
}

char exitProgram()
{
    char input[100];
    while (1)
    {
        int i = 0;
        int wrongInput;
        scanf("%[^\n]", &input);
        fflush(stdin);
        if (input[i + 1] == '\0')
        {
            if ((input[0] == 'y' || input[0] == 'Y') && input[1] == '\0')
            {
                return input[0];
            }
            else if ((input[0] == 'n' || input[0] == 'N') && input[1] == '\0')
            {
                return input[0];
            }
            else
            {
                wrongInput = 1;
            }
        }
        wrongInput = 1;
        if (wrongInput == 1)
        {
            printf("\t\t\t===================================\n");
            printf("\t\t\tInvalid input, please try again: ");
        }
    }
}

char validateContent(char *input)
{
    int i, wrongInput;
    i = 0;
    wrongInput = 0;
    scanf("%[^\n]", input);
    fflush(stdin);
    while (input[i] != '\0')
    {
        if (input[i] == '.')
        {
            wrongInput = 1;
            input[i] = '\0';
        }
        else if (input[i] == ' ')
        {
            if (input[0] == ' ' || input[i + 1] == '\0' || input[0] == '\0')
            {
                wrongInput = 1;
                input[i] = '\0';
            }
            else
            {
                i++;
            }
        }
        else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            {
                i++;
            }
            else
            {
                wrongInput = 1;
                input[i] = '\0';
            }
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            wrongInput = 1;
            input[i] = '\0';
        }
        else
        {
            wrongInput = 1;
            input[i] = '\0';
        }
    }
    if (input[0] == '\0')
    {
        wrongInput = 1;
        input[i] = '\0';
    }
    if (wrongInput == 1)
    {
        printf("\t\t\t===================================\n");
        printf("\t\t\tInvalid input, please try again: ");
        return 0;
    }
    else
    {
        return *input;
    }
}

char validate(char *input)
{
    while (1)
    {
        if (validateContent(input))
        {
            fflush(stdin);
            return *input;
        }
    }
}

char validateRegistrationNumber(char *registrationNumbers)
{
    while (1)
    {
        if (validateNIM(registrationNumbers))
        {
            fflush(stdin);
            return *registrationNumbers;
        }
    }
}

char validateNIM(char *input)
{
    int i, wrongInput;
    i = 0;
    wrongInput = 0;
    scanf("%[^\n]", input);
    fflush(stdin);
    while (input[i] != '\0')
    {
        if (input[i] == '.')
        {
            wrongInput = 1;
            input[i] = '\0';
        }
        else if (input[i] == ' ')
        {
            if (input[0] == ' ' || input[i + 1] == '\0')
            {
                wrongInput = 1;
                input[i] = '\0';
            }
            else
            {
                i++;
            }
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            i++;
        }
        else
        {
            wrongInput = 1;
            input[i] = '\0';
        }
    }
    if (input[0] == '\0')
    {
        wrongInput = 1;
        input[i] = '\0';
    }
    if (wrongInput == 1)
    {
        printf("\t\t\t===================================\n");
        printf("\t\t\tInvalid input, please try again: ");
        return 0;
    }
    else
    {
        return *input;
    }
}

int validInput()
{
    char input[100];
    int i = 0;
    int back = 0;
    int frontContent = 0;
    int backContent = 0;
    int status = 0;
    int dot = 0;
    int wrongInput = 0;
    int minus = 0;
    int result;

    scanf("%[^\n]", &input);
    fflush(stdin);
    while (input[i] != '\0')
    {
        if (input[i] == '.')
        {
            wrongInput = 1;
            input[i] = '\0';
        }
        else if (input[i] == ' ')
        {
            wrongInput = 1;
            input[i] = '\0';
        }
        else if ((input[i] >= '0' && input[i] <= '9') || input[0] == '-')
        {
            if (input[i] == '-')
            {
                minus++;
                if (minus > 1 || input[i + 1] == '\0')
                {
                    wrongInput = 1;
                    input[i] = '\0';
                }
            }
            else if (input[i] >= '0' && input[i] <= '9')
            {
                if (input[0] == '0')
                {
                    wrongInput = 1;
                    input[i] = '\0';
                }
                else
                {
                    frontContent = (frontContent * 10) + (input[i] - 48);
                }
            }
            else
            {
                wrongInput = 1;
                input[i] = '\0';
            }
            i++;
        }
        else
        {
            wrongInput = 1;
            input[i] = '\0';
        }
    }
    if (input[0] == '\0')
    {
        wrongInput = 1;
    }
    result = frontContent;
    if (minus == 1)
    {
        result = result - (result * 2);
    }
    if (wrongInput == 1)
    {
        printf("\t\t\t===================================\n");
        printf("\t\t\tInvalid input, please try again: ");
    }
    else
    {
        return result;
    }
    return validInput();
}

void addStudent()
{
    int check, choice, d;
    char registrationNumber[10];
    FILE *checkData;
    FILE *input;
    do
    {
        fflush(stdin);
        system("cls");
        printf("\t\t\tInput Student Registration Number and Name\n\n");
        printf("\t\t\tInput Student Registration Number : ");
        validateRegistrationNumber(&student.registrationNumber);

        fflush(stdin);
        printf("\t\t\tInput Student Name : ");
        validate(&student.name);

        check = 0;
        fflush(stdin);
        checkData = fopen("sim.txt", "r");
        if (checkData == NULL)
        {
            printf("\t\t\tFile txt Not Available\n");
        }
        else
        {
            while (!feof(checkData))
            {
                fscanf(checkData, "%s\n#%s#\n", &registrationNumber, &name);
                if (strcmp(student.registrationNumber, registrationNumber) == 0)
                {
                    fflush(stdin);
                    printf("\t\t\tRegistration Number already exists in the txt file!\n");
                    check = 1;
                }
            }
            fclose(checkData);
        }
        fflush(stdin);
        if (check != 1)
        {
            input = fopen("sim.txt", "a");
            fprintf(input, "%s\n#%s#\n", student.registrationNumber, student.name);
            fclose(input);
            check = 4;
        }
        if (check == 4)
        {
            printf("\n\n\t\t\tData added successfully\n");
        }
        printf("\n\t\t\t 1 To add data again\n");
        printf("\t\t\t 2 To exit from the data input menu\n\n");
        printf("\t\t\t Do you want to repeat or exit? : ");
        choice = checkChoice2();
    } while (choice == 1);
}

void searchStudent()
{
    char registrationNumber[10];
    int choice;
    int a, check;
    do
    {
        fflush(stdin);
        system("cls");
        printf("\t\t\tInput Student Registration Number (NIM)");
        check = 0;
        fflush(stdin);
        printf("\n\n\t\t\tEnter your NIM :");
        validateRegistrationNumber(&registrationNumber);

        FILE *checkData;

        checkData = fopen("sim.txt", "r");

        if (checkData == NULL)
        {
            printf("txt file does not exist!");
        }
        else
        {
            while (!feof(checkData))
            {
                fscanf(checkData, "%s\n# %[^#] #\n", &student.registrationNumber, &student.name);
                if (strcmp(student.registrationNumber, registrationNumber) == 0)
                {
                    fflush(stdin);
                    printf("\n\n\t\t\t Student Data      \n\n");
                    printf("\t\t\t Student Registration Number  : %s", student.registrationNumber);
                    printf("\n");
                    printf("\t\t\t Student Name: %s", student.name);
                    printf("\n\n");
                    check = 1;
                }
            }
            fclose(checkData);
        }
        if (check != 1)
        {
            printf("\n\n\t\t\t Cannot find the input Student Registration Number\n\n");
        }
        printf("\t\t\t 1 To search data again\n");
        printf("\t\t\t 2 To exit from the data input menu\n\n");
        printf("\t\t\t Do you want to repeat or exit? : ");
        choice = checkChoice2();
    } while (choice == 1);
}

int main()
{
    char check;
    int choice;
    identity();
    do
    {
        fflush(stdin);
        system("cls");
        printf("\t\t\t\t==============================================================================\n");
        printf("\t\t\t\t||                         Student Information System                      ||\n");
        printf("\t\t\t\t||                                           	                            ||\n");
        printf("\t\t\t\t||          1. Add Data                                                    ||\n");
        printf("\t\t\t\t||          2. Search Data                                                 ||\n");
        printf("\t\t\t\t||          3. Exit                         	                            ||\n");
        printf("\t\t\t\t||                                           	                            ||\n");
        printf("\t\t\t\t==============================================================================\n\n");
        printf("\t\t\tInput choice : ");
        choice = checkChoice1();
        fflush(stdin);
        if (choice == 1)
        {
            addStudent();
            system("cls");
        }
        else if (choice == 2)
        {
            searchStudent();
            system("cls");
        }
        else
        {
            printf("\t\t\t=====================================================\n");
            printf("\t\t\t     Thank you for using this program.    \n");
            printf("\t\t\t=====================================================");
            return 0;
        }
        printf("\n\t\t\t Y to repeat the program\n");
        printf("\t\t\t N to exit the program\n\n");
        printf("\t\t\t Do you want to repeat? : ");
        check = exitProgram();
    } while (check == 'y' || check == 'Y');
    printf("\t\t\t=====================================================\n");
    printf("\t\t\t     Thank you for using this program.    \n");
    printf("\t\t\t=====================================================");
    return 0;
}
