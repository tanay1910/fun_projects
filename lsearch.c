#include<stdio.h>

int Lsearch(int arr[10], int ele,int len)
{
	int i,flag=0,ind;
	for(i=0;i<len;i++)
	{
		if (arr[i]==ele){
			ind = i;
			flag=1;
			break;
		}
	}
	
	if(flag==1)
	{
		printf("element found at %d",ind);
	}
	else{
		printf("element not found.");
	}

}

void main(){
	int arr[10],ele,len,i;

	printf("enter the len of array: ");
	scanf("%d",&len);

	printf("enter the elements of the array: ");
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("enter the elements to find: ");
	scanf("%d",&ele);

	Lsearch(arr,ele,len);


}
