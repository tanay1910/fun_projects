#include<stdio.h>
#include<stdlib.h>

int smallestInt(int *ptr,int n)
{
	int smallest = *ptr;

	for(int i = 0; i<n; i++)
	{
		if(*ptr+i<smallest)
		{
			smallest=*ptr;
		}
	}

	return(smallest);

}

void main()
{
	int n,i,*ptr,*ptr1;
	printf("Enter the value of n: ");
	scanf("%d",&n);

	ptr = (int*) malloc(n*sizeof(int));
	ptr1=ptr;

	printf("Enter the elements of the array: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
	}

	printf("The smallest element is: %d\n",smallestInt(ptr1,n));

}