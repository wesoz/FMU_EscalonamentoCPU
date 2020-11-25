#include "scan.h"
#define  EXTERN
#include <stdio.h>
#include <stdlib.h>

#define SCANINT_INVALID_ENTRY "Digite apenas números"
#define SCANINT_MAX_VIOLATION "O número deve ser até %d"
#define SCANINT_MIN_VIOLATION "O número deve ser igual ou maior que %d"

void scanInt(int *value, int minValue, int maxValue) {
	int invalid = 1;
	char term;
	
	if (minValue > -1 && maxValue > -1 && maxValue <= minValue) {
		printf("Invalid parameters.\nMin: %d\nMax: %d", minValue, maxValue);
	}

	while (invalid == 1) {
		if(scanf("%d%c", value, &term) != 2 || term != '\n') {
		    printf("%s\n", SCANINT_INVALID_ENTRY);
		    scanf(" %c");
		}
		else if(minValue > -1 && *value < minValue) {
			printf(SCANINT_MIN_VIOLATION, maxValue);
		    scanf(" %c");
		} else if(maxValue > -1 && *value > maxValue) {
			printf(SCANINT_MAX_VIOLATION, maxValue);
		    scanf(" %c");
		} else {
		    invalid = 0;
		}
	}
}

