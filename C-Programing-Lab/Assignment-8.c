#include <stdio.h>

#define MAX 100

struct Employee
{
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float tax;
    float grossSalary;
    float netSalary;
};

struct Employee emp[MAX];
int count = 0;

// Function Prototypes
void addEmployee();
void displayEmployees();
void sortBySalary();

int main()
{
    int choice;

    do
    {
        printf("\n========== EMPLOYEE PAYROLL SYSTEM ==========\n");
        printf("1. Add Employee\n");
        printf("2. Display Salary Report\n");
        printf("3. Sort Employees by Net Salary\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                sortBySalary();
                break;

            case 4:
                printf("Program Ended...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(choice!=4);

    return 0;
}

// Add Employee
void addEmployee()
{
    printf("\nEnter Employee ID: ");
    scanf("%d",&emp[count].id);

    printf("Enter Employee Name: ");
    scanf("%s",emp[count].name);

    printf("Enter Basic Salary: ");
    scanf("%f",&emp[count].basicSalary);

    // Salary Calculations
    emp[count].hra = emp[count].basicSalary * 0.20;
    emp[count].da = emp[count].basicSalary * 0.10;

    emp[count].grossSalary =
        emp[count].basicSalary +
        emp[count].hra +
        emp[count].da;

    if(emp[count].grossSalary > 50000)
        emp[count].tax = emp[count].grossSalary * 0.10;
    else
        emp[count].tax = emp[count].grossSalary * 0.05;

    emp[count].netSalary =
        emp[count].grossSalary -
        emp[count].tax;

    count++;

    printf("Employee Added Successfully!\n");
}

// Display Employees
void displayEmployees()
{
    int i;

    if(count==0)
    {
        printf("No Employee Records Found!\n");
        return;
    }

    printf("\n---------------------------------------------------------------------------------------------\n");
    printf("ID\tName\tBasic\tHRA\tDA\tGross\tTax\tNet Salary\n");
    printf("---------------------------------------------------------------------------------------------\n");

    for(i=0;i<count;i++)
    {
        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
               emp[i].id,
               emp[i].name,
               emp[i].basicSalary,
               emp[i].hra,
               emp[i].da,
               emp[i].grossSalary,
               emp[i].tax,
               emp[i].netSalary);
    }
}

// Sort Employees by Net Salary
void sortBySalary()
{
    int i,j;
    struct Employee temp;

    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(emp[j].netSalary > emp[j+1].netSalary)
            {
                temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;
            }
        }
    }

    printf("Employees Sorted by Net Salary Successfully!\n");
}