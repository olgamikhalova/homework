#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    printf("Enter number of steps: \n");
    scanf("%d", &i);
    while(j < i){
            while(k <= j) {
                printf("*");
                k++;
            }
        printf("\n");
        k = 0;
        j++;
    }
    printf("\n");
    printf("\n");

    j = 0;
    while(j < i){
        while(k < i){
            printf("*");
            k++;
        }
        printf("\n");
        j++;
        k = j;
    }

    return 0;
}
