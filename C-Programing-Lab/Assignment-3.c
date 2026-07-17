#include <stdio.h>

// Function Prototypes
void displayAddress();
void dereferencePointer();
void swapNumbers();
void traverseArray();
void pointerArithmetic();

int main()
{
    int choice;

    do
    {
        printf("\n========== POINTER PLAYGROUND ==========\n");
        printf("1. Display Memory Address\n");
        printf("2. Dereference Pointer\n");
        printf("3. Swap Two Numbers using Pointer\n");
        printf("4. Traverse Array using Pointer\n");
        printf("5. Pointer Arithmetic\n");
        printf("6. Exit\n");

        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayAddress();
                break;

            case 2:
                dereferencePointer();
                break;

            case 3:
                swapNumbers();
                break;

            case 4:
                traverseArray();
                break;

            case 5:
                pointerArithmetic();
                break;

            case 6:
                printf("Program Closed...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

// Display Memory Address
void displayAddress()
{
    int num;
    printf("\nEnter a Number: ");
    scanf("%d", &num);

    printf("Value = %d\n", num);
    printf("Memory Address = %p\n", (void*)&num);
}

// Dereference Pointer
void dereferencePointer()
{
    int num;
    int *ptr;

    printf("\nEnter a Number: ");
    scanf("%d", &num);

    ptr = &num;

    printf("Pointer Address = %p\n", (void*)ptr);
    printf("Value Stored at Pointer = %d\n", *ptr);
}

// Swap Two Numbers
void swapNumbers()
{
    int a, b;
    int *p1, *p2, temp;

    printf("\nEnter First Number: ");
    scanf("%d", &a);

    printf("Enter Second Number: ");
    scanf("%d", &b);

    p1 = &a;
    p2 = &b;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("\nAfter Swapping:\n");
    printf("First Number = %d\n", a);
    printf("Second Number = %d\n", b);
}

// Traverse Array Using Pointer
void traverseArray()
{
    int arr[100], n, i;
    int *ptr;

    printf("\nEnter Size of Array: ");
    scanf("%d", &n);

    printf("Enter %d Elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    printf("\nArray Elements using Pointer:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    printf("\n");
}

// Pointer Arithmetic
void pointerArithmetic()
{
    int arr[100];
    int *ptr;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    printf("\nPointer Arithmetic:\n\n");

    for(i = 0; i < n; i++)
    {
        printf("Address = %p\tValue = %d\n",
               (void *)(ptr + i), *(ptr + i));
    }
}