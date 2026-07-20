#include <stdio.h>

#define MAX 100

struct Product
{
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product p[MAX];
int count = 0;

// Function Prototypes
void addProduct();
void displayProducts();
void searchProduct();
void updateProduct();
void sortByPrice();
void totalInventoryValue();

int main()
{
    int choice;

    do
    {
        printf("\n===== INVENTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Sort Products by Price\n");
        printf("6. Total Inventory Value\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateProduct();
                break;

            case 5:
                sortByPrice();
                break;

            case 6:
                totalInventoryValue();
                break;

            case 7:
                printf("Program Ended...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(choice != 7);

    return 0;
}

// Add Product
void addProduct()
{
    printf("\nEnter Product ID: ");
    scanf("%d",&p[count].id);

    printf("Enter Product Name: ");
    scanf("%s",p[count].name);

    printf("Enter Product Price: ");
    scanf("%f",&p[count].price);

    printf("Enter Quantity: ");
    scanf("%d",&p[count].quantity);

    count++;

    printf("Product Added Successfully!\n");
}

// Display Products
void displayProducts()
{
    int i;

    if(count==0)
    {
        printf("No Products Available!\n");
        return;
    }

    printf("\nID\tName\tPrice\tQuantity\n");

    for(i=0;i<count;i++)
    {
        printf("%d\t%s\t%.2f\t%d\n",
               p[i].id,
               p[i].name,
               p[i].price,
               p[i].quantity);
    }
}

// Search Product
void searchProduct()
{
    int id,i,found=0;

    printf("Enter Product ID: ");
    scanf("%d",&id);

    for(i=0;i<count;i++)
    {
        if(p[i].id==id)
        {
            printf("\nProduct Found\n");
            printf("ID       : %d\n",p[i].id);
            printf("Name     : %s\n",p[i].name);
            printf("Price    : %.2f\n",p[i].price);
            printf("Quantity : %d\n",p[i].quantity);

            found=1;
            break;
        }
    }

    if(found==0)
        printf("Product Not Found!\n");
}

// Update Product
void updateProduct()
{
    int id,i,found=0;

    printf("Enter Product ID to Update: ");
    scanf("%d",&id);

    for(i=0;i<count;i++)
    {
        if(p[i].id==id)
        {
            printf("Enter New Name: ");
            scanf("%s",p[i].name);

            printf("Enter New Price: ");
            scanf("%f",&p[i].price);

            printf("Enter New Quantity: ");
            scanf("%d",&p[i].quantity);

            printf("Product Updated Successfully!\n");

            found=1;
            break;
        }
    }

    if(found==0)
        printf("Product Not Found!\n");
}

// Sort by Price
void sortByPrice()
{
    int i,j;
    struct Product temp;

    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(p[j].price > p[j+1].price)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    printf("Products Sorted by Price Successfully!\n");
}

// Total Inventory Value
void totalInventoryValue()
{
    int i;
    float total=0;

    for(i=0;i<count;i++)
    {
        total += p[i].price * p[i].quantity;
    }

    printf("\nTotal Inventory Value = %.2f\n",total);
}