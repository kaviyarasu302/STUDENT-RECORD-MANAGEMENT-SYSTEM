#include"header.h"

void stud_show(ST *ptr)
{
	if(ptr==NULL)
	{
		puts("THERE IS NO STUDENT RECORD AVAILABLE TO DISPLAY!!!");
		printf("\n\n\n");
		return;
	}


	puts("------------------------------------------------------");
	printf("|%-12s%-25s%-15s|\n","ROLLNO","NAME","PERCENTAGE");
	puts("------------------------------------------------------");
	
	while(ptr!=NULL)
	{
		printf("|%-12s%-25s%-15.2f|\n",ptr->roll,ptr->name,ptr->marks);
		puts("------------------------------------------------------");
		ptr=ptr->next;
	}


}

