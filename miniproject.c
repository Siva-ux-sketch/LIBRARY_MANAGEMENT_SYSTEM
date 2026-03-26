#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct Book
{
    char id[20];
    char name[50];
    char author[50];
    char status[20];
};

struct Book library[MAX];
int count = 0;

// GET BOOK DETAILS
struct Book getBook()
{
    struct Book b;

    printf("Enter Book ID: ");
    scanf("%s", b.id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", b.name);

    printf("Enter Author: ");
    scanf(" %[^\n]", b.author);

    strcpy(b.status, "Available");

    return b;
}

// DISPLAY
void display()
{
    int i;

    if(count == 0)
    {
        printf("\nNo books available!\n");
        return;
    }

    for(i = 0; i < count; i++)
    {
        printf("\n%s | %s | %s | %s\n",
        library[i].id,
        library[i].name,
        library[i].author,
        library[i].status);
    }
}

// SEARCH
void searchBook()
{
    int i, found = 0;
    char key[50];

    printf("Enter Book ID or Name: ");
    scanf(" %[^\n]", key);

    for(i = 0; i < count; i++)
    {
        if(strcmp(library[i].id, key) == 0 ||
           strcmp(library[i].name, key) == 0)
        {
            printf("\nFound: %s | %s | %s | %s\n",
            library[i].id,
            library[i].name,
            library[i].author,
            library[i].status);
            found = 1;
        }
    }

    if(!found)
        printf("Book not found!\n");
}

// ISSUE
void issueBook()
{
    int i;
    char id[20];

    printf("Enter Book ID: ");
    scanf("%s", id);

    for(i = 0; i < count; i++)
    {
        if(strcmp(library[i].id, id) == 0)
        {
            if(strcmp(library[i].status, "Available") == 0)
            {
                strcpy(library[i].status, "Issued");
                printf("Book Issued!\n");
            }
            else
                printf("Already Issued!\n");
            return;
        }
    }

    printf("Book not found!\n");
}

// RETURN
void returnBook()
{
    int i;
    char id[20];

    printf("Enter Book ID: ");
    scanf("%s", id);

    for(i = 0; i < count; i++)
    {
        if(strcmp(library[i].id, id) == 0)
        {
            if(strcmp(library[i].status, "Issued") == 0)
            {
                strcpy(library[i].status, "Available");
                printf("Book Returned!\n");
            }
            else
                printf("Book was not issued!\n");
            return;
        }
    }

    printf("Book not found!\n");
}

// AVAILABLE BOOKS
void availableBooks()
{
    int i, found = 0;

    for(i = 0; i < count; i++)
    {
        if(strcmp(library[i].status, "Available") == 0)
        {
            printf("\n%s | %s | %s\n",
            library[i].id,
            library[i].name,
            library[i].author);
            found = 1;
        }
    }

    if(!found)
        printf("No available books!\n");
}

// INSERT (ALL IN ONE)
void insertBook()
{
    int choice, pos, i, j;
    char id[20];

    if(count == MAX)
    {
        printf("Library full!\n");
        return;
    }

    printf("\n--- INSERT MENU ---\n");
    printf("1. Beginning\n");
    printf("2. End\n");
    printf("3. At Position\n");
    printf("4. Before ID\n");
    printf("5. After ID\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    struct Book b = getBook();

    switch(choice)
    {
        case 1:
            for(i = count; i > 0; i--)
                library[i] = library[i-1];

            library[0] = b;
            count++;
            break;

        case 2:
            library[count++] = b;
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);

            if(pos < 0 || pos > count)
            {
                printf("Invalid position!\n");
                return;
            }

            for(i = count; i > pos; i--)
                library[i] = library[i-1];

            library[pos] = b;
            count++;
            break;

        case 4:
            printf("Enter Book ID: ");
            scanf("%s", id);

            for(i = 0; i < count; i++)
            {
                if(strcmp(library[i].id, id) == 0)
                {
                    for(j = count; j > i; j--)
                        library[j] = library[j-1];

                    library[i] = b;
                    count++;
                    return;
                }
            }
            printf("Book not found!\n");
            break;

        case 5:
            printf("Enter Book ID: ");
            scanf("%s", id);

            for(i = 0; i < count; i++)
            {
                if(strcmp(library[i].id, id) == 0)
                {
                    for(j = count; j > i+1; j--)
                        library[j] = library[j-1];

                    library[i+1] = b;
                    count++;
                    return;
                }
            }
            printf("Book not found!\n");
            break;

        default:
            printf("Invalid choice!\n");
    }
}

// DELETE (ALL IN ONE)
void deleteBook()
{
    int choice, pos, i, j;
    char id[20];

    if(count == 0)
    {
        printf("No books to delete!\n");
        return;
    }

    printf("\n--- DELETE MENU ---\n");
    printf("1. First\n");
    printf("2. Last\n");
    printf("3. At Position\n");
    printf("4. By ID\n");
    printf("5. Before ID\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            for(i = 0; i < count-1; i++)
                library[i] = library[i+1];
            count--;
            break;

        case 2:
            count--;
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);

            if(pos < 0 || pos >= count)
            {
                printf("Invalid position!\n");
                return;
            }

            for(i = pos; i < count-1; i++)
                library[i] = library[i+1];

            count--;
            break;

        case 4:
            printf("Enter Book ID: ");
            scanf("%s", id);

            for(i = 0; i < count; i++)
            {
                if(strcmp(library[i].id, id) == 0)
                {
                    for(j = i; j < count-1; j++)
                        library[j] = library[j+1];

                    count--;
                    return;
                }
            }
            printf("Book not found!\n");
            break;

        case 5:
            printf("Enter Book ID: ");
            scanf("%s", id);

            for(i = 1; i < count; i++)
            {
                if(strcmp(library[i].id, id) == 0)
                {
                    for(j = i-1; j < count-1; j++)
                        library[j] = library[j+1];

                    count--;
                    return;
                }
            }
            printf("Cannot delete!\n");
            break;

        default:
            printf("Invalid choice!\n");
    }
}

// MAIN
int main()
{
    int ch;

    do
    {
        printf("\n===== LIBRARY SYSTEM =====\n");
        printf("1. Insert Book\n");
        printf("2. Delete Book\n");
        printf("3. Display Books\n");
        printf("4. Search Book\n");
        printf("5. Issue Book\n");
        printf("6. Return Book\n");
        printf("7. Available Books\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insertBook(); break;
            case 2: deleteBook(); break;
            case 3: display(); break;
            case 4: searchBook(); break;
            case 5: issueBook(); break;
            case 6: returnBook(); break;
            case 7: availableBooks(); break;
            case 8: exit(0);
            default: printf("Invalid choice!\n");
        }

    } while(ch != 8);

    return 0;
}
