#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to convert binary to decimal
int binaryToDecimal(char binary[])
{
    int decimal = 0;
    int length = strlen(binary);

    if (length > 32)
    {
        printf("Invalid input: Binary number is too long.\n");
        return -1; // Validation failed
    }

    for (int i = 0; i < length; i++)
    {
        if (binary[i] == '1')
        {
            decimal += pow(2, length - i - 1);
        }
        else if (binary[i] != '0')
        {
            printf("Invalid input: Binary number should only contain 0 and 1.\n");
            return -1; // Validation failed
        }
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal)
{
    if (decimal == 0)
    {
        printf("Binary number: 0\n");
        return;
    }

    int binary[32];
    int i = 0;

    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    printf("Binary number: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main()
{
    char input[100];
    int choice;
    int validInput = 0;
    int restart = 0;

    while (1)
    {
        printf("Choose conversion:\n");
        printf("1. Binary to decimal\n");
        printf("2. Decimal to binary\n");
        printf("Enter choice (1/2): ");

        char buffer[1024];  // Additional buffer for input cleaning
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading the choice.\n");
            break;
        }

        if (sscanf(buffer, "%d", &choice) != 1)
        {
            printf("Invalid input: Enter a valid choice.\n");
            continue;
        }

        if (choice != 1 && choice != 2)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        if (choice == 1)
        {
            printf("Enter binary number: ");

            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Error reading the binary number.\n");
                break;
            }

            if (sscanf(buffer, "%s", input) != 1)
            {
                printf("Invalid input: Enter a valid binary number.\n");
                continue;
            }

            // Clean newline character (Enter) if present
            size_t input_len = strlen(input);
            if (input_len > 0 && input[input_len - 1] == '\n') {
                input[input_len - 1] = '\0';
            }

            int decimal = binaryToDecimal(input);
            if (decimal != -1)
            {
                printf("Conversion result: %d\n", decimal);
                validInput = 1;
            }
        }
        else if (choice == 2)
        {
            int decimal;
            printf("Enter decimal number: ");

            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Error reading the decimal number.\n");
                break;
            }

            if (sscanf(buffer, "%d", &decimal) != 1)
            {
                printf("Invalid input: Enter a valid decimal number.\n");
                continue;
            }

            if (decimal < 0)
            {
                printf("Invalid input: Decimal number should be positive.\n");
            }
            else
            {
                decimalToBinary(decimal);
                validInput = 1;
            }
        }

        while (1)
        {
            printf("Do you want to repeat? Enter 1 for yes, 2 to finish: ");

            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Error reading the repeat choice.\n");
                break;
            }

            if (sscanf(buffer, "%d", &restart) != 1)
            {
                printf("Invalid input: Enter a valid choice.\n");
                continue;
            }

            if (restart == 1 || restart == 2)
            {
                break;
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
            }
        }

        if (restart == 2)
        {
            break;
        }

        validInput = 0;
    }

    return 0;
}

