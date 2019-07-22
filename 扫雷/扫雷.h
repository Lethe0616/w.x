#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define EASY_COUNT 10

void game();
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);  //��ʼ������
void DisplayBoard(char board[ROWS][COLS], int row, int col);  //��ӡ����
void SetMine(char board[ROWS][COLS], int row, int col);  //������
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);  //���Ѱ���Ƿ�����
void SafeFirst(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);  //������ҵ�һ�α�ը��
void OpenMine(char mine[ROWS][COLS], char board[ROWS][COLS], int row, int col, int x, int y);  //��������Χû����ʵ��չ��
void FindMinePlus(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);  //����ʣ��δ��λ�ø��������õ��׸����ж���Ӯ
