
#include"header.h"

void stud_add(ST **ptr)
{
	char op;
	
	
	do
	{
	ST *last;
	ST *new =(ST *)malloc(sizeof(ST));


	puts("Enter the Student Name and mark:");
	scanf("%s %f",new->name,&new->marks);
	strcpy(new->roll,"V25CE9");
	char str[15];
 
        char last_let=new->name[0];
 
	if(last_let>='a' && last_let<='z')
	last_let=last_let-32;
 
	if(last_let>='A' && last_let<='Z')
	{
		sprintf(str,"%c%d",last_let,++count1[last_let-65]);
		strcat(new->roll,str);
	}

	

	if((*ptr)==NULL)
	{
		new->next=(*ptr);
		(*ptr)=new;
	}
	else
	{
		last=(*ptr);

		while(last->next != NULL)
		{
			last=last->next;
		}
		new->next=last->next;
		last->next=new;
	}
	count++;

	puts("Do you want to add one more student detail (y/n):");
	scanf(" %c",&op);


	}while(op=='Y' || op=='y');
}


