/* ******************************************************************
 *                      Project I: ASCII Triangle
 *  Author: Weerawardhana J.L.M.N. (E/10/389)
 * 
 *  CO212: Computer Programming, 
 *      Department of Computer Engineering, University of Peradeniya
 * *****************************************************************/

/* For ploting, we  suggest you to use an integer coordinate system.
   Therefore, you  should round your floating point representations
   to integers before performing the "ploting" operation.
 */
 
/* include the header files here */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* include the definitions here */
#define INPUT_LENGTH 256
#define NO_OF_INPUTS 12
#define SIZE 1000
#define THRESH  -0.000001

typedef struct point Point;

/* declare the function prototypes here */
void buildFrame(int r,int c,char str[SIZE][SIZE]);
void printPic(int r,int c,char str[SIZE][SIZE]);
void ConstPic(float inFloat[NO_OF_INPUTS],char str[SIZE][SIZE]);
int isInTry(Point p0,Point p1,Point p2,Point p3);



int main()
{
	/* declare local variables */
	
	
	char  inputString[INPUT_LENGTH]; // input from the user as a string
	float inputsFloat[NO_OF_INPUTS]; // Separated 12 input values 
	
	int countInput = 0;

	/* YOU SHOULD NOT MODIFY THE FOLLOWING */
	
	/* read the input from a user as a string */
	fgets (inputString, INPUT_LENGTH, stdin);
	
	/* 	extract the inputs while checking whether we have exactly have
		12 at the end of this section, the 12 inputs will be available
		in a floating point array named inputsFloat
	*/
 	char *separatedInput, *tail;
	
	/* break the inputString at white spaces. */
	separatedInput = strtok(inputString, " ");
	while(separatedInput != NULL)
	{
		if(countInput == 12)
		{
			printf("Too many inputs! Redundant inputs will be ignored\n");
			break;	
		}
		
		/* convert to float and store. */
		inputsFloat[countInput] = strtod(separatedInput, &tail); 

		if(*tail != '\0' && *tail != '\n' )
		{
			printf("Error in the input! Terminating\n");
			return 0;	
		} 
		separatedInput = strtok(NULL," ");
		countInput++;		
	} 

	if(countInput < 11 )
	{
		printf("%d\n",countInput);
		printf("Please enter all 12 inputs to calculate!\n");
		return -1;
	}

	/* 	extracting the inputs is done and the inputs are in a floating
		point array named inputsFloat 
	*/
	
	/* WRITE YOU CODE HERE */
	/* 	You are advised to break your program into smaller functions
		and call them in the main function, instead of writing all 
		your code in the main function
	*/
	char str[SIZE][SIZE]={};
	
	if( inputsFloat[4]<inputsFloat[2] || inputsFloat[5]<inputsFloat[3])
	{
		printf("Minimum value cannot exceed the maximum value!\n");
	}
	else if(inputsFloat[0]<=0 || inputsFloat[1]<=0)
	{
		printf("Row and column numbers should be non-zero positive values!\n");
	}
	else if(inputsFloat[4]<inputsFloat[6] || inputsFloat[4]<inputsFloat[8] || inputsFloat[4]<inputsFloat[10] || inputsFloat[5]<inputsFloat[7] || inputsFloat[5]<inputsFloat[9] || inputsFloat[5]<inputsFloat[11])
	{
		printf("The value given is out of range");
	}
	else if(inputsFloat[2]>inputsFloat[6] || inputsFloat[2]>inputsFloat[8] || inputsFloat[2]>inputsFloat[10] || inputsFloat[3]>inputsFloat[7] || inputsFloat[3]>inputsFloat[9] || inputsFloat[3]>inputsFloat[11])
	{
		printf("The value given is out of range");
	}
	else 
	{
		buildFrame(inputsFloat[0],inputsFloat[1],str);
		ConstPic(inputsFloat,str);
		printPic(inputsFloat[0],inputsFloat[1],str);
	}
	return 0;
}

