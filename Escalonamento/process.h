#ifndef PROCESS_H
#define PROCESS_H

#define STATE_READY_DESC "Pronto"
#define STATE_BLOCKED_DESC "Espera"
#define STATE_RUNNING_DESC "Execução"

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