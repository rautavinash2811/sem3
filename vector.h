#ifndef VECTOR_H
#define VECTOR_H

typedef struct 
{
    int *data;
    int size;
    int capacity;
} Vector;

void init_vector(Vector *v);
void push_back(Vector *v, int value);
int at(Vector *v, int index);
void print_vector(Vector *v);
void resize(Vector *v, int new_capacity); // changed to affect only capacity
int is_empty(Vector *v);
void pop_back(Vector *v);
void clear(Vector *v);
Vector copy(Vector *v);
int front(Vector *v);
int back(Vector *v);
int *begin(Vector *v);
int *end(Vector *v);
int *rbegin(Vector *v);
int *rend(Vector *v);
void free_vector(Vector *v);
int myfun();
#endif
