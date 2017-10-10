#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i;
    int j;
    int n;

    printf("Enter the height of the tree: ");
    scanf("%d", &n);
	for (i = 1; i <= n; i++){
		for (j = 0; j < (n - i); j++){
			printf(" ");
		}
		for (j = 0; j < 2 * i - 1; j++){
			printf("*");
		}
		printf("\n");
	}
	for (j = 1; j < n; j++){
			printf(" ");
		}
		printf("*");
	return 0;
}
