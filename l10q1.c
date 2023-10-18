#include<stdio.h>
#include<stdlib.h>

struct Node{
	int num;
	struct Node* llink;
	struct Node* rlink;
}*head,*tail,*temp;


struct DLL{
	struct Node* head;
	struct Node* tail;
};



void insertEnd(struct DLL* dll ,int val)
{
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->num=val;
	temp->rlink=NULL;
	temp->llink=NULL;

	if(dll->head==NULL){
		// printf("declaring first node");
		dll->head=dll->tail=temp;
		dll->head->rlink=head;
		dll->head->llink=head;
	}
	else
	{
		dll->tail->rlink=temp;
		temp->llink=dll->tail;
		dll->head->llink=temp;
		temp->rlink=dll->head;
		dll->tail=temp;
	}
}

void insertFront(struct DLL* dll, int val)
{
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->num=val;
	temp->rlink=NULL;
	temp->llink=NULL;

	if(dll->head==NULL){
		// printf("declaring first node");
		dll->head=dll->tail=temp;
		dll->head->rlink=head;
		dll->head->llink=head;
	}
	else
	{
		temp->rlink=dll->head;
		temp->llink=dll->tail;
		dll->tail->rlink=temp;
		dll->head->llink=temp;
		dll->head=temp;

	}

}

void deleteEnd(struct DLL* dll)
{
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp=dll->tail;

	if(dll->head==dll->tail)
	{
		printf("%d removed.(single element)\n",dll->tail->num);
		dll->head=dll->tail=NULL;
	}
	else if(dll->head==NULL)
	{
		printf("DLL empty!\n");
		return;
	}
	else{

	dll->tail->llink->rlink=dll->head;
	dll->head->llink=dll->tail->llink;
	dll->tail=dll->tail->llink;
	printf("%d removed from end.\n",temp->num);
	free(temp);
	}
}

void deleteFront(struct DLL* dll)
{
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp=dll->head;

	if(dll->head==dll->tail)
	{
		printf("%d removed.(single element)\n",dll->tail->num);
		dll->head=dll->tail=NULL;
	}
	else if(dll->head==NULL)
	{
		printf("DLL empty!\n");
		return;
	}
	else{

	dll->head->rlink->llink=dll->tail;
	dll->tail->rlink=dll->head->rlink;
	dll->head=dll->head->rlink;
	printf("%d removed from front.\n",temp->num);
	free(temp);
	}
}


void display(struct DLL* dll)
{
	if(dll->head==NULL)
	{
		printf("LL empty!\n");
		return;
	}
	else
	{
		struct Node* temp;
		temp=(struct Node*)malloc(sizeof(struct Node));
		temp=dll->head;

		if(dll->head==dll->tail)
		{
			printf("LL has single element: ");
			printf("-%d-",dll->head->num);
		}
		else{
			printf("DLL elements: \n");
			do
			{
				
				printf("%d-",temp->num);
				temp=temp->rlink;
			}	
			while(temp!=dll->tail);
			printf("%d\n",dll->tail->num);
		}
		

	}
}

void main()
{
	struct DLL* dll;
	dll=(struct DLL*)malloc(sizeof(struct DLL));
	dll->head=NULL;
	dll->tail=NULL;

	int option;

	do
	{
		printf("\n OPTIONS \n");
		printf("1. insert at rear.\n");
		printf("2. insert at front.\n");
		printf("3. remove from rear.\n");
		printf("4. insert from front.\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("select appropriate option: ");
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			int val1;
			printf("enter element(insert rear): ");
			scanf("%d",&val1);
			insertEnd(dll,val1);
			break;

		case 2:
			int val2;
			printf("enter element(insert front): ");
			scanf("%d",&val2);
			insertFront(dll,val2);
			break;

		case 3:
			deleteEnd(dll);
			break;

		case 4:
			deleteFront(dll);
			break;

		case 5:
			display(dll);
			break;

		case 6:
			printf("Exiting programme!\n");
			return;
			break;

		default:
			printf("Enter a valid option!\n");
			break;
		}

	}
	while(option!=6);


	// insertEnd(dll,1);
	// insertEnd(dll,2);
	// insertEnd(dll,3);
	// insertFront(dll,0);
	// deleteEnd(dll);
	// deleteFront(dll);
	// display(dll);
}
