#include<stdio.h>
#include <stdlib.h>

void passPointer(int *ptr)
{
	printf("Value stored at the %p location is %d\n",ptr,*ptr);
}

int *returnPointer(int *ptr)
{
	return(ptr);
}

int **ptrtoptr(int **ptr1)
{
	printf("value of main variable is: %d\n",**ptr1);
	printf("value of the double pointer: %p\n", *ptr1);
}


void main()
{
	int n,*ptr=&n;
	int **ptr1=&ptr;

	printf("Enter the value of n: \n");
	scanf("%d",&n);

	passPointer(ptr);
	printf("Returned pointer: %p\n",returnPointer(ptr));

	ptrtoptr(ptr1);




}