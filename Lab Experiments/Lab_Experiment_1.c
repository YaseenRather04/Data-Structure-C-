#include<stdio.h>
#include<stdlib.h>

void insert(int *list, int *size){

	int pos, value, i;

	printf("Enter Position : ");
	scanf("%d", &pos);

	printf("Enter Value : ");
	scanf("%d", &value);

	pos--;

	if(pos < 0 || pos >= *size)
		printf("Invalid position !!!!!!\n");

	else{
		for(i=*size; i>pos; i--){
			list[i] = list[i-1];
		}

		list[pos] = value;
		(*size)++;

		printf("Element inserted !!!!\n");
	}
}
void display(int *list, int size){

	if(size == 0){
		printf("List is empty !!!!\n");
	}

	else{
		int i;
		printf("List elements are : \n");

		for(i=0; i<size; i++){
			printf("%d ", list[i]);
		}	
	}
}
void delete(int *list, int *size){
	int pos, i;

	printf("Enter Position : ");
	scanf("%d", &pos);
	pos--;

	if(pos<0 || pos >= *size)
		printf("Invalid position !!!!!!\n");
	else{
		for(i=pos; i<*size-1; i++){
			list[i]=list[i+1];
		}
		(*size)--;
		printf("Element Deleted !!!!!\n");
	}
}
void search(int *list, int size){

	if(size == 0)
		printf("List is empty !!!\n");
	
	else{
        
		int i, value, flag=0;
		printf("Enter searching element : ");
		scanf("%d", &value);
		for(i=0; i<size; i++){
			if(list[i]==value){
				flag = 1;
				break;
			}
		}

		if(flag == 1)
			printf("Element found !!!!\n");
            
		else
			printf("Not Found !!!!!\n");	
	}
}
int main(){
	int list[100], size, i;

	scanf("%d", &size);

	for(i=0; i<size; i++)
		scanf("%d", &list[i]);

    insert(list, &size);

    display(list, size);

    delete(list, &size);

    display(list, size);

    search(list, size);

	
	return 0;
}
