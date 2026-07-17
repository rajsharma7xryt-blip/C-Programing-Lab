#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

struct Student s[MAX];
int count = 0;

// Function Prototypes
void addStudent();
void displayStudent();
void searchStudent();
void updateStudent();
void deleteStudent();

int main()
{
    int choice;

    do
    {
        printf("\n====== STUDENT RECORD MANAGEMENT SYSTEM ======\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudent();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Program Ended...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(choice!=6);

    return 0;
}

// Add Student
void addStudent()
{
    printf("\nEnter Roll Number: ");
    scanf("%d",&s[count].rollNo);

    printf("Enter Name: ");
    scanf("%s",s[count].name);

    printf("Enter Marks: ");
    scanf("%f",&s[count].marks);

    count++;

    printf("Student Added Successfully!\n");
}

// Display Students
void displayStudent()
{
    int i;

    if(count==0)
    {
        printf("No Student Records Found!\n");
        return;
    }

    printf("\nRollNo\tName\tMarks\n");

    for(i=0;i<count;i++)
    {
        printf("%d\t%s\t%.2f\n",
               s[i].rollNo,
               s[i].name,
               s[i].marks);
    }
}

// Search Student
void searchStudent()
{
    int roll,i,found=0;

    printf("Enter Roll Number to Search: ");
    scanf("%d",&roll);

    for(i=0;i<count;i++)
    {
        if(s[i].rollNo==roll)
        {
            printf("\nStudent Found\n");
            printf("Roll No : %d\n",s[i].rollNo);
            printf("Name    : %s\n",s[i].name);
            printf("Marks   : %.2f\n",s[i].marks);
            found=1;
            break;
        }
    }

    if(found==0)
        printf("Student Not Found!\n");
}

// Update Student
void updateStudent()
{
    int roll,i,found=0;

    printf("Enter Roll Number to Update: ");
    scanf("%d",&roll);

    for(i=0;i<count;i++)
    {
        if(s[i].rollNo==roll)
        {
            printf("Enter New Name: ");
            scanf("%s",s[i].name);

            printf("Enter New Marks: ");
            scanf("%f",&s[i].marks);

            printf("Record Updated Successfully!\n");

            found=1;
            break;
        }
    }

    if(found==0)
        printf("Student Not Found!\n");
}

// Delete Student
void deleteStudent()
{
    int roll,i,j,found=0;

    printf("Enter Roll Number to Delete: ");
    scanf("%d",&roll);

    for(i=0;i<count;i++)
    {
        if(s[i].rollNo==roll)
        {
            for(j=i;j<count-1;j++)
            {
                s[j]=s[j+1];
            }

            count--;

            printf("Record Deleted Successfully!\n");
            found=1;
            break;
        }
    }

    if(found==0)
        printf("Student Not Found!\n");
}