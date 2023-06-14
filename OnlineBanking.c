#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user
{
    char phone[50];
    char account[50];
    char password[50];
    float balance;
};


int main(){
    struct user usr;
    int opt;

    printf("\n What would you you like to do?");
    printf("\n\n1. Register an Account");
    printf("\n2. Login to an account");

    printf("\n\nEnter your choice:\t");
    scanf("%d", &opt);

    if(opt == 1){
        system("clear");
        printf("Enter your account number:\t");
        scanf("%s", usr.account);
        printf("\nEnter your phone number:\t");
        scanf("%s", usr.phone);
    }

    return 0;
}