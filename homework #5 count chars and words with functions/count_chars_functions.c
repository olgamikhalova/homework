#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
const int SIZE_OF_ENTERED_STRING = 1000000;
char alphabetArray[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char enteredStringArray[1000000];
char onlyLettersStringArray[1000000];
int numberOfLettersArray[26];
char temp1;
int temp;
int i = 0;
int j = 0;
int x = 0;

int* createNumberOfLettersArray()
{
	for (i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++){
		numberOfLettersArray[i] = 0;
	}
	return numberOfLettersArray;
}

char* getInputString()
{
    printf("Enter some string: \n");
    scanf("%[^\r\n]", enteredStringArray);
    strlwr(enteredStringArray);
    return enteredStringArray;
}

char* getOnlyLettersStringArray()
{
    for (i = 0; i < strlen(enteredStringArray); i++){
        for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
            if(enteredStringArray[i] == alphabetArray[j]){
                onlyLettersStringArray[x] = enteredStringArray[i];
                x++;
            }
        }
    }
    return onlyLettersStringArray;
}

void countChars()
{
    for(i = 0; i < strlen(onlyLettersStringArray); i++){
        for (j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
            if(onlyLettersStringArray[i] == alphabetArray[j]){
                numberOfLettersArray[j]++;
                break;
            }
        }
    }
}

void sort()
{
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
}

void showResult()
{
    for(i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++){
        if(numberOfLettersArray[i] == 0){
            continue;
        }
        printf("%c - %d\n", alphabetArray[i], numberOfLettersArray[i]);
    }
}

int main()
{
    char* enteredString = (char*)malloc(SIZE_OF_ENTERED_STRING * sizeof(char));

    int* numberOfLettersArray = createNumberOfLettersArray();
    char* enteredStringArray = getInputString();
    char* onlyLettersStringArray = getOnlyLettersStringArray();
    countChars();
    sort();
    showResult();

    free(enteredString);
}
