#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

int title(void);
void nframe1(int l);	// 일반스도쿠 9*9
void nframe2(int l);	// 일반스도쿠 16*16
void cframe1(int l);	// 부등호스도쿠
void xframe1(int l);	// 스도쿠X
void make(char t, int l);	// 스도쿠종류 분류 후 함수 호출, 시간순위표 생성

int h = 0;	// 제목 출력 제한 변수
int ncount,ccount,xcount,ncount2 = 0;	// 각 스도쿠 반복 횟수

int main(void)
{
	int l;
	char t;

	if (h == 0) h = title();	// 처음에만 제목 출력

	printf("------------------------------------------------------------------------------------\n");
	printf("\t\t##\t최대 20번 할 수 있습니다\t##\n\n 9*9 : %d\t 16*16 : %d\t sudoku X : %d\t sudoku with sign of inequality : %d\n\n", ncount, ncount2, xcount, ccount);
	printf("\t\tN : Normal sudoku\n\n \t\tC : Sudoku with Sign of Inequality\n\n \t\tX : Sudoku X \n");
	printf("------------------------------------------------------------------------------------\n\n");

	printf("input type : ");
	scanf(" %c", &t);	// 스도쿠 종류 입력

	printf("\ninput level(1~10) : ");
	scanf("%d", &l);	// 스도쿠 난이도(입력 숫자 개수)입력

	make(t, l);
	
	system("pause");
	return 0;
}

