#include<stdio.h>
#include"vector.h"
int main()
{
    Vector myvec;
    init_vector(&myvec);
    int n = 5;
    push_back(&myvec,n);
    print_vector(&myvec);
}