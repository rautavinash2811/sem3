#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// Function to create a vector
Vector* vector_create() {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v->size = 0;
    v->capacity = 10;
    v->data = (int*)malloc(v->capacity * sizeof(int));
    return v;
}

// Push back function
void vector_push_back(Vector* v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

// Pop back function
void vector_pop_back(Vector* v) {
    if (v->size > 0) {
        --v->size;
    }
}

// Resize function
void vector_resize(Vector* v, size_t new_size) {
    if (new_size > v->capacity) {
        v->capacity = new_size;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->size = new_size;
}

// Access an element by index
int vector_at(Vector* v, size_t index) {
    if (index < v->size) {
        return v->data[index];
    }
    return -1; // Return -1 if index is out of bounds
}

// Check if the vector is empty
int vector_empty(Vector* v) {
    return v->size == 0;
}

// Print vector (Forward)
void vector_print(Vector* v) {
    for (size_t i = 0; i < v->size; ++i) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

// Clear the vector
void vector_clear(Vector* v) {
    v->size = 0;
}

// Return a copy of the vector
Vector* vector_copy(Vector* v) {
    Vector* new_v = vector_create();
    new_v->size = v->size;
    new_v->capacity = v->capacity;
    new_v->data = (int*)malloc(new_v->capacity * sizeof(int));
    for (size_t i = 0; i < v->size; ++i) {
        new_v->data[i] = v->data[i];
    }
    return new_v;
}

// Get the first element
int vector_front(Vector* v) {
    if (v->size > 0) {
        return v->data[0];
    }
    return -1; // Return -1 if vector is empty
}

// Get the last element
int vector_back(Vector* v) {
    if (v->size > 0) {
        return v->data[v->size - 1];
    }
    return -1; // Return -1 if vector is empty
}

// Get the first iterator (begin)
int* vector_begin(Vector* v) {
    if (v->size > 0) {
        return &v->data[0];
    }
    return NULL; // Return NULL if vector is empty
}

// Get the last iterator (end)
int* vector_end(Vector* v) {
    if (v->size > 0) {
        return &v->data[v->size];
    }
    return NULL; // Return NULL if vector is empty
}

// Get the reverse first iterator (rbegin)
int* vector_rbegin(Vector* v) {
    if (v->size > 0) {
        return &v->data[v->size - 1];
    }
    return NULL; // Return NULL if vector is empty
}

// Get the reverse last iterator (rend)
int* vector_rend(Vector* v) {
    if (v->size > 0) {
        return &v->data[-1]; // Just past the first element in reverse iteration
    }
    return NULL; // Return NULL if vector is empty
}
