#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void get_flag(){
    puts("Congratz! Here U go");
    system("cat flag");
}

void no_flag(){
    puts("No flag... So sad (T.T)");
}

void greeting(){
    printf("By the way, what is your name?");
    char buf[64];
    read(0,buf,84);
    printf("Hi %s!\n",buf);
    no_flag();
    return;
}

int main(){
    setvbuf(stdin,0,2,0);
    setvbuf(stdout,0,2,0);
    puts("Do you know where return address is??");
    puts("If you don't know about it, google it! (grin)");
    puts("Hint) there's a function named get_flag");
    greeting();
    exit(0);
    return 0;
}
