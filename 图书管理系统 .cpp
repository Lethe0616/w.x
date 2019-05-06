#ifndef BOOK
#define BOOK
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define HH printf("%-10s%-20s%-20s%-10s%-10s%-10s%-10s\n","���","����","�鼮����","¥��","��ܺ���","����ʱ��","ʣ����")
struct book
{
	char name[100];
	char writer[100];
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

void menu()
{
	system("cls");
	printf("\n");
	printf("\t\t--------------ͼ����鼮���Ĺ���ϵͳ--------------\n") ;
	printf("\t\t|\t\t 1 �����Ŀ����                  |\n");
	printf("\t\t|\t\t 2 ��ʾ��Ŀ����                  |\n");
	printf("\t\t|\t\t 3 �޸���Ŀ��Ϣ                  |\n");
	printf("\t\t|\t\t 4 ɾ����Ŀ��Ϣ                  |\n");
	printf("\t\t|\t\t 5 ������Ŀ��Ϣ                  |\n");
	printf("\t\t|\t\t 6 ��Ŀ����                      |\n");
	printf("\t\t|\t\t 0 �˳�ϵͳ                      |\n");
	printf("\t\t--------------------------------------------------\n") ;
	printf("\t\t��ѡ��(0-6):") ;
}
void add(struct book b[])
{
	int i,id=0;
	char quit;
	do
	{
		printf("�鼮���:");
		scanf("%d",&id);
		for(i=0;i<n;i++)
		{
			if(id==b[i].id)
			{
				printf("������ڡ�\n");
				return;
			}
		}
		b[i].id =id;
		printf("���ߣ�");
		scanf("%s",&b[i].writer);
		printf("�鼮���ƣ�"); 
		scanf("%s",&b[i].name);
		printf("¥�㣺");
		scanf("%d",&b[i].floor);
		printf("��ܺ��룺");
		scanf("%d",&b[i].number);
		printf("����ʱ�䣺");
		scanf("%d",&b[i].time);
		printf("ʣ������");
		scanf("%d",&b[i].residue);
		n++;
		printf("�Ƿ�������?(Y/N)");
		scanf("\t%c",&quit) ;
	}while(quit != 'N' && quit != 'n');
}
void show(struct book b[],int i)
{
	printf("%-10d",b[i].id);
	printf("%-20s",b[i].writer);
	printf("%-20s",b[i].name);
    printf("%-10d",b[i].floor);
    printf("%-10d",b[i].number);
    printf("%-10d",b[i].time);
    printf("%-10d\n",b[i].residue);
}
void showAll(struct book b[])
{
	int i=0;
	HH;
	for (;i<n;i++)
	{
		show(b,i);	  
	}
}
void modify(struct book b[])
{
	char name[100],ch;
	int i;
	printf("�޸��鼮�ļ�¼��\n");
	printf("��������Ŀ���ƣ�");
	scanf("%s",&name);
	for (i=0;i<n;i++)
	{
		if(strcmp(name,b[i].name)==0)
		{
			getchar();
			printf("�ҵ�������Ϣ��������ʾ��\n");
			HH;
			show(b,i);
		    printf("�Ƿ��޸���Ϣ��(Y/N)\n");
			scanf("%c",&ch);
			if(ch=='Y'||ch=='y')	
			{
				getchar();
				printf("�鼮����:");
				scanf("%s",&b[i].name) ;
				printf("��ţ�");
				scanf("%d",&b[i].id) ;
				printf("���ߣ�");
				scanf("%s",&b[i].writer) ;
				printf("����ʱ�䣺");
				scanf("%d",&b[i].time) ;
				printf("¥�㣺");
				scanf("%d",&b[i].floor) ;
				printf("��ܺ��룺");
				scanf("%d",&b[i].number) ;
				printf("ʣ������");
				scanf("%d",&b[i].residue) ;
				printf("�޸���ϡ�\n") ;
			}
			return;
		}
	 } 
	 printf("û���ҵ�����ļ�¼��\n");
}
void del(struct book b[])
{
	char name[100];
	int i;
	char ch;
	printf("ɾ������ļ�¼��\n");
	printf("�������鼮���ƣ�"); 
	scanf("%s",&name);
	for (i=0;i<n;i++)
	{
		if(strcmp(name,b[i].name)==0)
		{
			getchar();
			printf("�ҵ������¼��������ʾ��\n");
			HH;
			show(b,i);
			printf("�Ƿ�ɾ����(Y/N)\n");
			scanf("%c",&ch);
			if(ch=='Y'||ch=='y')
			{
				for(;i<n;i++)
				b[i]=b[i+1];
				n--;
				printf("ɾ���ɹ���"); 
			}
			return; 
		}
	}
	printf("û���ҵ�������Ϣ��\n");
}	
void search(struct book b[])
{
	char name[100];
	int i;
	printf("���Ҹ���ļ�¼��\n");
	printf("�������鼮���ƣ�");
	scanf("%s",&name);
	for (i=0;i<n;i++) 
	{
	if(strcmp(name,b[i].name)==0) 
	{
		printf("�ҵ������¼��������ʾ��\n");
		HH;
		show(b,i);
		return;
	}
}
printf("û���ҵ�������Ϣ��\n");
}
void sort(struct book b[])
{
	int i,j;
	struct book t;
	printf("��¥������");
	for (i=0;i<n-1;i++) 
	{
		for(j=i+1;j<n;j++)
		{
			if(b[i].floor<b[j].floor)
			{
			t=b[i];
			b[i]=b[j];
			b[j]=t;
		}
	 } 
}
printf("���������£�\n");
showAll(b);
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "book.h"
int main()
{
	struct book b[10];
	int select,quit=0;
	int i;                     
    char *a1="123456";
	char a2[7];    
    printf("��ӭʹ��ͼ�����ϵͳ�� \n"); 
    for(i=0;i<3;i++)                            
    {  
                        
        printf("�������������룺\n");  
        scanf("%s",&a2);                   
        if (strcmp(a1,a2)==0)                    
        {  
          break; 
        }  
        else  
        {                              
            printf("�����˺Ż��������%d�Σ�����������\n",i+1);  
        }  
    }  
    if(i<3) 
    printf("��¼�ɹ���"); 
    else
    {
	printf("�������3�Σ�ϵͳ������");
    return 0;
	}
	while (1)
    {
    	menu();
    	scanf("%d",&select);
    	switch(select)
    	{
    		case 1:
    			add(b);
    			break;
    		case 2:
    			showAll(b);
    			break;
    		case 3:
    			modify(b);
    		    break;
    		case 4:
    		    del(b);
    			break;
    		case 5:
    			search(b);
    			break;
    		case 6:
    			sort(b);
    			break;
    		case 0:
    			quit=1;
    			break;
    		default:
    			printf("������0-6֮�������\n");
    			break;
		}
		if(quit==1)
		break;
		printf("��������������˵���\n");
		getchar();
		getchar();
	}
	printf("���������\n");
	return 0;
}      
