#include<stdio.h>
#include<string.h>

int main()
{
	int i=0;
	char mima[10]={0}; 
	for(i=0;i<3;i++)
	{
		printf("�������룺\n");
		scanf("%s",mima);
        if(0==strcmp(mima,"147258369"))
        {
        	 printf("������ȷ\n");
			 break; 
		}
		else
		{
			printf("�������\n");
		}
  	}
  	if(i==3)
  	{
  		printf("�˳�ϵͳ\n");
	  }
	return 0;
 } 
