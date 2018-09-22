#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv){
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stdout,NULL,_IONBF,0);
    volatile int iq;
    char buf[64];
    iq=0;
    printf("Hello SMC student, I know your IQ is : %d\n",iq);
    puts("If your IQ is not 0, I will give you flag..");
    printf("By the way, what is your name?\n>");
    read(STDIN_FILENO,buf,68);
    printf("Hi %s! Your IQ is 0x%08x!\n", buf, iq);
    if(iq){
        FILE* fp = fopen("./flag","r");
        fscanf(fp,"%s",buf);
        printf("Congratz!\n%s\n",buf);
        exit(0);
    }
    else{
        printf("Bye!");
        exit(0);
    }
    return 0;
}
