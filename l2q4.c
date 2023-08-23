#include<stdio.h>
#include<stdlib.h>

int **multiplyMatrices(int **mat1, int ** mat2, int r1,int c1,int r2,int c2)

{
	if(c1!=r2)
	{
		printf("Multiplication not possible.\n");
		return(NULL);
	}
	int **resultMatrix;
	resultMatrix = (int**) malloc(r1*sizeof(int*));
	for(int i=0;i<r1;i++)
	{ 
		resultMatrix[i]=(int*) malloc(c2*sizeof(int));
		for(int j=0;j<c2;j++)
		{
			resultMatrix[i][j]=0;
			for(int k=0;k<c1;k++)
			{
				resultMatrix[i][j]+=(mat1[i][k]+mat2[k][j]);
			}
		}
	}

	return(resultMatrix);
}

void displayMatrix(int **mat, int r, int c)
{
	for(int i =0; i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int r1, c1,r2,c2,**mat1,**mat2;
	printf("Enter the dimensions of the first matrix: \n");
	scanf("%d %d",&r1,&c1);

	printf("Enter the dimensions of the second matrix: \n");
	scanf("%d %d",&r2,&c2);

	mat1 = (int**) malloc (r1*sizeof(int*));
	printf("Enter the elements of the first matrix: \n");
	for(int i=0;i<r1;i++)
	{
		mat1[i]=(int*) malloc(c1*sizeof(int));
	}

	for(int i=0; i<r1;i++)
	{
		for(int j=0; j<c1;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("First matrix: \n");
	displayMatrix(mat1,r1,c1);


	mat2 = (int**) malloc (r2*sizeof(int*));
	printf("Enter the elements of the second matrix: \n");
	for(int i=0;i<r2;i++)
	{
		mat2[i]=(int*) malloc(c2*sizeof(int));
	}

	for(int i=0; i<r2;i++)
	{
		for(int j=0; j<c2;j++)
		{
			scanf("%d",&mat2[i][j]);
		}
	}
	printf("Second matrix: \n");
	displayMatrix(mat2,r2,c2);


	multiplyMatrices(mat1,mat2,r1,c1,r2,c2);
	printf("Multiplied matrix: \n");
	displayMatrix(multiplyMatrices(mat1,mat2,r1,c1,r2,c2),r1,c2);


}