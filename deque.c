typedef struct deque{
    int *elements;
    int capasity;
    int number_of_elements;
} deque;

void deque_create(deque *a){
    a->elements =  malloc(sizeof(int));
    a->capasity = 1;
    a->number_of_elements = 0;
}

int deque_is_empty(deque *a){
    return (a->number_of_elements == 0) ? 1 : 0;
}

void resize(deque *a){
    a->capasity++;
    a->elements = realloc(a->elements, a->capasity * sizeof(int));
}

void deque_push_front(deque *a, int b){ 
    if(a->number_of_elements == a->capasity){
        resize(a);
    }
    int tmp_1, tmp_2;
    tmp_1 = b;
    for(int i = 0; i < a->number_of_elements + 1; i++){
        tmp_2 = a->elements[i];
        a->elements[i] = tmp_1;
        tmp_1 = tmp_2;
    }
    a->number_of_elements++;
}

void deque_push_back(deque *a, int b){ 
    if(a->number_of_elements == deque_size(a)){
        resize(a);
    }
    a->elements[a->number_of_elements] = b;
    a->number_of_elements++;
}

void deque_print(deque *a){
    if(a->number_of_elements == 0){
        printf("Deque is already empty!\n");
        return;
    }
    for(int i = 0; i < a->number_of_elements; i++){
        if(i != a->number_of_elements - 1){
            printf("[%d] -> ", a->elements[i]);
        } else {
            printf("[%d]\n",a->elements[i]);
        }
    }
}

size_t deque_size(deque *a){
    return (size_t)a->capasity;
}

void deque_pop_back(deque *a){
    if(a->number_of_elements > 0){
        a->elements[a->number_of_elements] = 0;
        a->number_of_elements--;
    } else {
        printf("Error deque is already empty!\n");
    }
}

void deque_pop_front(deque *a){
    if(a->number_of_elements > 0){
        for(int i = 0; i < a->number_of_elements - 1; i++){
            a->elements[i] = a->elements[i + 1];
        }
        a->elements[a->number_of_elements - 1]= 0;
        a->number_of_elements--;
    } else {
        printf("Error deque is already empty!\n");
    }
}

void deque_erase(deque *a, int index){
    if(a->number_of_elements > 0){
        for(int i = index; i < a->number_of_elements - 1; i++){
            a->elements[i] = a->elements[i + 1];
        }
        a->elements[a->number_of_elements - 1]= 0;
        a->number_of_elements--;
    } else {
        printf("Error deque is already empty!\n");
    }
}

void deque_insert_index(deque *a, int b, int index){ 
    if(a->number_of_elements == a->capasity){
        resize(a);
    }
    int tmp_1, tmp_2;
    tmp_1 = b;
    for(int i = index; i < a->number_of_elements + 1; i++){
        tmp_2 = a->elements[i];
        a->elements[i] = tmp_1;
        tmp_1 = tmp_2;
    }
    a->number_of_elements++;
}