void nframe1(int l)
{
	int a, b, i, j, t, n;
	int cmd = 1;
	int copy[9][9] = { 0 };
	int point[16][2] = { 0 };
	double t1;
	clock_t start, finish;
	FILE* fp;

	int nsudoku1[9][9] = { 8, 3, 7,		9, 4, 5,		6, 2, 1,
						   5, 6, 2,		8, 3, 1,		4, 9, 7,
						   9, 1, 4,		2, 7, 6,		3, 8, 5,

						   6, 5, 8,		4, 1, 3,		2, 7, 9,
						   7, 4, 3,		5, 2, 9,		1, 6, 8,
						   2, 9, 1,		6, 8, 7,		5, 3, 4,

						   3, 8, 5,		1, 9, 2,		7, 4, 6,
						   4, 2, 6,		7, 5, 8,		9, 1, 3,
						   1, 7, 9,		3, 6, 4,		8, 5, 2 };

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			copy[i][j] = nsudoku1[i][j];	// 9*9 스도쿠 불러오기
		}
	}

	for (t = 0; t < l + 6; t++)	// 난이도+6 만큼 반복
	{
		srand((int)time(NULL));
		a = (rand() % 9);
		b = (rand() % 9);
		point[t][0] = a;
		point[t][1] = b;

		if (copy[a][b] != 0) copy[a][b] = 0;	// 랜덤자리를 지우기
		else t--;
	}

	printf("--------------------");

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0) printf(" ");
			if (j % 9 == 0) printf("\n");
			printf("%d ", copy[i][j]);	// 난이도에 맞는 스도쿠 출력
		}

		if (i % 3 == 2) printf("\n--------------------");
	}

	start = clock();
	while (cmd == 1)
	{
		printf("\n숫자를 입력할 위치를 선택하세요(행(0~8) 열(0~8)) : ");
		scanf("%d %d", &a, &b);	// 숫자 입력 위치 입력
		for (t = 0; t < l + 6; t++)
		{
			if (a == point[t][0] && b == point[t][1])
			{
				printf("입력할 숫자(1~9) : ");
				scanf("%d", &n);
				/*if (copy[a][0] != n && copy[a][1] != n && copy[a][2] != n && copy[a][3] != n && copy[a][4] != n && copy[a][5] != n && copy[a][6] != n && copy[a][7] != n && copy[a][8] != n)
				{
					if (copy[0][b] != n && copy[1][b] != n && copy[2][b] != n && copy[3][b] != n && copy[4][b] != n && copy[5][b] != n && copy[6][b] != n && copy[7][b] != n && copy[8][b] != n)
					{
						switch (a / 3)
						{
						case 0:
							switch (b / 3)
							{
							case 0: if (copy[0][0] != n && copy[0][1] != n && copy[0][2] != n && copy[1][0] != n && copy[1][1] != n && copy[1][2] != n && copy[2][0] != n && copy[2][1] != n && copy[2][2] != n) copy[a][b] = n;
							case 1: if (copy[0][3] != n && copy[0][4] != n && copy[0][5] != n && copy[1][3] != n && copy[1][4] != n && copy[1][5] != n && copy[2][3] != n && copy[2][4] != n && copy[2][5] != n) copy[a][b] = n;
							case 2: if (copy[0][6] != n && copy[0][7] != n && copy[0][8] != n && copy[1][6] != n && copy[1][7] != n && copy[1][8] != n && copy[2][6] != n && copy[2][7] != n && copy[2][8] != n) copy[a][b] = n;
							}
						case 1:
							switch (b / 3)
							{
							case 0: if (copy[3][0] != n && copy[3][1] != n && copy[3][2] != n && copy[4][0] != n && copy[4][1] != n && copy[4][2] != n && copy[5][0] != n && copy[5][1] != n && copy[5][2] != n) copy[5][b] = n;
							case 1: if (copy[3][3] != n && copy[3][4] != n && copy[3][5] != n && copy[4][3] != n && copy[4][4] != n && copy[4][5] != n && copy[5][3] != n && copy[5][4] != n && copy[5][5] != n) copy[a][b] = n;
							case 2: if (copy[3][6] != n && copy[3][7] != n && copy[3][8] != n && copy[4][6] != n && copy[4][7] != n && copy[4][8] != n && copy[5][6] != n && copy[5][7] != n && copy[5][8] != n) copy[a][b] = n;
							}
						case 2:
							switch (b / 3)
							{
							case 0: if (copy[6][0] != n && copy[6][1] != n && copy[6][2] != n && copy[7][0] != n && copy[7][1] != n && copy[7][2] != n && copy[8][0] != n && copy[8][1] != n && copy[8][2] != n) copy[a][b] = n;
							case 1: if (copy[6][3] != n && copy[6][4] != n && copy[6][5] != n && copy[7][3] != n && copy[7][4] != n && copy[7][5] != n && copy[8][3] != n && copy[8][4] != n && copy[8][5] != n) copy[a][b] = n;
							case 2: if (copy[6][6] != n && copy[6][7] != n && copy[6][8] != n && copy[7][6] != n && copy[7][7] != n && copy[7][8] != n && copy[8][6] != n && copy[8][7] != n && copy[8][8] != n) copy[a][b] = n;
							}
						}
					}
				}*/
				if (nsudoku1[a][b] == n) copy[a][b] = n;	// 맞는 숫자인지 확인
				else
				{
					printf("같은숫자가 있어 들어갈 수 없습니다");
					break;
				}


				printf("--------------------");

				for (i = 0; i < 9; i++)
				{
					for (j = 0; j < 9; j++)
					{
						if (j % 3 == 0) printf(" ");
						if (j % 9 == 0) printf("\n");
						printf("%d ", copy[i][j]);	// 숫자 입력한 스도쿠 출력
					}

					if (i % 3 == 2) printf("\n--------------------");
				}
			}
		}


		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (copy[i][j] == 0) break;
				cmd = 0;
			}
			if (copy[i][j] == 0)
			{
				cmd = 1;
				break;
			}
		}
	}
	finish = clock();
	t1 = (double)(finish - start) / CLOCKS_PER_SEC;	// 풀이 시간 측정
	printf("\nSolved time = %.3lf\n", t1);
	fp = fopen("ntimetable.txt", "a+");
	fprintf(fp,"%lf\n", t1);	//	측정한 시간 파일에 저장
	fclose(fp);
	ncount++;
}

