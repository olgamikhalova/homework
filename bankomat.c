#include <stdio.h>
#include <stdlib.h>

int main()
{
    int account[5000];
    int pin_mass[5000];
    int pin = 0;
    int i = 0;
    int operation = 0;
    int payment = 0;
    const int ADMIN = 0000;
    int adminOperation = 0;

    for (i = 0; i < 5000; i++){
        pin_mass[i] = 0000 + i;
    }

    for (i = 0; i < 5000; i++){
        account[i] = 100 * i;
    }

    for (i = 0; i < 3; i++){
        printf("Enter your pin-code: \n");
        int ok = scanf("%d", &pin);

        if (ok){
            if (pin < 5000){
            break;
            }
            if (pin >= 5000){
            printf("Wrong pin, try again \n");
            }
        } else {
            printf("Error! Only digits are allowed\n");
            fflush(stdin);
            i--;
        }
    }

    i = 0;
    if (pin == ADMIN){
        printf("Hello, Admin!\n");
        for (;;){
            printf("If you want to see the balance on all accounts, press 1\n");
            printf("If you want to zero all balances, press 2\n");
            printf("If you want to exit, press 3\n");
            scanf("%d", &adminOperation);

            switch(adminOperation){
                    case 1:
                        for (i = 0; i < 5000; i++){
                            printf("%d\n", account[i]);
                            }
                            break;
                    case 2:
                        for (i = 0; i < 5000; i++){
                            account[i] = 0;
                            }
                            break;
                    case 3:
                            return 0;
            }
        }
    }

    i = 0;
    for (;;){
        for (i = 0; i < 5000 && pin!= 0000; i++){
            if (pin_mass[i] == pin){
                printf("If you want to check the balance, press 1\n");
                printf("If you want to deposit money, press 2\n");
                printf("If you want to withdraw money, press 3\n");
                printf("If you want to exit, press 4\n");
                scanf("%d", &operation);

                switch(operation){
                    case 1:
                        printf("On your account: %d\n", account[i]);
                        break;
                    case 2:
                        printf("Enter payment: \n");
                        scanf("%d", &payment);
                        account[i] = account[i] + payment;
                        printf("On your account: %d\n", account[i]);
                        break;
                    case 3:
                        printf("How much do you want to withdraw? \n");
                        scanf("%d", &payment);
                        account[i] = account[i] - payment;
                        break;
                    case 4:
                        return 0;
                }
            }
        }
    }
        return 0;
}
