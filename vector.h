#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h> // For size_t

// Define the Vector struct
typedef struct 
{
    int* data;       // Pointer to the dynamic array
    size_t size;     // Number of elements in the vector
    size_t capacity; // Total capacity of the vector
} Vector;

// Function prototypes
Vector* vector_create();                            // Create a new vector
void vector_destroy(Vector* v);                     // Free memory
void vector_push_back(Vector* v, int value);        // Add an element to the end
int vector_at(const Vector* v, size_t index);       // Access element at index
void vector_resize(Vector* v, size_t new_capacity); // Resize the vector
size_t vector_size(const Vector* v);                // Get the size of the vector
size_t vector_capacity(const Vector* v);            // Get the capacity of the vector
int vector_empty(const Vector* v);                  // Check if the vector is empty
void vector_pop_back(Vector* v);                    // Remove the last element
void vector_clear(Vector* v);                       // Clear the vector
Vector* vector_return_copy(const Vector* v);        // Return a copy of the vector

#endif // VECTOR_H