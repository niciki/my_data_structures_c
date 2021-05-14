#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Item{
    struct Item *prev;
    int data;
}Item;

typedef struct stack{
    struct Item * top;
    int size;
}stack;

void stack_create(stack * s){
    s->top = 0;
    s->size = 0;
}

void stack_add(stack * s, int a){
    struct Item * b = malloc(sizeof(Item));
    b->prev = s->top;
    b->data = a;
    s->top = b;
    s->size++;
}

bool stack_empty(stack * s){
    return s->size == 0;    
}

int size(stack * s){
    return s->size;
}

int top_element(stack * s){
    return s->top->data;
}

void stack_pop(stack * s){
    if(s->size > 0){
        struct Item * i;
        i = s->top;
        s->top = s->top->prev;
        s->size--;
        free(i);
    }
}

void destroy(stack * s){
    while(s->size > 0){
        struct Item *i;
        i = s->top;
        s->top = s->top->prev;
        free(i);
        s->size--;
    }
    s->top = 0;
}

void stack_print(stack *s){
    struct Item * a = s->top;
    printf("Stack print: ");
    while(a != 0){
        printf("%d ", a->data);
        a = a->prev;
    }
    printf("\n");
}

int main(){
    int a;
    stack s;
    printf("MENU:\n\t1 to create stack\n\t2 to input element\n\t3 to print size\n\t"
    "4 to stack pop\n\t5 to destroy stack\n\t6 to print top elem\n\t7 to stack print\n");
    scanf("%d", &a);
    while(a != 8){
        if(a == 1){
            stack_create(&s);
        } else if(a == 2){
            int b;
            printf("Input elem: ");
            scanf("%d", &b);
            stack_add(&s, b);
        } else if(a == 3){
            printf("%d\n", size(&s));
        } else if(a == 4){
            stack_pop(&s);
        } else if(a == 5){
            destroy(&s);
        } else if(a == 6){
            printf("Top elem : %d \n",top_element(&s));
        } else if(a == 7){
            stack_print(&s);
        }
        scanf("%d", &a);
    }
}
