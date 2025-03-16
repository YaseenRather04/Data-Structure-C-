#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max_size 100

void stack(int *arr, int top){
    
    for(int i = 0; i < 3; i++){
        scanf("%d", &arr[i]);
        top++;
    }
    
    arr[top] = 0;
    top--;
    
    //top = 2; i = top + 1 == 3

    for(int i = top + 1; i < 5; i++){
        scanf("%d", &arr[i]);
        top++;
    }

    for(int i = top; i > 0; i--){
        arr[i] = 0;
        top--;
    }
   
    printf("%d", arr[top]);

}

int main() {

    int top = -1, arr[max_size];
    
    stack(arr, top);
    
    
    return 0;
}
