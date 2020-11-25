#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

#define TABLE_CELL_SEPARATOR "|"
#define TABLE_HEADER_CHAR "="
#define TABLE_FOOTER_CHAR "-"

Cell createCell(int maxLength, char *value) {
	Cell cell;
	cell.maxLength = maxLength;
	cell.value = value;
	return cell;
}

Table createTable(int colCount, int rowCount, Cell *headers) {
	Table table;
	table.rowCount = rowCount;
	table.colCount = colCount;
	table.cursor = 1;
	table.cells = (Cell**)malloc(sizeof(Cell*) * rowCount);
	for (int r = 0; r < rowCount; r++) {
		table.cells[r] = (Cell*)malloc(sizeof(Cell) * colCount);
		for (int c = 0; c < colCount; c++) {
			table.cells[r][c].maxLength = headers[c].maxLength;
			table.cells[r][c].value = (char*)malloc(sizeof(char) * headers[c].maxLength);
			if (r == 0) {
				table.cells[r][c].value = headers[c].value;
			}
		}
	}
	return table;
}

void printHeader(Table table) {
	/* Header Separator */
	printf(TABLE_HEADER_CHAR);
	for (int c = 0; c < table.colCount; c++)
	{
		for (int i = 0; i <= table.cells[0][c].maxLength; i++)
		{
			printf(TABLE_HEADER_CHAR);
		}
	}

	/* Header Names */
	printf("\n");
	printf("%s", TABLE_CELL_SEPARATOR);
	for (int c = 0; c < table.colCount; c++) {
		printf(" %s %s", table.cells[0][c].value, TABLE_CELL_SEPARATOR);
	}
	printf("\n");

	/* Header Separator */
	printf(TABLE_HEADER_CHAR);
	for (int c = 0; c < table.colCount; c++)
	{
		for (int i = 0; i <= table.cells[0][c].maxLength; i++)
		{
			printf(TABLE_HEADER_CHAR);
		}
	}
	printf("\n");	
}

void printFooter(Table table) {
	/* Footer Separator */
	printf(TABLE_FOOTER_CHAR);
	for (int c = 0; c < table.colCount; c++)
	{
		for (int i = 0; i <= table.cells[0][c].maxLength; i++)
		{
			printf(TABLE_FOOTER_CHAR);
		}
	}

	printf("\n");
}

void printContent(Table table) {
	for (int r = 0; r < table.rowCount - 1; r++)
	{
		printf("%s", TABLE_CELL_SEPARATOR);
		for (int c = 0; c < table.colCount; c++)
		{
			int valueLength = 0;
			// Blank space after the text
			int blankSpace = table.cells[r][c].maxLength;
			if (r < table.cursor) {
				valueLength = strlen(table.cells[r][c].value);
				blankSpace = table.cells[r][c].maxLength - valueLength;
				// Blank space before the text to centralize it
				int blankCenter = blankSpace / 2;
				for(int i = 0; i < blankCenter; i++) printf(" ");
				printf("%s", table.cells[r][c].value);
				// New count of blank space after the text
				blankSpace = blankSpace - blankCenter;
			}
			for(int i = 0; i < blankSpace; i++) printf(" ");
			printf("%s", TABLE_CELL_SEPARATOR);
		}
		printf("\n");
	}
}

void printTable(Table table) {

	printHeader(table);

	printContent(table);

	printFooter(table);
}