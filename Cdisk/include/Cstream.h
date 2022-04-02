#ifndef CSTREAM_H
#define CSTREAM_H
#define BUFFORSIZE 254

enum MODES {
	WITH_SPACE = 1,
	OUT_SPACE = 0,
};

typedef struct Varieble {
	int LineCount;
	int CharCount;
	char DATA[BUFFORSIZE];
}Var;


int GetNumberOfElementsInFile(const char* F_PATH, enum MODES Mode);
int GetNumberOfLineInFile(const char* F_PATH);
char LineRead(const char* F_PATH, char DATA[], int CharCount);
void FindWord(const char* F_PATH,const char* WORD);

#endif