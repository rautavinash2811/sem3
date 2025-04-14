#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void init_vector(Vector *v) {
    v->capacity = 2;
    v->size = 0;
    v->data = (int *)malloc(sizeof(int) * v->capacity);
}

void resize(Vector *v, int new_capacity) {
    if (new_capacity <= v->capacity) return;

    int *new_data = (int *)malloc(sizeof(int) * new_capacity);
    for (int i = 0; i < v->size; i++) {
        new_data[i] = v->data[i];
    }

    free(v->data);
    v->data = new_data;
    v->capacity = new_capacity;
}

void push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        resize(v, v->capacity * 2);
    }
    v->data[v->size++] = value;
}

int at(Vector *v, int index) {
    if (index < 0 || index >= v->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return v->data[index];
}

void print_vector(Vector *v) {
    printf("Vector elements: ");
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

int is_empty(Vector *v) {
    return v->size == 0;
}

void pop_back(Vector *v) {
    if (v->size > 0) {
        v->size--;
    }
}

void clear(Vector *v) {
    v->size = 0;
}

Vector copy(Vector *v) {
    Vector new_v;
    new_v.size = v->size;
    new_v.capacity = v->capacity;
    new_v.data = (int *)malloc(sizeof(int) * new_v.capacity);

    for (int i = 0; i < v->size; i++) {
        new_v.data[i] = v->data[i];
    }

    return new_v;
}

int front(Vector *v) {
    if (v->size == 0) {
        printf("Vector is empty\n");
        exit(1);
    }
    return v->data[0];
}

int back(Vector *v) {
    if (v->size == 0) {
        printf("Vector is empty\n");
        exit(1);
    }
    return v->data[v->size - 1];
}

int *begin(Vector *v) {
    return v->data;
}

int *end(Vector *v) {
    return v->data + v->size;
}

int *rbegin(Vector *v) {
    return v->data + v->size - 1;
}

int *rend(Vector *v) {
    return v->data - 1;
}

void free_vector(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
