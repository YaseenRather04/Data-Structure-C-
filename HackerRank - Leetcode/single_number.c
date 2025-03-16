#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void find(int list[], int *a){

    int flag = 0, pos;
    int arr[*a];
    for(int i = 0; i < *a; i++){
        
        for(int j = 0; j < a; j++){
            if(list[i] == arr[j]){
                break;
            }
            
            else{
                
                for(int j = 0; j < *a; j++){
                    if(list[i] == list[j]){
                        flag++;
                        if(flag == 2){
                            arr[i] == list[j];
                            flag = 0; break;
                        }
                    }
                    
                    
                }
                if(flag == 1){
                        pos = i;
                    }
            }
        }
        
    }
    
    printf("%d", list[pos]);
}

int main() {

    int a;
    
    scanf("%d", &a);
    
    int list[a];
    
    for(int i = 0; i < a; i++)
          scanf("%d", &list[i]);
    
    find(list, &a);
    
    return 0;
}
