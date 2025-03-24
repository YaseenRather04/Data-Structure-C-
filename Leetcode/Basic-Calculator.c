int stack[1000], top1 = -1, top2 = -1;
char opr[1000];

int priority(char k){
    switch(k){
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void doProcess(){
    if (top1 < 1 || top2 < 0) return;

    int a = stack[top1--];
    int b = stack[top1--];
    char c = opr[top2--];
    int z;

    switch(c){
        case '+': z = b + a;break;
        case '-': z = b - a;break;
        case '*': z = b * a;break;
        case '/': z = b / a;break;
        case '^': z = (int)pow(b, a);break;
        default: return;
    }
    stack[++top1] = z;
}


int calculate(char* s) {
    
    int size = strlen(s);

    for(int i = 0; i < size; i++){

        if(isdigit(s[i])){
            int num = 0;
            while(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            stack[++top1] = num;
        }

        else if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i]=='^'){
            while(top2 != -1 && priority(s[i]) <= priority(opr[top2]) && s[i] != '^'){
                doProcess();
            }
            opr[++top2] = s[i];
        }
    }

    while(top2 != -1){
        doProcess();
    }

    return stack[top1];

}
