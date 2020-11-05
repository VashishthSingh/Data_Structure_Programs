#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void printArray(char ar[3][3]){
    int i,j;
    for(i=0;i<3;i++){
        printf("-------------\n|");
        for(j=0;j<3;j++){
            printf(" %c |",ar[i][j]);
        }
        printf("\n");
    }
    printf("-------------\n");
}
void initialMessage(){
    printf("\nInstruction");
    printf("\n1st Player Symbol::0\n2nd Player Symbol::x");
    printf("\nLet's Begin:");
    printf("\nPress Any Key To Start:");
    getch();
}
int validate(char ar[3][3]){
    int i,a0[8]={0},ax[8]={0};
    for(i=0;i<3;i++){
        if(ar[0][i]=='0')   { a0[0]++; }
        if(ar[1][i]=='0')   { a0[1]++; }
        if(ar[2][i]=='0')   { a0[2]++; }
        if(ar[i][0]=='0')   { a0[3]++; }
        if(ar[i][1]=='0')   { a0[4]++; }
        if(ar[i][2]=='0')   { a0[5]++; }
        if(ar[i][i]=='0')   { a0[6]++; }
        if(ar[i][2-i]=='0') { a0[7]++; }
    }
    for(i=0;i<3;i++){
        if(ar[0][i]=='x')   { ax[0]++; }
        if(ar[1][i]=='x')   { ax[1]++; }
        if(ar[2][i]=='x')   { ax[2]++; }
        if(ar[i][0]=='x')   { ax[3]++; }
        if(ar[i][1]=='x')   { ax[4]++; }
        if(ar[i][2]=='x')   { ax[5]++; }
        if(ar[i][i]=='x')   { ax[6]++; }
        if(ar[i][2-i]=='x') { ax[7]++; }
    }
    for(i=0;i<8;i++){
        if(a0[i]==3){
            return(1);
        }
    }
    for(i=0;i<8;i++){
        if(ax[i]==3){
            return(2);
        }
    }
    return(0);
}
int main(){ 
    system("cls");
    char ar[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int flag=1,position,wonOrNot,drawGame=0;
    char ch;
    initialMessage();
    while(1){
        system("cls");
        printArray(ar);
        if(flag==1)
            printf("\nEnter A Position Number Between 1 to 9 For 1st Player: ");
        else
            printf("\nEnter A Position Number Between 1 to 9 For 2nd Player: ");
        scanf("%d",&position);
        if(position>=1 && position<=9){
            if(flag==1){
                ch='0';
                flag=2;
            }
            else{
                ch='x';
                flag=1;
            }
            if(position<=3){
                if(ar[0][position-1]!='0' && ar[0][position-1]!='x'){
                    ar[0][position-1]=ch;
                    drawGame++;
                } 
                else{
                    printf("\nYou Can Not Insert The Symbol Here: Choose Other Pos:");
                    getch();
                    if(ch=='0')
                        flag=1;
                    else
                        flag=2;
                }    
            }
            else if(position>3 && position<=6){
                if(ar[1][position-4]!='0' && ar[1][position-4]!='x'){
                    ar[1][position-4]=ch;
                    drawGame++;
                }
                else{
                    printf("\nYou Can Not Insert The Symbol Here: Choose Other Pos:");
                    getch();
                    if(ch=='0')
                        flag=1;
                    else
                        flag=2;
                }
            }
            else{
                if(ar[2][position-7]!='0' && ar[2][position-7]!='x'){
                    ar[2][position-7]=ch;
                    drawGame++;
                } 
                else{
                    printf("\nYou Can Not Insert The Symbol Here: Choose Other Pos:");
                    getch();
                    if(ch=='0')
                        flag=1;
                    else
                        flag=2;
                }
            }
            wonOrNot=validate(ar);
            if(wonOrNot==1){
                system("cls");
                printArray(ar);
                printf("\nPlayer 1st Won The Game:");
                //break;
            }
            else if(wonOrNot==2){
                system("cls");
                printArray(ar);
                printf("\nPlayer 2nd Won The Game:");
                //break;
            }
            if(drawGame==9 && wonOrNot==0){
                system("cls");
                printArray(ar);
                printf("\nGame Draw:");
                //break;
            }
            if(wonOrNot==1 || wonOrNot==2 || (drawGame==9 && wonOrNot==0)){
                printf("\nEnter Y To Play Again Or Other Key To Exit: ");
                char playAgain;
                fflush(stdin);
                scanf("%c",&playAgain);
                if(playAgain=='Y' || playAgain=='y'){
                    flag=1;
                    drawGame=0;
                    for(int i=0;i<3;i++){
                        ar[0][i]=i+49;
                        ar[1][i]=i+52;
                        ar[2][i]=i+55;
                    }
                    printf("\nYou Choose To Play Again:");
                    printf("\nEnter Any Key To Start The Game Again");
                    getch();
                }
                else{
                    break;
                }
            }
        }
        else{
            printf("\nInvalid Position:");
        }
    }//end of infinite loop
    printf("\nThanks For Playing THe Game:");
    getch();
    return 0;
}