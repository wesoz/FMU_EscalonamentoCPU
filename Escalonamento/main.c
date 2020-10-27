#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan.h"
#include "process.h"

#define MAIN_MAX_PROCESSES 10
#define MAIN_MIN_PROCESSES 1

Process* processes;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");

	printf("Informe quantos processos serão criados: ");
	int processQuantity;
	scanInt(&processQuantity, MAIN_MIN_PROCESSES, MAIN_MAX_PROCESSES);

	processes = malloc(sizeof(Process) * processQuantity);
	
	free(processes);

	for(int i = 0; i < processQuantity; i++) {
		scanProcess(&processes[i]);
	}

	printf("\n\n");
	system("pause");
	return 0;
}

