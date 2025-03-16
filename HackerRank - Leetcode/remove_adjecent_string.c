#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 100000

void reccur(char* str){
    
    int len = strlen(str), top = -1;
    
    char stack[len];
        
        for(int i = 0; i < len; i++){
            
            if(str[i] == stack[top]) stack[top--] = 0;
            
            else stack[++top] = str[i];
            
        }
    
    for(int i = 0; i <= top; i++) printf("%c", stack[i]);
    
}

int main() {

    char str[max]; int n;
    
    gets(str);
    
    reccur(str);
    
    return 0;
}
