#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 3
#define COL 3

void game();
void InitBoard(char board[ROW][COL], int row, int col);  //��ʼ������
void DisplatBoard(char board[ROW][COL], int row, int col);  //��ӡ����
void PlayMove(char board[ROW][COL], int row, int col);  //�������
void ComputerMove(char board[ROW][COL], int row, int col);  //��������
char IsWin(char board[ROW][COL], int row, int col);  //�ж���Ӯ *���Ӯ #����Ӯ Qƽ�� C����
void ComputerMovePlus(char board[ROW][COL], int row, int col);  //���Ի���һ�������
