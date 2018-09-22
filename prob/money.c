#include <stdio.h>
#include <stdlib.h>

int max = 100000;
int money;

void print_menu(){
	printf("1. Make money\n");
	printf("2. Give money\n");
    printf("3. Check pocket\n");
	printf("4. Quit\n\n>");
}

void check_pocket(){
    printf("You have %d won.\n\n", money);
}
void make_money(){
    int input;
    printf("I can give U money (Max : %d)\n>", max);
    scanf("%d", &input);
    if(input > max){
        puts("Stop! R U trying to meet jang bbae ki???");
        return;
    }
    else{
        money+=input;
        max-=input;
        check_pocket();
    }
}

void give_money(){
    int input;
    printf("U can give me money(your money : %d)\n>", money);
    scanf("%d", &input);
    if(input > money){
        puts("U don't have enough money;;;");
        return;
    }
    else{
        money-=input;
        max+=input;
        check_pocket();
    }
}

void get_flag(){
    int n;
    if(money < 0x70000000){
        printf("U don't have enough money;;;;;\n");
        printf("You must have at least %d won",0x70000000);
        fflush(stdin);
        return;
    }
    else{
        puts("Congratz");
        system("cat flag");
    }
}

int main(){
	setvbuf(stdin,0,_IONBF,0);
	setvbuf(stdout,0,_IONBF,0);
	int menu=1;
	while(1){
		print_menu();
        scanf("%d", &menu);
		switch(menu){
			case 1:
                make_money();
				break;
			case 2:
                give_money();
				break;
            case 3:
                check_pocket();
                break;
			case 4:
                puts("Maybe U should learn about Integer Overflow\nBye!");
				exit(0);
            case 31337:
                get_flag();
			default:
				printf("Wrong input!\n");
		}
	}
	return 0;
}
