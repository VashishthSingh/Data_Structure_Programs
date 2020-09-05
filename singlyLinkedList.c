#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

//function declaration
struct node *createNode(int);
void insertAtBeg();
void showList();
int menu();
struct node* searchNode(int);
void insertAtLast();
void insertAtPosition();
void deleteFirst();

// defining function to create a node
struct node *createNode(int val){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;
    return (ptr);
}
void insertAtLast(){
    int val;
    printf("\nEnter the node value: ");
    scanf("%d", &val);
    struct node *p = createNode(val);
    if(head==NULL){
        head=p;
    }
    else{
        struct node *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=p;
    }
    printf("\nNode Successfully Inserted:");
}
void insertAtBeg(){
    int val;
    printf("\nEnter the node value: ");
    scanf("%d", &val);
    struct node *p = createNode(val);
    if (head == NULL){
        head = p;
    }
    else{
        p->next = head;
        head = p; 
    }
    printf("\nNode Added Successfully:");
}
void insertAtBeg1(struct node **head1){
	int val;
    printf("\nEnter the node value: ");
    scanf("%d", &val);
    struct node *p = createNode(val);
    if (*head1 == NULL){
        *head1 = p;
    }
    else{
        p->next = *head1;
        *head1 = p; 
    }
    printf("\nNode Added Successfully:");
}
void showList(){
    struct node *p=head;
    if(p==NULL){
        printf("\nList is Empty");
    }
    else{
        printf("\nList Is:\n");
        while(p!=NULL){
            printf("%d ",p->data);
            p=p->next;
        }
    }
}
void showList1(struct node **head1){
    struct node *p=*head1;
    if(p==NULL){
        printf("\nList is Empty");
    }
    else{
        printf("\nList Is:\n");
        while(p!=NULL){
            printf("%d ",p->data);
            p=p->next;
        }
    }
}
struct node* searchNode(int data){
    struct node *ptr=head;
    while(ptr!=NULL){
        if(ptr->data==data){
            return(ptr);
        }
        ptr=ptr->next;
    }
    return(NULL);// node is not found but list in not empty
}
void insertAtPosition(){
    int val,data;
    printf("\nEnter the node value: ");
    scanf("%d", &val);
    printf("\nEnter the node value After which new node has to be inserted:");
    scanf("%d", &data);
    struct node *p = createNode(val);
    if(head==NULL){
        printf("\nList is Empty, Insertion not possible");
    }
    else{
        struct node *pt=searchNode(data);
        if(pt==NULL){
            printf("\nNode Not Found In The List");
        }
        else{
            if(pt->next==NULL){
                pt->next=p;
                printf("\nThe Node Inserted as Last Node");
            }
            else{
                p->next=pt->next;
                pt->next=p;
                printf("\nNode Inserted as Middle Node");
            }
        }
    }  
}
void deleteFirst(){
    if(head==NULL){
        printf("\nList Is Empty, Deletion Not Possible");
    }
    else{
        if(head->next==NULL){
            free(head);
            head=NULL;
            printf("\nNode Successfullu Deleted, List Is Empty Now");
        }
        else{
            struct node *temp=head;
            head=head->next;
            free(temp);
            printf("\nNode Successfully Deleted");
        }
    }
}
void deleteLast(){
    if(head==NULL){
        printf("\nList Is Empty, Deletion Is Not Possible");
    }
    else{
        if(head->next==NULL){
            free(head);
            head=NULL;
            printf("\nNode Successfullu Deleted, List Is Empty Now");
        }
        else{
            struct node *temp=head,*pt;
            while(temp->next!=NULL){
                pt=temp;
                temp=temp->next;
            }
            pt->next=NULL;
            free(temp);
            printf("\nNode Successfullu Deleted");
        }
    }
}
void deleteSpecificNode(){
    int data;
    printf("\nEnter The Node Data You Want To Delete: ");
    scanf("%d",&data);
    if(head==NULL){
        printf("\nList Is Empty, Deletion Is Not Possible");
    }
    else{
        struct node *p=searchNode(data);
        if(p==NULL){
            printf("\nThis Node Doesn't Exist In The List");
        }
        else{
            if(head->next==NULL){
                free(head);
                head=NULL;
                printf("\nNode Successfully Deleted, List Is Empty Now");
            }
            else if(head==p){
                deleteFirst();
            }
            else if(p->next==NULL){
                deleteLast();
            }
            else{
                struct node *temp=head;
                while(temp->next!=p){
                    temp=temp->next;
                }
                temp->next=p->next;
                free(p);
                printf("\nMiddle Node Deleted");
            }
        }
    }
}
void updateNode(){
	int data,val;
	if(head==NULL){
		printf("\nList Is Empty, Updation Is Not Possible");
	}
	else{
		printf("\nEnter The Node Data Which Has To Be Updated: ");
		scanf("%d",&data);
		printf("\nEnter The New Data: ");
		scanf("%d",&val);
		struct node *p=searchNode(data);
		if(p==NULL){
			printf("\nThis Node Doesn't Exist");
		}
		else{
			p->data=val;
			printf("\nNode Successfully Updated");
		}
	}	
}
void getLength(){
	if(head==NULL)
		printf("\nLength Of Linked List Is: 0");
	else{
		struct node *temp=head;
		int count=0;
		while(temp!=NULL){
			count++;
			temp=temp->next;
		}
		printf("\nLength Of Linked List Is: %d",count);
	}
}
void deleteAllNode(){
	if(head==NULL){
		printf("\nList Is Empty");
	}
	else{
		struct node *temp=head,*pt;
		while(temp!=NULL){
			pt=temp;
			temp=temp->next;
			free(pt);
		}
		head=NULL;
		printf("\nList Is Now Empty, All Node Got Deleted");
	}
}
void findNode(){
	if(head==NULL){
		printf("\nList Is Empty");
	}
	else{
		int data;
		printf("\nEnter The Node Data You Wnat To Search: ");
		scanf("%d",&data);
		struct node *p=searchNode(data);
		if(p==NULL){
			printf("\nNode Not Found In The List");
		}
		else{
			printf("\nNode Is Present In The List");
		}
	}
}
void reverseLinkedList(){
	if(head==NULL){
		printf("\nList Is Empty");
	}
	else{
		struct node *prev=NULL,*curr=head,*next=NULL;
		while(curr!=NULL){
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		head=prev;
		printf("\nLinked List Reversed");
	}
}

struct node* isCycle() {
    struct node *slow=head,*fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return(fast);
    }
    return(NULL);
}

