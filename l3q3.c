#include<stdio.h>
#include <stdlib.h>

struct employees{
	char name[50];
	
	struct {
		int dd,mm,yyyy;
	}dob;

	struct {
		int hno,zip;
		char state[50];
	}address;	

};

void display(struct employees *emp,int n)
{
	for(int i = 0 ; i<n;i++)
	{
		printf("\n\nemployee %d details: \n",i+1);

		printf("name: ");
		printf("%s\n",(emp+i)->name);

		printf("\ndd/mm/yyyy: ");
		printf("%d %d %d\n",(emp+i)->dob.dd,(emp+i)->dob.mm,(emp+i)->dob.yyyy);

		printf("\nAddress:\nhno: ");
		printf("%d",(emp+i)->address.hno);

		printf("\nzip: ");
		printf("%d",(emp+i)->address.zip);

		printf("\nstate: ");
		printf("%s",(emp+i)->address.state);
	}

		
}

void main()
{
	struct employees *emp,*emp1;

	int n;

	printf("Enter number of employees: ");
	scanf("%d",&n);

	emp = (struct employees *)malloc(n*sizeof(struct employees *));
	emp1=emp;

	for(int i = 0; i<n; i++)
	{
		printf("Enter employee %d details: \n",i+1);

		printf("Enter name: ");
		scanf("%s",(emp+i)->name);

		printf("\nEnter dd/mm/yyyy: ");
		scanf("%d %d %d",&(emp+i)->dob.dd,&(emp+i)->dob.mm,&(emp+i)->dob.yyyy);

		printf("\nEnter hno: ");
		scanf("%d",&(emp+i)->address.hno);

		printf("\nEnter zip: ");
		scanf("%d",&(emp+i)->address.zip);

		printf("\nEnter state: ");
		scanf("%s",(emp+i)->address.state);	
	}
	display(emp1,n);


}