#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Item{
    struct Item *prev;
    struct Item *next;
    int data;
}Item;

typedef struct vector{
    struct Item * start;
    struct Item * fin;
    int size;
}vector;

void vector_create(vector * v){
    v->start = 0;
    v->fin = 0;
    v->size = 0;
}

void vector_push_back(vector * v, int a){
    struct Item * i;
    i = malloc(sizeof(Item));
    if(v->size == 0){
        i->prev = v->fin;
        i->data = a;
        v->start = i;
        v->start->next = v->fin;
    } else {
        i->prev = v->fin;
        i->data = a;
        v->fin = i;
        v->fin->next = 0;
    }
    v->size++;
}

int vector_size(vector * v){
    return v->size;
}

void vector_destroy(vector * v){
    while(v->size > 0){
        v->size--;
        struct Item * i = v->fin;
        v->fin = v->fin->prev;
        free(i);
    }
    v->start = 0;
    v->fin = 0;
}

int vector_return_index(vector * v, int index){
    if(index > v->size - 1){
        printf("Error index is bigger then number of elements in vector!\n");
        return 0;
    }
    struct Item * curr;
    curr = v->fin;
    for(int i = v->size; i > index - 1; i--){
        curr = curr->prev;
    }
    return curr->data;
}

int vector_pop(vector * v){
    struct Item * i = v->fin;
    v->fin = v->fin->prev;
    free(i);
}

void vector_last(vector * v){
    printf("Last elem: %d\n",v->fin->data);
}

void vector_first(vector * v){
    printf("First elem: %d\n",v->start->data);
}

int main(){
    int a, b;
    vector v;
    printf("MENU:\n\t1 to create vector\n\t2 to input element\n\t3 to print size\n\t"
    "4 to vector pop\n\t5 to destroy vector\n\t6 to print index elem\n\t7 to vector print\n"
    "\t8 to print first element\n\t9 to print last element\n\t10 to exit\n");
    scanf("%d", &a);
    while(a != 10){
        if(a == 1){
            vector_create(&v);
        } else if(a == 2){
            printf("Input elem: ");
            scanf("%d", &b);
            vector_push_back(&v, b);
        } else if(a == 3){
            printf("%d\n", vector_size(&v));
        } else if(a == 4){
            vector_pop(&v);
        } else if(a == 5){
            vector_destroy(&v);
        } else if(a == 6){
            printf("Please input index: ");
            scanf("%d", &b);
            printf("Elem : %d \n",vector_return_index(&v, b));
        } else if(a == 7){
            printf("Elem : ");
            for(int i = 0; i < v.size; i++){
                printf("%d ",vector_return_index(&v, i));
            }
            printf("\n");
        } else if(a == 8){
            vector_first(&v);
        } else if(a == 9){
            vector_last(&v);
        }
        scanf("%d", &a);
    }
}