struct node* getStartingPoint(){
	struct node *temp=head;
	struct node *fast=isCycle();
	while(temp!=fast){ // temp=4000, fast=4000
		temp=temp->next;
		fast=fast->next;
	}
	return(fast);
}

void removeCycle(){
	struct node *temp=head,*last=NULL;
	struct node *fast=isCycle();
	while(temp!=fast){ // temp=4000, fast=4000
		temp=temp->next;
		last=fast;
		fast=fast->next;
	}
	last->next=NULL;
}

int menu(){
    int ch;
    printf("\n1. Insert At start");
    printf("\n2. Insert At End");
    printf("\n3. Insert At Specific Position");
    printf("\n4. View List");
    printf("\n5. Exit");
    printf("\n6. Delete First Node");
    printf("\n7. Delete Last Node");
    printf("\n8. Delete Specific Node");
    printf("\n9. Update The Node");
    printf("\n10. Get Length Of Linked List");
    printf("\n11. Delete All Node From Linked List");
    printf("\n12. Search A Perticular Node");
    printf("\n13. Reverse The Linked List");
    printf("\n14. Insert At Start head1");
    printf("\n15. Show List head1");
    printf("\nEnter Your Choice: ");
    scanf("%d", &ch);
    return (ch);
}

int main(int argc, char const *argv[]){
    int breakInfiniteLoop=0;
    struct node *head1=NULL;
    while(1){
        system("cls");
        switch (menu()){
        case 1:
            insertAtBeg();
            getch();
            break;
        case 2:
            insertAtLast();
            getch();
            break;
        case 3:
            insertAtPosition();
            getch();
            break;
        case 4:
            showList();
            getch();
            break;
        case 5:
            breakInfiniteLoop=1;
            break;
        case 6:
            deleteFirst();
            getch();
            break;
        case 7:
            deleteLast();
            getch();
            break;
        case 8:
            deleteSpecificNode();
            getch();
            break;
        case 9:
        	updateNode();
        	getch();
        	break;
        case 10:
        	getLength();
        	getch();
        	break;
        case 11:
        	deleteAllNode();
        	getch();
        	break;
        case 12:
        	findNode();
        	getch();
        	break;
    	case 13:
    		reverseLinkedList();
    		getch();
    		break;
    	case 14:
    		insertAtBeg1(&head1);
    		getch();
    		break;
    	case 15:
    		showList1(&head1);
    		getch();
    		break;
        default:
            break;
        }
        if(breakInfiniteLoop==1)
            break;
    }// end of infinite loop
    return 0;
}

