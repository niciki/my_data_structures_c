//vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

typedef struct complex_number{
    int real;
    int im;
}complex_number;

typedef struct vector{
    int number_of_elements;
    int capacity;
    complex_number* number;
}vector;

typedef struct vector_int{
    int number_of_elements;
    int capacity;
    int* elem;
}vector_int;

void vector_create(vector *v,int size);
int is_vector_empty(vector *v);
int size(vector *v);
complex_number load(vector *v,int number);
void resize(vector *v);
void vector_push_back(vector *v, complex_number c);
void vector_print(vector *v);
void vector_create_int(vector_int *v,int size);
void vector_push_back_int(vector_int *v, int c);
void read_from_file(vector_int *string, vector_int *colomn, vector *value, int *num_strings, int *num_colomns);
void resize_int(vector_int *v);
void vector_print_int(vector_int *v);

//vector.c
void vector_create(vector *v,int size){
    v->capacity = size;
    v->number_of_elements = 0;
    v->number = malloc(sizeof(complex_number) * v->capacity);
}

int is_vector_empty(vector *v){
    return  (v->number_of_elements == 0) ? 1 : 0; 
}

int size(vector *v){
    return v->capacity;
}

complex_number load(vector *v,int number){
    if((number >= 0) && (number <= v->capacity - 1)){
        return v->number[number];
    }
}

void resize(vector *v){
    v->capacity++;
    v->number = realloc(v->number, sizeof(complex_number) * v->capacity);
}

void vector_push_back(vector *v, complex_number c) {
    if(v->number_of_elements == v->capacity) {
        resize(v);
    }
    v->number[v->number_of_elements] = c;
    v->number_of_elements++;    
}

void vector_print(vector *v){
    for(int i = 0; i < v->number_of_elements; i++){
        if(i != v->number_of_elements - 1){
            printf("[%d + i * %d] -> ", v->number[i].real, v->number[i].im);
        } else {
            printf("[%d + i * %d]\n", v->number[i].real, v->number[i].im);
        }
    }
}

void vector_create_int(vector_int *v,int size){
    v->capacity = size;
    v->number_of_elements = 0;
    v->elem = malloc(sizeof(int) * v->capacity);
}

void vector_push_back_int(vector_int *v, int c) {
    if(v->number_of_elements == v->capacity) {
        resize_int(v);
    }
    v->elem[v->number_of_elements] = c;
    v->number_of_elements++;    
}

void resize_int(vector_int *v){
    v->capacity++;
    v->elem = realloc(v->elem, sizeof(int) * v->capacity);
}

void vector_print_int(vector_int *v){
    for(int i = 0; i < v->number_of_elements ; i++){
            printf("%d ", v->elem[i]);
    }
    printf("\n");
}

#endif
