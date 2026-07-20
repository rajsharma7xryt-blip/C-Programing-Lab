#include <stdio.h>

int arr[100], temp[100];
int n;

// Function Prototypes
void inputArray();
void largestSecondLargest();
void smallestSecondSmallest();
void reverseArray();
void removeDuplicates();
void frequencyCount();
void linearSearch();
void sortArray();

int main()
{
    int choice;

    inputArray();

    do
    {
        printf("\n========== LEETCODE ARRAY CHALLENGE ==========\n");
        printf("1. Largest and Second Largest\n");
        printf("2. Smallest and Second Smallest\n");
        printf("3. Reverse Array\n");
        printf("4. Remove Duplicates\n");
        printf("5. Frequency Count\n");
        printf("6. Linear Search\n");
        printf("7. Sort Array\n");
        printf("8. Time Complexity\n");
        printf("9. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                largestSecondLargest();
                break;

            case 2:
                smallestSecondSmallest();
                break;

            case 3:
                reverseArray();
                break;

            case 4:
                removeDuplicates();
                break;

            case 5:
                frequencyCount();
                break;

            case 6:
                linearSearch();
                break;

            case 7:
                sortArray();
                break;

            case 8:
                printf("\nTime Complexity:\n");
                printf("Largest/Smallest : O(n)\n");
                printf("Second Largest/Smallest : O(n)\n");
                printf("Reverse Array : O(n)\n");
                printf("Remove Duplicates : O(n^2)\n");
                printf("Frequency Count : O(n^2)\n");
                printf("Linear Search : O(n)\n");
                printf("Bubble Sort : O(n^2)\n");
                break;

            case 9:
                printf("Program Ended...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(choice!=9);

    return 0;
}

// Input Array
void inputArray()
{
    int i;

    printf("Enter Number of Elements: ");
    scanf("%d",&n);

    printf("Enter %d Elements:\n",n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

// Largest & Second Largest
void largestSecondLargest()
{
    int i;
    int largest=arr[0],secondLargest=arr[0];

    for(i=1;i<n;i++)
    {
        if(arr[i]>largest)
        {
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]>secondLargest && arr[i]!=largest)
        {
            secondLargest=arr[i];
        }
    }

    printf("Largest = %d\n",largest);
    printf("Second Largest = %d\n",secondLargest);
}

// Smallest & Second Smallest
void smallestSecondSmallest()
{
    int i;
    int smallest=arr[0],secondSmallest=arr[0];

    for(i=1;i<n;i++)
    {
        if(arr[i]<smallest)
        {
            secondSmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]<secondSmallest && arr[i]!=smallest)
        {
            secondSmallest=arr[i];
        }
    }

    printf("Smallest = %d\n",smallest);
    printf("Second Smallest = %d\n",secondSmallest);
}

// Reverse Array
void reverseArray()
{
    int i;

    printf("Reverse Array:\n");

    for(i=n-1;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
}

// Remove Duplicates
void removeDuplicates()
{
    int i,j,newSize=0,duplicate;

    for(i=0;i<n;i++)
    {
        duplicate=0;

        for(j=0;j<newSize;j++)
        {
            if(arr[i]==temp[j])
            {
                duplicate=1;
                break;
            }
        }

        if(!duplicate)
        {
            temp[newSize++]=arr[i];
        }
    }

    printf("Array After Removing Duplicates:\n");

    for(i=0;i<newSize;i++)
    {
        printf("%d ",temp[i]);
    }

    printf("\n");
}

// Frequency Count
void frequencyCount()
{
    int copy[100];
    int i,j,count;

    for(i=0;i<n;i++)
        copy[i]=arr[i];

    printf("Frequency:\n");

    for(i=0;i<n;i++)
    {
        if(copy[i]==-99999)
            continue;

        count=1;

        for(j=i+1;j<n;j++)
        {
            if(copy[i]==copy[j])
            {
                count++;
                copy[j]=-99999;
            }
        }

        printf("%d = %d Times\n",copy[i],count);
    }
}

// Linear Search
void linearSearch()
{
    int key,i;

    printf("Enter Element to Search: ");
    scanf("%d",&key);

    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            printf("Element Found at Position %d\n",i+1);
            return;
        }
    }

    printf("Element Not Found!\n");
}

// Bubble Sort
void sortArray()
{
    int i,j,temp1;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp1=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp1;
            }
        }
    }

    printf("Sorted Array:\n");

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
}