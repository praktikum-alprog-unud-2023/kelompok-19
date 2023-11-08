#include <stdio.h>

int january (int date) {
    if(date>=1 && date<=19) {
        printf("---------------------------------\n");
        printf("|                               |\n");
        printf("| Congrats, you're a Capricorn! |\n");
        printf("|                               |\n");
        printf("---------------------------------\n");
    } else if(date>=20 && date<=31) {
        printf("---------------------------------\n");
        printf("|                               |\n");
        printf("| Congrats, you're an Aquarius! |\n");
        printf("|                               |\n");
        printf("---------------------------------\n");
    } else {
        printf("Your input is wrong.");
    }
}

int february (int date) {
    int dateValid = 1;
    do {
        if(date>=1 && date<=18) {
            printf("---------------------------------\n");
            printf("|                               |\n");
            printf("| Congrats, you're an Aquarius! |\n");
            printf("|                               |\n");
            printf("---------------------------------\n");
            dateValid = 1;
        } else if(date>=19 && date<=28) {
            printf("------------------------------\n");
            printf("|                            |\n");
            printf("| Congrats, you're a Pisces! |\n");
            printf("|                            |\n");
            printf("------------------------------\n");
            dateValid = 1;
        }else {
            printf("Your input is wrong. It's not a leap year, so this month only has 28 days. Please re-enter: ");
            scanf("%d", &date);
            dateValid = 0;
        }
    } while (dateValid == 0);
}

int februaryLeap(int date) {
    int dateValid = 1; 
    do {
        if (date >= 1 && date <= 18) {
            printf("---------------------------------\n");
            printf("|                               |\n");
            printf("| Congrats, you're an Aquarius! |\n");
            printf("|                               |\n");
            printf("---------------------------------\n");
            dateValid = 1; 
        } else if (date >= 19 && date <= 29) {
            printf("------------------------------\n");
            printf("|                            |\n");
            printf("| Congrats, you're a Pisces! |\n");
            printf("|                            |\n");
            printf("------------------------------\n");
            dateValid = 1; 
        } else {
            printf("Your input is wrong. This month only has 29 days. Please re-enter: ");
            scanf("%d", &date); 
            dateValid = 0; 
        }
    } while (dateValid == 0); 
}

int march(int date) {
    if(date>=1 && date<=20) {
        printf("------------------------------\n");
        printf("|                            |\n");
        printf("| Congrats, you're a Pisces! |\n");
        printf("|                            |\n");
        printf("------------------------------\n");
    } else if(date>=21 && date<=31) {
        printf("------------------------------\n");
        printf("|                            |\n");
        printf("| Congrats, you're an Aries! |\n");
        printf("|                            |\n");
        printf("------------------------------\n");
    }else {
        printf("Your input is wrong.");
    }
}

int april(int date) {
    if(date>=1 && date<=19) {
        printf("------------------------------\n");
        printf("|                            |\n");
        printf("| Congrats, you're an Aries! |\n");
        printf("|                            |\n");
        printf("------------------------------\n");
    } else if(date>=20 && date<=30) {
        printf("------------------------------\n");
        printf("|                            |\n");
        printf("| Congrats, you're a Taurus! |\n");
        printf("|                            |\n");
        printf("------------------------------\n");
    }else {
        printf("Your input is wrong.");
    }
}

int may(int date) {
    if(date>=1 && date<=20) {
        printf("------------------------------\n");
        printf("|                            |\n");
        printf("| Congrats, you're a Taurus! |\n");
        printf("|                            |\n");
        printf("------------------------------\n");
    } else if(date>=21 && date<=31) {
        printf("------------------------------\n");
        printf("|                            |\n");
        printf("| Congrats, you're a Gemini! |\n");
        printf("|                            |\n");
        printf("------------------------------\n");
    }else {
        printf("Your input is wrong.");
    }
}

int june(int date) {
    if(date>=1 && date<=20) {
        printf("------------------------------\n");
        printf("|                            |\n");
        printf("| Congrats, you're a Gemini! |\n");
        printf("|                            |\n");
        printf("------------------------------\n");
    } else if(date>=21 && date<=30) {
        printf("------------------------------\n");
        printf("|                            |\n");
        printf("| Congrats, you're a Cancer! |\n");
        printf("|                            |\n");
        printf("------------------------------\n");
    }else {
        printf("Your input is wrong. This month only has 30 days.");
    }
}

int july(int date) {
    if(date>=1 && date<=22) {
        printf("------------------------------\n");
        printf("|                            |\n");
        printf("| Congrats, you're a Cancer! |\n");
        printf("|                            |\n");
        printf("------------------------------\n");
    } else if(date>=23 && date<=31) {
        printf("---------------------------\n");
        printf("|                         |\n");
        printf("| Congrats, you're a Leo! |\n");
        printf("|                         |\n");
        printf("---------------------------\n");
    } else {
        printf("Your input is wrong.");
    }
}

int august(int date) {
    if(date>=1 && date<=22) {
        printf("---------------------------\n");
        printf("|                         |\n");
        printf("| Congrats, you're a Leo! |\n");
        printf("|                         |\n");
        printf("---------------------------\n");
    } else if(date>=23 && date<=31) {
        printf("-----------------------------\n");
        printf("|                           |\n");
        printf("| Congrats, you're a Virgo! |\n");
        printf("|                           |\n");
        printf("-----------------------------\n");
    }else {
        printf("Your input is wrong.");
    }
}

