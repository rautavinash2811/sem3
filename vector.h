#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

// Define the Vector struct
typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Vector;

// Function declarations
Vector* vector_create();
void vector_push_back(Vector* v, int value);
void vector_pop_back(Vector* v);
void vector_resize(Vector* v, size_t new_size);
int vector_at(Vector* v, size_t index);
int vector_empty(Vector* v);
void vector_print(Vector* v);
void vector_clear(Vector* v);
Vector* vector_copy(Vector* v);
int vector_front(Vector* v);
int vector_back(Vector* v);
int* vector_begin(Vector* v);
int* vector_end(Vector* v);
int* vector_rbegin(Vector* v);
int* vector_rend(Vector* v);

#endif // VECTOR_H
