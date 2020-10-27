#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
	char name[16];
	int priority;
	int duration;
	int state;
} Process;

void scanProcess(Process* process);
void printProcess(char *name, char* priority, char* duration, char* state);
void printProcessHeader();
void printProcessBody(char *name, char* priority, char* duration, char* state);
void getState(int state, char* description);

#endif