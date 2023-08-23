#include<stdio.h>

int matrixmulti(int m1[10][10],int m2[10][10],int r1,int r2,int c1,int c2)
{
	int prod[10][10],i,j,k;
	if(r2!=c1){
		printf("matrix can not be multiplied");
		return 0;
	}

	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			prod[i][j]=0;
			for(k=0;k<r2;k++)
			{
				prod[i][j]+=(m1[i][k]*m2[k][j]);
			}
		}
	}

	printf("prod is:\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++)
		{
			printf("%d ",prod[i][j]);
		}
		printf("\n");
	}


}

void main(){
	int r1,r2,c1,c2,i,j,k,l,m1[10][10],m2[10][10];

	printf("enter the dimension of both arrays(r1,c1,r2,c2): ");
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);

	printf("enter the elements for m1: ");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}

	printf("enter the elements for m2: ");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++)
		{
			scanf("%d",&m2[i][j]);
		}
	}

	printf("m1 is:\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++)
		{
			printf("%d ",m1[i][j]);
		}
		printf("\n");
	}

	printf("m2 is:\n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++)
		{
			printf("%d ",m2[i][j]);
		}
		printf("\n");
	}

	matrixmulti(m1,m2,r1,r2,c1,c2);

}