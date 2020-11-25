#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan.h"
#include "process.h"
#include "table.h"

#define MAIN_MAX_PROCESSES 10
#define MAIN_MIN_PROCESSES 1

Process* processes;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");

	TableHeader headers[4];
	headers[0] = createTableHeader(9, "Process");
	headers[1] = createTableHeader(10, "Priority");
	headers[2] = createTableHeader(10, "Duration");
	headers[3] = createTableHeader(9, "State");

	Table table = createTable(3, 4, headers);
	printTable(table);

	Cell cells[4];

	cells[0].value = "P1";
	cells[1].value = "5";
	cells[2].value = "10";
	cells[3].value = STATE_READY_DESC;

	insertTableCells(&table, cells);

	printTable(table);

	printf("Informe quantos processos serão criados: ");
	int processQuantity;
	scanInt(&processQuantity, MAIN_MIN_PROCESSES, MAIN_MAX_PROCESSES);

	processes = malloc(sizeof(Process) * processQuantity);

	for(int i = 0; i < processQuantity; i++) {
		scanProcess(&processes[i]);
	}

	free(processes);

	printf("\n\n");
	system("pause");
	return 0;
}

