#ifndef VECTOR_H
#define VECTOR_H

// Structure definition for Vector
typedef struct 
{
    int *data;      // Pointer to the array of elements
    int size;       // Number of elements in the vector
    int capacity;   // Total allocated space for the vector
} Vector;

// Function declarations
void init_vector(Vector *v);          // Initialize the vector
void push_back(Vector *v, int value); // Add an element to the end
int at(Vector *v, int index);         // Access element at index
void print_vector(Vector *v);         // Print vector elements
void resize(Vector *v, int new_size); // Resize the vector
int is_empty(Vector *v);              // Check if the vector is empty
void pop_back(Vector *v);             // Remove the last element
void clear(Vector *v);                // Clear the vector
Vector copy(Vector *v);               // Return a copy of the vector
int front(Vector *v);                 // Get the first element (front)
int back(Vector *v);                  // Get the last element (back)
int *begin(Vector *v);                // Get the first iterator (begin)
int *end(Vector *v);                  // Get the last iterator (end)
int *rbegin(Vector *v);               // Get the first reverse iterator (rbegin)
int *rend(Vector *v);                 // Get the last reverse iterator (rend)
void free_vector(Vector *v);          // Free the vector's memory
int myfun();
#endif
