char* removeStars(char* s) {

    int a = strlen(s);
    char* stack = (char*)malloc((a + 1)*sizeof(char));
    int top = -1;
    
    for(int i = 0; i < a;i++){

        if(s[i] != '*'){
            stack[++top] = s[i];
        }
        else{
            top--;
        }
    }


    stack[++top] = '\0';

    return stack;
}