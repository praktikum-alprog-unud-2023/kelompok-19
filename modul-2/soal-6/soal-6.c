#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double loanPrincipal, interestRate, principalPayment, totalInstallment = 0, totalInterest = 0;
    int loanTerm, month;
    int valid;
    char input[256];

    // Input loan principal, interest rate (%), and loan term
    do {
        valid = 1;
        printf("Loan Principal: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%lf", &loanPrincipal) != 1 || loanPrincipal <= 0) {
            printf("Error, please try again. Invalid input. Please enter a loan amount greater than 0.\n");
            valid = 0;
        }
    } while (!valid);

    do {
        valid = 1;
        printf("Interest Rate(%): ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%lf", &interestRate) != 1 || interestRate <= 0 || interestRate >= 100) {
            printf("Error, please try again. Invalid input. Please enter an interest rate between 0 and 100.\n");
            valid = 0;
        }
    } while (!valid);

    do {
        valid = 1;
        printf("Loan Term(months): ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &loanTerm) != 1 || loanTerm <= 0) {
            printf("Error, please try again. Invalid input. Please enter a loan term greater than 0.\n");
            valid = 0;
        }
    } while (!valid);

    printf("Month\tInterest\tPrincipal Payment\tMonthly Installment\n");

    for (month = 1; month <= loanTerm; month++) {
        principalPayment = loanPrincipal / loanTerm;
        double monthlyInterest = (loanPrincipal - (month - 1) * principalPayment) * (interestRate / 12.0 / 100.0);
        double monthlyInstallment = principalPayment + monthlyInterest;

        totalInterest += monthlyInterest;
        totalInstallment += monthlyInstallment;

        printf("%d\t$%.0lf\t$%.0lf\t$%.0lf\n", month, monthlyInterest, principalPayment, monthlyInstallment);
    }

    printf("Total Interest $%.0lf\n", totalInterest);
    printf("Total Installment $%.0lf\n", totalInstallment);

    return 0;
}

