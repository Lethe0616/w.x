#include<stdio.h>
#include<string.h>

int main()
{
	int i=0;
	char mima[10]={0}; 
	for(i=0;i<3;i++)
	{
		printf("ÊäÈëÃÜÂë£º\n");
		scanf("%s",mima);
        if(0==strcmp(mima,"147258369"))
        {
        	 printf("ÃÜÂëÕýÈ·\n");
			 break; 
		}
		else
		{
			printf("ÃÜÂë´íÎó\n");
		}
  	}
  	if(i==3)
  	{
  		printf("ÍË³öÏµÍ³\n");
	  }
	return 0;
 } 
