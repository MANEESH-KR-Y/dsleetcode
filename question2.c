int calculate(char* s) {
    int n = 0; // Current number being parsed
    char op = '+'; // Last operator
    int stack[10000]; // Stack to store intermediate results
    int top = -1; // Stack pointer
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (isdigit(ch)) {
            // Parse the current number
            n = n * 10 + (ch - '0');
        } 
        if (!isdigit(ch) && !isspace(ch) || s[i + 1] == '\0') {    // Handle the previous operator
            if (op == '+') {
                stack[++top] = n;
            } else if (op == '-') {
                stack[++top] = -n;
            } else if (op == '*') {
                stack[top] *= n;
            } else if (op == '/') {
                stack[top] /= n; // Integer division truncates towards zero
            }   // Update operator and reset the number
            op = ch;
            n = 0;
        }
    }   // Calculate the final result
    int result = 0;
    while (top >= 0) {
        result += stack[top--];
    }
    return result;
}
