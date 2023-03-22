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

    // Store users in a file
    FILE *fp;
    char filename[50];

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

        printf("Enter your account #:\t");
        scanf("%s", usr.ac);
        printf("Enter your phone #:\t");
        scanf("%s", usr.phone);
        printf("Enter your new password: \t");
        scanf("%s", usr.password);
        usr.balance = 0;

        // User file storing
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp);

        if(fwrite != 0) {
            printf("\n\nAccount successfully registered!");
        } else {
            printf("\n\nSomething went wrong... please try again.");
        }
    }

    return 0;
}