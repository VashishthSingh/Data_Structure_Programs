#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct NOde{   // node, Node, NOde  
	int data;
	struct NOde *next;
};
struct NOde* createNodeS(int val){
	struct NOde *p=(struct NOde*)malloc(sizeof(struct NOde));	
	p->data=val;
	p->next=NULL;
	return(p);
}
int menuForStack(){
	int ch;
	printf("\n1. Push");
	printf("\n2. Pop");
	printf("\n3. View Stack");
	printf("\n4. Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	return(ch);
}
struct NOde* pushTostack(struct NOde *stack){
	int val;
	printf("\nEnter The value : ");
	scanf("%d",&val); // 1
	struct NOde *p=createNodeS(val);
	if(stack==NULL){
		stack=p;
		printf("\nNode Inserted As A First Node");
	}
	else{
		struct NOde *temp=stack;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=p;
		printf("\nNode Inserted");	
	}
	return(stack);
}
struct NOde* popFromStack(struct NOde *stack){
	if(stack==NULL){
		printf("\nPop Is Not Allowed, Stack Is Empty");
	}
	else{
		if(stack->next==NULL){
			printf("\nPoped Node Value Is: %d",stack->data);
			free(stack);
			stack=NULL;
			printf("\nNode Deleted, Stack Is Now Empty");
		}
		else{
			struct NOde *temp=stack,*pt=stack;
			while(temp->next!=NULL){
				pt=temp;
				temp=temp->next;
			}
			printf("\nPoped Node Value Is: %d",temp->data);
			free(temp);
			pt->next=NULL;
			printf("\nNode Deleted");
		}	
	}
	return(stack);
}
void showStack(struct NOde *stack){
	if(stack==NULL){
		printf("\nStack Is Empty");
	}
	else{
		struct NOde *temp=stack;
		printf("\nStack Elements Are:\n");
		while(temp){
			printf("%d ",temp->data);
			temp=temp->next;
		}	
	}
}
int main(){
	struct NOde *stack=NULL;
	int breakInfiniteLoop=0;
	while(1){
		system("cls");
		switch(menuForStack()){
			case 1:
				stack=pushTostack(stack);
				getch();
				break;
			case 2:
				stack=popFromStack(stack);
				getch();
				break;
			case 3:
				showStack(stack);
				getch();
				break;
			case 4:
				breakInfiniteLoop=1;
				break;
			default:
				printf("\nInvalid choice");
				getch();
		}
		if(breakInfiniteLoop==1)
			break;
	}
	return(0);
}





