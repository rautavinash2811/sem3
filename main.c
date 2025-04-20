#include <stdio.h>
#include "vector.h"

// Custom input function for integer input
// int myfun() 
// {
//     int value;
//     scanf("%d", &value);
//     return value;
// }

int main() 
{
    Vector v;
    init_vector(&v);

    int choice, value, index, new_size;

    while (1) 
    {
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
        printf("15. Get Current Size and Capacity\n");
        printf("16. Exit\n");
        printf("Enter your choice: ");
        
        choice = myfun();  // Get choice using myfun()
        
        switch (choice) 
        {
            case 1:
                printf("How many elements do you want to add: ");
                int p = myfun();  // Get the number of elements to add using myfun()
                for (int i = 0; i < p; i++) 
                {
                    printf("Enter value %d to add: ", (i + 1));
                    value = myfun();  // Get value to add using myfun()
                    push_back(&v, value);
                }
                break;
            case 2:
                printf("Enter index: ");
                index = myfun();  // Get index using myfun()
                int findindex = at(&v, index);
                if (findindex == -1)
                {
                    break;
                }
                else
                {
                    printf("Element at index %d is %d\n", index, findindex);
                    break;
                }
            case 3:
                print_vector(&v);
                break;
            case 4:
                printf("Enter new size: ");
                new_size = myfun();  // Get new size using myfun()
                resize(&v, new_size);
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
            case 8: 
            {
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
                printf("Reverse elements: ");
                for (int *ptr = rbegin(&v); ptr != rend(&v); --ptr) 
                {
                    printf("%d ", *ptr);
                }
                printf("\n");
                break;
            
            case 15:
                printf("Current size: %d\n", v.size);
                printf("Current capacity: %d\n", v.capacity);
                break;
            case 16:
                free_vector(&v);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
