#include"header.h"

void stud_del(ST **ptr)
{
	char op;
	char roll[20];
	char name[20];
	char ch;
	int flag=0;

	do
	{

		
	if((*ptr)==NULL)
	{
		puts("NO STUDENT RECORD IS AVAILABLE TO DELETE !!!");
		printf("\n\n\n");
		return ;
	}

	puts("R/r : Delete using Roll Number");
	puts("N/n : Delete using Name");

	puts("Enter Your Choice:");
	scanf(" %c",&op);



	switch(op)
	{
		case 'R' :
		case 'r' : DEL:
			   puts("Enter the Student Roll to delete(Ex:V25CE9A1):");
			   scanf("%s",roll);
			   ST *temp=(*ptr),*prv;

			   while(temp!=NULL)
			   {
				
				  if(strcmp(temp->roll,roll)==0)
				  {
					if(temp==(*ptr))
					{
						(*ptr)=temp->next;
					}

					else
					{
						prv->next=temp->next;
					}
						free(temp);
						flag=1;
						temp=NULL;
						puts("STUDENT RECORD DELETED SUCCESSFULLY!!!");
						count--;
						break;
				  }

				   prv=temp;
				   temp=temp->next;


			   }

			   if(flag==0)
			   {
				
			  	 puts("ROLL NO NOT FOUND!!!");
			  	 printf("ENTER THE CORRECT ROLL NO!!!\n\n");
			   }
			   break;

                case 'N' :
		case 'n' : puts("Enter the student name:");
			   scanf("%s",name);
			   
			   char ch1;
		   	   	   
			   ST *temp1=(*ptr);
			   
			   while(temp1!=NULL)
			   {
				   if(strcmp(temp1->name,name)==0)
				   {
					   
				           puts("------------------------------------------------------");
					   printf("|%-12s%-25s%-15.2f|\n",temp1->roll,temp1->name,temp1->marks);
					   flag=1;
				   }


               			   temp1=temp1->next;
			   }
					
			   if (flag==1)
			   puts("------------------------------------------------------");

			   if(flag==0)
			   {
				   printf("GIVEN NAME IS NOT FOUND IN THE RECORD!!!\n\n");
				   break;
			   }

			   puts("Are you sure to delete the student record (y/n):");
			   scanf(" %c",&ch1);

			   if(ch1=='Y'||ch1=='y')
			   {
				   goto DEL;
			   }
			   else
			   break;

		default : puts("INVALID CHOICE!!!"); break;


	}


	puts("Do you want to delete one more student record (y/n):");
	scanf(" %c",&ch);

	}while(ch=='Y'||ch=='y');

}
