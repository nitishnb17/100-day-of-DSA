#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }

int evaluatePostfix(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int b = pop();
            int a = pop();
            if (ch == '+') push(a + b);
            else if (ch == '-') push(a - b);
            else if (ch == '*') push(a * b);
            else if (ch == '/') push(a / b);
        }
    }
    return pop();
}

int main() {
    char expr[] = "231*+9-";
    printf("Expression: %s\n", expr);
    printf("Result: %d\n", evaluatePostfix(expr));
    return 0;
}
