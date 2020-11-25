#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scan.h"

// Process
#define SCANPROCESS_REQUEST_NAME "Digite o nome do processo"
#define SCANPROCESS_REQUEST_PRIORITY "Digite a prioridade do processo"
#define SCANPROCESS_MIN_PRIORITY 1
#define SCANPROCESS_MAX_PRIORITY 20
#define SCANPROCESS_REQUEST_DURATION "Digite a duracao do processo"
#define SCANPROCESS_MIN_DURATION 1
#define SCANPROCESS_MAX_DURATION 100

// States
#define STATE_READY 1
#define STATE_BLOCKED 2
#define STATE_RUNNING 3



void scanProcess(Process* process) {

	char priority[(sizeof(int)*8+1)];
	char duration[(sizeof(int)*8+1)];

	process->state = STATE_READY;
	char state[256];
	getState(process->state, state);

	system("cls");
	printProcess("", "", "", state);

	printf("%s:", SCANPROCESS_REQUEST_NAME);
	scanf("%[^\n]s", process->name);
	
	system("cls");
	printProcess(process->name, "", "", state);

	int readValue;

	printf("%s:", SCANPROCESS_REQUEST_PRIORITY);
	scanInt(&process->priority, SCANPROCESS_MIN_PRIORITY, SCANPROCESS_MAX_PRIORITY);
	
	itoa(process->priority, priority, 10);
	system("cls");
	printProcess(process->name, priority, "", state);

	printf("%s:", SCANPROCESS_REQUEST_DURATION);
	scanInt(&process->duration, SCANPROCESS_MIN_DURATION, SCANPROCESS_MAX_DURATION);
	
	itoa(process->duration, duration, 10);
	system("cls");
	printProcess(process->name, priority, duration, state);

}

void getState(int state, char* description) {
	switch(state) {
		case STATE_READY:
			strcpy(description, STATE_READY_DESC);
			break;
		case STATE_BLOCKED:
			strcpy(description, STATE_BLOCKED_DESC);
			break;
		case STATE_RUNNING:
			strcpy(description, STATE_RUNNING_DESC);
			break;
	}
}

void printProcessHeader() {
	printf("\n ===========================================");
	printf("\n | Process | Priority | Duration |  State  |");
	printf("\n ===========================================\n");
}

void printProcessBody(char *name, char* priority, char* duration, char* state) {

	int nameLen = strlen(name);
	int priorityLen = strlen(priority);
	int durationLen = strlen(duration);
	int stateLen = strlen(state);

	printf(" |%s", name);
	for(int i = 0; i < 9 - nameLen; i++) printf(" ");

	printf("|%s", priority);
	for(int i = 0; i < 10 - priorityLen; i++) printf(" ");

	printf("|%s", duration);
	for(int i = 0; i < 10 - durationLen; i++) printf(" ");

	printf("|%s", state);
	for(int i = 0; i < 9 - stateLen; i++) printf(" ");

	printf("|\n");
	printf(" -------------------------------------------\n\n");
}

void printProcess(char *name, char* priority, char* duration, char* state) {
	printProcessHeader();
	printProcessBody(name, priority, duration, state);
}