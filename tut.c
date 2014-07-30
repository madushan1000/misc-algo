#include <stdio.h>
int main()
{
	char ch[2];
	
	scanf("%c %c",&ch[0],&ch[1]);
	
	int i;
	int val[2]={0};
	
	for(i=0;i<2;i++)
	{
		if(ch[i]>='0' && ch[i]<='9')
		{
			val[i]=ch[i]-'0';
		}
		if(ch[i]>='A' && ch[i]<='F')
		{
			val[i]=ch[i]-'A'+10;
		}
	}
	
	printf("%d",val[0]*8+val[1]);
	
	return 0;
}