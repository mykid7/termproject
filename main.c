#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void nframe1(void);
void nframe2(void);
void cframe1(void);
void cframe2(void);
void xframe1(void);
void xframe2(void);
void make(char t, int l, int s);

int main(void)
{
	int l, s;
	char t;

	printf("--------------------------------------------\n");
	printf(" n : normal sudoku\n c : sudoku with sign of inequality\n x : sudoku X \n");
	printf("--------------------------------------------\n");
	printf("input type : ");
	scanf("%c", &t);
	printf("input level(1~10)\n");
	scanf("%d", &l);
	printf("input size\n");
	scanf("%d", &s);
	make(t, l, s);
	system("pause");
	return 0;
}

void nframe1(void)
{
	int i, j;

	int nsudoku1[9][9] = { 8, 3, 7,		9, 4, 5,		6, 2, 1,
						   5, 6, 2,		8, 3, 1,		4, 9, 7,
						   9, 1, 4,		2, 7, 6,		3, 8, 5,

						   6, 5, 8,		4, 1, 3,		2, 7, 9,
						   7, 4, 3,		5, 2, 9,		1, 6, 8,
						   2, 9, 1,		6, 8, 7,		5, 3, 4,

						   3, 8, 5,		1, 9, 2,		7, 4, 6,
						   4, 2, 6,		7, 5, 8,		9, 1, 3,
						   1, 7, 9,		3, 6, 4,		8, 5, 2 };

	printf("--------------------");

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0) printf(" ");
			if (j % 9 == 0) printf("\n");
			printf("%d ", nsudoku1[i][j]);
		}

		if (i % 3 == 2) printf("\n--------------------");
	}
}

void cframe1(void)
{
	int i, j;

	int csudoku1[9][9] = { 5, 4, 9,  2, 6, 8,  1, 7, 3,
						   1, 3, 6,  7, 5, 9,  4, 8, 2,
						   7, 2, 8,  1, 4, 3,  9, 5, 6,

						   8, 6, 5,  4, 7, 1,  2, 3, 9,
						   9, 1, 2,  3, 8, 6,  7, 4, 5,
						   3, 7, 4,  9, 2, 5,  6, 1, 8,

						   6, 9, 1,  8, 3, 7,  5, 2, 4,
						   2, 5, 3,  6, 1, 4,  8, 9, 7,
						   4, 8, 7,  5, 9, 2,  3, 6, 1 };

	printf("--------------------");

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0) printf(" ");
			if (j % 9 == 0) printf("\n");
			printf("%d ", csudoku1[i][j]);
		}

		if (i % 3 == 2) printf("\n--------------------");
	}
}

void xframe1(void)
{
	int i, j;

	int xsudoku1[9][9] = { 4, 7, 8,  1, 9, 3,  5, 6, 2,
						   2, 9, 1,  8, 6, 5,  4, 7, 3,
						   6, 3, 5,  4, 7, 2,  8, 9, 1,

						   8, 1, 7,  6, 2, 4,  9, 3, 5,
						   9, 2, 4,  5, 3, 7,  1, 8, 6,
						   5, 6, 3,  9, 1, 8,  7, 2, 4,

						   3, 4, 6,  7, 8, 1,  2, 5, 9,
						   7, 5, 9,  2, 4, 6,  3, 1, 8,
						   1, 8, 2,  3, 5, 9,  6, 4, 7 };

	printf("--------------------");

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0) printf(" ");
			if (j % 9 == 0) printf("\n");
			printf("%d ", xsudoku1[i][j]);
		}

		if (i % 3 == 2) printf("\n--------------------");
	}
}

void nframe2(void)
{
	int i, j;

	int nsudoku2[16][16] = { 9, 1, 6, 10,		7, 4, 2, 14,		3, 11, 5, 12,		15, 16, 8, 13,
                             13, 15, 16, 7, 	11, 5, 10, 3,		6, 2, 8, 1,			9, 4, 12, 14,
                             5, 2, 14, 12,		8, 1, 13, 9,		16, 15, 4, 7,		10, 11, 3, 6,
                             4, 11, 3, 8,		16, 6, 12, 15,	    14, 9, 10, 13,	    7, 2, 5, 1,

                             15, 16, 7, 9,		14, 8, 3, 4,		11, 10, 2, 6,		13, 12, 1, 5,
                             12, 14, 5, 6,		13, 2, 1, 11,		4, 8, 15, 9,		3, 7, 16, 10,
                             11, 3, 10, 13, 	9, 12, 15, 7,		1, 5, 14, 16,		4, 6, 2, 8,
                             1, 4, 8, 2,		10, 16, 5, 6,		13, 12, 7, 3,		11, 14, 15, 9,

                             14, 13, 2, 16, 	3, 10, 11, 12,  	8, 6, 9, 15,		1, 5, 7, 4,
                             8, 6, 12, 15,		1, 9, 14, 5,		7, 4, 3, 2,			16, 13, 10, 11,
                             7, 10, 4, 11,		2, 15, 16, 8,		5, 1, 13, 14,		6, 3, 9, 12,
                             3, 9, 1, 5,			6, 7, 4, 13,	10, 16, 12, 11, 	2, 8, 14, 15,

                             6, 7, 11, 4,		12, 3, 8, 16,		9, 14, 1, 10,		5, 15, 13, 2,
                             16, 5, 13, 1,		15, 14, 6, 10,  	2, 7, 11, 8,		12, 9, 4, 3,
                             10, 12, 9, 14, 	4, 13, 7, 2,		15, 3, 6, 5,		8, 1, 11, 16,
                             2, 8, 15, 3,		5, 11, 9, 1,		12, 13, 16, 4,  	14, 10, 6, 7 };

	printf("\n-----------------------------------------------------------------------------");

	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			if (j % 4 == 0) printf(" ");
			if (j % 16 == 0) printf("\n");
			printf("%d | ", nsudoku2[i][j]);
		}

		if (i % 4 == 3) printf("\n----------------------------------------------------------------------------");
	}
}

void cframe2(void)
{
	int i, j;

	int csudoku2[16][16] = { 9, 1, 6, 10,		7, 4, 2, 14,		3, 11, 5, 12,		15, 16, 8, 13,
                             13, 15, 16, 7, 	11, 5, 10, 3,		6, 2, 8, 1,			9, 4, 12, 14,
                             5, 2, 14, 12,		8, 1, 13, 9,		16, 15, 4, 7,		10, 11, 3, 6,
                             4, 11, 3, 8,		16, 6, 12, 15,	    14, 9, 10, 13,	    7, 2, 5, 1,

                             15, 16, 7, 9,		14, 8, 3, 4,		11, 10, 2, 6,		13, 12, 1, 5,
                             12, 14, 5, 6,		13, 2, 1, 11,		4, 8, 15, 9,		3, 7, 16, 10,
                             11, 3, 10, 13, 	9, 12, 15, 7,		1, 5, 14, 16,		4, 6, 2, 8,
                             1, 4, 8, 2,		10, 16, 5, 6,		13, 12, 7, 3,		11, 14, 15, 9,

                             14, 13, 2, 16, 	3, 10, 11, 12,  	8, 6, 9, 15,		1, 5, 7, 4,
                             8, 6, 12, 15,		1, 9, 14, 5,		7, 4, 3, 2,			16, 13, 10, 11,
                             7, 10, 4, 11,		2, 15, 16, 8,		5, 1, 13, 14,		6, 3, 9, 12,
                             3, 9, 1, 5,			6, 7, 4, 13,	10, 16, 12, 11, 	2, 8, 14, 15,

                             6, 7, 11, 4,		12, 3, 8, 16,		9, 14, 1, 10,		5, 15, 13, 2,
                             16, 5, 13, 1,		15, 14, 6, 10,  	2, 7, 11, 8,		12, 9, 4, 3,
                             10, 12, 9, 14, 	4, 13, 7, 2,		15, 3, 6, 5,		8, 1, 11, 16,
                             2, 8, 15, 3,		5, 11, 9, 1,		12, 13, 16, 4,  	14, 10, 6, 7 };

	printf("\n-----------------------------------------------------------------------------");

	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			if (j % 4 == 0) printf(" ");
			if (j % 16 == 0) printf("\n");
			printf("%d | ", csudoku2[i][j]);
		}

		if (i % 4 == 3) printf("\n----------------------------------------------------------------------------");
	}
}

void xframe2(void)
{
	int i, j;

	int xsudoku2[16][16] = { 9, 1, 6, 10,		7, 4, 2, 14,		3, 11, 5, 12,		15, 16, 8, 13,
                             13, 15, 16, 7, 	11, 5, 10, 3,		6, 2, 8, 1,			9, 4, 12, 14,
                             5, 2, 14, 12,		8, 1, 13, 9,		16, 15, 4, 7,		10, 11, 3, 6,
                             4, 11, 3, 8,		16, 6, 12, 15,	    14, 9, 10, 13,	    7, 2, 5, 1,

                             15, 16, 7, 9,		14, 8, 3, 4,		11, 10, 2, 6,		13, 12, 1, 5,
                             12, 14, 5, 6,		13, 2, 1, 11,		4, 8, 15, 9,		3, 7, 16, 10,
                             11, 3, 10, 13, 	9, 12, 15, 7,		1, 5, 14, 16,		4, 6, 2, 8,
                             1, 4, 8, 2,		10, 16, 5, 6,		13, 12, 7, 3,		11, 14, 15, 9,

                             14, 13, 2, 16, 	3, 10, 11, 12,  	8, 6, 9, 15,		1, 5, 7, 4,
                             8, 6, 12, 15,		1, 9, 14, 5,		7, 4, 3, 2,			16, 13, 10, 11,
                             7, 10, 4, 11,		2, 15, 16, 8,		5, 1, 13, 14,		6, 3, 9, 12,
                             3, 9, 1, 5,			6, 7, 4, 13,	10, 16, 12, 11, 	2, 8, 14, 15,

                             6, 7, 11, 4,		12, 3, 8, 16,		9, 14, 1, 10,		5, 15, 13, 2,
                             16, 5, 13, 1,		15, 14, 6, 10,  	2, 7, 11, 8,		12, 9, 4, 3,
                             10, 12, 9, 14, 	4, 13, 7, 2,		15, 3, 6, 5,		8, 1, 11, 16,
                             2, 8, 15, 3,		5, 11, 9, 1,		12, 13, 16, 4,  	14, 10, 6, 7 };

	printf("\n-----------------------------------------------------------------------------");

	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			if (j % 4 == 0) printf(" ");
			if (j % 16 == 0) printf("\n");
			printf("%d | ", xsudoku2[i][j]);
		}

		if (i % 4 == 3) printf("\n----------------------------------------------------------------------------");
	}
}

