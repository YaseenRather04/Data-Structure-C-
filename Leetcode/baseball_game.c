int calPoints(char** operations, int operationsSize) {

    int stack[operationsSize];
    int top = -1;

    for(int i = 0; i < operationsSize; i++){

        if(strcmp(operations[i], "+")==0){

            int sum = stack[top] + stack[top-1];
            stack[++top] = sum;

        }

        else if(strcmp(operations[i], "D")==0) {

            int dou = stack[top] + stack[top];
            stack[++top] = dou;

        }

        else if(strcmp(operations[i], "C")==0) 
            top--;

        else {
            stack[++top]=atoi(operations[i]);
        }

    }

    int solution = 0;

    for(int i = 0; i <= top; i++) solution += stack[i];

    return solution;
    
}