struct point
{
	float x;
	float y;
};



void buildFrame(int r,int c,char str[SIZE][SIZE])
{
	int i,j;
	for(i=0;i<r+2;i++)
	{
		for(j=0;j<c+2;j++)
		{
			if(i==0 || i==r+1)
			{
				if(j==0 || j==c+1)
				{
					str[i][j]='+';
				}
				else
				{
					str[i][j]='-';
				}
			}
			else
			{
				if(j==0 || j==c+1)
				{
					str[i][j]='|';
				}
				else
				{
					str[i][j]=' ';
				}
			}
		}
	}
}

void ConstPic(float inFloat[NO_OF_INPUTS],char str[SIZE][SIZE])
{
	int r,c;
	int i,j;
	
	r=inFloat[0];
	c=inFloat[1];
	if(r!=inFloat[0] || c!=inFloat[1])
	{
		printf("rows and columns should be integers. So they are truncated\n");
	}
	Point pmin,pmax,p1,p2,p3,p0,trans;
	
	pmin.x=inFloat[2];
	pmin.y=inFloat[3];
	
	pmax.x=inFloat[4];
	pmax.y=inFloat[5];
	
	trans.x=((pmax.x-pmin.x))/(c-1);
	trans.y=((pmax.y-pmin.y))/(r-1);
	
	//printf("%f %f \n",trans.x,trans.y);
	
	p1.x=inFloat[6];
	p1.y=inFloat[7];
	
	p2.x=inFloat[8];
	p2.y=inFloat[9];
	
	p3.x=inFloat[10];
	p3.y=inFloat[11];
	
	//printf("%f %f %f %f %f %f \n",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
	
	p1.x=p1.x-pmin.x;
	p1.y=p1.y-pmin.y;
	
	p2.x=p2.x-pmin.x;
	p2.y=p2.y-pmin.y;
	
	p3.x=p3.x-pmin.x;
	p3.y=p3.y-pmin.y;
	
	//printf("%f %f %f %f %f %f \n",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
	
	p1.x=p1.x/trans.x;
	p1.y=p1.y/trans.y;
	
	p2.x=p2.x/trans.x;
	p2.y=p2.y/trans.y;
	
	p3.x=p3.x/trans.x;
	p3.y=p3.y/trans.y;
	
	//printf("%f %f %f %f %f %f \n",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
	
	p1.x=round(p1.x);
	p1.y=round(p1.y);
	
	p2.x=round(p2.x);
	p2.y=round(p2.y);
	
	p3.x=round(p3.x);
	p3.y=round(p3.y);
	
	
	//rintf(
	
	//printf("%f %f %f %f %f %f \n",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			
			p0.x=j-1;
			p0.y=i-1;
			
			//printf("%f %f\t",p0.x,p0.y);
			
			if(isInTry(p0,p1,p2,p3))
			{
				str[i][j]='*';
			}
		}
		//printf("\n");
		
	}
}

int isInTry(Point p0,Point p1,Point p2,Point p3)
{
	float alpha,beta,gama,det;
	
	det=(p2.y-p3.y)*(p1.x-p3.x)+(p3.x-p2.x)*(p1.y-p3.y);
	
	alpha=((p2.y-p3.y)*(p0.x-p3.x)+(p3.x-p2.x)*(p0.y-p3.y))/det;
	beta=((p3.y-p1.y)*(p0.x-p3.x)+(p1.x-p3.x)*(p0.y-p3.y))/det;
	gama=1-alpha-beta;
	
	//printf("%f %f %f\n",alpha,beta,gama);
	
	if (alpha>=THRESH && alpha<=1 && beta>=THRESH  && beta<=1 && gama>=THRESH && gama<=1 )
	{
		return 1;
	}
	
	return 0;
}


void printPic(int r,int c,char str[SIZE][SIZE])
{
	int i;
	for(i=r+1;i>=0;i--)
	{
		printf("%s\n",str[i]);
	}
}