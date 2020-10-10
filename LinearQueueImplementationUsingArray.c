#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct linearQueue{
	int rear;
	int front;
	int capacity;
	int *arr;
};
struct linearQueue* createLinearQueue(int cap){
	struct linearQueue *p=(struct linearQueue*)malloc(sizeof(struct linearQueue));
	p->rear=-1;
	p->front=-1;
	p->capacity=cap;
	p->arr=(int*)malloc(sizeof(int)*p->capacity);
	return(p);
}
int isLinearQueueEmpty(struct linearQueue *Q){
	if(Q->rear==-1 && Q->front==-1)
		return(1);
	else
		return(0);
}
int isLinearQueueFull(struct linearQueue *Q){
	if(Q->rear==Q->capacity-1)
		return(1);
	else
		return(0);
}
int linearQueueSize(struct linearQueue *Q){
	if(Q->front==-1 && Q->rear==-1)
		return(0);
	else{
		return((Q->rear)-(Q->front)+1);
	}
}
void showLinearQueueElements(struct linearQueue *Q){
	if(isLinearQueueEmpty(Q)){
		printf("\nLinear Queue Is Empty");
	}
	else{
		int index=Q->front;
		for(;index<=Q->rear;index++){
			printf("%d ",Q->arr[index]);
		}
	}
}
void showLinearQueueStatus(struct linearQueue *Q){
	printf("\nFront = %d, Rear = %d",Q->front,Q->rear);
}
void enqueueToLinearQueue(struct linearQueue *Q){
	if(isLinearQueueFull(Q)){
		printf("\nOverflow Condition, Enqueue Is Not Possible.");
		showLinearQueueStatus(Q);
	}
	else{
		int val;
		printf("\nEnter The Element: ");
		scanf("%d",&val);
		Q->rear++;
		if(Q->front==-1)
			Q->front++;
		Q->arr[Q->rear]=val;
		printf("\nEnqueued");
		showLinearQueueStatus(Q);
	}
}
void deQueueToLinearQueue(struct linearQueue *Q){
	if(isLinearQueueEmpty(Q)){
		printf("\nUnderflow Condition, deQueue Is Not Possible");
		showLinearQueueStatus(Q);
	}
	else{
		int val=Q->arr[Q->front]; 
		if(Q->front==Q->rear){
			Q->front=-1;
			Q->rear=-1;
			printf("\nNow Queue Is Empty, Because Only One Ele. Was In THe Q.");
		}
		else{
			Q->front++;
			printf("\ndeQueued, Queue Is Not Empty.");
		}
		printf("\ndeQueued Value = %d",val);
		showLinearQueueStatus(Q);
	}
}
int linearQueueMenu(){
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
	struct linearQueue *Q=NULL;
	Q=createLinearQueue(5);
	int exitInfiniteLoop13=0;
	while(1){
		system("cls");
		switch(linearQueueMenu()){
			case 1:
				enqueueToLinearQueue(Q);
				getch();
				break;
			case 2:
				deQueueToLinearQueue(Q);
				getch();
				break;
			case 3:
				printf("\nNumber Of Elements Are: %d",linearQueueSize(Q));
				getch();
				break;
			case 4:
				if(isLinearQueueFull(Q))
					printf("\nYes, Queue Is Full");
				else
					printf("\nNo, Queue Is Not Full");
				getch();
				break;
			case 5:
				if(isLinearQueueEmpty(Q))
					printf("\nQueue Is Empty");
				else
					printf("\nNot Empty");
				getch();
				break;
			case 6:
				showLinearQueueElements(Q);
				getch();
				break;
			case 7:
				showLinearQueueStatus(Q);
				getch();
				break;
			case 8:
				exitInfiniteLoop13=1;
				break;
			default:
				printf("\nInvalid Choice");
		}//end of switch
		if(exitInfiniteLoop13==1)
			break;
	}//end of infinite loop
	getch();
	return(0);
}//end of main







