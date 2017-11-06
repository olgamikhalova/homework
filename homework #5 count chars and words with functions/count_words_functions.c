#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
const int SIZE_OF_ENTERED_STRING = 1000000;
char allLettersArray[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char stringArray[1000000];
int numberOfWords = 0;
int flag = -1;
int i = 0;
int j = 0;

char* getInputString()
{
    printf("Enter some string: \n");
    scanf("%[^\r\n]", stringArray);
    strlwr(stringArray);
    return stringArray;
}

int checkFlagTrue()
{
        for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
            if(stringArray[i] == allLettersArray[j]){
                break;
            }
        }
        if (j == NUMBER_OF_LETTERS_IN_ALPHABET){
            flag = -1;
        }
    return flag;
}
int checkFlagFalse()
{
    for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
            if(stringArray[i] == allLettersArray[j]){
                flag = 1;
                numberOfWords++;
            }
        }
        return flag;
}

int* countWords()
{
        for(i = 0; i < strlen(stringArray); i++){
            if (flag == 1){
                int* flag = checkFlagTrue();
            }
        if (flag == -1){
            int* flag = checkFlagFalse();
        }
    }
    return numberOfWords;
}

int main()
{
	char* enteredString = (char*)malloc(SIZE_OF_ENTERED_STRING * sizeof(char));

	char* stringArray = getInputString();
	printf("%d\n", countWords());
	free(enteredString);
}
