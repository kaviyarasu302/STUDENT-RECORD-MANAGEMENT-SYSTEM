#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<stdarg.h>

typedef struct student
{
    char roll[20];
    char name[20];
    float marks;

    struct student *next;
} ST;

extern unsigned int rn;
extern unsigned int count;
extern ST *hptr;
extern int count1[26];
extern char last_let;

void stud_add(ST **);
void stud_del(ST **);
void stud_show(ST *);
void stud_mod(ST **);
void stud_save(ST *);
void stud_sort(ST *);
void stud_exit(ST *);
