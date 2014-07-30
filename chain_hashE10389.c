//lab7 E/10/389
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node *LIST;
struct node{
	char* c;
	LIST next;};

LIST* create_hash_table(int);
int insert(LIST*,char*);
int hash(char*);
int search(LIST*,char*);
	
int main(){
	LIST* ht=create_hash_table(256);//hashtable creation
	insert(ht,"mad");
	insert(ht,"nis");
	insert(ht,"wee");
	insert(ht,"mad");
	insert(ht,"lfs");
	insert(ht,"xzf");
	printf("%d\n",search(ht,"mad"));
	printf("%d\n",search(ht,"nis"));
	printf("%d\n",search(ht,"wee"));
	printf("%d\n",search(ht,"looo"));
	return 0;
}

LIST* create_hash_table(int max)
{
	LIST* ht=malloc(sizeof(LIST)*max);//allocating memory as pointer array to LIST
	int i;
	for(i=0;i<max;i++) //making a dummy node at the start and setting each pointer to NULL
	{
		LIST new=malloc(sizeof(struct node));
		new -> c = "\0";
		new -> next = NULL;
		ht[i]=new;
	}
	return ht;
}

int hash(char* key)
{
	return key[0]-' ';//hash value calculation
}

int insert(LIST* ht,char* key)
{
	LIST new=malloc(sizeof(struct node)); //new LIST entry for storing new data
	new->c=malloc(sizeof(char)*strlen(key));
	strcpy(new->c,key);
	new->next=NULL;
	
	LIST tmp=ht[hash(key)]; //calculating hash and finding the hashtable position 
	LIST prev; 
	while(tmp) //while reach the node NULL
	{
		if(!strcmp(key,tmp->c)) //Comparing the input string and the strings in hashtable 
		{
			return 1; //If it's there return 1
		}
		prev=tmp; //unless store the previous node
		tmp=tmp->next; //move on to the next node
	}
	prev->next=new; //attach the new node at the end of the linked list
	return 0; //return 0
}

int search(LIST* ht,char* key)
{
	LIST tmp=ht[hash(key)];
	while(tmp) //while reach the node NULL
	{
		if(!strcmp(key,tmp->c)) //Comparing the input string and the strings in hashtable 
		{
			return 1; //If it's there return 1
		}
		tmp=tmp->next; //move on to the next node
	}
	return 0;
}