void cframe1(int l)
{
	int a, b, i, j, t, n;
	int cmd = 1;
	int copy[9][9] = { 0 };
	int point[16][2] = { 0 };
	double t1;
	clock_t start, finish;
	FILE* fp;

	int csudoku1[9][9] = { 5, 4, 9,  2, 6, 8,  1, 7, 3,
						   1, 3, 6,  7, 5, 9,  4, 8, 2,
						   7, 2, 8,  1, 4, 3,  9, 5, 6,

						   8, 6, 5,  4, 7, 1,  2, 3, 9,
						   9, 1, 2,  3, 8, 6,  7, 4, 5,
						   3, 7, 4,  9, 2, 5,  6, 1, 8,

						   6, 9, 1,  8, 3, 7,  5, 2, 4,
						   2, 5, 3,  6, 1, 4,  8, 9, 7,
						   4, 8, 7,  5, 9, 2,  3, 6, 1 };

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			copy[i][j] = csudoku1[i][j];
		}
	}

	for (t = 0; t < l + 6; t++)
	{
		srand((int)time(NULL));
		a = (rand() % 9);
		b = (rand() % 9);
		point[t][0] = a;
		point[t][1] = b;
		//printf("%d %d", a, b);
		if (copy[a][b] != 0) copy[a][b] = 0;
		else t--;
	}

	printf("--------------------------------");

	for (i = 0; i < 9; i++)
	{
		if (i == 1) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 253, 161, 253, 161, 253, 161, 252, 161, 253, 161, 252, 161, 252, 161, 252, 161, 253);
		if (i == 2) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 252, 161, 253, 161, 252, 161, 253, 161, 253, 161, 253, 161, 252, 161, 253, 161, 252);
		if (i == 4) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 252, 161, 253, 161, 253, 161, 253, 161, 252, 161, 252, 161, 252, 161, 252, 161, 253);
		if (i == 5) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 253, 161, 252, 161, 252, 161, 252, 161, 253, 161, 253, 161, 253, 161, 253, 161, 252);
		if (i == 7) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 253, 161, 253, 161, 252, 161, 253, 161, 253, 161, 253, 161, 252, 161, 252, 161, 252);
		if (i == 8) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 252, 161, 252, 161, 252, 161, 253, 161, 252, 161, 252, 161, 253, 161, 253, 161, 253);

		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0) printf(" ");
			if (j % 9 == 0) printf("\n");
			printf("%d ", copy[i][j]);
			if (i == 0 && (j == 1 || j == 3 || j == 4 || j == 6)) printf("< ");
			if (i == 0 && (j == 0 || j == 7)) printf("> ");
			if (i == 1 && (j == 0 || j == 1 || j == 4 || j == 6)) printf("< ");
			if (i == 1 && (j == 3 || j == 7)) printf("> ");
			if (i == 2 && (j == 1 || j == 3 || j == 7)) printf("< ");
			if (i == 2 && (j == 0 || j == 4 || j == 6)) printf("> ");
			if (i == 3 && (j == 3 || j == 6 || j == 7)) printf("< ");
			if (i == 3 && (j == 0 || j == 1 || j == 4)) printf("> ");
			if (i == 4 && (j == 1 || j == 3 || j == 7)) printf("< ");
			if (i == 4 && (j == 0 || j == 4 || j == 6)) printf("> ");
			if (i == 5 && (j == 0 || j == 4 || j == 7)) printf("< ");
			if (i == 5 && (j == 1 || j == 3 || j == 6)) printf("> ");
			if (i == 6 && (j == 0 || j == 4 || j == 7)) printf("< ");
			if (i == 6 && (j == 1 || j == 3 || j == 6)) printf("> ");
			if (i == 7 && (j == 0 || j == 4 || j == 6)) printf("< ");
			if (i == 7 && (j == 1 || j == 3 || j == 7)) printf("> ");
			if (i == 8 && (j == 0 || j == 3 || j == 6)) printf("< ");
			if (i == 8 && (j == 1 || j == 4 || j == 7)) printf("> ");
		}

		if (i % 3 == 2) printf("\n--------------------------------");
	}

	start = clock();
	while (cmd == 1)
	{
		printf("\n숫자를 입력할 위치를 선택하세요(행(0~8) 열(0~8)) : ");
		scanf("%d %d", &a, &b);
		for (t = 0; t < l + 6; t++)
		{
			if (a == point[t][0] && b == point[t][1])
			{
				printf("입력할 숫자(1~9) : ");
				scanf("%d", &n);
				
				if (csudoku1[a][b] == n) copy[a][b] = n;
				else
				{
					printf("같은숫자가 있어 들어갈 수 없습니다");
					break;
				}


				printf("--------------------------------");

				for (i = 0; i < 9; i++)
				{
					if (i == 1) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 253, 161, 253, 161, 253, 161, 252, 161, 253, 161, 252, 161, 252, 161, 252, 161, 253);
					if (i == 2) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 252, 161, 253, 161, 252, 161, 253, 161, 253, 161, 253, 161, 252, 161, 253, 161, 252);
					if (i == 4) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 252, 161, 253, 161, 253, 161, 253, 161, 252, 161, 252, 161, 252, 161, 252, 161, 253);
					if (i == 5) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 253, 161, 252, 161, 252, 161, 252, 161, 253, 161, 253, 161, 253, 161, 253, 161, 252);
					if (i == 7) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 253, 161, 253, 161, 252, 161, 253, 161, 253, 161, 253, 161, 252, 161, 252, 161, 252);
					if (i == 8) printf("\n%c%c  %c%c %c%c  %c%c  %c%c %c%c  %c%c  %c%c %c%c", 161, 252, 161, 252, 161, 252, 161, 253, 161, 252, 161, 252, 161, 253, 161, 253, 161, 253);

					for (j = 0; j < 9; j++)
					{
						if (j % 3 == 0) printf(" ");
						if (j % 9 == 0) printf("\n");
						printf("%d ", copy[i][j]);
						if (i == 0 && (j == 1 || j == 3 || j == 4 || j == 6)) printf("< ");
						if (i == 0 && (j == 0 || j == 7)) printf("> ");
						if (i == 1 && (j == 0 || j == 1 || j == 4 || j == 6)) printf("< ");
						if (i == 1 && (j == 3 || j == 7)) printf("> ");
						if (i == 2 && (j == 1 || j == 3 || j == 7)) printf("< ");
						if (i == 2 && (j == 0 || j == 4 || j == 6)) printf("> ");
						if (i == 3 && (j == 3 || j == 6 || j == 7)) printf("< ");
						if (i == 3 && (j == 0 || j == 1 || j == 4)) printf("> ");
						if (i == 4 && (j == 1 || j == 3 || j == 7)) printf("< ");
						if (i == 4 && (j == 0 || j == 4 || j == 6)) printf("> ");
						if (i == 5 && (j == 0 || j == 4 || j == 7)) printf("< ");
						if (i == 5 && (j == 1 || j == 3 || j == 6)) printf("> ");
						if (i == 6 && (j == 0 || j == 4 || j == 7)) printf("< ");
						if (i == 6 && (j == 1 || j == 3 || j == 6)) printf("> ");
						if (i == 7 && (j == 0 || j == 4 || j == 6)) printf("< ");
						if (i == 7 && (j == 1 || j == 3 || j == 7)) printf("> ");
						if (i == 8 && (j == 0 || j == 3 || j == 6)) printf("< ");
						if (i == 8 && (j == 1 || j == 4 || j == 7)) printf("> ");
					}

					if (i % 3 == 2) printf("\n--------------------------------");
				}
			}
		}


		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (copy[i][j] == 0) break;
				cmd = 0;
			}
			if (copy[i][j] == 0)
			{
				cmd = 1;
				break;
			}
		}
	}
	finish = clock();
	t1 = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nSolved time = %.3lf\n", t1);
	fp = fopen("ctimetable.txt", "a+");
	fprintf(fp, "%lf\n", t1);
	fclose(fp);
	ccount++;
}

