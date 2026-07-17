#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient
{
    int id;
    char name[50];
    int age;
    char disease[50];
};

struct Patient p[MAX];
int count = 0;

// Function Prototypes
void addPatient();
void displayPatients();
void searchPatient();
void updatePatient();
void deletePatient();

int main()
{
    int choice;

    do
    {
        printf("\n===== HOSPITAL PATIENT MANAGEMENT =====\n");
        printf("1. Register Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                updatePatient();
                break;

            case 5:
                deletePatient();
                break;

            case 6:
                printf("Program Ended...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

// Register Patient
void addPatient()
{
    printf("\nEnter Patient ID: ");
    scanf("%d", &p[count].id);

    printf("Enter Patient Name: ");
    scanf("%s", p[count].name);

    printf("Enter Age: ");
    scanf("%d", &p[count].age);

    printf("Enter Disease: ");
    scanf("%s", p[count].disease);

    count++;

    printf("Patient Registered Successfully!\n");
}

// Display Patients
void displayPatients()
{
    int i;

    if(count == 0)
    {
        printf("No Patient Records Found!\n");
        return;
    }

    printf("\nID\tName\tAge\tDisease\n");

    for(i = 0; i < count; i++)
    {
        printf("%d\t%s\t%d\t%s\n",
               p[i].id,
               p[i].name,
               p[i].age,
               p[i].disease);
    }
}

// Search Patient
void searchPatient()
{
    int id, i, found = 0;

    printf("Enter Patient ID to Search: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(p[i].id == id)
        {
            printf("\nPatient Found\n");
            printf("ID      : %d\n", p[i].id);
            printf("Name    : %s\n", p[i].name);
            printf("Age     : %d\n", p[i].age);
            printf("Disease : %s\n", p[i].disease);

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Patient Not Found!\n");
}

// Update Patient
void updatePatient()
{
    int id, i, found = 0;

    printf("Enter Patient ID to Update: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(p[i].id == id)
        {
            printf("Enter New Name: ");
            scanf("%s", p[i].name);

            printf("Enter New Age: ");
            scanf("%d", &p[i].age);

            printf("Enter New Disease: ");
            scanf("%s", p[i].disease);

            printf("Patient Record Updated Successfully!\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Patient Not Found!\n");
}

// Delete Patient
void deletePatient()
{
    int id, i, j, found = 0;

    printf("Enter Patient ID to Delete: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(p[i].id == id)
        {
            for(j = i; j < count - 1; j++)
            {
                p[j] = p[j + 1];
            }

            count--;

            printf("Patient Record Deleted Successfully!\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Patient Not Found!\n");
}