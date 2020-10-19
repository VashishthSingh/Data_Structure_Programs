#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct NODE{
	int data;
	struct NODE *next;
};
struct NODE* createNode(int val){
	struct NODE *p=(struct NODE*)malloc(sizeof(struct NODE));
	p->data=val;
	p->next=NULL;
	return(p);
}
int menuForQueue(){
	int ch;
	printf("\n1. Enqueue");
	printf("\n2. Dequeue");
	printf("\n3. View Queue");
	printf("\n4. Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	return(ch);
}
void enqueue(struct NODE **Q){
	int val;
	printf("\nEnter The value : ");
	scanf("%d",&val);
	struct NODE *p=createNode(val);
	if((*Q)==NULL){
		(*Q)=p;
		printf("\nNode Inserted, And This Was The First Node.");
	}
	else{
		struct NODE *temp=(*Q);
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=p;
		printf("\nNode Inserted At Last.. And Q Was Not Empty.");
	}
}
void dequeue(struct NODE **Q){
	if((*Q)==NULL){
		printf("\nQueue Is Empty.");
	}
	else if((*Q)->next==NULL){
		printf("\nNode Data = %d",(*Q)->data);
		free(*Q);
		(*Q)=NULL;
		printf("\nDeleted.. Queue Is Empty Now.");
	}
	else{
		struct NODE *temp=(*Q);
		printf("\nNode Data = %d",(*Q)->data);
		(*Q)=(*Q)->next;
		free(temp);
		printf("\nNode Deleted.");
	}
}
void showQueue(struct NODE **Q){
	if((*Q)==NULL){
		printf("\nQueue Is Empty.");
	}
	else{
		struct NODE *temp=(*Q);
		while(temp){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
int main(){
	struct NODE *Q=NULL;
	int breakInfiniteLoop1234=0;
	while(1){
		system("cls");
		switch(menuForQueue()){
			case 1:
				enqueue(&Q);
				getch();
				break;
			case 2:
				dequeue(&Q);
				getch();
				break;
			case 3:
				showQueue(&Q);
				getch();
				break;
			case 4:
				breakInfiniteLoop1234=1;
				break;
			default:
				printf("\nInvalid choice");
				getch();
		}
		if(breakInfiniteLoop1234==1)
			break;
	}
	return(0);
}





