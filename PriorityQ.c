#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct node{
	struct node *prev;
	int data;
	int priority;
	struct node *next;
};
struct node* createNode(int d,int pri){
	struct node *p=(struct node*)malloc(sizeof(struct node));
	p->prev=NULL;
	p->data=d;
	p->priority=pri;
	p->next=NULL;
	return(p);
}
void deleteNode(struct node **pQ){
	if((*pQ)==NULL){ 
		printf("\nPriority Queue Is Empty. Deletion Not Possible");
	}
	else{
		if((*pQ)->next==NULL){
			printf("\nDelete Node Is: %d %d",(*pQ)->data,(*pQ)->priority);
			free(*pQ); 
			(*pQ)=NULL; 
		}
		else{
			printf("\nDelete Node Is: %d %d",(*pQ)->data,(*pQ)->priority);
			(*pQ)=(*pQ)->next;  
			free((*pQ)->prev);
                        (*pQ)->prev=NULL;
		}
	}
}
void insertNode(struct node **pQ){
	int data,pri;
	printf("\nEnter Data And Priority For Node: ");
	scanf("%d %d",&data,&pri);
	struct node *p=createNode(data,pri);
	if((*pQ)==NULL){
		(*pQ)=p;
		printf("\nNode Inserted Successfullu. It Was The Very First Node");
	}
	else{
		struct node *temp=(*pQ);
		while(temp->next!=NULL){
			if(temp->priority>pri)
				break;
			temp=temp->next;
		}
		if(temp->priority>pri){
			if(temp->prev==NULL){
				p->next=(*pQ);
				(*pQ)->prev=p;
				(*pQ)=p;
				printf("\nNode Inserted As A First Node");
			}
			else{
				p->next=temp;
				p->prev=temp->prev;
				temp->prev->next=p;
				temp->prev=p;
				printf("\nNode Inserted Somewhere In The Middle");
			}
		}
		else if(temp->priority<=pri){
			p->prev=temp;
			temp->next=p;
			printf("\nNode Inserted As A Last Node");
		}
	}
}
void showPQueue(struct node **pQ){
	if(*pQ==NULL){
		printf("\nPriority Queue In Empty:");
	}
	else{
		struct node *temp=*pQ;
		printf("\n\n");
		while(temp!=NULL){
			printf("%d %d   ",temp->data,temp->priority);
			temp=temp->next;
		}
	}
}
int menu(){
	int ch;
	printf("\n1. Insert");
	printf("\n2. Delete");
	printf("\n3. Show PQ");
	printf("\n4. Exit");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	return(ch);
}
int main(){
	system("cls");
	struct node *pQ=NULL;
	int breakInfiniteLoop=0;
	while(1){
		system("cls");
		switch(menu()){
			case 1:
				insertNode(&pQ);
				showPQueue(&pQ);
				getch();
				break;
			case 2:
				deleteNode(&pQ);
				getch();
				break;
			case 3:
				showPQueue(&pQ);
				getch();
				break;
			case 4:
				breakInfiniteLoop=1;
				break;
			default:
				printf("\nInvalid Choice:");
		}//end of switch
		if(breakInfiniteLoop==1){
			break;
		}
	}//end of infinite loop
	getch();
	return(0);
}