void xframe1(int l)
{
	int a, b, i, j, t, n;
	int cmd = 1;
	int copy[9][9] = { 0 };
	int point[16][2] = { 0 };
	double t1;
	clock_t start, finish;
	FILE* fp;

	int xsudoku1[9][9] = { 4, 7, 8,  1, 9, 3,  5, 6, 2,
						   2, 9, 1,  8, 6, 5,  4, 7, 3,
						   6, 3, 5,  4, 7, 2,  8, 9, 1,

						   8, 1, 7,  6, 2, 4,  9, 3, 5,
						   9, 2, 4,  5, 3, 7,  1, 8, 6,
						   5, 6, 3,  9, 1, 8,  7, 2, 4,

						   3, 4, 6,  7, 8, 1,  2, 5, 9,
						   7, 5, 9,  2, 4, 6,  3, 1, 8,
						   1, 8, 2,  3, 5, 9,  6, 4, 7 };

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			copy[i][j] = xsudoku1[i][j];
		}
	}

	for (t = 0; t < l + 6; t++)
	{
		srand((int)time(NULL));
		a = (rand() % 9);
		b = (rand() % 9);
		point[t][0] = a;
		point[t][1] = b;

		if (copy[a][b] != 0) copy[a][b] = 0;
		else t--;
	}

	printf("--------------------");

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0) printf(" ");
			if (j % 9 == 0) printf("\n");
			printf("%d ", copy[i][j]);
		}

		if (i % 3 == 2) printf("\n--------------------");
	}

	start = clock();
	while (cmd == 1)
	{
		printf("\n숫자를 입력할 위치를 선택하세요(행(0~8) 열(0~8)) : ");
		scanf("%d %d", &a, &b);
		for (t = 0; t < l + 6; t++)
		{
			if (a == point[t][0] && b == point[t][1])
			{
				printf("입력할 숫자(1~9) : ");
				scanf("%d", &n);
				
				if (xsudoku1[a][b] == n) copy[a][b] = n;
				else
				{
					printf("같은숫자가 있어 들어갈 수 없습니다");
					break;
				}


				printf("--------------------");

				for (i = 0; i < 9; i++)
				{
					for (j = 0; j < 9; j++)
					{
						if (j % 3 == 0) printf(" ");
						if (j % 9 == 0) printf("\n");
						printf("%d ", copy[i][j]);
					}

					if (i % 3 == 2) printf("\n--------------------");
				}
			}
		}


		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (copy[i][j] == 0) break;
				cmd = 0;
			}
			if (copy[i][j] == 0)
			{
				cmd = 1;
				break;
			}
		}
	}
	finish = clock();
	t1 = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nSolved time = %.3lf\n", t1);
	fp = fopen("xtimetable.txt", "a+");
	fprintf(fp, "%lf\n", t1);
	fclose(fp);
	xcount++;
}

