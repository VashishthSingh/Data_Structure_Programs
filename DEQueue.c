#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node* createNode(int d){
	struct node *p=(struct node*)malloc(sizeof(struct node));
	p->data=d;
	p->prev=NULL;
	p->next=NULL;
	return(p);
}
void insertAtFront(struct node **front,struct node **rear){
	int data;
	printf("\nEnter The Data: ");
	scanf("%d",&data);
	struct node *p=createNode(data);
	if((*front)==NULL && (*rear)==NULL){
		(*front)=p;
		(*rear)=p;
		printf("\nQueue Was Empty. Now Queue Has One Node.");
	}
	else{
		p->next=(*front);
		(*front)->prev=p;
		(*front)=p;
		printf("\nQueue Had Already Some Nodes. Insertion At Front Successfull");
	}
}
void insertAtRear(struct node **front,struct node **rear){
	int data;
	printf("\nEnter The Data: ");
	scanf("%d",&data);
	struct node *p=createNode(data);
	if((*front)==NULL && (*rear)==NULL){
		(*front)=p;
		(*rear)=p;
		printf("\nQueue Was Empty. Now Queue Has One Node.");
	}
	else{
		p->prev=(*rear);
		(*rear)->next=p;
		(*rear)=p;
		printf("\nQueue Had Already Some Nodes. Insertion At Rear Successfull");
	}
}
void deleteAtFront(struct node **front,struct node **rear){
	if((*front)==NULL && (*rear)==NULL){
		printf("\nDEQueue Is Empty. deletion Not Possible");
	}
	else if((*front)==(*rear)){
		printf("\nDeleted Node Is: %d",(*front)->data);
		free(*front);
		(*front)=NULL;
		(*rear)=NULL;
		printf("\nDEQueue Had Only One Node. Now DEQueue IS Empty");
	}
	else{
		printf("\nDeleted Node Is: %d",(*front)->data);
		(*front)=(*front)->next;
		free((*front)->prev);
		(*front)->prev=NULL;
		printf("\nNode Deleted.");
	}
}
void deleteAtRear(struct node **front,struct node **rear){
	if((*front)==NULL && (*rear)==NULL){
		printf("\nDEQueue Is Empty. deletion Not Possible");
	}
	else if((*front)==(*rear)){
		printf("\nDeleted Node Is: %d",(*rear)->data);
		free(*front);
		(*front)=NULL;
		(*rear)=NULL;
		printf("\nDEQueue Had Only One Node. Now DEQueue IS Empty");
	}
	else{
		printf("\nDeleted Node Is: %d",(*rear)->data);
		(*rear)=(*rear)->prev;
		free((*rear)->next);
		(*rear)->next=NULL;
		printf("\nNode Deleted Successfully.");
	}
}
void showDEQueue(struct node **front){
	if((*front)==NULL){
		printf("\nDEQueue Is Empty");
	}
	else{
		struct node *temp=(*front);
		printf("\nNodes Are:\n");
		while(temp){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
void getFront(struct node **front){
	if((*front)==NULL){
		printf("\nDEQueue Is Empty.");
	}
	else{
		printf("Front Node Data Is: %d",(*front)->data);
	}
}
void getRear(struct node **rear){
	if((*rear)==NULL){
		printf("\nDEQueue Is Empty.");
	}
	else{
		printf("Front Node Data Is: %d",(*rear)->data);
	}
}
int menu(){
	int ch;
	printf("\n1. Insert At Front");
	printf("\n2. Insert At Rear");
	printf("\n3. Delete At Front");
	printf("\n4. Delete At Rear");
	printf("\n5. View DEQueue");
	printf("\n6. Exit");
	printf("\n7. Get Front");
	printf("\n8. Get Rear");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	return(ch);
}
int main(){
	system("cls");
	struct node *front=NULL, *rear=NULL;
	int breakInfiniteLoop=0;
	while(1){
		system("cls");
		switch(menu()){
			case 1:
				insertAtFront(&front,&rear);
				getch();
				break;
			case 2:
				insertAtRear(&front,&rear);
				getch();
				break;
			case 3:
				deleteAtFront(&front,&rear);
				getch();
				break;
			case 4:
				deleteAtRear(&front,&rear);
				getch();
				break;
			case 5:
				showDEQueue(&front);
				getch();
				break;
			case 6:
				breakInfiniteLoop=1;
				break;
			case 7:
				getFront(&front);
				getch();
				break;
			case 8:
				getRear(&rear);
				getch();
				break;
			default:
				printf("\nInvalid Choice");
		}//end of switch
		if(breakInfiniteLoop==1){
			break;
		}
	}//enf of loop
	return(0);
}




