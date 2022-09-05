#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include "include/Cstream.h"

int GetNumberOfLineInFile(const char* F_PATH) {
	FILE* File;

	int LineCount = 1;
	char tempchar = 0;

	if (fopen_s(&File, F_PATH, "r") == 0) {
		while (tempchar = fgetc(File)) {
			if (tempchar == '\n') {
				LineCount = LineCount + 1;
			}
			if (feof(File)) { break; }
		}
	}
	else {
		printf("Fail to open a file");
	}
	fclose(File);
	return LineCount;
}

int GetNumberOfElementsInFile(const char* F_PATH, enum MODES Mode) {
	FILE* File;

	char tempchar = 0;
	int CharCount = -1;

	if (fopen_s(&File, F_PATH, "r") == 0) {
		if (Mode == OUT_SPACE) {
			while (tempchar = fgetc(File)) {
				if (tempchar != ' ' && tempchar != '  ' && tempchar != '   ' && tempchar != '    ')
					CharCount = CharCount + 1;
				if (feof(File)) { break; }
			}
		}
		else {
			CharCount = CharCount + 1;
			while (fgetc(File) != EOF) {
				CharCount = CharCount + 1;
			}
		}
	}
	else {
		printf("Fail to open a file");
	}
	fclose(File);
	return CharCount;
}

char ReadFileContent(const char* F_PATH, char DATA[], const int Lenght) {
	FILE* File;
	if (fopen_s(&File, F_PATH, "r") == 0) {
		for (int i = 0; i < (Lenght); i++) {
			if (File != NULL) {
				DATA[i] = fgetc(File);
			}
		}
	}
	else {
		printf("Fail to open a file");
	}
	fclose(File);
	return *DATA;
}


void FindWord(const char* F_PATH, char F_WORD[]) {

	char* WORD = (char*)malloc(strlen(F_WORD));
	WORD = F_WORD;


	char DATA[BUFFORSIZE];
	char Arr[BUFFORSIZE] = { 0 };

	int count = 0;
	int Arr_count = 0;

	ReadFileContent(F_PATH, DATA, GetNumberOfElementsInFile(F_PATH, WITH_SPACE));


	int endPlace = 0;
	int FirstPlace = 0;
	int j = 0;
	for (int i = 0; i < GetNumberOfElementsInFile(F_PATH, WITH_SPACE); i++) {
		if (DATA[i] == WORD[j] && DATA[i + 1] == WORD[j + 1]) {
			endPlace = i;
			Arr[j] = DATA[i];
			j++;
		}
		else { j = 0; }
	}
	FirstPlace = (endPlace - (strlen(WORD) - 1));


	int CharTest = 0;
	for (int i = 0; i < strlen(Arr); i++) {
		if (Arr[i] == WORD[i]) { CharTest++; }
		if (CharTest == (strlen(WORD) - 1)) { printf("Found IT"); }
		printf("%c", Arr[i]);
	}
	WORD = 0;
	free(WORD);
}

void FindCharacter(const char* F_PATH, char Character[]) {


	char* WORD = (char*)malloc(strlen(Character));
	WORD = Character;


	char DATA[BUFFORSIZE];
	char Arr[BUFFORSIZE] = { 0 };

	int count = 0;
	int Arr_count = 0;

	ReadFileContent(F_PATH, DATA, GetNumberOfElementsInFile(F_PATH, WITH_SPACE));


	for (int i = 0; i < GetNumberOfElementsInFile(F_PATH, WITH_SPACE); i++) {
		if (DATA[i] == WORD[count]) {
			for (int j = i; DATA[j] == WORD[count] && j < (i + strlen(WORD)); j++) {
				Arr[Arr_count] = DATA[j];
				count++;
				Arr_count++;
			}
			count = 0;
		}
	}
	for (int i = 0; i < strlen(Arr); i++) {
		printf("%c", Arr[i]);
	}
	WORD = 0;
	free(WORD);
}