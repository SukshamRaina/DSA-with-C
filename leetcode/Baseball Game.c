int calPoints(char** op, int size) {
    int stack[size]; 
    int top = -1;     
    for (int i = 0; i < size; i++) {
        if (strcmp(op[i], "C") == 0) {
            if (top >= 0) top--;
        } 
        else if (strcmp(op[i], "D") == 0) {
            if (top >= 0) {
                stack[top + 1] = 2 * stack[top];  
                top++;
            }
        } 
        else if (strcmp(op[i], "+") == 0) {
            if (top >= 1) {
                stack[top + 1] = stack[top] + stack[top - 1];
                top++;
            }
        } 
        else { 
            stack[++top] = atoi(op[i]);
        }
    }

    int sum = 0;
    for (int i = 0; i <= top; i++) { 
        sum += stack[i];
    }
    
    return sum;
}
