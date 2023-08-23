#include<stdio.h>

void sparse(int arr[10][10],int m,int n){
	int i,j,count=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]==0)
			{
				count++;
			}
		}
	}

	if(count>(m*n/2))
	{
		printf("its a sparse matrix.");
	}
	else{
		printf("its NOT a sparse matrix.");
	}
}

void main(){
	int m,n,i,j;
	int matrix[10][10];
	printf("enter the dimensions of the matrix: ");
	scanf("%d%d",&m,&n);

	//entering the matrix elements
	printf("enter the elements of the matrix: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}

	//showing the matrix
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	//checking for sparse
	sparse(matrix,m,n);

}