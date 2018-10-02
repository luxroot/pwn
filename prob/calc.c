#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int cnt;

void get_flag(){
    puts("Congratz!");
    system("cat flag");
}

void intro(){
    setvbuf(stdin,0,2,0);
    setvbuf(stdout,0,2,0);
    srand(time(NULL));
    puts("=== simple calc ===");
    puts("you will need a calculator to solve this prob");
    puts("simple rule : just solve the problem");
    puts("there are 4 operators, +:add -:sub *:mul /:div");
    puts("ex: prob ]add 5 10");
    puts("    ans ]15");
    puts("ex: prob ]mul 2 23");
    puts("    ans ]46");
    puts("if you solve 100 probs, I will give you flag!");
}

int prob(){
    int a,b,ans,inp=0xFFFFFFFF;
    char op[4]={0,};
AA:
    a=rand()%45000;
    b=rand()%45000;
    switch(rand()%4){
        case 0:
            strcat(op,"add");
            ans=a+b;
            break;
        case 1:
            strcat(op,"mul");
            ans=a*b;
            break;
        case 2:
            strcat(op,"div");
            b=rand()%10+1;
            ans=a/b;
            break;
        case 3:
            strcat(op,"sub");
            if(a-b==-1)goto AA;
            ans=a-b;
    }
    printf("prob >%s %d %d\nans :",op,a,b);
    scanf("%d", &inp);
    if(inp==ans){
        puts("Y34h!");
        return 1;
    }
    puts("Seriously?");
    return 0;
}

int main(){
    intro();
    while(1){
        printf("\n\nYou solved %d problems\n",cnt);
        if(cnt>=100){
            get_flag();
            exit(0);
        }
        cnt += prob();
    }
    exit(0);
    return 0;
}
