#include<stdio.h>
#include <string.h>

void isPalin(char a[15],int index){
	int len = strlen(a) - (index+1);
	if(a[index]==a[len])
	{
		if(index+1==len || index == len)
		{
			printf("Entered string is a Palindrome\n");
			return;
		}
		isPalin(a,index+1);
	}else{
		printf("Entered string is NOT a Palindrome!\n");
	}
}

void main(){
	char a[15];
	printf("Enter a string: ");
	scanf("%s",a);
	printf("Entered string: %s\n",a);
	isPalin(a,0);
}