#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct Node{  
    int data;
    struct node *next;
    struct node *prev;
};

struct Node* createNodeD(int val){
	struct Node *p=(struct Node*)malloc(sizeof(struct Node));
	p->data=val;
	p->next=NULL;
	p->prev=NULL;
	return(p);	
}
void showListD(struct Node *Head){
	if(Head==NULL){
		printf("\nList Is Empty");
	}
	else{
		struct Node *temp=Head;
		printf("\nList Is:\n");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
struct Node* insertAtBegD(struct Node *Head){
	int data;
	printf("\nEnter Node Data: ");
	scanf("%d",&data);
	struct Node *p=createNodeD(data);
	if(Head==NULL){
		Head=p;
	}
	else{
		p->next=Head;
		Head->prev=p;
		Head=p;
	}	
	printf("\nNode Successflly Inserted");
	return(Head);
}
struct Node* getLastNode(struct Node *Head){
	if(Head==NULL){
		return(NULL);
	}
	else{
		struct Node *temp=Head;
		while(temp->next!=NULL)
			temp=temp->next;
		return(temp);
	}
}
struct Node* insertAtLastD(struct Node *Head){
	int data;
	printf("\nEnter Node Data: ");
	scanf("%d",&data);
	struct Node *p=createNodeD(data);
	if(Head==NULL){
		Head=p;
	}
	else{
		struct Node *temp=getLastNode(Head);	
		p->prev=temp;
		temp->next=p;
	}
	printf("\nNode successfully Inserted");
	return(Head);
}
struct Node* searchNodeD(struct Node *Head,int val){
	struct Node *temp=Head;
	while(temp!=NULL){
		if(temp->data==val){
			return(temp);
		}
		temp=temp->next;
	}
	return(NULL);
}
struct Node* insertAtSpecificPositionD(struct Node *Head){
	int data,newData;
	printf("\nEnter The Node Data After Which You Want To Insert New Node: ");
	scanf("%d",&data);

	if(Head==NULL){
		printf("\nList Is Empty");
	}
	else{
		struct Node *temp=searchNodeD(Head,data);
		if(temp==NULL){
			printf("\nNode Not Found In The List, Insertion Not Possible");
		}
		else{
			printf("\nEnter Node Data: ");
			scanf("%d",&newData);  // 1
			struct Node *p=createNodeD(newData);
			if(temp->next==NULL){
				p->prev=temp;
				temp->next=p;
			}
			else{
				p->prev=temp;
				p->next=temp->next;
				//temp->next->prev=p; // dev cpp / trubo , code blocks
				struct Node *pt=temp->next;
				pt->prev=p;
				temp->next=p;	
			}
			printf("\nNode Successfully Inserted");
		}
	}	
	return(Head);
}
void deleteFirstD(struct Node **Head){
	if(*Head==NULL){
	  	printf("\nList Is Empty, Deletion Not Possible");
	}                                       
	else{
	  	if((*Head)->next==NULL){
	  		free(*Head);
	  		*Head=NULL;
	  	}	
	  	else{
	  		struct Node *temp=*Head;
	  		*Head=(*Head)->next;
	  		(*Head)->prev=NULL;
	  		free(temp);
	  	}
	  	printf("\nNode Successfully Deleted");
	}
}
struct Node* deleteLastD(struct Node *Head){
	if(Head==NULL){
		printf("\nList Is Empty, Deletion Not Possible");
	}
	else{
		struct Node *temp=getLastNode(Head);
		if(Head->next==NULL){
			free(Head);
			Head=NULL;
			printf("\nNode Deleted, List Is Empty Now");
		}
		else{
			//temp->prev->next=NULL;
			struct Node *pt=temp->prev;
			pt->next=NULL;
			free(temp);	
			printf("\nNode Deleted");
		}
	}
	return(Head);
}
struct Node* deleteSpecificNodeD(struct Node *Head){
	if(Head==NULL){
		printf("\nList Is Empty, Deletion Not Possible");
	}
	else{
		int data;
		printf("\nEnter The Node Data You Want To Delete: ");
		scanf("%d",&data);
		
		struct Node *temp=searchNodeD(Head,data);
		if(temp==NULL){
			printf("\nNode Not Found In The List, Deletion Not Possible");
		}
		else{
			if(Head->next==NULL){
				free(temp);
				Head=NULL;
				printf("\nNode Successfully Deleted, List Is Empty Now");
			}
			else if(temp->next==NULL){
				struct Node *pt=temp->prev;
				pt->next=NULL;
				free(temp);
				printf("\nNode Successfully Deleted, This Was The Last Node");
			}
			else{
				//temp->prev->next=temp->next;
				struct Node *ptr=temp->prev;
				ptr->next=temp->next;
				
				//temp->next->prev=temp->prev;
				struct Node *ptr2=temp->next;
				ptr2->prev=temp->prev;
				printf("\nNode Successfully Deleted, This Was A Middle Node");	
			}
		}	
	}
	return(Head);	
}

void updateNodeD(struct Node *Head){
	if(Head==NULL){
		printf("\nList Is Empty, Kindly Insert Some Node");
	}
	else{
		int data;
		printf("\nEnter The Node data You Want To Update: ");
		scanf("%d",&data);
		struct Node *pt=searchNodeD(Head,data);
		if(pt==NULL){
			printf("\nNode Not Found, Hence Update Can Not Be Done");
		}
		else{
			int newData;
			printf("\nEnter The New Node data: ");
			scanf("%d",&newData);
			pt->data=newData;
			printf("\nNode Successfully Updated");
		}
	}
}
int Menu(){
	int choice;
	
	printf("\n1. Insert Node At Start");
	printf("\n2. Insert Node At Last");
	printf("\n3. Insert Node At A Specific Position");
	
	printf("\n4. Delete First Node");
	printf("\n5. Delete Last Node");
	printf("\n6. Delete Specific Node");
	
	printf("\n7. Show List");  // traversing the linked list
	printf("\n8. Update A Node");
	
	printf("\n9. Exit");
	printf("\n10. Get Last Node");
	
	printf("\nEnter Your Choice: ");
	scanf("%d",&choice);
	return(choice);
}

int main(){
	int breakInfiniteLoop=0;
	struct Node *Head=NULL;
	
	while(1){
        system("cls");
        switch (Menu()){
        	case 1:
        		Head=insertAtBegD(Head);
        		getch();
        		break;
        	case 2:
        		Head=insertAtLastD(Head);
        		getch();
        		break;
        	case 3:
        		Head=insertAtSpecificPositionD(Head);
        		getch();
        		break;
        	case 4:
        		deleteFirstD(&Head);
        		getch();
        		break;
        	case 5:
        		Head=deleteLastD(Head);
        		getch();
        		break;
        	case 6:
        		Head=deleteSpecificNodeD(Head);
        		getch();
        		break;
        	case 7:
        		showListD(Head);
        		getch();
        		break;
        	case 8:
        		updateNodeD(Head);
        		getch();
        		break;
        	case 9:
            	breakInfiniteLoop=1;
            	break;
            case 10:
            	if(Head!=NULL)
            		printf("Last Node Is: %d",getLastNode(Head)->data);
            	else
            		printf("\nList Is Empty");
            	getch();
            	break;
            default:
            	printf("\nInvalid Choice");
        }//end of swicth
        if(breakInfiniteLoop==1)
            break;
    }// end of infinite loop
    return(0);
}


