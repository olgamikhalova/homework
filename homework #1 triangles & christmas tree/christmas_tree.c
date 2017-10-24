#include <stdio.h>
#include <stdlib.h>

int main()
{
    int height = 0;
    int spaces = 0;
    int stars = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    scanf("%d", &height);

    for (i = 0, spaces = height, stars = -1; i <= height; i++, stars += 2, spaces--){
        for (j = 0; j < spaces; j++){
            printf(" ");
        }

        for (k = 0; k < stars; k++){
            printf("*");
        }

        printf("\n");
    }

    for (i = 0; i < height - 1; i++){
        printf(" ");
    }

    printf("*\n");
    return 0;
}
