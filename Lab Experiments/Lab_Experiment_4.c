#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int top1 = -1, top2 = -1;
int operand[100];
char operator[100];

int precedence(char opr) {
    switch (opr) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void doProcess() {
    if (top1 < 1 || top2 < 0) return;

    int x = operand[top1--];
    int y = operand[top1--];
    char opr = operator[top2--];

    int z;
    switch (opr) {
        case '+': operand[++top1] = y + x; break;
        case '-': operand[++top1] = y - x; break;
        case '*': operand[++top1] = y * x; break;
        case '/': operand[++top1] = y / x; break;
        case '^': operand[++top1] = pow(y, x); break;
        default: return;
    }
}

int evalInfixExpression(char *exp) {
    top1 = top2 = -1; // Reset stacks

    int size = strlen(exp);
    for (int i = 0; i < size; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            operand[++top1] = num;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (top2 != -1 && precedence(ch) <= precedence(operator[top2])) {
                doProcess();
            }
            operator[++top2] = ch;
        } else if (ch == '(') {
            operator[++top2] = ch;
        } else if (ch == ')') {
            while (top2 >= 0 && operator[top2] != '(') {
                doProcess();
            }
            if (top2 >= 0) top2--; // Remove '('
        }
    }
    while (top2 != -1) {
        doProcess();
    }
    return operand[top1--];
}

int evalPostfixExpression(char *exp) {
    top1 = -1; // Reset operand stack

    int size = strlen(exp);
    for (int i = 0; i < size; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            operand[++top1] = num;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            doProcess();
        }
    }
    return operand[top1--];
}

int evalPrefixExpression(char *exp) {
    top1 = -1; // Reset operand stack

    int size = strlen(exp);
    for (int i = size - 1; i >= 0; i--) {
        char ch = exp[i];

        if (isdigit(ch)) {
            int num = 0, place = 1;
            while (i >= 0 && isdigit(exp[i])) {
                num = num + (exp[i] - '0') * place;
                place *= 10;
                i--;
            }
            i++;
            operand[++top1] = num;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            doProcess();
        }
    }
    return operand[top1--];
}

int main() {
    char str[100];

    printf("Enter Infix expression: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
    int result = evalInfixExpression(str);
    printf("Result = %d\n", result);

    printf("Enter Postfix expression: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
    result = evalPostfixExpression(str);
    printf("Result = %d\n", result);

    printf("Enter Prefix expression: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
    result = evalPrefixExpression(str);
    printf("Result = %d\n", result);

    return 0;
}
