#include<stdio.h>
#include<conio.h>
void printboard();
int checkwin();

char board[]={'0','1','2','3','4','5','6','7','8','9'};

void main(){
    int player=1,input,status=-1,choice;
    do{
    player=(player%2==0)?2:1;  
    char mark=(player==1)?'x':'0';
    printf("Enter your choice\n");
    scanf("%d",&input);
    if(input<1 || input>9){
        printf("Invalid input");
    }
    board[input]=mark;
    printboard();
    int result=checkwin();
    if(result==1){
        printf("Winner\n");
    }else if(result==0){
        printf("Draw\n");
    }
    player++;
    }while(status==-1);
}

void printboard(){
    printf("---TIC TAC TOE---");
     printf("  |    |  \n");
    printf(" %c|  %c | %c \n",board[1],board[2],board[3]);
    printf("__|____|__\n");
    printf("  |    |  \n");
    printf(" %c|  %c | %c \n",board[4],board[5],board[6]);
    printf("__|____|__\n");
     printf("  |    |   \n");
    printf(" %c|  %c |  %c \n",board[7],board[8],board[9]);
    printf("\n\n");
}

int checkwin(){
    if(board[1]==board[2] && board[2]==board[3]){
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7]){
        return 1;
    }
    if(board[7]==board[8] && board[8]==board[9]){
        return 1;
    }
    if(board[3]==board[6] && board[6]==board[9]){
        return 1;
    }
    if(board[1]==board[5] && board[5]==board[9]){
        return 1;
    }
    if(board[3]==board[5] && board[5]==board[7]){
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8]){
        return 1;
    }
    if(board[4]==board[5] && board[5]==board[6]){
        return 1;
    }
    int count=0;
    for(int i=1; i<=9; i++){
        if(board[i]=='x' || board[i]=='0'){
            count++;
        }
    }
    if(count==9){
        return 0;
    }
    return -1;
}