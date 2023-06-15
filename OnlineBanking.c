#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
    char phone[50];
    char account[50];
    char password[50];
    float balance;
};

int main()
{
    struct user usr;
    FILE *fp;
    char filename[50], phone[50], pword[50];
    int opt, choice;
    char cont = 'y';

    printf("\n What would you you like to do?");
    printf("\n\n1. Register an Account");
    printf("\n2. Login to an account");

    printf("\n\nEnter your choice:\t");
    scanf("%d", &opt);

    if (opt == 1)
    {
        system("clear");
        printf("Enter your account number:\t");
        scanf("%s", usr.account);
        printf("\nEnter your phone number:\t");
        scanf("%s", usr.phone);
        printf("\nEnter your password:\t");
        scanf("%s", usr.password);
        usr.balance = 0.0;
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(usr), 1, fp);
        if (fwrite != 0)
        {
            printf("\n\nAccount created successfully!");
        }
        else
        {
            printf("\n\nError creating account!, Please try again.");
        }
        fclose(fp);
    }

    if (opt == 2)
    {
        system("clear");
        printf("\nEnter your phone number:\t");
        scanf("%s", phone);
        printf("Password: \t");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        if (fp == NULL)
        {
            printf("\nAccount doesn't exist");
        }
        else
        {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(pword, usr.password))
            {
                while(cont == 'y'){
                    system("clear");
                    printf("\nPress 1 to check balance");
                    printf("\nPress 2 to deposit");
                    printf("\nPress 3 to withdraw");
                    printf("\nPress 4 to online transfer");
                    printf("\nPress 5 to change password");
                    printf("\n\nEnter your choice:\t");
                    scanf("%d", &choice);

                    switch(choice){
                        case 1:
                            printf("\nYour balance is: $%.2f", usr.balance);
                            break;

                    }

                    printf("\nDo you want to continue the transaction [y/n]\t");
                    scanf("%s", &cont);
                }
            }
            else
            {
                printf("\nWrong password!");
            }
        }
    }

    return 0;
}