#include <stdio.h>

#define MAX 100

int arr[MAX], n = 0;

// Display
void display()
{
    if(n == 0)
    {
        printf("\nArray is empty\n");
        return;
    }

    printf("\nElements: ");
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Insert at beginning
void insertFirst(int value)
{
    if(n == MAX)
    {
        printf("\nArray is full\n");
        return;
    }
    
    int i;
    for(i = n; i > 0; i--)
        arr[i] = arr[i-1];

    arr[0] = value;
    n++;
}

// Insert at end
void insertLast(int value)
{
    if(n == MAX)
    {
        printf("\nArray is full\n");
        return;
    }

    arr[n++] = value;   // simplified
}

// Insert at position
void insertAtPos(int value, int pos)
{
    if(n == MAX)
    {
        printf("\nArray is full\n");
        return;
    }

    if(pos < 1 || pos > n+1)
    {
        printf("\nInvalid Position\n");
        return;
    }
    
    int i;
    for(i = n; i >= pos; i--)
        arr[i] = arr[i-1];

    arr[pos-1] = value;
    n++;
}

// Delete from beginning
void deleteFirst()
{
    if(n == 0)
    {
        printf("\nArray is empty\n");
        return;
    }

    int i;
    for(i = 0; i < n-1; i++)
        arr[i] = arr[i+1];

    n--;
}

// Delete from end
void deleteLast()
{
    if(n == 0)
    {
        printf("\nArray is empty\n");
        return;
    }

    n--;
}

// Delete at position
void deleteAtPos(int pos)
{
    if(n == 0)
    {
        printf("\nArray is empty\n");
        return;
    }

    if(pos < 1 || pos > n)
    {
        printf("\nInvalid Position\n");
        return;
    }
    
    int i;
    for(i = pos-1; i < n-1; i++)
        arr[i] = arr[i+1];

    n--;
}

// Search
void search(int value)
{
    int found = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == value)
        {
            printf("\nElement found at position %d\n", i+1);
            found = 1;
        }
    }

    if(found == 0)
        printf("\nElement not found\n");
}

// Main
int main()
{
    int choice, value, pos;

    while(1)
    {
        printf("\n--- ARRAY OPERATIONS ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from First\n");
        printf("5. Delete from Last\n");
        printf("6. Delete from Position\n");
        printf("7. Search Element\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFirst(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertLast(value);
                break;

            case 3:
                printf("Enter value & position: ");
                scanf("%d %d", &value, &pos);
                insertAtPos(value, pos);
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 8:
                display();
                break;

            case 9:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
