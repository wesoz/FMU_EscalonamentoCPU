#ifndef TABLE_H
#define TABLE_H

typedef struct Cell {
	int maxLength;
	char *value;
} Cell;

typedef struct Table {
	Cell **cells;
	int rowCount;
	int colCount;
	int cursor;
} Table;

Cell createCell(int maxLength, char *value);
Table createTable(int colCount, int rowCount, Cell *headers);
void printTable(Table table);

#endif