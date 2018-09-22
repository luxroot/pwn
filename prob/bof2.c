#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv){
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stdout,NULL,_IONBF,0);
    volatile int iq;
    char buf[64];
    int len;
    iq=0;
    printf("Hello SMC student, I know your IQ is : %d\n",iq);
    puts("If your IQ is 0x414345, I will give you flag..");
    printf("By the way, what is your name?\n>");
    len = read(0,buf,68);
    buf[len-1]=0;
    printf("Hi %s! Your IQ is 0x%08x!\n", buf, iq);

    if(iq==0x414345){
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
