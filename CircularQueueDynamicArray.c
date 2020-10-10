#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct queue{
	int rear;
	int front;
	int capacity;
	int *arr;
};

struct queue* createQueue(int cap){
	struct queue *p=(struct queue*)malloc(sizeof(struct queue));
	p->rear=-1;
	p->front=-1;
	p->capacity=cap;
	p->arr=(int*)malloc(sizeof(int)*p->capacity);
	return(p);
}
int isQueueEmpty(struct queue *Q){
	if(Q->rear==-1 && Q->front==-1)
		return(1);
	else
		return(0);
}
int isQueueFull(struct queue *Q){
	if((Q->rear+1)%(Q->capacity)==Q->front)
		return(1);
	else
		return(0);
}
int queueSize(struct queue *Q){
	if(Q->front==-1 && Q->rear==-1)
		return(0);
	else{
		if(isQueueFull(Q))
			return(Q->capacity);
		return(((Q->capacity)-(Q->front)+(Q->rear)+1)%(Q->capacity));
	}
}
void showQueueElements(struct queue *Q){
	if(isQueueEmpty(Q)){
		printf("\nQueue Is Empty");
	}
	else{
		int index=Q->front;
		int size=queueSize(Q);
		for(;size--;){
			printf("%d ",Q->arr[index]);
			index=(index+1)%(Q->capacity);
		}
	}
}
void showQueueStatus(struct queue *Q){
	printf("\nFront = %d, Rear = %d, Queue Cap = %d",Q->front,Q->rear,Q->capacity);
}
void doubleQueueCapacity(struct queue *Q){
	int size=queueSize(Q),i;
	int *temp=(int*)malloc(sizeof(int)*((Q->capacity)*2));
	int index=Q->front;
	for(i=0;size--;i++){
		temp[i]=Q->arr[index];
		index=(index+1)%(Q->capacity);
	}
	free(Q->arr);
	Q->capacity=(Q->capacity)*2;
	Q->arr=temp;
	Q->front=0;
	Q->rear=i-1;
}
void halfQueueCapacity(struct queue *Q){
	int size=queueSize(Q),i;
	if(Q->capacity>5 && size==(Q->capacity)/2){
		int *temp=(int*)malloc(sizeof(int)*((Q->capacity)/2));
		int index=Q->front;
		for(i=0;size--;i++){
			temp[i]=Q->arr[index];
			index=(index+1)%(Q->capacity);
		}
		free(Q->arr);
		Q->capacity=(Q->capacity)/2;
		Q->arr=temp;
		Q->front=0;
		Q->rear=i-1;
	}
}
void enqueue(struct queue *Q){
	if(isQueueFull(Q)){
		doubleQueueCapacity(Q);
		showQueueStatus(Q);
	}
	int val;
	printf("\nEnter The Element: ");
	scanf("%d",&val);
	Q->rear=(Q->rear+1)%(Q->capacity);
	if(Q->front==-1)
		Q->front++;
	Q->arr[Q->rear]=val;
	printf("\nEnqueued");
	
}
void deQueue(struct queue *Q){
	if(isQueueEmpty(Q)){
		printf("\nUnderflow Condition, deQueue Is Not Possible");
		showQueueStatus(Q);
	}
	else{
		int val=Q->arr[Q->front]; // val=7
		if(Q->front==Q->rear){
			Q->front=-1;
			Q->rear=-1;
			printf("\nNow Queue Is Empty, Because Only One Ele. Was In THe Q.");
		}
		else{
			Q->front=((Q->front)+1)%(Q->capacity);
			printf("\ndeQueued, Queue Is Not Empty.");
			halfQueueCapacity(Q);
		}
		printf("\ndeQueued Value = %d",val);
		showQueueStatus(Q);
	}
}
int queueMenu(){
	int ch;
	printf("\n1. EnQueue");
	printf("\n2. DeQueue");
	printf("\n3. Get Queue Size");
	printf("\n4. Is Queue Full");
	printf("\n5. Is Queue Empty");
	printf("\n6. Show Queue Elements");
	printf("\n7. Get Front And Rear Status");
	printf("\n8. Exit");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	return(ch);
}

int main(){
	struct queue *Q=NULL;
	Q=createQueue(5);
	int exitInfiniteLoop12=0;
	while(1){
		system("cls");
		switch(queueMenu()){
			case 1:
				enqueue(Q);
				getch();
				break;
			case 2:
				deQueue(Q);
				getch();
				break;
			case 3:
				printf("\nNumber Of Elements Are: %d",queueSize(Q));
				getch();
				break;
			case 4:
				if(isQueueFull(Q))
					printf("\nYes, Queue Is Full");
				else
					printf("\nNo, Queue Is Not Full");
				getch();
				break;
			case 5:
				if(isQueueEmpty(Q))
					printf("\nQueue Is Empty");
				else
					printf("\nNot Empty");
				getch();
				break;
			case 6:
				showQueueElements(Q);
				getch();
				break;
			case 7:
				showQueueStatus(Q);
				getch();
				break;
			case 8:
				exitInfiniteLoop12=1;
				break;
			default:
				printf("\nInvalid Choice");
		}//end of switch
		if(exitInfiniteLoop12==1)
			break;
	}//end of infinite loop
	getch();
	return(0);
}//end of main



