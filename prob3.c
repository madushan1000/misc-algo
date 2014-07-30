#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	long k,rk;
	char str[100];
	scanf("%l",&k);
	
	for(i=0;i<1000;i++)
	{
		itoa(k,str,10);
		rk=atoi(strrev(str));
		//printf("%l %l %s\n",k,rk,str);
		if(k==rk)
		{
			printf("%d",i);
			break;
		}
		else
		{
			k=k+rk;
		}
	}
	return 0;
}