#include<stdio.h>
#include <stdlib.h>

struct info{
	int reg_no;
	char name[50];
	char address[50];
};

struct college{
	char college_name[50];
	char uni_name[50];
};

struct dob{
		int dd,mm,yyyy;
	};

struct student{
	//studnent.dob->month.char * malloc (strlen*sizeof(char))
	
	struct dob *DOB;
	struct info *stu_info;
	struct college *college_info;
	
};

void displayStu(struct student *stu)
{
	printf("student details: \n");

	printf("student dd/mm/yy: ");
	// printf("%d %d %d",stu->DOB->dd,stu->DOB->mm,stu->DOB->yyyy);
	scanf("%d",&stu->DOB->dd);
	scanf("%d",&stu->DOB->mm);
	scanf("%d",&stu->DOB->yyyy);

	printf("reg no: ");
	printf("%d",stu->stu_info->reg_no);

	printf("name: ");
	printf("%s",stu->stu_info->name);

	printf("address: ");
	printf("%s",stu->stu_info->address);

	printf("college name: ");
	printf("%s",stu->college_info->college_name);

	printf("uni name: ");
	printf("%s",stu->college_info->uni_name);
}

void main()
{
	struct student *stu,*stu1;
	stu = (struct student *)malloc(5*sizeof(struct student *));
	stu1=stu;

	printf("Enter student details: \n");

	printf("Enter student dd/mm/yy: ");
	scanf("%d %d %d",&stu->DOB->dd,&stu->DOB->mm,&stu->DOB->yyyy);

	printf("Enter reg no: ");
	scanf("%d",&stu->stu_info->reg_no);

	printf("Enter name: ");
	scanf("%s",stu->stu_info->name);

	printf("Enter address: ");
	scanf("%s",stu->stu_info->address);

	printf("Enter college name: ");
	scanf("%s",stu->college_info->college_name);

	printf("Enter uni name: ");
	scanf("%s",stu->college_info->uni_name);

	displayStu(stu1);

}