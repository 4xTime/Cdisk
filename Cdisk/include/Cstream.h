#ifndef CSTREAM_H
#define CSTREAM_H
#define BUFFORSIZE 256

//GetNumberOfElementsInFile use MODES
enum MODES {
	WITH_SPACE = 1,
	OUT_SPACE = 0,
};

int GetNumberOfElementsInFile(const char* F_PATH, enum MODES Mode);
int GetNumberOfLineInFile(const char* F_PATH);
int ReadFileContent(const char* F_PATH, char DATA[], int Length);
int FindWord(const char* F_PATH, const char* F_WORD);
#endif