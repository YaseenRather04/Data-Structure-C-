#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void greater(int arr[], int size){
    
    int front = 0, res[size], index = 0, ind = 0;
    
    for(int i = 0; i < size; i++){
        
        bool great = false;
        
        if(i == size - 1){
            if(arr[i] < arr[front]) res[index] = arr[front];
            else if(arr[i]< arr[front + 1]) res[index] = arr[front + 1];
            else res[index++] = -1;
        }
        
        else{
            
            for(int j = i + 1; j < size; j++){
                
                if(arr[i] < arr[j]){
                    great = true;
                    ind = j;
                    break;
                }   
            }
            
            if(great == true) res[index++] = arr[ind];
            else res[index++] = -1;
            
        }
    }
    
    for(int i = 0; i < size; i++) printf("%d ", res[i]);
    
    
}

int main() {
    
    int size;
    
    scanf("%d", &size);
    
    int arr[size];
    
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
    
    greater(arr, size);
       
    return 0;
}
