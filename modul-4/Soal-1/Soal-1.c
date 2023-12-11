#include <stdio.h>
#include <math.h>

// Define struct for salary data
struct Salary {
    float hourlyWage;
    float overtimeHourlyWage;
};

int main() {
    // Initialize salary data within the struct
    struct Salary wageData;
    wageData.hourlyWage = 10625;
    wageData.overtimeHourlyWage = 8 * wageData.hourlyWage;

    int hoursWorked;
    float totalWage = 0.0;

    printf("Enter the number of hours worked: ");
    scanf("%d", &hoursWorked);

    // Calculate wage based on hours worked
    if (hoursWorked <= 8) {
        totalWage = hoursWorked * wageData.hourlyWage;
    } else {
        totalWage = 8 * wageData.hourlyWage + (hoursWorked - 8) * wageData.overtimeHourlyWage;
    }

    // Display the daily wage calculation details
    printf("Daily Wage Details:\n");
    printf("Hours Worked: %d hours\n", hoursWorked);
    printf("Hourly Wage: Rp%.2f\n", wageData.hourlyWage);
    printf("Overtime Hourly Wage: Rp%.2f\n", wageData.overtimeHourlyWage);
    printf("Total Daily Wage: Rp%.2f\n", totalWage);

    return 0;
}

