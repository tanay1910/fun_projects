#include<stdio.h>
#include<stdlib.h>

#define Max 100

struct twoStacks{
	int data[Max];
	int top1;
	int top2;
};

void intializeTwoStacks(struct twoStacks* twoStacks)
{
	twoStacks->top1 = -1;
	twoStacks->top2 = (Max+1)/2;
}

int isEmpty1(struct twoStacks* twoStacks)
{
	if(twoStacks->top1==-1)
	{
		return 1;
	}
	else{
		return 0;
	}
}

int isEmpty2(struct twoStacks* twoStacks)
{
	if(twoStacks->top2==-1)
	{
		return 1;
	}
	else{
		return 0;
	}
}

int isFull1(struct twoStacks* twoStacks)
{
	if(twoStacks->top1>=(Max/2))
	{
		return 1;
	}
	else{
		return 0;
	}
}

int isFull2(struct twoStacks* twoStacks)
{
	if(twoStacks->top2>=(Max-1))
	{
		return 1;
	}
	else{
		return 0;
	}
}

void push1(struct twoStacks* twoStacks, int value)
{	
	if(isFull1(twoStacks))
	{
		printf("Stack1 overflow!");
		return;
	}
	else
	{
		twoStacks->data[++(twoStacks->top1)]=value;
		printf("%d pushed to stack1.\n",value);
		printf("new top1 value: %d",twoStacks->top1);
	}
}

void push2(struct twoStacks* twoStacks, int value)
{	
	if(isFull2(twoStacks))
	{
		printf("Stack2 overflow!");
		return;
	}
	else
	{
		twoStacks->data[(twoStacks->top2)++]=value;
		printf("%d pushed to stack2.\n",value);
		printf("new top2 value: %d",twoStacks->top2);
	}
}

void pop1(struct twoStacks* twoStacks)
{
	if(isEmpty1(twoStacks))
	{
		printf("Stack1 underflow.\n");
		return;
	}
	int temp = twoStacks->data[twoStacks->top1];
	twoStacks->top1--;
	printf("%d popped from stack1.\n",temp);
}

void pop2(struct twoStacks* twoStacks)
{
	if(isEmpty2(twoStacks))
	{
		printf("Stack2 underflow.\n");
		return;
	}
	int temp = twoStacks->data[twoStacks->top2];
	twoStacks->top2--;
	printf("%d popped from stack2.\n",temp);
}

void display1(struct twoStacks* twoStacks)
{

	if(isEmpty1(twoStacks))
	{
		printf("Stack underflow.\n");
		return;
	}
	printf("Displaying stack1 elements: ");
	for(int i = 0 ; i<= twoStacks->top1;i++)
	{
		printf("%d ",twoStacks->data[i]);
	}
}

void display2(struct twoStacks* twoStacks)
{

	if(isEmpty2(twoStacks))
	{
		printf("Stack underflow.\n");
		return;
	}
	printf("Displaying stack2 elements: ");
	for(int i = (Max+1)/2 ; i< twoStacks->top2;i++)
	{
		printf("%d ",twoStacks->data[i]);
	}
}




void main()
{
	struct twoStacks s1;
	intializeTwoStacks(&s1);

	int option;
	int value;

	while(option!=4)
	{
		printf("\n   Menu   \n");
		printf("1. Push1\n");
		printf("2. Push2\n");
		printf("3. Pop1\n");
		printf("4. Pop2\n");
		printf("5. Display1\n");
		printf("6. Display2\n");
		printf("7. Exit\n");

		printf("Enter option: ");
		scanf("%d",&option);


		switch(option)
		{
		case 1:
			printf("Enter number: ");
			scanf("%d",&value);
			push1(&s1,value);
			break;
		case 2:	
			printf("Enter number: ");
			scanf("%d",&value);
			push2(&s1,value);

			break;

		case 3:
			pop1(&s1);
			break;
		case 4:
			pop2(&s1);
			break;
		case 5:
			display1(&s1);
			break;
		case 6:
			display2(&s1);
			break;
		case 7:
			printf("Exiting app.\n");
			exit(1);
			break;

		default:
			printf("Invalid option. Try again.");
		
		}
	}
}
