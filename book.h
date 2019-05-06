#ifndef BOOK
#define BOOK
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define HH printf("%-10s%-15s%-15s%-10s%-10s%-10s%-10s\n","�鼮����","���","¥��","��ܺ���","����ʱ��","����","ʣ����")
struct book
{
	char name[10];
	char writer[10];
	int id;
	int floor;
	int number;
	int time;
	int residue;
};
static int n;
void menu();
void add(struct book b[]);
void show(struct book b[],int i);
void showAll(struct book b[]);
void modify(struct book b[]);
void del(struct book b[]);
void search(struct book b[]);
void sort(struct book b[]);
#endif