void make(char t, int l, int s)
{
	switch (tolower(t)) {
	case 'n':
		switch (l) {
		case 1:
			switch (s) {
			case 9: nframe1(); break;
			case 16: nframe2(); break;
			default: main();
			}break;
		case 2:
			switch (s) {
			case 9: nframe1(); break;
			case 16: nframe2(); break;
			default: main();
			}break;
		case 3:
			switch (s) {
			case 9: nframe1(); break;
			case 16: nframe2(); break;
			default: main();
			}break;
		case 4:
			switch (s) {
			case 9: nframe1(); break;
			case 16: nframe2(); break;
			default: main();
			}break;
		case 5:
			switch (s) {
			case 9: nframe1(); break;
			case 16: nframe2(); break;
			default: main();
			}break;
		case 6:
			switch (s) {
			case 9: nframe1(); break;
			case 16: nframe2(); break;
			default: main();
			}break;
		case 7:
			switch (s) {
			case 9: nframe1(); break;
			case 16: nframe2(); break;
			default: main();
			}break;
		case 8:
			switch (s) {
			case 9: nframe1(); break;
			case 16: nframe2(); break;
			default: main();
			}break;
		case 9:
			switch (s) {
			case 9: nframe1(); break;
			case 16: nframe2(); break;
			default: main();
			}break;
		case 10:
			switch (s) {
			case 9: nframe1(); break;
			case 16: nframe2(); break;
			default: main();
			}break;
		default: main();
		}break;
	case 'x':
		switch (l) {
		case 1:
			switch (s) {
			case 9: xframe1(); break;
			case 16: xframe2(); break;
			default: main();
			}break;
		case 2:
			switch (s) {
			case 9: xframe1(); break;
			case 16: xframe2(); break;
			default: main();
			}break;
		case 3:
			switch (s) {
			case 9: xframe1(); break;
			case 16: xframe2(); break;
			default: main();
			}break;
		case 4:
			switch (s) {
			case 9: xframe1(); break;
			case 16: xframe2(); break;
			default: main();
			}break;
		case 5:
			switch (s) {
			case 9: xframe1(); break;
			case 16: xframe2(); break;
			default: main();
			}break;
		case 6:
			switch (s) {
			case 9: xframe1(); break;
			case 16: xframe2(); break;
			default: main();
			}break;
		case 7:
			switch (s) {
			case 9: xframe1(); break;
			case 16: xframe2(); break;
			default: main();
			}break;
		case 8:
			switch (s) {
			case 9: xframe1(); break;
			case 16: xframe2(); break;
			default: main();
			}break;
		case 9:
			switch (s) {
			case 9: xframe1(); break;
			case 16: xframe2(); break;
			default: main();
			}break;
		case 10:
			switch (s) {
			case 9: xframe1(); break;
			case 16: xframe2(); break;
			default: main();
			}break;
		default: main();
		}break;
	case 'c':
		switch (l) {
		case 1:
			switch (s) {
			case 9: cframe1(); break;
			case 16: cframe2(); break;
			default: main();
			}break;
		case 2:
			switch (s) {
			case 9: cframe1(); break;
			case 16: cframe2(); break;
			default: main();
			}break;
		case 3:
			switch (s) {
			case 9: cframe1(); break;
			case 16: cframe2(); break;
			default: main();
			}break;
		case 4:
			switch (s) {
			case 9: cframe1(); break;
			case 16: cframe2(); break;
			default: main();
			}break;
		case 5:
			switch (s) {
			case 9: cframe1(); break;
			case 16: cframe2(); break;
			default: main();
			}break;
		case 6:
			switch (s) {
			case 9: cframe1(); break;
			case 16: cframe2(); break;
			default: main();
			}break;
		case 7:
			switch (s) {
			case 9: cframe1(); break;
			case 16: cframe2(); break;
			default: main();
			}break;
		case 8:
			switch (s) {
			case 9: cframe1(); break;
			case 16: cframe2(); break;
			default: main();
			}break;
		case 9:
			switch (s) {
			case 9: cframe1(); break;
			case 16: cframe2(); break;
			default: main();
			}break;
		case 10:
			switch (s) {
			case 9: cframe1(); break;
			case 16: cframe2(); break;
			default: main();
			}break;
		default: main();
		}break;
	default: main();
	}
}
