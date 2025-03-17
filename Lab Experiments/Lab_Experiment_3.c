#include <stdio.h>
#include <string.h>
#define max 10000

int checkbalance(char* str){

    int len = strlen(str); //to make a stack to store paranthesis;

    char stack[len]; int top = -1;

    for(int i = 0; i < len; i++){

        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[') stack[++top] = ch;

        else if(ch == ')' || ch == '}' || ch == ']') {

            if(top == -1) return 0;

            else if (ch == ')' && stack[top] != '(') return 0;

            else if (ch == '}' && stack[top] != '{') return 0;

            else if (ch == ']' && stack[top] != '[') return 0;

            else stack[top--] = 0;

        }

    }

    if(top == -1) return 1;

    else return 0;

}

int main(){
    
    char str[max];

    gets(str);

    if(checkbalance(str)) printf("True");

    else printf("False");


    return 0;
}
