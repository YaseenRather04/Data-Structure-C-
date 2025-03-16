#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void delete(int list[], int *a, int k){
    
    int pos = -1;
    
    for(int i = 0; i < *a; i++){
        if(k == list[i]){
            pos = i;
            break;
        }
    }
    
    if(pos == -1){
        
        for(int i = 0; i < *a; i++){
            printf("%d ", list[i]);
        }
        return;
    }
    
    for(int i = pos; i < *a - 1; i++){
            list[i] = list[i + 1];
        }
    
    (*a)--;

    for(int i = 0; i < *a; i++)
        printf("%d ", list[i]);
    
}

int main() {

    int a;
    
    scanf("%d", &a);
    
    int list[a];
    
    for(int i = 0; i < a; i++)
          scanf("%d", &list[i]);
    
    int num;
    
    scanf("%d", &num);
    
    delete(list, &a, num);
    
    return 0;
}
