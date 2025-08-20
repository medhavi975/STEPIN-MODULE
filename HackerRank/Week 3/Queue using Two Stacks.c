#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000


typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int val) {
    s->arr[++(s->top)] = val;
}

int pop(Stack* s) {
    return s->arr[(s->top)--];
}

int peek(Stack* s) {
    return s->arr[s->top];
}

int main() {
    int q;
    scanf("%d", &q);

    Stack stack_in, stack_out;
    init(&stack_in);
    init(&stack_out);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {   
            int x;
            scanf("%d", &x);
            push(&stack_in, x);
        } 
        else if (type == 2) {  
            if (isEmpty(&stack_out)) {
                while (!isEmpty(&stack_in)) {
                    push(&stack_out, pop(&stack_in));
                }
            }
            pop(&stack_out);
        } 
        else if (type == 3) {  
            if (isEmpty(&stack_out)) {
                while (!isEmpty(&stack_in)) {
                    push(&stack_out, pop(&stack_in));
                }
            }
            printf("%d\n", peek(&stack_out));
        }
    }

    return 0;
}

