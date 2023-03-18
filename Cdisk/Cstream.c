#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include "include/Cstream.h"

int GetNumberOfLineInFile(const char* F_PATH) {
	FILE* File;

	int LineCount = 1;
	int tempchar = 0;

	if (fopen_s(&File, F_PATH, "r") != 0) {
		printf("Cannot open file %s.\n", F_PATH);
		return -1;
	}

	while ((tempchar = fgetc(File)) != EOF) {
		if (tempchar == '\n') {
			LineCount = LineCount + 1;
		}


	}

	if (ferror(File)) {
		printf("An error occurred while reading the file");
		fclose(File);
		return -1;
	}
	fclose(File);
	return LineCount;
}

int GetNumberOfElementsInFile(const char* F_PATH, enum MODES Mode) {
	FILE* File;

	int tempchar;
	int CharCount = 0;

	if (fopen_s(&File, F_PATH, "r") != 0) {
		printf("Cannot open file %s.\n", F_PATH);
		return -1;
	}

	if (Mode == OUT_SPACE) {
		while ((tempchar = fgetc(File)) != EOF) {
			//For OUT_SPACE checknig white characters (max 4) 
			if (tempchar != ' ' && tempchar != '  ' && tempchar != '   ' && tempchar != '    ')
				CharCount = CharCount + 1;
		}
	}
	else if (Mode == WITH_SPACE) {
		//WITH_SPACE mode get all elements
		//CharCount = CharCount + 1;
		while (fgetc(File) != EOF) {
			CharCount = CharCount + 1;
		}
	}

	fclose(File);
	return CharCount - 1;
}

int ReadFileContent(const char* F_PATH, char DATA[], const int Length) {
	FILE* File;
	if (fopen_s(&File, F_PATH, "r") != 0) {
		printf("Cannot open file %s.\n", F_PATH);
		return -1;
	}
	int i = 0;
	while (i < Length && File != NULL && !feof(File)) {
		DATA[i] = fgetc(File);
		i++;
	}
	fclose(File);
	return 0;
}

int FindWord(const char* F_PATH, const char* F_WORD) {

	int num_elements = GetNumberOfElementsInFile(F_PATH, WITH_SPACE);

	// Allocating memory for WORD 
	char* WORD = (char*)malloc(strlen(F_WORD) + 1);
	if (WORD != NULL) {
		strcpy_s(WORD, (strlen(F_WORD) + 1), F_WORD);
	}
	else {
		fprintf(stderr, "Memory allocation error for WORD in FindWord()\n");
		return -1;
	}
	//DATA for entire File content
	//new decleration of DATA as a char*
	char* DATA = (char*)malloc(num_elements);
	if (DATA == NULL) {
		free(WORD);
		return;
	}
	//Arr for searching word
	char* Arr = (char*)malloc(num_elements);
	if (DATA == NULL) {
		free(WORD);
		free(DATA);
		return;
	}

	//assigning file content to DATA
	ReadFileContent(F_PATH, DATA, num_elements);

	int j = 0;
	int POS = 0;
	int LineNum = 0;
	int Break = 0;
	//Searching for word and place it into Arr
	for (int i = 0; i < num_elements; i++) {
		if (DATA[i] == '\n') { LineNum++; }
		if (i + 1 < num_elements && DATA[i] == WORD[j] && DATA[i + 1] == WORD[j + 1]) {
			Arr[j] = DATA[i];
			j++;
		}
		else { j = 0; }
	}
	//Temp var to store result
	char* TempVar = (char*)malloc(strlen(WORD) + 1);
	if (TempVar == NULL) {
		free(WORD);
		free(DATA);
		free(Arr);
		return;
	}
	//Copying Arr to TempVar
	strncpy_s(TempVar, (strlen(WORD) + 1), Arr, strlen(WORD) - 1);


	int Positive = 0;
	for (int i = 0; i < strlen(F_WORD + 1); i++) {
		if (TempVar[i] == F_WORD[i]) {
			Positive++;
		}
	}

	free(WORD);
	free(DATA);
	free(Arr);
	free(TempVar);

	if (Positive == strlen(F_WORD) - 1) {
		return 1;
	}
	else {
		return 0;
	}

}
