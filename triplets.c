#include<stdio.h>

void main(){
	//int arr[6] = {1,-1,0,2,-2,6};
	int i,j,k,len=5;
	int arr[5];
	printf("enter the elements of the array: ");
	for(i=0;i<5;i++)
	{
		scanf("%d\n",&arr[i]);
	}

	for(i=0;i<5;i++)
	{
		printf("%d\n",arr[i]);
	}

	for(i=0;i<len-2;i++)
	{
		for(j=i+1;j<len-1;j++)
		{
			for(k=j+1;k<len;k++)
			{
				if((arr[i]+arr[j]+arr[k])==0)
				{
					printf("%d %d %d - its a triplet\n",arr[i],arr[j],arr[k]);
				}
			}
		}
	}

}

