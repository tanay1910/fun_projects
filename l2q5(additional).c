#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,*start=&n,*end=&n,*arr;

	printf("Enter the length of the array: \n");
	scanf("%d",&n);
	arr = (int*) malloc(n*sizeof(int));

	printf("Enter the array elements: \n");
	for(int i = 0;i<n;i++)
	{
		scanf("%d",arr+i);
	}

	end=arr;


}
