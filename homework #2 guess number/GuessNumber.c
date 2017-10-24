#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int searchedNum = 0;
	int usersNum = 0;
	int selector = 0;
	for (;;){
		srand(time(NULL));
		searchedNum = rand() % 10;

		for (i = 0; i < 3; i++){

			for (;;){
				printf("\nEnter positive number between 0 and 10: ");
				int ok = scanf("%d", &usersNum);

				if (ok){
					if (usersNum < 0){
						printf("Oops, your number is negative!");
						continue;
					}
					if (usersNum > searchedNum){
						printf("Lower");
					}
					if (usersNum < searchedNum){
						printf("Bigger");
					}
					break;
				}
				else {
					printf("\n Error! Only digits are allowed");
					fflush(stdin);//clear input buffer
					break;
				}
			}
			if (usersNum == searchedNum){
                printf("\nOur congratulations! You are the best!");
                break;
            }
		}
		selector = getchar();
		printf("\nContinue or exit? y / n: ");
		scanf("%c", &selector);
		if (selector == 'n'){
			return 0;
		}
		continue;
	}
}

