#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Stack{
	int top;
	int capacity;
	int *arr;
};
struct Stack* createStack(int cap){
	struct Stack *stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->top=-1;
	stack->capacity=cap;
	stack->arr=(int*)malloc(sizeof(int)*stack->capacity);
	return(stack);
}
int MEnu(){
	int choice;
	printf("\n1. Push");
	printf("\n2. Pop");
	printf("\n3. Show Stack");
	printf("\n4. Exit");
	
	printf("\nEnter The Choice: ");
	scanf("%d",&choice);
	return(choice);
}
// OverFlow 
int isStackFull(struct Stack *stack){
	if(stack->top==stack->capacity-1)
		return(1);
	else
		return(0);		
}
// UnderFlow
int isStackEmpty(struct Stack *stack){
	if(stack->top==-1)
		return(1);
	else
		return(0);
}
void doubleStack(struct Stack *stack){
	int i,j;
	stack->capacity=(stack->capacity)*2;
	int *temp=(int*)malloc(stack->capacity*sizeof(int));
	for(i=0,j=0;i<=stack->top;i++,j++){
		temp[j]=stack->arr[i];
	}
	free(stack->arr);
	stack->arr=temp;
}
void halfStack(struct Stack *stack){
	if(stack->top==((stack->capacity)/2)-1 && stack->capacity>5){
		stack->capacity=(stack->capacity)/2;
		int *temp=(int*)malloc(stack->capacity*sizeof(int));
		int i,j;
		for(i=0,j=0;i<=stack->top;i++,j++){
			temp[j]=stack->arr[i];
		}
		free(stack->arr);
		stack->arr=temp;
		printf("\nStack Half Done\n");
	}
}
void push(struct Stack *stack){
	if(isStackFull(stack)){
		doubleStack(stack);
		printf("\nStack Size Doubled");
	}
	int val;
	printf("\nEnter The Value: ");
	scanf("%d",&val);
	stack->top++;
	stack->arr[stack->top]=val;
	printf("\nValue Pushed");
}
void printStatusOfStack(struct Stack *stack){
	printf("\n---------------------");
	printf("\nStack Capacity : %d",stack->capacity);
	printf("\nStack Top : %d",stack->top);
	printf("\nStack Size : %d",4*stack->capacity);
	printf("\n---------------------");
}
void pop(struct Stack *stack){
	if(isStackEmpty(stack)){
		printf("\nUnderflow Condition, Pop is Not Allowed");
	}
	else{
		int val=stack->arr[stack->top];
		stack->top--;
		printf("\nPoped Value Is: %d",val);
		halfStack(stack);
	}
}
void showStack(struct Stack *stack){
	if(isStackEmpty(stack)){
		printf("\nStack Is Empty ");
	}
	else{
		int index;
		printf("\nStack Elements Are:\n");
		for(index=0;index<=stack->top;index++)
			printf("%d ",stack->arr[index]);	
	}
}
int main(){
	struct Stack *stack=createStack(5);
	int breakInfiniteLoop=0;
	while(1){
		system("cls");
		switch (MEnu()){
        	case 1:
        		push(stack);
        		printStatusOfStack(stack);
        		getch();
        		break;
        	case 2:
        		pop(stack);
        		printStatusOfStack(stack);
        		getch();
        		break;
        	case 3:
        		showStack(stack);
        		printStatusOfStack(stack);
        		getch();
        		break;
        	case 4:
        		breakInfiniteLoop=1;
        		break;
            default:
            	printf("\nInvalid Choice");
            	getch();
        }//end of swicth
        if(breakInfiniteLoop==1)
            break;
	}
	return(0);
}




