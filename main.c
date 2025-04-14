#include <stdio.h>
#include "vector.h"

int main() {
    Vector v;
    init_vector(&v);

    int choice, value, index, new_capacity;

    while (1) {
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
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                push_back(&v, value);
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Element at index %d is %d\n", index, at(&v, index));
                break;
            case 3:
                print_vector(&v);
                break;
            case 4:
                printf("Enter new capacity: ");
                scanf("%d", &new_capacity);
                resize(&v, new_capacity);
                printf("Vector resized.\n");
                break;
            case 5:
                if (is_empty(&v))
                    printf("Vector is empty.\n");
                else
                    printf("Vector is not empty.\n");
                break;
            case 6:
                pop_back(&v);
                printf("Last element removed.\n");
                break;
            case 7:
                clear(&v);
                printf("Vector cleared.\n");
                break;
            case 8: {
                Vector copy_v = copy(&v);
                printf("Copied vector: ");
                print_vector(&copy_v);
                free_vector(&copy_v);
                break;
            }
            case 9:
                printf("First element: %d\n", front(&v));
                break;
            case 10:
                printf("Last element: %d\n", back(&v));
                break;
            case 11:
                printf("First element using begin(): %d\n", *begin(&v));
                break;
            case 12:
                printf("Last element using end()-1: %d\n", *(end(&v) - 1));
                break;
            case 13:
                printf("First reverse element using rbegin(): %d\n", *rbegin(&v));
                break;
            case 14:
                printf("Reverse end is before start. rend() points before data[0].\n");
                break;
            case 15:
                free_vector(&v);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
