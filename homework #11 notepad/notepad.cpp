#include <iostream>
#include <cstdio>
#include <string.h>
#include <limits>
#include <stdlib.h>

using namespace std;

FILE* openFile(char* filePath, char* mode){
    FILE* file = fopen(filePath, mode);
    return file;
}

void writeFile(FILE* file, char* text){
    fputs(text, file);
}

void addNote(FILE* file, char* text){
	char fullNote[52];
	int sz = strlen(text);
	for (int i = 0; i < 51; i++)
	{
		if (i < sz)
			fullNote[i] = text[i];
		else
			fullNote[i] = char(32);
	}
	fullNote[50] = '|';
	fullNote[51] = '\0';
	fseek(file, 0L, SEEK_END);
	fputs(fullNote, file);
}

void editNote(FILE* file, int noteNum){
	int byteCnt = (noteNum - 1) * 51;
	char c;
	char oldNote[52];
	char newNote[52];

	fseek(file, byteCnt, SEEK_SET);
	for (int i = 0; i < 50; i++){
		c = getc(file);
		oldNote[i] = c;
	}
	oldNote[50] = '\0';
	cout << "Old note      : ";
	cout << oldNote << endl;
	cout << "Input new note: ";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.getline(newNote, 52, '\n');
	fseek(file, byteCnt, SEEK_SET);
	fputs(newNote, file);
}

void deleteNote(FILE* file, int noteNum){
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	char newNote[52];
	int byteCnt = (noteNum - 1) * 51;
	char* endNotes = (char*)malloc((size - byteCnt) * sizeof(char));
	char c;

	fseek(file, byteCnt + 51, SEEK_SET);
	for (int i = 0; i < size - byteCnt - 51; i++){
		c = getc(file);
		endNotes[i] = c;
	}
	fseek(file, byteCnt, SEEK_SET);
	endNotes[size - byteCnt - 1] = '\0';
	fputs(endNotes, file);
}

void notepadManager(){
	cout << "Welcome to notepad!\n\n";

	cout << "Select an action:" << endl;
	cout << "1. Show notes\n";
	cout << "2. Add notes\n";
	cout << "3. Edit note\n";
	cout << "4. Delete note\n";
	cout << "5. Exit\n";

	int select = 0;
	int n, i=0;

	FILE* file;
	char line[256];
	char c;
	char note[52];
	int quitting = 0;

	do{
		cin >> select;

		switch (select){
		case 1:
			file = openFile("notepad.txt", "r");
			c = getc(file);

			while (c != EOF)
			{
				printf("%c", c);
				c = getc(file);
			}

			fclose(file);
			break;

		case 2: {
		    file = openFile("notepad.txt", "a");
			printf("Input a note: ");
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.getline(note, 52, '\n');
			addNote(file, note);

			fclose(file);
			break;
		}

		case 3:
			file = openFile("notepad.txt", "r+");
			printf(" Input the number of note to edit: ");
			scanf("%d", &n);

			editNote(file, n);
			fclose(file);
			break;

		case 4:
			file = openFile("notepad.txt", "r+");
			printf(" Input the number of note to delete: ");
			scanf("%d", &n);
			deleteNote(file, n);
			fclose(file);
			break;

		default:
			break;
		}
	} while (select != 5);
}

int main()
{
    notepadManager();
    return 0;
}
