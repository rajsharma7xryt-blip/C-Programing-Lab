#include <stdio.h>
#include <string.h>

#define MAX 100

char str[MAX];

// Function Prototypes
void inputString();
void stringLength();
void reverseString();
void palindrome();
void countVowelsDigitsSpaces();
void characterFrequency();

int main()
{
    int choice;

    do
    {
        printf("\n====== STRING UTILITY TOOLKIT ======\n");
        printf("1. Enter String\n");
        printf("2. Find Length\n");
        printf("3. Reverse String\n");
        printf("4. Check Palindrome\n");
        printf("5. Count Vowels, Digits & Spaces\n");
        printf("6. Character Frequency\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // remove newline

        switch(choice)
        {
            case 1:
                inputString();
                break;

            case 2:
                stringLength();
                break;

            case 3:
                reverseString();
                break;

            case 4:
                palindrome();
                break;

            case 5:
                countVowelsDigitsSpaces();
                break;

            case 6:
                characterFrequency();
                break;

            case 7:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(choice != 7);

    return 0;
}

// Enter String
void inputString()
{
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    str[strcspn(str, "\n")] = '\0';
}

// Find Length
void stringLength()
{
    printf("Length of String = %lu\n", strlen(str));
}

// Reverse String
void reverseString()
{
    int i;
    int len = strlen(str);

    printf("Reversed String = ");

    for(i=len-1;i>=0;i--)
        printf("%c", str[i]);

    printf("\n");
}

// Check Palindrome
void palindrome()
{
    int i;
    int len = strlen(str);
    int flag = 1;

    for(i=0;i<len/2;i++)
    {
        if(str[i] != str[len-i-1])
        {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("String is Palindrome.\n");
    else
        printf("String is NOT Palindrome.\n");
}

// Count Vowels, Digits & Spaces
void countVowelsDigitsSpaces()
{
    int i;
    int vowels=0, digits=0, spaces=0;

    for(i=0; str[i]!='\0'; i++)
    {
        char ch = str[i];

        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||
           ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            vowels++;

        else if(ch>='0' && ch<='9')
            digits++;

        else if(ch==' ')
            spaces++;
    }

    printf("Vowels = %d\n", vowels);
    printf("Digits = %d\n", digits);
    printf("Spaces = %d\n", spaces);
}

// Character Frequency
void characterFrequency()
{
    int freq[256]={0};
    int i;

    for(i=0; str[i]!='\0'; i++)
    {
        freq[(unsigned char)str[i]]++;
    }

    printf("\nCharacter Frequency:\n");

    for(i=0;i<256;i++)
    {
        if(freq[i]!=0)
        {
            printf("%c = %d\n", i, freq[i]);
        }
    }
}