#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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
int validate(char ar[3][3]){
    int i,a0[8]={0},ax[8]={0};
    for(i=0;i<3;i++){
        if(ar[0][i]=='0'){ a0[0]++; }
        if(ar[1][i]=='0'){ a0[1]++; }
        if(ar[2][i]=='0'){ a0[2]++; }

        if(ar[i][0]=='0'){ a0[3]++; }
        if(ar[i][1]=='0'){ a0[4]++; }
        if(ar[i][2]=='0'){ a0[5]++; }

        if(ar[i][i]=='0'){ a0[6]++; }
        if(ar[i][2-i]=='0'){ a0[7]++; }
    }
    for(i=0;i<3;i++){
        if(ar[0][i]=='x'){ ax[0]++; }
        if(ar[1][i]=='x'){ ax[1]++; }
        if(ar[2][i]=='x'){ ax[2]++; }

        if(ar[i][0]=='x'){ ax[3]++; }
        if(ar[i][1]=='x'){ ax[4]++; }
        if(ar[i][2]=='x'){ ax[5]++; }

        if(ar[i][i]=='x'){ ax[6]++; }
        if(ar[i][2-i]=='x'){ ax[7]++; }
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
    int falg=1,position,wonOrNot,drawGame=0;
    char ch;
    while(1){
        system("cls");
        printArray(ar);
        if(falg==1){
            printf("\nEnter A Number from 1 to 9: For Player 1: ");
        }
        else{
            printf("\nEnter A Number from 1 to 9: For Player 2: ");
        }
        scanf("%d",&position);
        if(position>=1 && position<=9){ // 1 to 9  // 0/x
            if(falg==1){
                ch='0';
                falg=0;
            }
            else{
                ch='x';
                falg=1;
            }
            if(position>=1 && position<=3){ // 1 to 3
                if(ar[0][position-1]!='0' && ar[0][position-1]!='x'){
                    ar[0][position-1]=ch;
                    drawGame++;
                }
                else{
                    printf("\nYou Can Not Place The Char Here. Choose Other Position:");
                    if(ch=='x'){
                        falg=0;
                    }
                    else{
                        falg=1;
                    }
                    getch();
                }
            }
            else if(position>=4 && position<=6){ // 4 to 6
                if(ar[1][position-4]!='0' && ar[1][position-4]!='x'){
                    ar[1][position-4]=ch;
                    drawGame++;
                }
                else{
                    printf("\nYou Can Not Place The Char Here. Choose Other Position:");
                    if(ch=='x'){
                        falg=0;
                    }
                    else{
                        falg=1;
                    }
                    getch();
                }
            }
            else{  // 7 to 9
                if(ar[2][position-7]!='0' && ar[2][position-7]!='x'){
                    ar[2][position-7]=ch;
                    drawGame++;
                }
                else{
                    printf("\nYou Can Not Place The Char Here. Choose Other Position:");
                    if(ch=='x'){
                        falg=0;
                    }
                    else{
                        falg=1;
                    }
                    getch();
                }
            }
            wonOrNot=validate(ar);
            if(wonOrNot==1){
                system("cls");
                printArray(ar);
                printf("\nPlayer One Won The Game:");
                getch();
                //break;
            }
            if(wonOrNot==2){
                system("cls");
                printArray(ar);
                printf("\nPlayer Two Won The Game:");
                getch();
                //break;
            }
            if(drawGame==9 && wonOrNot==0){
                system("cls");
                printArray(ar);
                printf("\nGame Draw:");
                getch();
                //break;
            }
            if(wonOrNot==1 || wonOrNot==2 || (drawGame==9 && wonOrNot==0)){
                printf("\nEnter Y To Play Again Or Other Key To Exit: ");
                char playAgain;
                fflush(stdin);
                scanf("%c",&playAgain);
                if(playAgain=='Y' || playAgain=='y'){
                    falg=1;
                    drawGame=0;
                    int i;
                    //ar[0][0]='1'; ar[1][0]='2';ar[2][0]='3';
                    //ar[1][0]='4'; ar[1][1]='5'; ar[1][2]='6';
                    //ar[2][0]='7'; ar[2][1]='8'; ar[2][2]='9';
                    for(i=0;i<3;i++){
                        ar[0][i]=i+49; // 49->'1' 50->'2'        // 0->1   1->2  2->3
                        ar[1][i]=i+52;// 52->'4'  53->'5'
                        ar[2][i]=i+55;// 55->'7' 56->'8' 57->'9'
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
            printf("\nInvald Position: Enter A Number From 1 To 9 Only:");
            getch();
        }
    }

    getch();
    return(0);
}