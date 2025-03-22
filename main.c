#include "vector.h"
#include <stdio.h>

int main() 
{
    Vector* v = vector_create(); // Create a vector
    int choice, value, index;

    while (1) 
    {
        // Menu for user interaction
        printf("\n--- Custom Vector Library ---\n");
        printf("1. Push Back (Add Element)\n");
        printf("2. Access Element at Index\n");
        printf("3. Print Vector\n");
        printf("4. Resize Vector\n");
        printf("5. Check if Vector is Empty\n");
        printf("6. Pop Back (Remove Last Element)\n");
        printf("7. Clear Vector\n");
        printf("8. Return a Copy of the Vector\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: // Push Back
                printf("Enter value to push back: ");
                scanf("%d", &value);
                vector_push_back(v, value);
                printf("Value %d added to the vector.\n", value);
                break;

            case 2: // Access Element at Index
                printf("Enter index to access: ");
                scanf("%d", &index);
                if (index >= 0 && index < vector_size(v)) 
                {
                    printf("Element at index %d: %d\n", index, vector_at(v, index));
                } else 
                {
                    printf("Invalid index!\n");
                }
                break;

            case 3: // Print Vector
                printf("Vector elements: ");
                for (size_t i = 0; i < vector_size(v); i++) 
                {
                    printf("%d ", vector_at(v, i));
                }
                printf("\n");
                break;

            case 4: // Resize Vector
                printf("Enter new capacity: ");
                scanf("%d", &value);
                if (value >= vector_size(v)) 
                {
                    vector_resize(v, value);
                    printf("Vector resized to capacity %d.\n", value);
                } else 
                {
                    printf("New capacity must be >= current size (%zu).\n", vector_size(v));
                }
                break;

            case 5: // Check if Vector is Empty
                if (vector_empty(v)) 
                {
                    printf("Vector is empty.\n");
                } else 
                {
                    printf("Vector is not empty.\n");
                }
                break;

            case 6: // Pop Back
                if (vector_size(v) > 0) 
                {
                    vector_pop_back(v);
                    printf("Last element removed.\n");
                } else 
                {
                    printf("Vector is already empty.\n");
                }
                break;

            case 7: // Clear Vector
                vector_clear(v);
                printf("Vector cleared.\n");
                break;

            case 8: // Return a Copy of the Vector
                {
                    Vector* v_copy = vector_return_copy(v);
                    printf("Copied vector elements: ");
                    for (size_t i = 0; i < vector_size(v_copy); i++) 
                    {
                        printf("%d ", vector_at(v_copy, i));
                    }
                    printf("\n");
                    vector_destroy(v_copy); // Clean up the copy
                }
                break;

            case 9: // Exit
                vector_destroy(v); // Clean up the original vector
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}