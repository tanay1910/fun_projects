#include<stdio.h>

void toH(int n, char rodA, char rodC, char rodB){

	if(n==1){
		printf("Move disk 1 from %c to %c\n",rodA,rodC );
		return;
	}

	toH(n-1,rodA,rodB,rodC);
	printf("Move disk %d from %c to %c\n",n,rodA,rodC);
	toH(n-1,rodB,rodC,rodA);
}

int main(){
	int n;
	printf("Enter the number of disks: ");
	scanf("%d",&n);
	toH(n,'A','C','B');

	return 0;
}