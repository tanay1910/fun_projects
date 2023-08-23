#include<stdio.h>
//copy one str to another
void copyStr(char a[], char b[],int ind){
	b[ind]=a[ind];
	if(a[ind]=='\0')
	{
		return;
	}
	copyStr(a,b,ind+1);
}

void main(){
	char a[15], b[15];
	printf("Enter a string: ");
	fgets(s,100,stdin);	
	printf("Entered string: %s",a);
	copyStr(a,b,0);
	printf("Copied string: %s",b);
}
