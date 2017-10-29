#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
    char allLettersArray[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char stringArray[1000000];
    int flag = -1;
	int words = 0;
	int i = 0;
	int j = 0;

	printf("Enter some string: \n");
    scanf("%[^\r\n]", stringArray);
    strlwr(stringArray);

    for(i = 0; i < strlen(stringArray); i++){
        if (flag == 1){
            for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
                if(stringArray[i] == allLettersArray[j]){
                    break;
                }
            }
        if (j == NUMBER_OF_LETTERS_IN_ALPHABET){
            flag = -1;
        }
        }
        if (flag == -1){
            for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
                if(stringArray[i] == allLettersArray[j]){
                    flag = 1;
                    words++;
                }
            }
        }
    }
	printf("%d\n", words);
    return 0;
}
