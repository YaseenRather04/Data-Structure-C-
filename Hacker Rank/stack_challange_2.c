#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 100

void operations(int *arr, int top){
    
    int c = top - 2;
    
    for(int i = top; i > c; i--){
        arr[i] = 0;
        top--;
    }
    
    c = top + 4;
    
    for(int i = top + 1; i <= c; i++){
        scanf("%d", &arr[i]);
        top++;
    }
    
    arr[top] = 0;
    top--;
    
    c = top + 2;
    
    for(int i = top + 1; i <= c; i++){
        scanf("%d", &arr[i]);
        top++;
    }
    
    c = top - 3;
    
    for(int i = top; i > c; i--){
        arr[i] = 0;
        top--;
    }
    
    for(int i = top; i >= 0; i--)
        printf("%d ", arr[i]);
    
    
    
}

int main() {

    int top = -1, stack[max], n;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &stack[i]);
    
    top = n - 1;
    
    operations(stack, top);
    
    
    return 0;
}
