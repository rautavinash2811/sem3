#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// Display menu
void display_menu() {
    printf("\n--- Custom Vector Library ---\n");
    printf("1. Push Back (Add Element)\n");
    printf("2. Access Element at Index\n");
    printf("3. Print Vector\n");
    printf("4. Resize Vector\n");
    printf("5. Check if Vector is Empty\n");
    printf("6. Pop Back (Remove Last Element)\n");
    printf("7. Clear Vector\n");
    printf("8. Return a Copy of the Vector\n");
    printf("9. Get First Element (front)\n");
    printf("10. Get Last Element (back)\n");
    printf("11. Get First Iterator (begin)\n");
    printf("12. Get Last Iterator (end)\n");
    printf("13. Get Reverse First Iterator (rbegin)\n");
    printf("14. Get Reverse Last Iterator (rend)\n");
    printf("15. Exit\n");
}

int main() {
    Vector* v = vector_create();
    int choice, value, index;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push back (add element)
                printf("Enter value to add: ");
                scanf("%d", &value);
                vector_push_back(v, value);
                printf("Value %d added to the vector.\n", value);
                break;
            case 2: // Access element at index
                printf("Enter index: ");
                scanf("%d", &index);
                value = vector_at(v, index);
                if (value != -1) {
                    printf("Element at index %d: %d\n", index, value);
                } else {
                    printf("Index out of bounds.\n");
                }
                break;
            case 3: // Print vector
                printf("Vector elements: ");
                vector_print(v);
                break;
            case 4: // Resize vector
                printf("Enter new size: ");
                scanf("%d", &value);
                vector_resize(v, value);
                printf("Vector resized to size %d.\n", value);
                break;
            case 5: // Check if vector is empty
                if (vector_empty(v)) {
                    printf("Vector is empty.\n");
                } else {
                    printf("Vector is not empty.\n");
                }
                break;
            case 6: // Pop back (remove last element)
                vector_pop_back(v);
                printf("Last element removed from the vector.\n");
                break;
            case 7: // Clear vector
                vector_clear(v);
                printf("Vector cleared.\n");
                break;
            case 8: // Return a copy of the vector
                {
                    Vector* copy = vector_copy(v);
                    printf("A copy of the vector has been created. Vector elements: ");
                    vector_print(copy);
                    free(copy->data);
                    free(copy);
                }
                break;
            case 9: // Get front (first element)
                value = vector_front(v);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                } else {
                    printf("Vector is empty.\n");
                }
                break;
            case 10: // Get back (last element)
                value = vector_back(v);
                if (value != -1) {
                    printf("Back element: %d\n", value);
                } else {
                    printf("Vector is empty.\n");
                }
                break;
            case 11: // Get begin iterator
                {
                    int* begin = vector_begin(v);
                    if (begin != NULL) {
                        printf("First element via iterator: %d\n", *begin);
                    } else {
                        printf("Vector is empty.\n");
                    }
                }
                break;
            case 12: // Get end iterator
                {
                    int* end = vector_end(v);
                    if (end != NULL) {
                        printf("End iterator (one past last element): %d\n", *end);
                    } else {
                        printf("Vector is empty.\n");
                    }
                }
                break;
            case 13: // Get reverse begin iterator
                {
                    int* rbegin = vector_rbegin(v);
                    if (rbegin != NULL) {
                        printf("Reverse first element: %d\n", *rbegin);
                    } else {
                        printf("Vector is empty.\n");
                    }
                }
                break;
            case 14: // Get reverse end iterator
                {
                    int* rend = vector_rend(v);
                    if (rend != NULL) {
                        printf("Reverse last element (one before first): %d\n", *rend);
                    } else {
                        printf("Vector is empty.\n");
                    }
                }
                break;
            case 15: // Exit
                printf("Exiting program...\n");
                free(v->data);
                free(v);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
