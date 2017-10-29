#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
    const int SIZE_OF_ENTERED_STRING = 1000000;
    char alphabetArray[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char enteredStringArray[1000000];
	char onlyLettersStringArray[1000000];
	char temp1;
    int temp;
    int numberOfLettersArray[26];
    int i = 0;
    int j = 0;
    int x = 0;

    char* enteredString = (char*)malloc(SIZE_OF_ENTERED_STRING * sizeof(char));

    for(i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++){
        numberOfLettersArray[i] = 0;
    }

    printf("Enter some string: \n");
    scanf("%[^\r\n]", enteredStringArray);
    strlwr(enteredStringArray);
    //comparing arrays and clearing the finished string from non-letters
	for (i = 0; i < strlen(enteredStringArray); i++){
        for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
            if(enteredStringArray[i] == alphabetArray[j]){
                onlyLettersStringArray[x] = enteredStringArray[i];
                x++;
            }
        }
    }
    //count of letters in the only-letters-array
    for(i = 0; i < strlen(onlyLettersStringArray); i++){
        for (j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
            if(onlyLettersStringArray[i] == alphabetArray[j]){
                numberOfLettersArray[j]++;
                break;
            }
        }
    }
    //bubble sorting of arrays
    for (i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET - 1; i++){
        for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET - 1 - i; j++){
                if(numberOfLettersArray[j] < numberOfLettersArray[j+1]){
                    temp1 = alphabetArray[j];
                    alphabetArray[j] = alphabetArray[j+1];
                    alphabetArray[j+1] = temp1;

                    temp = numberOfLettersArray[j];
                    numberOfLettersArray[j] = numberOfLettersArray[j+1];
                    numberOfLettersArray[j+1] = temp;
                }
        }
    }

    for(i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++){
        if(numberOfLettersArray[i] == 0){
            continue;
        }
        printf("%c - %d\n", alphabetArray[i], numberOfLettersArray[i]);
    }
    free(enteredString);

    return 0;
}
