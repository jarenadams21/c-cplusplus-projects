#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Online Banking System Project in C ~ ADV. LEARNING 

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

    // Users for application
    struct user usr, transferUser;

    // Store users in a file
    FILE *fp;
    char filename[50];

    // Current user phone number and password
    char phone[50], pword[50];

    // User option selections
    int opt, choice;

    // Continue?
    char cont = 'y';

    // Amount to deposit
    float amount;

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
        // .dat files are used by applications
        //  DAT files contain binary text
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp);

        if(fwrite != 0) {
            printf("\n\nAccount successfully registered!");
        } else {
            printf("\n\nSomething went wrong... please try again.");
        }
        // Close the file after opening
        fclose(fp);
    }
    if(opt == 2) {
        system("clear");
        printf("\nEnter your phone number:\t ");
        scanf("%s", phone);
        printf("Enter your password:\t ");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");

        // Validate account was created in first place
        if(fp == NULL) {
            printf("\nAccount number not registered");
        }
        else {
        // Read the content of filename, and store it in this user
        fread(&usr, sizeof(struct user), 1, fp);
        fclose(fp);

        // Successfull login
        if(!strcmp(pword, usr.password)) {
            printf("\n\tWelcome %s\n", usr.phone);
            while(cont == 'y') {
                system("clear");
                printf("\nPress 1 to check balance");
                printf("\nPress 2 to deposit an amount");
                printf("\nPress 3 to withdraw");
                printf("\nPress 4 to transfer the balance");
                printf("\nPress 5 to change the password");
                printf("\n\nYour choice:\t");
                scanf("%d", &choice);

                switch(choice) {
                    case 1: 
                        printf("\nYour current balance is %f", usr.balance);
                        break;
                    case 2:
                        printf("\nEnter an amount to deposit:\t");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if(fwrite != NULL) printf("\nSuccessfully deposited.");
                        fclose(fp);
                        break;
                    case 3:
                        printf("\nEnter an amount to withdraw:\t");
                        scanf("%f", &amount);
                        usr.balance -= amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if(fwrite != NULL) printf("\nSuccessfully withdrawn.");
                        fclose(fp);
                        break;
                        // 27:50
                    case 4:
                        printf("\nPlease enter the phone number to transfer the balance:\t");
                        scanf("%s", phone);
                        printf("\nPlease enter the amount to transfer:\t");
                        scanf("%f", &amount);
                        if(amount > usr.balance) printf("\nInsuffienct balance...");
                        else {
                            strcpy(filename, phone);
                            fp = fopen(strcat(filename, ".dat"), "r");
                            // Invalid phone number?
                            if(fp == NULL) {
                                printf("\nPhone number not registered in system.");
                                return 0;
                            }

                            fread(&transferUser, sizeof(struct user), 1, fp);
                            fclose(fp);
                            transferUser.balance += amount;
                            fp = fopen(filename, "w");
                            fwrite(&transferUser, sizeof(struct user), 1, fp);

                            fclose(fp);
                            if(fwrite != NULL) {
                                printf("\n You have successfully transferred the amount.");
                                strcpy(filename, usr.phone);
                                fp = fopen(strcat(filename, ".dat"), "w");
                                usr.balance -= amount;
                                fwrite(&usr, sizeof(struct user), 1, fp);
                                fclose(fp);
                            }
                           
                        }
                        break;

                    case 5:
                        printf("\nPlease enter your new password:\t");
                        scanf("%s", pword);
                        fp = fopen(filename, "w");
                        strcpy(usr.password, pword);
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if(fwrite != NULL) {
                             printf("\nPassword successfully changed.");
                        }
                        break;
                    default:
                        printf("\nInvalid option selected...");
                }

                printf("\nDo you want to continue the transaction [y/n]");
                scanf("%s", &cont);
            }
        } else {
            printf("\nInvalid password");
        }
    }

    }

    return 0;
}