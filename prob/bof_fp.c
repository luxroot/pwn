#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int len;

void get_flag(){
    puts("Congratz! Here U go");
    system("cat flag");
}

void no_flag(){
    puts("No flag... So sad (T.T)");
}

int main(){
    setvbuf(stdin,0,2,0);
    setvbuf(stdout,0,2,0);
    char buf[64]={0,};
    void (*fp)();
    fp = no_flag;
    puts("Do you know about funtion pointer??");
    puts("If you don't know about it, google it! (grin)");
    printf("By the way, what is your name?\n>");
    len = read(0,buf,68);
    if(buf[len-1] == '\n'){
        buf[len-1]='\0';
    }
    printf("Hi %s!\n",buf);
    if(0){
        puts("This part is just a hint");
        puts("I just want you to know there is a function named get_flag");
        exit(0);
    }
    else{
        fp();
        exit(0);
    }
    return 0;
}