int september(int date) {
    if(date>=1 && date<=22) {
        printf("-----------------------------\n");
        printf("|                           |\n");
        printf("| Congrats, you're a Virgo! |\n");
        printf("|                           |\n");
        printf("-----------------------------\n");
    } else if(date>=23 && date<=30) {
        printf("-----------------------------\n");
        printf("|                           |\n");
        printf("| Congrats, you're a Libra! |\n");
        printf("|                           |\n");
        printf("-----------------------------\n");
    }else {
        printf("Your input is wrong. This month only has 30 days.");
    }
}

int october(int date) {
     if(date>=1 && date<=22) {
        printf("-----------------------------\n");
        printf("|                           |\n");
        printf("| Congrats, you're a Libra! |\n");
        printf("|                           |\n");
        printf("-----------------------------\n");
    } else if(date>=23 && date<=31) {
        printf("-------------------------------\n");
        printf("|                             |\n");
        printf("| Congrats, you're a Scorpio! |\n");
        printf("|                             |\n");
        printf("-------------------------------\n");
    }else {
        printf("Your input is wrong.");
    }
}

int november(int date) {
    if(date>=1 && date<=21) {
        printf("-------------------------------\n");
        printf("|                             |\n");
        printf("| Congrats, you're a Scorpio! |\n");
        printf("|                             |\n");
        printf("-------------------------------\n");
    } else if(date>=22 && date<=30) {
        printf("-----------------------------------\n");
        printf("|                                 |\n");
        printf("| Congrats, you're a Sagittarius! |\n");
        printf("|                                 |\n");
        printf("-----------------------------------\n");
    }else {
        printf("Your input is wrong. This month only has 30 days.");
    }
}

int december(int date) {
    if(date>=1 && date<=21) {
        printf("-----------------------------------\n");
        printf("|                                 |\n");
        printf("| Congrats, you're a Sagittarius! |\n");
        printf("|                                 |\n");
        printf("-----------------------------------\n");
    } else if(date>=22 && date<=31) {
        printf("---------------------------------\n");
        printf("|                               |\n");
        printf("| Congrats, you're a Capricorn! |\n");
        printf("|                               |\n");
        printf("---------------------------------\n");
    }else {
        printf("Your input is wrong.");
    }
}

int main() {
    int year, month, date, choice;
    char buffer[100]; 
    char repeat;

    printf("\n");
    printf("\t\t\t\t\t\t\t\t------------------------------\n");
    printf("\t\t\t\t\t\t\t\tProgram to Predict Your Zodiac\n");
    printf("\t\t\t\t\t\t\t\t------------------------------\n");

    do {
        while (1) {
            printf("\nEnter your birth year (1000 - 2100): ");
            fgets(buffer, sizeof(buffer), stdin);

            if (sscanf(buffer, "%d", &year) == 1 && year >= 1000 && year <= 2100) {
                break; 
            } else {
                printf("Your input is wrong. Please re-enter.");
            }
        }

        while (1) {
            printf("Enter your birth month (1-12): ");
            fgets(buffer, sizeof(buffer), stdin); 

            if (sscanf(buffer, "%d", &month) == 1 && month >= 1 && month <= 12) {
                break; 
            } else {
                printf("Your input is wrong. Please re-enter.\n");
            }
        }

        while (1) {
            printf("Enter your birth date: ");
            fgets(buffer, sizeof(buffer), stdin); 

            if (sscanf(buffer, "%d", &date) == 1 && date >= 1 && date <= 31) {
                break; 
            } else {
                printf("Your input is wrong. Please re-enter.\n");
            }
        }
    
        if (year % 4 == 0) {
            switch(month) {
                case 1:
                    january(date);
                    break;

                case 2:
                    februaryLeap(date);
                    break;

                case 3:
                    march(date);
                    break;

                case 4:
                    april(date);
                    break;

                case 5:
                    may(date);
                    break;

                case 6:
                    june(date);
                    break;

                case 7:
                    july(date);
                    break;

                case 8:
                    august(date);
                    break;

                case 9:
                    september(date);
                    break;

                case 10:
                    october(date);
                    break;

                case 11:
                    november(date);
                    break;

                case 12:
                    december(date);
                    break;

                default:
                    printf("Your input is wrong. Please try again");
            }
        } else {
            switch(month) {
                case 1:
                    january(date);
                    break;

                case 2:
                    february(date);
                    break;

                case 3:
                    may(date);
                    break;

                case 4:
                    april(date);
                    break;

                case 5:
                    may(date);
                    break;

                case 6:
                    june(date);
                    break;

                case 7:
                    july(date);
                    break;

                case 8:
                    august(date);
                    break;

                case 9:
                    september(date);
                    break;

                case 10:
                    october(date);
                    break;

                case 11:
                    november(date);
                    break;

                case 12:
                    december(date);
                    break;

                default:
                    printf("Your input is wrong. Please try again");
            }
        }

        while (1) {
            printf("Do you want to run the program again? (1 for yes, 0 for no): ");
            getchar();
            fgets(buffer, sizeof(buffer), stdin);
            
            if (sscanf(buffer, "%c", &repeat) == 1) {
                if (repeat == '0' || repeat == '1') {
                    break;
                } else {
                    printf("Your input is wrong. Please re-enter.\n");
                }
            } else {
                printf("Your input is wrong. Please re-enter.");
            }
        }
        printf("-------------------------------------------------\n");

    } while (repeat == '1');

    printf("\n----------------------------------------------------------\n");
    printf("| Thank you for trying this program, till we meet again! |\n");
    printf("----------------------------------------------------------\n");

    return 0;
}
