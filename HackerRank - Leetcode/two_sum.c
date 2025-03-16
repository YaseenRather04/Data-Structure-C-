#include<stdio.h>
#include<stdlib.h>

void sum(int *arr, int *size, int target){
    
    int result[2];
    
    for(int i = 0; i < *size; i++){
        for(int j = i + 1; j < *size;j++){
            
            if(target == arr[i] + arr[j]){
                result[0] = i;
                result[1] = j;
            }
        }
    }
    for(int i = 0; i < 2; i++)
        printf("%d ", result[i]);
}


int main(){
    
    int size, target;
    
    scanf("%d", &size);
    
    int arr[size];
    
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    
    scanf("%d", &target);
    
    sum(arr, &size, target);
    
}