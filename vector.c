#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

// Create a new vector
Vector* vector_create() 
{
    Vector* v = (Vector*)malloc(sizeof(Vector));
    if (!v) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    v->size = 0;
    v->capacity = 1; // Start with a small capacity
    v->data = (int*)malloc(v->capacity * sizeof(int));
    if (!v->data) 
    {
        free(v);
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return v;
}

// Free memory allocated for the vector
void vector_destroy(Vector* v) 
{
    if (v) 
    {
        free(v->data);
        free(v);
    }
}

// Add an element to the end of the vector
void vector_push_back(Vector* v, int value) 
{
    if (v->size == v->capacity) 
    {
        // Double the capacity if full
        vector_resize(v, v->capacity * 2);
    }
    v->data[v->size++] = value;
}

// Access element at a specific index
int vector_at(const Vector* v, size_t index) 
{
    if (index >= v->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    return v->data[index];
}

// Resize the vector to a new capacity
void vector_resize(Vector* v, size_t new_capacity) 
{
    int* new_data = (int*)realloc(v->data, new_capacity * sizeof(int));
    if (!new_data) 
    {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(1);
    }
    v->data = new_data;
    v->capacity = new_capacity;
}

// Get the size of the vector
size_t vector_size(const Vector* v) 
{
    return v->size;
}

// Get the capacity of the vector
size_t vector_capacity(const Vector* v) 
{
    return v->capacity;
}

// Check if the vector is empty
int vector_empty(const Vector* v) 
{
    return v->size == 0;
}

// Remove the last element
void vector_pop_back(Vector* v) 
{
    if (v->size > 0) 
    {
        v->size--;
    }
}

// Clear the vector
void vector_clear(Vector* v) 
{
    v->size = 0;
}

// Return a copy of the vector
Vector* vector_return_copy(const Vector* v) 
{
    Vector* copy = vector_create();
    copy->size = v->size;
    copy->capacity = v->capacity;
    copy->data = (int*)malloc(copy->capacity * sizeof(int));
    if (!copy->data) 
    {
        vector_destroy(copy);
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t i = 0; i < v->size; i++) 
    {
        copy->data[i] = v->data[i];
    }
    return copy;
}