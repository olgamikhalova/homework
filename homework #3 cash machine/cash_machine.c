#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int ADMIN_PIN = 0000;
    const int ATTEMPTS_ENTER_PIN = 3;
    const int NUMBER_OF_ACCOUNTS_AND_PINS = 5000;
    const int ACCOUNT_MULTIPLIER = 100;
    int accountsArray[5000];
    int pinsArray[5000];
    int userPin = 0;
    int moneyOperation = 0;
    int userPayment = 0;
    int adminOperation = 0;
    int i = 0;

    for (i = 0; i < NUMBER_OF_ACCOUNTS_AND_PINS; i++){
        pinsArray[i] = ADMIN_PIN + i;
    }

    for (i = 0; i < NUMBER_OF_ACCOUNTS_AND_PINS; i++){
        accountsArray[i] = ACCOUNT_MULTIPLIER * i;
    }

    for (i = 0; i < ATTEMPTS_ENTER_PIN; i++){
        printf("Enter your pin-code: \n");
        int ok = scanf("%d", &userPin);

        if (ok){
            if (userPin < 0){
                printf("You entered negative pin, try again \n");
                continue;
            }
            if (userPin < NUMBER_OF_ACCOUNTS_AND_PINS){
                break;
            }
            if (userPin >= NUMBER_OF_ACCOUNTS_AND_PINS){
                printf("Wrong pin, try again \n");
            }
        } else {
            printf("Error! Only digits are allowed\n");
            fflush(stdin);
            i--;
        }
    }

    i = 0;
    if (userPin == ADMIN_PIN){
    for (;;){
            printf("Hello, Admin!\n");
            printf("If you want to see the balance on all accounts, press 1\n");
            printf("If you want to zero all balances, press 2\n");
            printf("If you want to exit, press 3\n");
            scanf("%d", &adminOperation);

            switch(adminOperation){
                    case 1:
                        for (i = 0; i < NUMBER_OF_ACCOUNTS_AND_PINS; i++){
                            printf("%d\n", accountsArray[i]);
                            }
                            break;
                    case 2:
                        for (i = 0; i < NUMBER_OF_ACCOUNTS_AND_PINS; i++){
                            accountsArray[i] = 0;
                            }
                            break;
                    case 3:
                            return 0;
                    }
        }
    }

    i = 0;
    for (;;){
        for (i = 0; i < NUMBER_OF_ACCOUNTS_AND_PINS && userPin != ADMIN_PIN; i++){
            if (pinsArray[i] == userPin){
                printf("\nIf you want to check the balance, press 1\n");
                printf("If you want to deposit money, press 2\n");
                printf("If you want to withdraw money, press 3\n");
                printf("If you want to exit, press 4\n");
                scanf("%d", &moneyOperation);

                switch(moneyOperation){
                    case 1:
                        printf("On your account: %d\n", accountsArray[i]);
                        break;
                    case 2:
                        printf("Enter payment: \n");
                        scanf("%d", &userPayment);
                        accountsArray[i] = accountsArray[i] + userPayment;
                        printf("On your account: %d", accountsArray[i]);
                        break;
                    case 3:
                        printf("How much do you want to withdraw? \n");
                        scanf("%d", &userPayment);
                        accountsArray[i] = accountsArray[i] - userPayment;
                        break;
                    case 4:
                        return 0;
                }
            }
        }
    }
        return 0;
}
