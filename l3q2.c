#include<stdio.h>
#include <stdlib.h>

struct student{
	char name[50];
	int rno;
	int cgpa;
};

void readStu(struct student *stu)
{
	printf("Enter name: \n");
	scanf("%s",stu->name);

	printf("Enter rno: \n");
	scanf("%d",&stu->rno);

	printf("Enter cgpa: \n");
	scanf("%d",&stu->cgpa);
}

void showStu(struct student *stu)
{


	printf("name: ");
	printf("%s\n",stu->name);

	printf("rno: ");
	printf("%d\n",stu->rno);

	printf("cgpa: ");
	printf("%d\n",stu->cgpa);
}

void swapstruct(struct student *s1, struct student *s2)
{
	struct student *temp;
	temp = s1;
	s1 = s2;
	s2 = temp;

}


void sort(struct student *stu, int n)
{
	int i,j;
	for(i = 0; i<n;i++)
	{
		int smallest = (stu+i)->rno;
		struct student *smallest_struct;
		smallest_struct=(stu+i);
		for(j=i;j<n;j++)
		{
			if((stu+j)->rno<smallest)
			{
				swapstruct(stu+j,smallest_struct);
			}
		}
	}
	for(i=n-1;i>-1;i--)
	{
		showStu(stu+i);
	}
}



void main()
{
	struct student *stu,*stu1;

	int n;

	printf("Enter number of students: ");
	scanf("%d",&n);

	stu = (struct student *)malloc(n*sizeof(struct student *));
	stu1=stu;

	
	printf("enter students data: \n");
	for(int i = 0; i<n;i++)
	{
		printf("enter data of student %d: \n",i+1);
		readStu(stu+i);
	}

	showStu(stu);

	sort(stu1,n);


}