#ifndef CSTREAM_H
#define CSTREAM_H
#define BUFFORSIZE 254

enum MODES {
	WITH_SPACE = 1,
	OUT_SPACE = 0,
};


int GetNumberOfElementsInFile(const char* F_PATH, enum MODES Mode);
int GetNumberOfLineInFile(const char* F_PATH);
char ReadFileContent(const char* F_PATH, char DATA[], int Lenght);
void FindWord(const char* F_PATH,const char* WORD);
void FindCharacter(const char* F_PATH, char Character[]);

#endif