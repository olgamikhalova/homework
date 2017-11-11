#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* createNumberOfLettersArray(int NUMBER_OF_LETTERS_IN_ALPHABET){
    int i = 0;
    int* array = (int*)malloc(NUMBER_OF_LETTERS_IN_ALPHABET * sizeof(int));
	for (i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++){
		array[i] = 0;
	}
	return array;
}

char* getInputString(int SIZE_OF_ENTERED_STRING){
    int i = 0;
    char* enteredString = (char*) malloc(SIZE_OF_ENTERED_STRING * sizeof(char));
    printf("Enter some string: \n");
    scanf("%[^\r\n]", enteredString);
    strlwr(enteredString);
    return enteredString;
}

char* getOnlyLettersStringArray(int NUMBER_OF_LETTERS_IN_ALPHABET, char* alphabetArray, char* inputedStringArray, int SIZE_OF_ENTERED_STRING){
    int i = 0;
    int j = 0;
    int x = 0;
    char* onlyCharsStringArray = (char*) malloc(SIZE_OF_ENTERED_STRING * sizeof(char));
    for (i = 0; i < strlen(inputedStringArray); i++){
        for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
            if(inputedStringArray[i] == alphabetArray[j]){
                onlyCharsStringArray[x] = inputedStringArray[i];
                x++;
            }
        }
    }
    return onlyCharsStringArray;
}

void countChars(char* lettersStringArray, int NUMBER_OF_LETTERS_IN_ALPHABET, char* alphabetArray, int* countOfLettersArray){
    int i = 0;
    int j = 0;
    for(i = 0; i < strlen(lettersStringArray); i++){
        for (j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
            if(lettersStringArray[i] == alphabetArray[j]){
                countOfLettersArray[j]++;
                break;
            }
        }
    }
}

void sort(int NUMBER_OF_LETTERS_IN_ALPHABET, int* countOfLettersArray, char* alphabetArray){
    int i = 0;
    int j = 0;
    int temp = 0;
    int temp1 = 0;
    for (i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET - 1; i++){
        for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET - 1 - i; j++){
                if(countOfLettersArray[j] < countOfLettersArray[j+1]){
                    temp1 = alphabetArray[j];
                    alphabetArray[j] = alphabetArray[j+1];
                    alphabetArray[j+1] = temp1;

                    temp = countOfLettersArray[j];
                    countOfLettersArray[j] = countOfLettersArray[j+1];
                    countOfLettersArray[j+1] = temp;
                }
        }
    }
}

void showResult(int NUMBER_OF_LETTERS_IN_ALPHABET, int* countOfLettersArray, char* alphabetArray){
    int i = 0;
    for(i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++){
        if(countOfLettersArray[i] == 0){
            continue;
        }
        printf("%c - %d\n", alphabetArray[i], countOfLettersArray[i]);
    }
}

int main(){
    const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
    const int SIZE_OF_ENTERED_STRING = 1000000;
    char alphabetArray[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char enteredStringArray[1000000];

    char* enteredString = (char*)malloc(SIZE_OF_ENTERED_STRING * sizeof(char));

    int* countOfLettersArray = createNumberOfLettersArray(NUMBER_OF_LETTERS_IN_ALPHABET);
    char* inputedStringArray = getInputString(SIZE_OF_ENTERED_STRING);
    char* lettersStringArray = getOnlyLettersStringArray(NUMBER_OF_LETTERS_IN_ALPHABET, alphabetArray, inputedStringArray, SIZE_OF_ENTERED_STRING);
    countChars(lettersStringArray, NUMBER_OF_LETTERS_IN_ALPHABET, alphabetArray, countOfLettersArray);
    sort(NUMBER_OF_LETTERS_IN_ALPHABET, countOfLettersArray, alphabetArray);
    showResult(NUMBER_OF_LETTERS_IN_ALPHABET, countOfLettersArray, alphabetArray);

    free(enteredString);
}
