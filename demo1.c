#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *start=NULL;
void insertAtB(int);
void insertAtE(int);
struct Node *MiddleNode(struct Node *start);
void deleteAtB();
void deleteAtE();
void deleteAtSP(int);
int NodeCount();
void revdisplay(struct Node *temp);
int searchNode(int);
void showAll();
void revList();
struct Node* removeElements(struct Node* start, int );
void main()
{
	insertAtE(10);
	insertAtE(20);
	insertAtE(30);
	insertAtE(40);
	insertAtE(50);
	removeElements(start,40);
	// revList();
	// showAll();
	// MiddleNode(start);
	// printf(".................\n");
	// printf("searchNode\t=>  %d \n",searchNode(40));
	// revdisplay(start);
	printf(".................\n");
	// deleteAtSP(4);
	// printf("%d\n",NodeCount());
	//  deleteAtB();
	showAll();
}
struct Node* removeElements(struct Node* start, int val) {
    while(start!=NULL && start->data==val)
    {
        struct Node *temp3=start;
        start=start->next;
        free(temp3);
    }
    struct Node *temp1=start;
    struct Node *temp2=NULL;
    while(temp1!=NULL) {
        if(temp1->data == val) {
            temp2->next=temp1->next;
            struct Node *temp3=temp1;
            temp1=temp1->next;
            free(temp3);
        }
        else {
            temp2=temp1;
            temp1=temp1->next;
        }
    }
    return start;
}
struct Node *MiddleNode(struct Node *start)
{
	struct Node *slow=start;
	struct Node *fast=start;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
	// printf("%d\n",slow->data);
}
void showAll()
{
	struct Node *temp1=start;
	while(temp1!=NULL)
	{
		printf("%d\n",temp1->data);
		temp1=temp1->next;
	}
} 
void insertAtB(int x)
{
	struct Node *temp=malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("no space\n");
		return;
	}
	temp->data=x;
	temp->next=start;
	start=temp;
}
void insertAtE(int x)
{
	if(start==NULL)
	{
		insertAtB(x);
		return;
	}
	struct Node *temp1=start;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	struct Node *temp=malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	temp1->next=temp;
}
void deleteAtB()
{
	struct Node *temp1=start;
	if(temp1==NULL)
	{
		printf("free space........\n");
		return;
	}
	start=start->next;
	free(temp1);
}
void deleteAtE()
{
	if(start!=NULL)
	{
		deleteAtB();
		return;
	}
	struct Node *temp1=start;
	struct Node *temp2=start;
	while(temp1->next!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=temp1->next;
	free(temp1);
}
int NodeCount()
{
	int c=0;
	struct Node *temp1=start;
	while(temp1!=NULL)
	{
		c++;
		temp1=temp1->next;
	}
	return c;
}
void deleteAtSP(int p)
{
	if(p<=1)
	{
		deleteAtB();
		return;
	}
	if(p>NodeCount())
	{
		printf("Out of Node\n");
		return;
	}
	struct Node *temp1=start;
	struct Node *temp2=start;
	for(int i=1;i<p-1;i++)
	{
		temp1=temp1->next;
	}
	temp2=temp1->next;
	temp1->next=temp2->next;
	free(temp2);
	
}
int searchNode(int se)
{
	int index=-1;
	struct Node *temp1=start;
	while(temp1!=NULL)
	{
		index++;
		if(temp1->data==se)
		return index;
		
		temp1=temp1->next;
	}
	return -1;
}
void revdisplay(struct Node *temp)
{
	if(temp==NULL)return;
		revdisplay(temp->next);
		printf("%d\n",temp->data);
}
void revList()
{
	struct Node *temp1=start;
	struct Node *temp2=NULL;
	struct Node *temp3;
	while(temp1!=NULL)
	{
		temp3=temp1->next;
		temp1->next=temp2;
		temp2=temp1;
		temp1=temp3;
	}
	start=temp2;
}   