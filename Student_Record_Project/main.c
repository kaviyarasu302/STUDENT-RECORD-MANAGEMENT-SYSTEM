
#include"header.h"

unsigned int rn=0;
unsigned int count=0;
int count1[26]={0};
char last_let;

ST *hptr=NULL;

int main()
{
        system("clear");
	char op;
	
	ST st;
	int c=0;

	if(hptr==NULL)
	{
		FILE *fs=fopen("student.dat","r");

		if(fs!=NULL)
		{

			char str[100];
			fgets(str,100,fs);

			while(fscanf(fs,"%s%s%f",st.roll,st.name,&st.marks)==3)
			{
				c++;
			}

			rewind(fs);

			fgets(str,100,fs);

			if(c>0)
			{

				for(int i=0;i<c;i++)
				{
					ST *new =(ST *)malloc(sizeof(ST));

					fscanf(fs,"%s%s%f",new->roll,new->name,&new->marks);

					if((hptr)==NULL)
					{
						new->next=(hptr);
						(hptr)=new;
					}
					else
					{
						ST *last=(hptr);

						while(last->next != NULL)
						{
							last=last->next;
						}
						new->next=last->next;
						last->next=new;
					}
				}
				ST *last=hptr;

				while(last != NULL)
				{
				    int i = strlen(last->roll) - 1;
				    int n;

				    while(last->roll[i] >= '0' && last->roll[i] <= '9')
    				   {
       					 i--;
    				  }

  				  last_let = last->roll[i];

   				 n = atoi(&last->roll[i + 1]);

				   count1[last_let - 'A'] = n;

				    last = last->next;
				}


				count=c;
				}
				fclose(fs);
				}
				}

				do
				{

				puts("**** STUDENT RECORD MENU ****");
				printf("\n");
				puts(" A/a : Add New Record");
				puts(" D/d : Delete a Record");
				puts(" S/s : Show the List");
				puts(" M/m : Modify a Record");
				puts(" V/v : Save");
				puts(" T/t : Sort the List");
				puts(" E/e : Exit");
				printf("\n\n");

				puts("Enter the choice:");
				scanf(" %c",&op);



				switch(op)
				{
					case 'A' :
					case 'a' : stud_add(&hptr); system("clear"); break;

					case 'D' :
					case 'd' : stud_del(&hptr);sleep(1);system("clear"); break;

					case 'S' :
					case 's' : stud_show(hptr);  break;

					case 'M' :
					case 'm' : stud_mod(&hptr);sleep(1);system("clear");  break;

					case 'V' :
					case 'v' : stud_save(hptr);sleep(1);system("clear"); break;
	
					case 'T' :
					case 't' : stud_sort(hptr); break;

					case 'E' :
					case 'e' : stud_exit(hptr);sleep(1);system("clear"); return 0;

					default : puts("INVALID CHOICE"); sleep(1); system("clear");
				}


			}while(!((op=='E')||(op=='e')));

}