void nframe2(int l)
{
	int a, b, i, j, t, n;
	int cmd = 1;
	int copy[16][16] = { 0 };
	int point[16][2] = { 0 };
	double t1;
	clock_t start, finish;
	FILE* fp;

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
                             3, 9, 1, 5,		6, 7, 4, 13,	    10, 16, 12, 11, 	2, 8, 14, 15,

                             6, 7, 11, 4,		12, 3, 8, 16,		9, 14, 1, 10,		5, 15, 13, 2,
                             16, 5, 13, 1,		15, 14, 6, 10,  	2, 7, 11, 8,		12, 9, 4, 3,
                             10, 12, 9, 14, 	4, 13, 7, 2,		15, 3, 6, 5,		8, 1, 11, 16,
                             2, 8, 15, 3,		5, 11, 9, 1,		12, 13, 16, 4,  	14, 10, 6, 7 };

	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			copy[i][j] = nsudoku2[i][j];
		}
	}

	for (t = 0; t < l + 6; t++)
	{
		srand((int)time(NULL));
		a = (rand() % 16);
		b = (rand() % 16);
		point[t][0] = a;
		point[t][1] = b;
		
		if (copy[a][b] != 0) copy[a][b] = 0;
		else t--;
	}

	printf("\n-------------------------------------------------------------");

	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			if (j % 4 == 0) printf("\t");
			if (j % 16 == 0) printf("\n");
			printf("%2d ", copy[i][j]);
		}

		if (i % 4 == 3) printf("\n-------------------------------------------------------------");
	}

	start = clock();
	while (cmd == 1)
	{
		printf("\n숫자를 입력할 위치를 선택하세요(행(0~15) 열(0~15)) : ");
		scanf("%d %d", &a, &b);
		for (t = 0; t < l + 6; t++)
		{
			if (a == point[t][0] && b == point[t][1])
			{
				printf("입력할 숫자(1~16) : ");
				scanf("%d", &n);
				
				if (nsudoku2[a][b] == n) copy[a][b] = n;
				else
				{
					printf("같은숫자가 있어 들어갈 수 없습니다");
					break;
				}


				printf("\n-------------------------------------------------------------");

				for (i = 0; i < 16; i++)
				{
					for (j = 0; j < 16; j++)
					{
						if (j % 4 == 0) printf("\t");
						if (j % 16 == 0) printf("\n");
						printf("%2d ", copy[i][j]);
					}

					if (i % 4 == 3) printf("\n-------------------------------------------------------------");
				}
			}
		}


		for (i = 0; i < 16; i++)
		{
			for (j = 0; j < 16; j++)
			{
				if (copy[i][j] == 0) break;
				cmd = 0;
			}
			if (copy[i][j] == 0)
			{
				cmd = 1;
				break;
			}
		}
	}
	finish = clock();
	t1 = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nSolved time = %.3lf\n", t1);
	fp = fopen("ntimetable2.txt", "a+");
	fprintf(fp, "%lf\n", t1);
	fclose(fp);
	ncount2++;
}

