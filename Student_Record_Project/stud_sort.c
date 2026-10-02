#include"header.h"


void stud_sort(ST *ptr)
{
	if(ptr==NULL)
	{
		puts("THERE IS NO STUDENT DATA IS AVAILABE TO SORT!!!");
		return;
	}

	char op;

	puts("N/n : Sort by Name");
	puts("P/p : Sort by Percentage");

	puts("Enter your choice:");
	scanf(" %c",&op);

        ST **p=(ST **)malloc(count*sizeof(ST *));

	 for(int i=0;i<count;i++)
	 {
		 p[i]=ptr;
		 ptr=ptr->next;
	 }

	 ST *temp;
	switch(op)
	{
		case 'N' :
		case 'n' : for(int i=0;i<count-1;i++)
			   {
				   for(int j=0;j<count-i-1;j++)
				   {
					   if(strcmp(p[j]->name,p[j+1]->name)>0)
					   {
						temp=p[j];
						p[j]=p[j+1];
						p[j+1]=temp;

					   }
				   }

			   }

			   printf("RECORD SORTED BY NAME IS DISPLAYING BELOW \n");
			   break;

		case 'P' :
		case 'p' : for(int i=0;i<count-1;i++)
			   {
				   for(int j=0;j<count-i-1;j++)
				   {
					   if((p[j]->marks)<(p[j+1]->marks))
					   {
						temp=p[j];
						p[j]=p[j+1];
						p[j+1]=temp;

					   }
				   }

			   }

			   printf("RECORD SORTED BY PERCENTAGE IS DISPLAYING BELOW \n");
			   break;

		default : puts("INVALID CHOICE!!!"); free(p);return;

	}

	puts("------------------------------------------------------");
	printf("|%-12s%-25s%-15s|\n","ROLLNO","NAME","PERCENTAGE");
	puts("------------------------------------------------------");
	for(int i=0;i<count;i++)
	{
		printf("|%-12s%-25s%-15.2f|\n",p[i]->roll,p[i]->name,p[i]->marks);
		puts("------------------------------------------------------");
	}

	
	free(p);
	p=NULL;

}
