#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int precedinece(char op){

    switch (op)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^': return 3;

    default : return 0;
    
    }
}

char* convertInFixtoPostfix(char* exp){

    int size = strlen(exp), top = -1, index = 0;
    char operator[size];
    char* str = (char*)malloc(size + 1);

    for (int i = 0; i < size; i++)
    {
        char ch = exp[i];

        if(isalnum(ch)) str[index++] = ch;

        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){

            if(top == -1) operator[++top] = ch;
            
            else {
                while (top != -1 && precedinece(ch)<=precedinece(operator[top]))
                {
                    str[index++] = operator[top--];
                }
                operator[++top] = ch;
            }
        }

        else if(ch == '(') operator[++top] = ch;
        
        else if(ch == ')'){
            while (operator[top] != '(') str[index++] = operator[top--];
            top--;
        }
    }

    while(top != -1) str[index++] = operator[top--];
    str[index] = '\0';
    return str;
    

}

char* convertInfixtoPrefix(char* exp){

    int size = strlen(exp), top = -1, index = 0;
    char operator[size];
    char* str = (char*)malloc(size + 1);
    char* rev;

    for (int i = size - 1; i >= 0; i--)
    {
        char ch = exp[i];

        if(isalnum(ch)) str[index++] = ch;

        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){

            if(top == -1) operator[++top] = ch;
            
            else {
                while (top != -1 && precedinece(ch)<=precedinece(operator[top]))
                {
                    str[index++] = operator[top--];
                }
                operator[++top] = ch;
            }
        }

        else if(ch == ')') operator[++top] = ch;
        
        else if(ch == '('){
            while (operator[top] != ')') str[index++] = operator[top--];
            top--;
        }
    }

    while(top != -1) str[index++] = operator[top--];
    str[index] = '\0';
    rev = strrev(str);
    return rev;

}

char* convertPostfixtoinfix(char* exp){

    int size = strlen(exp), top = -1;
    char stack[size][100];

    for(int i = 0; i < size; i++){

        char ch = exp[i];

        if(isalnum(ch)){
            char temp[] = {ch, '\0'};
            strcpy(stack[++top], temp);

        }

        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){

            char *s1 = stack[top--];
            char *s2 = stack[top--];
            char s3[100];
            snprintf(s3, 100, "(%s%c%s)", s2, ch, s1);
            strcpy(stack[++top], s3);
        }
    }

    char* s = stack[top];
    return s;

}

char* convertprefixtoinfix(char* exp){

    int size = strlen(exp), top = -1;
    char stack[size][100];

    for(int i = size - 1; i >= 0; i--){

        char ch = exp[i];

        if(isalnum(ch)){
            char temp[] = {ch, '\0'};
            strcpy(stack[++top], temp);

        }

        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){

            char *s1 = stack[top--];
            char *s2 = stack[top--];
            char s3[100];
            snprintf(s3, 100, "(%s%c%s)", s1, ch, s2);
            strcpy(stack[++top], s3);
        }
    }

    char* s = stack[top];
    return s;

}

int main(){
    
    char exp[100];
    gets(exp);
    printf("%s\n", convertInFixtoPostfix(exp));
    printf("%s\n", convertInfixtoPrefix(exp));
    gets(exp);
    printf("%s\n", convertPostfixtoinfix(exp));
    gets(exp);
    printf("%s\n", convertprefixtoinfix(exp));
    
    return 0;
}