void make(char t, int l)
{	
	int s,i,j,k,u,v = 0;
	char d = 'N';
	FILE* fp;
	double a[20];
	double temp;
	
	switch (tolower(t)) {
	case 'n':

		printf("\ninput size(9 / 16) : ");
		scanf("%d", &s);

		switch (s) {
		case 9: {
			nframe1(l);

			fp = fopen("ntimetable.txt", "r+");
			for (i = 0;i < 20; i++)
			{
				fscanf(fp, "%lf", &a[i]);
				if (a[i] < 0) break;

				for (v = 0; v < i+1; v++)	// 선택정렬
				{
					k = v;
					for (j = v + 1; j < i+1; j++)
					{
						if (a[k] > a[j])
						{
							k = j;
						}
					}
					temp = a[v];
					a[v] = a[k];
					a[k] = temp;
				}
			}
			
			printf("--------------------------------------------\n");
			for (i = 0; i < 20; i++)
			{
				if (a[i] < 0) break;
				printf("%2d. %lf\n", i+1, a[i]);
			}
			printf("--------------------------------------------\n");
			fclose(fp);
			
			fp = fopen("ntimetable.txt", "w");
			for (i = 0; i < 20; i++)
			{
				if (a[i] < 0) break;
				fprintf(fp, "%lf\n", a[i]);
			}
			fclose(fp);

			if (ncount > 20) break;
			printf("계속하시겠습니까?(Y/N) : ");
			scanf(" %c", &d);

			if (toupper(d) == 'N') break;
			printf("\n");
			main();

		}break;

		case 16: {
			nframe2(l);

			fp = fopen("ntimetable2.txt", "r");
			for (i = 0; i < 20; i++)
			{
				fscanf(fp, "%lf", &a[i]);
				if (a[i] < 0) break;
				
				for (v = 0; v < i + 1; v++)
				{
					k = v;
					for (j = v + 1; j < i + 1; j++)
					{
						if (a[k] > a[j])
						{
							k = j;
						}
					}
					temp = a[v];
					a[v] = a[k];
					a[k] = temp;
				}
			}

			printf("--------------------------------------------\n");
			for (i = 0; i < 20; i++)
			{
				if (a[i] < 0) break;
				printf("%2d. %lf\n", i + 1, a[i]);
			}
			printf("--------------------------------------------\n");
			fclose(fp);
			
			fp = fopen("ntimetable2.txt", "w");
			for (i = 0; i < 20; i++)
			{
				if (a[i] < 0) break;
				fprintf(fp, "%lf\n", a[i]);
			}
			fclose(fp);

			if (ncount2 > 20) break;
			printf("계속하시겠습니까?(Y/N) : ");
			scanf(" %c", &d);

			if (toupper(d) == 'N') break;
			printf("\n");
			main();

		}break;

	}break;

	case 'x': {
		xframe1(l);

		fp = fopen("xtimetable.txt", "r");
		for (i = 0; i < 20; i++)
		{
			fscanf(fp, "%lf", &a[i]);
			if (a[i] < 0) break;
			
			for (v = 0; v < i + 1; v++)
			{
				k = v;
				for (j = v + 1; j < i + 1; j++)
				{
					if (a[k] > a[j])
					{
						k = j;
					}
				}
				temp = a[v];
				a[v] = a[k];
				a[k] = temp;
			}
		}

		printf("--------------------------------------------\n");
		for (i = 0; i < 20; i++)
		{
			if (a[i] < 0) break;
			printf("%2d. %lf\n", i + 1, a[i]);
		}
		printf("--------------------------------------------\n");
		fclose(fp);
		
		fp = fopen("xtimetable.txt", "w");
		for (i = 0; i < 20; i++)
		{
			if (a[i] < 0) break;
			fprintf(fp, "%lf\n", a[i]);
		}
		fclose(fp);

		if (xcount > 20) break;
		printf("계속하시겠습니까?(Y/N) : ");
		scanf(" %c", &d);

		if (toupper(d) == 'N') break;
		printf("\n");
		main();

	}break;

	case 'c': {
		cframe1(l);

		fp = fopen("ctimetable.txt", "r");
		for (i = 0; i < 20; i++)
		{
			fscanf(fp, "%lf", &a[i]);
			if (a[i] < 0) break;
			
			for (v = 0; v < i + 1; v++)
			{
				k = v;
				for (j = v + 1; j < i + 1; j++)
				{
					if (a[k] > a[j])
					{
						k = j;
					}
				}
				temp = a[v];
				a[v] = a[k];
				a[k] = temp;
			}
		}

		printf("--------------------------------------------\n");
		for (i = 0; i < 20; i++)
		{
			if (a[i] < 0) break;
			printf("%2d. %lf\n", i + 1, a[i]);
		}
		printf("--------------------------------------------\n");
		fclose(fp);
		
		fp = fopen("ctimetable.txt", "w");
		for (i = 0; i < 20; i++)
		{
			if (a[i] < 0) break;
			fprintf(fp, "%lf\n", a[i]);
		}
		fclose(fp);

		if (ccount > 20) break;
		printf("계속하시겠습니까?(Y/N) : ");
		scanf(" %c", &d);

		if (toupper(d) == 'N') break;
		printf("\n");
		main();

	}break;
	
	default:
		{
			printf("다시 입력하세요");
			main();
		}
	}
}

int title(void)
{
	printf(" __________                   _________        __________                           \n");
	printf("|             |          |   |         |      |          |   |    /     |          |\n");
	printf("|             |          |   |          |     |          |   |   /      |          |\n");
	printf("|__________   |          |   |           |    |          |   |  /       |          |\n");
	printf("           |  |          |   |            |   |          |   | /        |          |\n");
	printf("           |  |          |   |           |    |          |   | ＼       |          |\n");
	printf("           |  |          |   |          |     |          |   |   ＼     |          |\n");
	printf("___________|  |__________|   |________|       |__________|   |     ＼   |__________|\n");
	printf("\n");

	return 1;
}