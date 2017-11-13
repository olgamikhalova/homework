#include <stdio.h>
#include <stdlib.h>

char* getInputString(char inputedString[]){
    printf("Enter some string: \n");
    scanf("%s", inputedString);
    return inputedString;
}

int getInputKey(int inputedKey){
    printf("Enter key to encrypt or decrypt your string (one decimal number): \n");
    scanf("%d", &inputedKey);
    return inputedKey;
}

void encryptString(char inputedArray[], int inputedKey, int NUMBER_OF_LETTERS_IN_ALPHABET){
    int i = 0;
    for (i = 0; i < strlen(inputedArray); i++){

        inputedArray[i] += (inputedKey + NUMBER_OF_LETTERS_IN_ALPHABET) % NUMBER_OF_LETTERS_IN_ALPHABET;

        if(inputedArray[i] > 'z'){
            inputedArray[i] -= NUMBER_OF_LETTERS_IN_ALPHABET;
        }
    }
    printf("%s\n", inputedArray);
}

void decryptString(char inputedArray[], int inputedKey, int NUMBER_OF_LETTERS_IN_ALPHABET){
    int i = 0;
    for (i = 0; i< strlen(inputedArray); i++){

        inputedArray[i] -= (inputedKey + NUMBER_OF_LETTERS_IN_ALPHABET ) % NUMBER_OF_LETTERS_IN_ALPHABET;

        if(inputedArray[i] < 'a'){
            inputedArray[i] += NUMBER_OF_LETTERS_IN_ALPHABET;
        }
    }
    printf("%s\n", inputedArray);
}

void getMenu(int NUMBER_OF_LETTERS_IN_ALPHABET, int ENCRIPT_STRING, int DECRIPT_STRING, int EXIT, int encodingType, char* inputedString, int inputedKey){

    //for(;;){

        /*printf("\nIf you want encrypt string, enter 1\nIf you want to decrypt string, enter 2\nFor exit, enter 3 \n");
        scanf("%d", &encodingType);*/
        if (encodingType == ENCRIPT_STRING){
            encryptString(inputedString, inputedKey, NUMBER_OF_LETTERS_IN_ALPHABET);
            //continue;
        }
        if (encodingType == DECRIPT_STRING){
            decryptString(inputedString, inputedKey, NUMBER_OF_LETTERS_IN_ALPHABET);
            //continue;
        }
        //if (encodingType == EXIT){
            //return 0;
        //}
    //}
}

int main(int argc, char* argv[]){
    if (argc < 4)
    {
        printf ("Use: caesar_encryption.exe {string} {key} {method}");
        return 1;
    }

    const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
    const int ENCRIPT_STRING = 1;
    const int DECRIPT_STRING = 2;
    const int EXIT = 3;
    int encodingType;
    char enteredString[100000];

    char* inputedString = argv[1];
    int inputedKey = atoi(argv[2]);
    encodingType = atoi(argv[3]);
    strlwr(inputedString);

    //inputedString = getInputString(enteredString);
    //inputedKey = getInputKey(inputedKey);

    getMenu(NUMBER_OF_LETTERS_IN_ALPHABET, ENCRIPT_STRING, DECRIPT_STRING, EXIT, encodingType, inputedString, inputedKey);
}
