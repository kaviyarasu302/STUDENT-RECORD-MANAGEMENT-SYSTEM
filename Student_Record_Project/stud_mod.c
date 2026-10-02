#include"header.h"


void mod_field(ST ***ptr)
{
	int flag=0;
	char roll[20];
	puts("Enter the rollno of the student to modify(Ex:V25CE9A1):");
        scanf("%s",roll);
	ST *temp=(**ptr);
	while(temp!=NULL)
	{
		if(strcmp(temp->roll,roll)==0)
		{
			flag=1;
			break;
		}
		temp=temp->next;
	}

	if(flag)
	{
		puts("WHAT DO YOU WANT TO MODIFY");
		puts("N/n : Name");
		puts("P/p : Percentage");
                puts("Enter the choice:");
		char mod_op;
		scanf(" %c",&mod_op);

		switch(mod_op)
		{
			case 'N' :
			case 'n' : puts("ENTER THE NEW NAME:");
				   char new_name[20];
				   scanf("%s",new_name);
				   strcpy(temp->name,new_name);
                                   printf("NAME MODIFIED SUCCESSFULLY\n\n");
                                   break;


			case 'P' :
			case 'p' : MOD:
				   puts("ENTER THE UPDATED PERCENTAGE:");
				   
				   float per;
				   scanf("%f",&per);
				   temp->marks=per;
				   printf("PERCENTAGE MODIFIED SUCCESSFULLY\n\n");
				   break;

                 }

	}

	else
	{
		puts("ROLL NO NOT FOUND ENTER VALID ROLLNO !!!");
		return;
	}


}

void stud_mod(ST **ptr)
{
	if((*ptr)==NULL)
	{
		puts("THERE IS NO STUDENT RECORD AVAILABLE TO MODIFY!!!");
		return;
	}
	

	char op,ch;
	int flag=0;
	char roll[20];
	
	do
	{
	
	puts("SEARCH BY: ");
	puts("R/r : Roll Number");
	puts("N/n : Name");
	puts("P/p : Percentage");
	puts("Enter your choice:");
	scanf(" %c",&op);

	ST *temp;

	switch(op)
	{
		case 'R' :
		case 'r' : puts("Enter the rollno to modify(Ex:V25CE9A1):");
			   scanf("%s",roll);
			   temp=(*ptr);

			   while(temp!=NULL)
			   {
				   if(strcmp(temp->roll,roll)==0)
				   {
                                           flag=1;
					   break;
				   }
				   temp=temp->next;
			   }

			   if(flag)
			   {
				   puts("ENTER THE NEW ROLL TO REPLACE IT(Ex:V25CE9A1):");
				   char new_roll[20];
				   scanf("%s",new_roll);
				   strcpy(temp->roll,new_roll);

			           printf("ROLL NUMBER MODIFIED SUCCESSFULLY !!!\n\n");

			   }
			   else printf("GIVEN ROLLNO IS NOT FOUND!!!\n\n");
			   break;


		case 'N' :
		case 'n' : puts("Enter the student name:");
			   char name[20];
			   scanf("%s",name);
			   temp=(*ptr);
			   while(temp!=NULL)
                           {
                                   if(strcmp(temp->name,name)==0)
                                   {

                                           puts("------------------------------------------------------");
                                           printf("|%-12s%-25s%-15.2f|\n",temp->roll,temp->name,temp->marks);
                                           flag=1;
                                   }


                                   temp=temp->next;
                           }

			   if(flag==0)
			   {
				   printf("GIVEN NAME IS NOT FOUND!!!\n\n");
				   break;
			   }

			   else 
			   {
                           puts("------------------------------------------------------");

			   mod_field(&ptr);
			   	
   			    break;			   
			   }



		case 'P' : 
		case 'p' : puts("Enter the Percentage :");
			   float per;
			   scanf("%f",&per);
			   temp=(*ptr);
				
			   while(temp!=NULL)
                           {
                                   if(temp->marks==per)
                                   {

                                           puts("------------------------------------------------------");
                                           printf("|%-12s%-25s%-15.2f|\n",temp->roll,temp->name,temp->marks);
                                           flag=1;
                                   }


                                   temp=temp->next;
                           }

                           if(flag==0)
                           {
                                   printf("GIVEN PERCENTAGE IS NOT FOUND!!!\n\n");
                                   break;
                           }

                           else
                           {
                           puts("------------------------------------------------------");

                           mod_field(&ptr);

                            break;
                           }


			      

			 
				   
			   
			    


		default : puts("INVALID CHOICE"); break;
	}

	puts("Again Do you want to modify any one more Student record (y/n):");
	scanf(" %c",&ch);	
	
	}while(ch=='Y'||ch=='y');
}
