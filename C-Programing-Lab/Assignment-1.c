#include <stdio.h>

#define MAX 100

int marks[MAX];
char names[MAX][50];
int n;

// Function Prototypes
void inputMarks();
void displayMarks();
void calculateStats();
void searchStudent();
void sortMarks();

int main()
{
    int choice;

    do
    {
        printf("\n====== STUDENT MARKS ANALYZER ======\n");
        printf("1. Enter Student Marks\n");
        printf("2. Display Marks\n");
        printf("3. Calculate Highest, Lowest, Total & Average\n");
        printf("4. Search Student Marks\n");
        printf("5. Sort Marks (Ascending)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                inputMarks();
                break;

            case 2:
                displayMarks();
                break;

            case 3:
                calculateStats();
                break;

            case 4:
                searchStudent();
                break;

            case 5:
                sortMarks();
                break;

            case 6:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

// Function to input student marks
void inputMarks()
{
    int i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("\nStudent %d Name: ", i+1);
        scanf("%s", names[i]);

        printf("Marks: ");
        scanf("%d", &marks[i]);
    }
}

// Function to display student marks
void displayMarks()
{
    int i;

    printf("\n------ Student Marks ------\n");

    for(i=0; i<n; i++)
    {
        printf("%d. %s : %d\n", i+1, names[i], marks[i]);
    }
}

// Function to calculate highest, lowest, total, average
void calculateStats()
{
    int i;
    int highest, lowest, total = 0;
    float average;

    highest = marks[0];
    lowest = marks[0];

    for(i=0; i<n; i++)
    {
        if(marks[i] > highest)
            highest = marks[i];

        if(marks[i] < lowest)
            lowest = marks[i];

        total += marks[i];
    }

    average = (float)total / n;

    printf("\nHighest Marks : %d", highest);
    printf("\nLowest Marks  : %d", lowest);
    printf("\nTotal Marks   : %d", total);
    printf("\nAverage Marks : %.2f\n", average);
}

// Function to search student's marks
void searchStudent()
{
    char search[50];
    int i, found = 0;

    printf("Enter student name to search: ");
    scanf("%s", search);

    for(i=0; i<n; i++)
    {
        int j = 0;

        while(search[j] == names[i][j] && search[j] != '\0')
        {
            j++;
        }

        if(search[j] == '\0' && names[i][j] == '\0')
        {
            printf("%s scored %d marks.\n", names[i], marks[i]);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Student not found!\n");
}

// Function to sort marks in ascending order
void sortMarks()
{
    int i, j, temp;
    char tempName[50];
    int k;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(marks[j] > marks[j+1])
            {
                temp = marks[j];
                marks[j] = marks[j+1];
                marks[j+1] = temp;

                for(k=0; ; k++)
                {
                    tempName[k] = names[j][k];

                    if(names[j][k] == '\0')
                        break;
                }

                for(k=0; ; k++)
                {
                    names[j][k] = names[j+1][k];

                    if(names[j+1][k] == '\0')
                        break;
                }

                for(k=0; ; k++)
                {
                    names[j+1][k] = tempName[k];

                    if(tempName[k] == '\0')
                        break;
                }
            }
        }
    }

    printf("\nMarks sorted successfully in ascending order.\n");
}