#include"header.h"

void stud_save(ST *ptr)
{
	if(ptr==NULL)
	{
		puts("THERE IS NO STUDENT DATA TO SAVE");
		return;
	}

	FILE *fs=fopen("student.dat","w");

        fprintf(fs,"%-12s%-25s%-15s\n","ROLLNO","NAME","PERCENTAGE");
	while(ptr!=NULL)
	{
		fprintf(fs,"%-12s%-25s%-15.2f\n",ptr->roll,ptr->name,ptr->marks);
		ptr=ptr->next;
	}

	puts("STUDENT RECORD SAVED SUCCESSFULLY");

	fclose(fs);

}
