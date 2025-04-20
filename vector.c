#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// Initialize the vector with default size and capacity
void init_vector(Vector *v) 
{
    v->size = 0;
    v->capacity = 2;  // Starting with a capacity of 2
    v->data = (int *)malloc(v->capacity * sizeof(int));
}

// Push back an element into the vector
void push_back(Vector *v, int value) 
{
    if (v->size >= v->capacity) 
    {
        v->capacity *= 2;  // Double the capacity when it's full
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size] = value;  // Add new value
    v->size++;  // Increment size after adding value
}

// Access element at a given index
int at(Vector *v, int index) 
{
    if (index >= 0 && index < v->size)
        return v->data[index];
    else
        return -1;  // Return -1 if index is out of bounds
}

// Print the vector's elements
void print_vector(Vector *v) 
{
    printf("Vector: ");
    for (int i = 0; i < v->size; i++) 
    {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

// Resize the vector
void resize(Vector *v, int new_size) 
{
    if (new_size > v->capacity) 
    {
        v->capacity = new_size;  // Ensure enough capacity
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->size = new_size;  // Update size to new size
}

// Check if the vector is empty
int is_empty(Vector *v) 
{
    return v->size == 0;
}

// Pop back (remove last element)
void pop_back(Vector *v) 
{
    if (v->size > 0) 
    {
        v->size--;  // Decrease size when removing last element
    }
}

// Clear the vector
void clear(Vector *v) 
{
    v->size = 0;  // Reset size, capacity stays the same
}

// Return a copy of the vector
Vector copy(Vector *v) 
{
    Vector copy_v;
    copy_v.size = v->size;
    copy_v.capacity = v->capacity;
    copy_v.data = (int *)malloc(copy_v.capacity * sizeof(int));
    for (int i = 0; i < v->size; i++) 
    {
        copy_v.data[i] = v->data[i];
    }
    return copy_v;
}

// Get the first element (front)
int front(Vector *v) 
{
    return v->size > 0 ? v->data[0] : -1;
}

// Get the last element (back)
int back(Vector *v) 
{
    return v->size > 0 ? v->data[v->size - 1] : -1;
}

// Get the first iterator (begin)
int *begin(Vector *v) 
{
    return v->data;
}

// Get the last iterator (end)
int *end(Vector *v) 
{
    return v->data + v->size;
}

// Get the first reverse iterator (rbegin)
int *rbegin(Vector *v) 
{
    return v->data + v->size - 1;
}

// Get the last reverse iterator (rend)
int *rend(Vector *v) 
{
    return v->data - 1;
}

// Free the vector's resources
void free_vector(Vector *v) 
{
    free(v->data);
}



























int myfun() 
{
    int n;
    while (1) 
    {
        // printf("Please enter an integer: ");
        
        // Try to read the input
        if (scanf("%d", &n) == 1) 
        {
            // If the input is a valid integer, break out of the loop
            return n;
        }
         else 
        {
            // If input is not an integer, show an error message and clear the input buffer
            printf("Invalid input!");
            printf("Please enter a valid integer : ");
            
            // Clear the invalid input from the buffer
            while (getchar() != '\n'); // Flush the rest of the line (clear invalid input)
        }
    }
}