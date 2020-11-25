#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

#define TABLE_CELL_SEPARATOR "|"
#define TABLE_HEADER_CHAR "="
#define TABLE_FOOTER_CHAR "-"
#define TABLE_CURSOR_SYMBOL "->"

void printCentralized(char *text, int length);
void printOffset(int offset);
void printCursor(int offset);

TableHeader createTableHeader(int maxLength, char *text) {
	TableHeader tableHeader;
	tableHeader.maxLength = maxLength;
	tableHeader.text = text;
	return tableHeader;
}

Table createTable(int rowCount, int colCount, TableHeader *headers, int offset) {
	Table table;
	table.rowCount = rowCount;
	table.colCount = colCount;
	table.cursor = 0;
	table.offset = offset;
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

void printOffset(int offset) {
	for(int i = 0; i < offset; i++) printf(" ");
}

void printCursor(int offset) {
	printCentralized(TABLE_CURSOR_SYMBOL, offset);
}

void printCentralized(char *text, int length) {
	/* Center Text */
	int textLength = strlen(text);
	/* Total amount of blank space */
	int blankSpace = length - textLength;
	/* Amount of blank space before the text */
	int blankCenter = blankSpace / 2;
	for(int i = 0; i < blankCenter; i++) printf(" ");
	printf("%s", text);
	/* Fill the rest of the lenth with blank space */
	blankSpace = blankSpace - blankCenter;
	for(int i = 0; i < blankSpace; i++) printf(" ");
}

void printHeader(Table table) {
	/* Header Separator */
	printOffset(table.offset);
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
	printOffset(table.offset);
	printf("%s", TABLE_CELL_SEPARATOR);
	for (int c = 0; c < table.colCount; c++) {
		printCentralized(table.headers[c].text, table.headers[c].maxLength);
		printf("%s", TABLE_CELL_SEPARATOR);
	}
	printf("\n");

	/* Header Separator */
	printOffset(table.offset);
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
	printOffset(table.offset);
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

void printContent(Table table, int cursorPosition) {
	for (int r = 0; r < table.rowCount; r++)
	{
		if (table.offset > 0 && cursorPosition == r)
		{
			printCursor(table.offset);
		} else {
			printOffset(table.offset);
		}
		printf("%s", TABLE_CELL_SEPARATOR);
		for (int c = 0; c < table.colCount; c++)
		{
			if (r < table.cursor) {
				printCentralized(table.cells[r][c].value, table.headers[c].maxLength);
			} else {
				printCentralized(" ", table.headers[c].maxLength);
			}
			printf("%s", TABLE_CELL_SEPARATOR);
		}
		printf("\n");
	}
}

void printTable(Table table, int cursorPosition) {

	printHeader(table);

	printContent(table, cursorPosition);

	printFooter(table);
}