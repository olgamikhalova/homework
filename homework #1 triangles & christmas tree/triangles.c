#include <stdio.h>
#include <stdlib.h>

int main()
{
    int height = 0;
    int j = 0;
    int k = 0;

    printf("Enter the height of triangle: \n");
    scanf("%d", &height);

    for (j = 0; j < height; j++){//triangle from min to max
        for (k = 0; k <= j; k++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (j = 0; j < height; j++){//triangle from max to min
        for (k = j; k < height; k++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
