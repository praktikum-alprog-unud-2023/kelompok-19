#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int towerOfHanoiRecursive(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return 1;
    } else {
        int steps1 = towerOfHanoiRecursive(n - 1, source, target, auxiliary);
        printf("Move disk %d from %c to %c\n", n, source, target);
        int steps2 = towerOfHanoiRecursive(n - 1, auxiliary, source, target);
        return steps1 + 1 + steps2;
    }
}

int towerOfHanoiIterative(int n) {
    int totalSteps = (1 << n) - 1;
    return totalSteps;
}

int validateInteger(int min, int max) {
    char buff[255], *invalid;
    int valid;
    do {
        scanf("%[^\n]", buff);
        getchar();
        if (sscanf(buff, "%d%c", &valid, invalid) == 1 && valid >= min && valid <= max)
            return valid;
        else
            printf("Wrong input, try again!\n>> ");
    } while (1);
}

int main() {
    char input[100];
    int n;
    int choice = 1;

    while (choice == 1) {
        printf("Enter the number of disks: ");
        fgets(input, sizeof(input), stdin);

        // Validate input as a number
        if (sscanf(input, "%d", &n) != 1 || n <= 0) {
            printf("Please enter a valid number.\n");
            continue;
        }

        int totalStepsRecursive = towerOfHanoiRecursive(n, 'A', 'B', 'C');
        printf("Minimum number of steps (recursive method): %d\n", totalStepsRecursive);

        int totalStepsIterative = towerOfHanoiIterative(n);
        printf("Minimum number of steps (iterative method): %d\n", totalStepsIterative);

        printf("Do you want to calculate again? (0/1): ");

        choice = validateInteger(0, 1);
    }

    return 0;
}
