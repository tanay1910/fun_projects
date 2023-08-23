#include<stdio.h>

struct complex{
	int real;
	int imaginary;
};

struct complex add(struct complex c1, struct complex c2)
{
	struct complex result;
	result.real = c1.real+c2.real;
	result.imaginary = c1.imaginary+c2.imaginary;
	return(result);
};

void display(struct complex c1)
{
	printf("\n%d + %di\n",c1.real,c1.imaginary);
}

// struct complex add(struct complex c1, struct complex c2)
// {
// 	struct complex result;
// 	result.real = c1.real+c2.real;
// 	result.imaginary=c1.imaginary+c2.imaginary;
// 	return(result);
// }

struct complex subtract(struct complex c1, struct complex c2)
{
	struct complex result;
	result.real = c1.real-c2.real;
	result.imaginary=c1.imaginary-c2.imaginary;
	return(result);
}

struct complex multiply(struct complex c1, struct complex c2)
{
	struct complex result;
	result.real = c1.real*c2.real - c1.imaginary*c2.imaginary;
	result.imaginary=c1.real*c2.imaginary - c1.imaginary*c2.real;
	return(result);
}

void main()
{

	struct complex c1;
	printf("Enter the real and imaginary parts of c1: \n");
	scanf("%d %d",&c1.real,&c1.imaginary);
	display(c1);

	struct complex c2;
	printf("Enter the real and imaginary parts of c2: \n");
	scanf("%d %d",&c2.real,&c2.imaginary);
	display(c2);

	printf("c1 + c2 = ");
	display(add(c1,c2));
	printf("c1 - c2 = ");
	display(subtract(c1,c2));
	printf("c1 * c2 = ");
	display(multiply(c1,c2));




}