#include<stdio.h>
int main()
{
	int i,j,k,c=0,b;
	int ina[20];
	for(i=0;i<20;i++)
	{
		printf("Type next integer: ");
		scanf("%d",&k);
		b=0;
		for(j=0;j<c;j++)
		{
			if(k==ina[j])
			{
				printf("%d\n",k);
				b=1;
				//printf("%d %d %d %d %d\n",i,j,k,c,b);
				break;
				
			}
		}
		if(!b)
		{
			ina[c]=k;
			c+=1;
			//printf("%d %d %d %d %d\n",i,j,k,c,b);
		}
		//printf("%d %d %d %d %d\n",i,j,k,c,b);
	}
	return 0;
}