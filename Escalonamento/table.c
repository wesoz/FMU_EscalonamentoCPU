#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

#define TABLE_CELL_SEPARATOR "|"
#define TABLE_HEADER_CHAR "="
#define TABLE_FOOTER_CHAR "-"

TableHeader createTableHeader(int maxLength, char *text) {
	TableHeader tableHeader;
	tableHeader.maxLength = maxLength;
	tableHeader.text = text;
	return tableHeader;
}

Table createTable(int rowCount, int colCount, TableHeader *headers) {
	Table table;
	table.rowCount = rowCount;
	table.colCount = colCount;
	table.cursor = 0;
	table.headers = malloc(sizeof(TableHeader) * colCount);
	table.cells = (Cell**)malloc(sizeof(Cell*) * rowCount);
	for (int r = 0; r < rowCount; r++) {
		table.cells[r] = (Cell*)malloc(sizeof(Cell) * colCount);
		for (int c = 0; c < colCount; c++) {
			table.cells[r][c].value = (char*)malloc(sizeof(char) * headers[c].maxLength);
			if (r == 0) {
				table.headers[c].maxLength = headers[c].maxLength;
				table.headers[c].text = headers[c].text;
			}
		}
	}
	return table;
}

void insertTableCells(Table *table, Cell *cells) {
	*table->cells[table->cursor] = *cells;
	table->cursor++;
}

void updateTableCell(Table *table, Cell *cells, int position) {
	*table->cells[position] = *cells;
}

void printHeader(Table table) {
	/* Header Separator */
	printf(TABLE_HEADER_CHAR);
	for (int c = 0; c < table.colCount; c++)
	{
		for (int i = 0; i <= table.headers[c].maxLength; i++)
		{
			printf(TABLE_HEADER_CHAR);
		}
	}

	/* Header Names */
	printf("\n");
	printf("%s", TABLE_CELL_SEPARATOR);
	for (int c = 0; c < table.colCount; c++) {
		/* Center Text */
		int textLength = strlen(table.headers[c].text);
		/* Total amount of blank space */
		int blankSpace = table.headers[c].maxLength - textLength;
		/* Amount of blank space before the text */
		int blankCenter = blankSpace / 2;
		for(int i = 0; i < blankCenter; i++) printf(" ");
		printf("%s", table.headers[c].text);
		/* Fill the rest of the lenth with blank space */
		blankSpace = blankSpace - blankCenter;
		for(int i = 0; i < blankSpace; i++) printf(" ");
		printf("%s", TABLE_CELL_SEPARATOR);
	}
	printf("\n");

	/* Header Separator */
	printf(TABLE_HEADER_CHAR);
	for (int c = 0; c < table.colCount; c++)
	{
		for (int i = 0; i <= table.headers[c].maxLength; i++)
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
		for (int i = 0; i <= table.headers[c].maxLength; i++)
		{
			printf(TABLE_FOOTER_CHAR);
		}
	}

	printf("\n");
}

void printContent(Table table) {
	for (int r = 0; r < table.rowCount; r++)
	{
		printf("%s", TABLE_CELL_SEPARATOR);
		for (int c = 0; c < table.colCount; c++)
		{
			int valueLength = 0;
			// Blank space after the text
			int blankSpace = table.headers[c].maxLength;
			if (r < table.cursor) {
				valueLength = strlen(table.cells[r][c].value);
				blankSpace = table.headers[c].maxLength - valueLength;
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