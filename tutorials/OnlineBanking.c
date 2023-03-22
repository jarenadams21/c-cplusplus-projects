#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user {
    // Phone number
    char phone[50];
    // Account number
    char ac[50];
    // User password
    char password[50];
    // Balance
    float balance;
};

int main() {

    // User for application
    struct user usr;
    // User option selected
    int opt;
    printf("\nWhat do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\n Your choice:\t");
    scanf("%d", &opt);

    if(opt == 1) {
        // Clears the screen
        system("clear");

        printf("Enter your account number:\t");
        scanf("%s", &usr.ac);
        printf("\nEnter your phone number:\t");
        scanf("s", &usr.phone);
        printf("Enter your new password: \t");
        scanf("%s", usr.password);
        usr.balance = 0;
    }

    return 0;
}