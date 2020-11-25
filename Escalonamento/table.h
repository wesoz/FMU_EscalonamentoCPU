#ifndef TABLE_H
#define TABLE_H

typedef struct TableHeader {
	int maxLength;
	char *text;
} TableHeader;

typedef struct Cell {
	char *value;
} Cell;

typedef struct Table {
	TableHeader *headers;
	Cell **cells;
	int rowCount;
	int colCount;
	int cursor;
	int offset;
} Table;

TableHeader createTableHeader(int maxLength, char *text);
Table createTable(int colCount, int rowCount, TableHeader *headers, int offset);
void insertTableCells(Table *table, Cell *cells);
void updateTableCell(Table *table, Cell *cells, int position);
void printTable(Table table, int cursorPosition);

#endif