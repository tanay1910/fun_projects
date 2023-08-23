#include<stdio.h>
#include <stdlib.h>



void reverseArray(int *arr,int n)
{
	if(n==1)
	{
		printf("only one elemets.");
	}

	int *low = arr;
	int *start = arr;
	int *start1 = arr;
	int *end = arr+n-1;

	while(start<end)
	{
		int temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;

	}

	printf("Reversed array: \n");
	for(int i=0; i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}


void main()
{
	int n,*ptr,*ptr1,i;
	printf("Enter the number of elements in the array: \n");
	scanf("%d",&n);

	ptr = (int*) malloc(n*sizeof(int));
	ptr1=ptr;

	printf("Enter the array elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(ptr+i));
	}

	printf("entered array: \n");
	for (i = 0; i < n; ++i)
	{
		printf("%d ",*ptr+i);
	}

	printf("\n");

	reverseArray(ptr1,n);


}