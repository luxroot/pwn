#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void get_flag(){
    system("cat flag");
}

int rps(){
    int computer=rand()%3,len,player=-1,i=0;
    char input[10]={0,};
    switch(computer){
        case 0:
            puts("My choice >Rock");
            break;
        case 1:
            puts("My choice >Paper");
            break;
        case 2:
            puts("My choice >Scissors");
            break;
    }
    printf("Your input(Rock, Scissors, Paper) >");
    len = read(STDIN_FILENO,input,10);
    if(input[len-1]=='\n')  input[len-1]='\0';
    while(input[i]){
        input[i]=toupper(input[i]);
        i++;
    }
    if(!strcmp(input,"ROCK"))   player=2;
    if(!strcmp(input,"SCISSORS"))   player=1;
    if(!strcmp(input,"PAPER"))  player=0;
    if(player==-1)return 0;
    if(player==computer){
        return 1;
    }
    else{
        puts("Seriously??");
        return 0;
    }
}

void intro(){
    puts("===== Play a game with me! =====");
    puts("Do you know rock paper scissors?");
    puts("It's a simple game.. Rock beats scissors,");
    puts("And scissors beat paper.");
    puts("Finally, paper beats rock.");
    puts("So simple rule.. if you win 100times, I'll just give you flag");
}

int main(){
    setvbuf(stdin,0,2,0);
    setvbuf(stdout,0,2,0);
    srand(time(NULL));
    int cnt=0;
    intro();
    while(1){
        printf("\nYou have won %d times.\n",cnt);
        if(cnt >= 100){
            get_flag();
            exit(0);
        }
        cnt += rps();
    }
    exit(0);
    return 0;
}
