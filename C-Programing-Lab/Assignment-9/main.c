#include <stdio.h>
#include <stdlib.h>

int *arr = NULL;
int size = 0;

// Function Prototypes
void insertElement();
void displayArray();
void deleteElement();
void updateElement();
void linearSearch();
void sortArray();
void binarySearch();

int main()
{
    int choice;

    do
    {
        printf("\n========== DYNAMIC ARRAY OPERATIONS ==========\n");
        printf("1. Insert Element\n");
        printf("2. Display Array\n");
        printf("3. Delete Element\n");
        printf("4. Update Element\n");
        printf("5. Linear Search\n");
        printf("6. Sort Array\n");
        printf("7. Binary Search\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insertElement();
                break;

            case 2:
                displayArray();
                break;

            case 3:
                deleteElement();
                break;

            case 4:
                updateElement();
                break;

            case 5:
                linearSearch();
                break;

            case 6:
                sortArray();
                break;

            case 7:
                binarySearch();
                break;

            case 8:
                free(arr);
                printf("Program Ended...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(choice!=8);

    return 0;
}

// Insert Element
void insertElement()
{
    arr = (int *)realloc(arr, (size + 1) * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    printf("Enter Element: ");
    scanf("%d",&arr[size]);

    size++;

    printf("Element Inserted Successfully!\n");
}

// Display Array
void displayArray()
{
    int i;

    if(size==0)
    {
        printf("Array is Empty!\n");
        return;
    }

    printf("Array Elements: ");

    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
}

// Delete Element
void deleteElement()
{
    int value,i,j,found=0;

    if(size==0)
    {
        printf("Array is Empty!\n");
        return;
    }

    printf("Enter Element to Delete: ");
    scanf("%d",&value);

    for(i=0;i<size;i++)
    {
        if(arr[i]==value)
        {
            for(j=i;j<size-1;j++)
            {
                arr[j]=arr[j+1];
            }

            size--;

            arr=(int *)realloc(arr,size*sizeof(int));

            printf("Element Deleted Successfully!\n");

            found=1;
            break;
        }
    }

    if(found==0)
        printf("Element Not Found!\n");
}

// Update Element
void updateElement()
{
    int oldValue,newValue,i,found=0;

    printf("Enter Old Value: ");
    scanf("%d",&oldValue);

    for(i=0;i<size;i++)
    {
        if(arr[i]==oldValue)
        {
            printf("Enter New Value: ");
            scanf("%d",&newValue);

            arr[i]=newValue;

            printf("Element Updated Successfully!\n");

            found=1;
            break;
        }
    }

    if(found==0)
        printf("Element Not Found!\n");
}

// Linear Search
void linearSearch()
{
    int value,i;

    printf("Enter Element to Search: ");
    scanf("%d",&value);

    for(i=0;i<size;i++)
    {
        if(arr[i]==value)
        {
            printf("Element Found at Position %d\n",i+1);
            return;
        }
    }

    printf("Element Not Found!\n");
}

// Sort Array
void sortArray()
{
    int i,j,temp;

    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Array Sorted Successfully!\n");
}

// Binary Search
void binarySearch()
{
    int value,low=0,high=size-1,mid;

    printf("Enter Element to Search: ");
    scanf("%d",&value);

    while(low<=high)
    {
        mid=(low+high)/2;

        if(arr[mid]==value)
        {
            printf("Element Found at Position %d\n",mid+1);
            return;
        }
        else if(arr[mid]<value)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    printf("Element Not Found!\n");
}