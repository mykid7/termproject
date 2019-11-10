#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j;
	
	int frame[9][9] = {0};
	
	for (i = 0; i < 9; i++)
	{
		if (i % 3 == 0) printf("\n");
		if (i % 9 == 0) printf("\n");
		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0) printf(" ");
			if (j % 9 == 0) printf("\n");
			printf("%d ", frame[i][j]);
		}
	}
}
