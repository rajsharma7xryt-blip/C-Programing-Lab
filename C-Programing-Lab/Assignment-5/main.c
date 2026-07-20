#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *marks;
    int total = 0, highest, lowest;
    float average;

    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamic Memory Allocation
    marks = (int *)malloc(n * sizeof(int));

    if(marks == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    // Input Marks
    printf("\nEnter marks of %d students:\n", n);

    for(i = 0; i < n; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    // Display Marks
    printf("\nDisplay Student Marks:\n");

    for(i = 0; i < n; i++)
    {
        printf("Student %d = %d\n", i + 1, marks[i]);
    }

    // Calculate Statistics
    highest = lowest = marks[0];

    for(i = 0; i < n; i++)
    {
        if(marks[i] > highest)
            highest = marks[i];

        if(marks[i] < lowest)
            lowest = marks[i];

        total += marks[i];
    }

    average = (float)total / n;

    printf("\nHighest Marks : %d\n", highest);
    printf("Lowest Marks  : %d\n", lowest);
    printf("Total Marks   : %d\n", total);
    printf("Average Marks : %.2f\n", average);

    // Release Memory
    free(marks);

    printf("\nMemory Released Successfully.\n");

    return 0;
}