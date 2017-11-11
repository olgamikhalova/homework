#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char* getInputString(int SIZE_OF_ENTERED_STRING){
    char* inputedArray = (char*) malloc(SIZE_OF_ENTERED_STRING * sizeof(char));
    printf("Enter some string: \n");
    scanf("%[^\r\n]", inputedArray);
    strlwr(inputedArray);
    return inputedArray;
}

int countWords(char* enteredStringArray, int SIZE_OF_ENTERED_STRING, int NUMBER_OF_LETTERS_IN_ALPHABET, char* allLettersArray){
    int i = 0;
    int j = 0;
    int flag = -1;
    int words = 0;
        for(i = 0; i < strlen(enteredStringArray); i++){
            if (flag == 1){
                for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
                    if(enteredStringArray[i] == allLettersArray[j]){
                        break;
                    }
                }
                if (j == NUMBER_OF_LETTERS_IN_ALPHABET){
                    flag = -1;
                }
            }
            if (flag == -1){
                for(j = 0; j < NUMBER_OF_LETTERS_IN_ALPHABET; j++){
                    if(enteredStringArray[i] == allLettersArray[j]){
                        flag = 1;
                        words++;
                    }
                }
            }
        }
    return words;
}

int main(){
    const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
    const int SIZE_OF_ENTERED_STRING = 1000000;
    char allLettersArray[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	char* enteredString = (char*)malloc(SIZE_OF_ENTERED_STRING * sizeof(char));

	char* enteredStringArray = getInputString(SIZE_OF_ENTERED_STRING);
    printf("%d\n", countWords(enteredStringArray, SIZE_OF_ENTERED_STRING, NUMBER_OF_LETTERS_IN_ALPHABET, allLettersArray));
	free(enteredString);
}
