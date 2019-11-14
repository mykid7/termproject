#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void frame1(void);
void frame2(void);
void make(char t, int l, int s);
void normal(void);
void sudokux(void);
void compare(void);

int main(void)
{
	int l, s;
	char t;

	printf("input type\n");
	printf(" n : normal sudoku, c : sudoku with sign of inequality, x : sudoku X \n");
	printf("-----------------------------------------------------------------------\n");
	scanf("%c", &t);
	printf("input level(1~10)\n");
	scanf("%d", &l);
	printf("input size\n");
	scanf("%d", &s);
	make(t,l,s);
}

void frame1(void)
{
	int i, j;

	int sudoku1[9][9] = { 0 };

	printf("--------------------");

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0) printf(" ");
			if (j % 9 == 0) printf("\n");
			printf("%d ", sudoku1[i][j]);
		}

		if (i % 3 == 2) printf("\n--------------------");
	}
}

void frame2(void)
{
	int i, j;

	int sudoku2[16][16] = { 0 };

	printf("\n-----------------------------------");

	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			if (j % 4 == 0) printf(" ");
			if (j % 16 == 0) printf("\n");
			printf("%d ", sudoku2[i][j]);
		}

		if (i % 4 == 3) printf("\n-----------------------------------");
	}
}

void make(char t, int l, int s)
{
	switch (t) {
	case 'n': normal();
		switch (l) {
		case 1: sudoku1();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 2: sudoku2();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 3: sudoku3();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 4: sudoku4();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 5: sudoku5();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 6: sudoku6();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 7: sudoku7();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 8: sudoku8();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 9: sudoku9();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 10: sudoku10();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		default: main();
		}break;
	case 'x': sudokux();
		switch (l) {
		case 1: sudoku1();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 2: sudoku2();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 3: sudoku3();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 4: sudoku4();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 5: sudoku5();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 6: sudoku6();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 7: sudoku7();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 8: sudoku8();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 9: sudoku9();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 10: sudoku10();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		default: main();
		}break;
	case 'c': compare();
		switch (l) {
		case 1: sudoku1();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 2: sudoku2();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 3: sudoku3();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 4: sudoku4();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 5: sudoku5();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 6: sudoku6();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 7: sudoku7();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 8: sudoku8();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 9: sudoku9();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		case 10: sudoku10();
			switch (s) {
			case 9: frame1(); break;
			case 16: frame2(); break;
			default: main();
			}break;
		default: main();
		}break;
	default: main();
}
