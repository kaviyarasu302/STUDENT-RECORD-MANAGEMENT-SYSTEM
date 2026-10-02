#include"header.h"


void stud_exit(ST *ptr)
{

	char op;
	puts("S/s : Save and Exit");
	puts("E/e : Exit Without Saving");
	puts("Enter your choice:");

	scanf(" %c",&op);

	switch (op)
	{
		case 'S' :
		case 's' : stud_save(hptr); 
			   break;

		case 'E' :
		case 'e' : puts("EXIT WITHOUT SAVING");
			   break;

		default : puts("INVALID OPTION");
	}
}
