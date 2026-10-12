#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

int add(int num1,int num2,int score);
int minus(int num1,int num2,int score);
int multiply(int num1,int num2,int score);
int divide(int num1,int num2,int score);
int choice();
void set_keypress_mode(int enable);

int main() {
    int operator=0;
    int num1,num2,n,score=0;
    char ch;
    printf("enter how log do you want to play : ");
    scanf("%i",&n);
    set_keypress_mode(1);
    srand(time(0));
    while (n!=0) {
        num1 = (rand() % 100) + 1;
        num2 = (rand() % 100) + 1;
        switch (operator) {
            case 0:
                printf("+ %i || + %i\n",num1,num2);
                score =add(num1,num2,score);
                break;
            case 1:
                printf("- %i || - %i\n",num1,num2);
                score=minus(num1,num2,score);
                break;
            case 2:
                num1 = (rand() % 10) + 1;
                num2 = (rand() % 10) + 1;
                printf("* %i || * %i\n",num1,num2);
                score=multiply(num1,num2,score);
                break;
            case 3:
                num1 = (rand() % 10) + 2;
                num2 = (rand() % 10) + 2;
                printf("/ %i || / %i\n",num1,num2);
                score=divide(num1,num2,score);
        }
        operator = (rand() % 4);
        printf("\nscore : %i \n",score);
        n--;
    }
    return 0;
}
int add(int num1,int num2,int score) {
    char ch;
    ch = choice();
    switch (ch) {
        case 1:
            score += num1;
            break;
        case 2:
            score += num2;
            break;
    }
    return score;
}
int minus(int num1,int num2,int score) {
    char ch;
    ch = choice();
    switch (ch) {
        case 1:
            score -= num1;
            break;
        case 2:
            score -= num2;
            break;
    }
    return score;
}
int multiply(int num1,int num2,int score) {
    char ch;
    ch = choice();
    switch (ch) {
        case 1:
            score *= num1;
            break;
        case 2:
            score *= num2;
            break;
    }
    return score;
}
int divide(int num1,int num2,int score) {
    char ch;
    ch = choice();
    switch (ch) {
        case 0:
        case 1:
            score /= num1;
            break;
        case 2:
            score /= num2;
            break;
    }
    return score;
}
int choice() {
    char ch = getchar();
    if (ch == '\033') {
        getchar();
        char arrowType = getchar(); 
        switch (arrowType) {
            case 'D':
                return 1;
                break;

            case 'C':
                return 2;
                break;
            case 'q':
                return 0;
            default:
                break;
        }
    }
}
void set_keypress_mode(int enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}
