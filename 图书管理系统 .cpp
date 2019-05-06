#ifndef BOOK
#define BOOK
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define HH printf("%-10s%-20s%-20s%-10s%-10s%-10s%-10s\n","编号","作者","书籍名称","楼层","书架号码","出版时间","剩余量")
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
	printf("\t\t--------------图书馆书籍借阅管理系统--------------\n") ;
	printf("\t\t|\t\t 1 添加书目名称                  |\n");
	printf("\t\t|\t\t 2 显示书目名称                  |\n");
	printf("\t\t|\t\t 3 修改书目信息                  |\n");
	printf("\t\t|\t\t 4 删除书目信息                  |\n");
	printf("\t\t|\t\t 5 查找书目信息                  |\n");
	printf("\t\t|\t\t 6 书目排序                      |\n");
	printf("\t\t|\t\t 0 退出系统                      |\n");
	printf("\t\t--------------------------------------------------\n") ;
	printf("\t\t请选择(0-6):") ;
}
void add(struct book b[])
{
	int i,id=0;
	char quit;
	do
	{
		printf("书籍编号:");
		scanf("%d",&id);
		for(i=0;i<n;i++)
		{
			if(id==b[i].id)
			{
				printf("此书存在。\n");
				return;
			}
		}
		b[i].id =id;
		printf("作者：");
		scanf("%s",&b[i].writer);
		printf("书籍名称："); 
		scanf("%s",&b[i].name);
		printf("楼层：");
		scanf("%d",&b[i].floor);
		printf("书架号码：");
		scanf("%d",&b[i].number);
		printf("出版时间：");
		scanf("%d",&b[i].time);
		printf("剩余量：");
		scanf("%d",&b[i].residue);
		n++;
		printf("是否继续添加?(Y/N)");
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
	printf("修改书籍的记录。\n");
	printf("请输入书目名称：");
	scanf("%s",&name);
	for (i=0;i<n;i++)
	{
		if(strcmp(name,b[i].name)==0)
		{
			getchar();
			printf("找到该书信息，如下所示：\n");
			HH;
			show(b,i);
		    printf("是否修改信息？(Y/N)\n");
			scanf("%c",&ch);
			if(ch=='Y'||ch=='y')	
			{
				getchar();
				printf("书籍名称:");
				scanf("%s",&b[i].name) ;
				printf("编号：");
				scanf("%d",&b[i].id) ;
				printf("作者：");
				scanf("%s",&b[i].writer) ;
				printf("出版时间：");
				scanf("%d",&b[i].time) ;
				printf("楼层：");
				scanf("%d",&b[i].floor) ;
				printf("书架号码：");
				scanf("%d",&b[i].number) ;
				printf("剩余量：");
				scanf("%d",&b[i].residue) ;
				printf("修改完毕。\n") ;
			}
			return;
		}
	 } 
	 printf("没有找到该书的记录。\n");
}
void del(struct book b[])
{
	char name[100];
	int i;
	char ch;
	printf("删除该书的记录。\n");
	printf("请输入书籍名称："); 
	scanf("%s",&name);
	for (i=0;i<n;i++)
	{
		if(strcmp(name,b[i].name)==0)
		{
			getchar();
			printf("找到该书记录，如下所示：\n");
			HH;
			show(b,i);
			printf("是否删除？(Y/N)\n");
			scanf("%c",&ch);
			if(ch=='Y'||ch=='y')
			{
				for(;i<n;i++)
				b[i]=b[i+1];
				n--;
				printf("删除成功。"); 
			}
			return; 
		}
	}
	printf("没有找到该书信息。\n");
}	
void search(struct book b[])
{
	char name[100];
	int i;
	printf("查找该书的记录。\n");
	printf("请输入书籍名称：");
	scanf("%s",&name);
	for (i=0;i<n;i++) 
	{
	if(strcmp(name,b[i].name)==0) 
	{
		printf("找到该书记录，如下所示：\n");
		HH;
		show(b,i);
		return;
	}
}
printf("没有找到该书信息。\n");
}
void sort(struct book b[])
{
	int i,j;
	struct book t;
	printf("按楼层排序，");
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
printf("排序结果如下：\n");
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
    printf("欢迎使用图书管理系统： \n"); 
    for(i=0;i<3;i++)                            
    {  
                        
        printf("请输入您的密码：\n");  
        scanf("%s",&a2);                   
        if (strcmp(a1,a2)==0)                    
        {  
          break; 
        }  
        else  
        {                              
            printf("您的账号或密码错误%d次，请重新输入\n",i+1);  
        }  
    }  
    if(i<3) 
    printf("登录成功。"); 
    else
    {
	printf("密码错误3次，系统锁定。");
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
    			printf("请输入0-6之间的数字\n");
    			break;
		}
		if(quit==1)
		break;
		printf("按任意键返回主菜单。\n");
		getchar();
		getchar();
	}
	printf("程序结束。\n");
	return 0;
}      
