#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 100

void ops(int *stack, int n){
    
    int top = -1;
    int b = n;

    int stack2[b];
    
    
    while(n > 0){
        int small = stack[0];
        int index = 0;
        
        for(int j = 1; j < n; j++){
            if(stack[j] < small){  
                small = stack[j];
                index = j;
            }
        }
        
        stack2[++top] = small;
        
        for(int j = index; j < n - 1; j++){
             
            stack[j] = stack[j + 1];
        }
        n--;  
    }
    
    for(int i = top; i >=0;i--)
        printf("%d ", stack2[i]);
}

int main() {
    
    int stack[max], n;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &stack[i]);
    
    ops(stack, n);

    
    return 0;
}
