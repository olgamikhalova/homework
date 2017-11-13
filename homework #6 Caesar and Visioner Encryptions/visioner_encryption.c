#include <stdio.h>
#include <stdlib.h>


void encryptString(char inputedArray[], char key[], int ASCII_START_OF_ALPHABET, int NUMBER_OF_LETTERS_IN_ALPHABET, int ALL_CHARS_EXCEPT_LETTERS){
    int i = 0;
    int j = 0;
    for (i = 0; i < strlen(inputedArray); i++, j++){
        if(j > strlen(key) - 1){
            j = 0;
        }

        inputedArray[i] += (key[j] - ASCII_START_OF_ALPHABET + NUMBER_OF_LETTERS_IN_ALPHABET) % NUMBER_OF_LETTERS_IN_ALPHABET;

        if(inputedArray[i] > 'z'){
            inputedArray[i] -= NUMBER_OF_LETTERS_IN_ALPHABET;
        }

        if (inputedArray[i] < 0){
            inputedArray[i] += ALL_CHARS_EXCEPT_LETTERS;
        }
    }
    printf("%s\n", inputedArray);
}

void decryptString(char inputedArray[], char key[], int ASCII_START_OF_ALPHABET, int NUMBER_OF_LETTERS_IN_ALPHABET, int ALL_CHARS_EXCEPT_LETTERS){
    int i = 0;
    int j = 0;
    for (i = 0; i< strlen(inputedArray); i++, j++){
        if(j > strlen(key) - 1){
            j = 0;
        }
        inputedArray[i] -= (key[j] - ASCII_START_OF_ALPHABET + NUMBER_OF_LETTERS_IN_ALPHABET ) % NUMBER_OF_LETTERS_IN_ALPHABET;

        if(inputedArray[i] < 'a'){
            inputedArray[i] += NUMBER_OF_LETTERS_IN_ALPHABET;
        }
        if (inputedArray[i] < 0){
            inputedArray[i] += ALL_CHARS_EXCEPT_LETTERS ;
        }
    }
    printf("%s\n", inputedArray);
}

void getMenu(int NUMBER_OF_LETTERS_IN_ALPHABET, int ENCRIPT_STRING, int DECRIPT_STRING, int ASCII_START_OF_ALPHABET, int ALL_CHARS_EXCEPT_LETTERS, int EXIT, int encodingType, char* enteredString, int key){
    //for(;;){

        /*printf("\nIf you want encrypt string, enter 1\nIf you want to decrypt string, enter 2\nFor exit, enter 3 \n");
        scanf("%d", &encodingType);*/
        if (encodingType == ENCRIPT_STRING){
            encryptString(enteredString, key, ASCII_START_OF_ALPHABET, NUMBER_OF_LETTERS_IN_ALPHABET, ALL_CHARS_EXCEPT_LETTERS);
           // continue;
        }
        if (encodingType == DECRIPT_STRING){
            decryptString(enteredString, key, ASCII_START_OF_ALPHABET, NUMBER_OF_LETTERS_IN_ALPHABET, ALL_CHARS_EXCEPT_LETTERS);
           // continue;
        }
        /*if (encodingType == EXIT){
            return 0;
        }
    }*/
}

int main(int argc, char* argv[]){

    if (argc < 4)
    {
        printf ("Use: visioner_encryption.exe {string} {key} {method}");
        return 1;
    }

    const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
    const int ASCII_START_OF_ALPHABET = 96;
    const int ALL_CHARS_EXCEPT_LETTERS = 230;
    const int ENCRIPT_STRING = 1;
    const int DECRIPT_STRING = 2;
    const int EXIT = 3;
    char* key;
    int encodingType;

    /*printf("Enter some string here:\n");
    scanf("%s", &enteredString);
    printf("Enter keyword to encrypt or decrypt your string:\n");
    scanf("%s", &key);*/
    char* enteredString;

    enteredString = argv[1];
    key = argv[2];
    encodingType = atoi(argv[3]);

    strlwr(enteredString);

    getMenu(NUMBER_OF_LETTERS_IN_ALPHABET, ENCRIPT_STRING, DECRIPT_STRING, ASCII_START_OF_ALPHABET, ALL_CHARS_EXCEPT_LETTERS, EXIT, encodingType, enteredString, key);
}
