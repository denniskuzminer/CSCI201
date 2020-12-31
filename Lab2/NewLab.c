#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int);
int getint(int *pn);

struct Node1d
{
    struct Node1d *next;
    char name[20];
};
struct Node2d
{
    struct Node1d *first;
    char name[20];
    struct Node2d *down;
};

struct Node2d *find2DNoPrint(struct Node2d *head, char *name2d)
{
    struct Node2d *curr = head;
    while (curr != NULL)
    {
        if (strcmp(curr->name, name2d) == 0)
        {
            return curr;
        }
        curr = curr->down;
    }
    return NULL;
}

struct Node2d *find1DNoPrint(struct Node2d *head, char *name1d)
{
    struct Node2d *curr = head;
    curr = curr->down;
    while (curr != NULL)
    {
        struct Node1d *curr1d = curr->first;
        while (curr1d != NULL)
        {
            if (strcmp(curr1d->name, name1d) == 0)
            {
                return curr;
            }
            curr1d = curr1d->next;
        }
        curr = curr->down;
    }
    return NULL;
}

void appendRear2D(struct Node2d *head, char *name1)
{
    struct Node2d *curr = head;
    while (curr->down != NULL)
    {
        curr = curr->down;
    }
    curr->down = (struct Node2d *)malloc(sizeof(struct Node2d));
    strcpy(curr->down->name, name1);
    curr->down->down = NULL;
    curr->down->first = NULL;
}

void appendRear1D(struct Node2d *head, char *name1, char *name2d)
{
    if (find2DNoPrint(head, name2d) != NULL)
    {
        struct Node2d *curr = head;
        while (!(strcmp(curr->name, name2d) == 0))
        {
            curr = curr->down;
        }
        struct Node1d *curr1d = curr->first;
        if (curr->first != NULL)
        {
            while (curr1d->next != NULL)
            {
                curr1d = curr1d->next;
            }
            curr1d->next = (struct Node1d *)malloc(sizeof(struct Node1d));
            strcpy(curr1d->next->name, name1);
            curr1d->next->next = NULL;
        }
        else
        {
            curr->first = (struct Node1d *)malloc(sizeof(struct Node1d));
            strcpy(curr->first->name, name1);
            curr->first->next = NULL;
        }
    }
    else
    {
        printf("Node %s does not exist. New node was not added.\n", name2d);
        return;
    }
}

void printAll(struct Node2d *head)
{
    struct Node2d *curr = head;
    curr = curr->down;
    while (curr != NULL)
    {
        printf("2d node name = %s\n", curr->name);
        if (curr->first != NULL)
        {
            struct Node1d *curr1d = curr->first;
            while (curr1d != NULL)
            {
                printf("\t1d node name = %s\n", curr1d->name);
                curr1d = curr1d->next;
            }
        }
        curr = curr->down;
    }
}

void print1DList(struct Node2d *head, char *name2d)
{
    if (find2DNoPrint(head, name2d) != NULL)
    {
        struct Node2d *curr = head;
        while (!(strcmp(curr->name, name2d) == 0))
        {
            curr = curr->down;
        }
        printf("2d node name = %s\n", curr->name);
        struct Node1d *curr1d = curr->first;
        if (curr->first != NULL)
        {
            struct Node1d *curr1d = curr->first;
            while (curr1d != NULL)
            {
                printf("\t1d node name = %s\n", curr1d->name);
                curr1d = curr1d->next;
            }
        }
    }
    else
    {
        printf("Node %s does not exist.\n", name2d);
        return;
    }
}

struct Node2d *find2D(struct Node2d *head, char *name2d)
{

    struct Node2d *curr = head;
    while (curr != NULL)
    {
        if (strcmp(curr->name, name2d) == 0)
        {
            printf("found\n");
            return curr;
        }
        curr = curr->down;
    }
    printf("not found\n");
    return NULL;
}

struct Node2d *find1D(struct Node2d *head, char *name1d)
{
    struct Node2d *curr = head;
    curr = curr->down;
    while (curr != NULL)
    {
        struct Node1d *curr1d = curr->first;
        while (curr1d != NULL)
        {
            if (strcmp(curr1d->name, name1d) == 0)
            {
                printf("found\n");
                return curr;
            }
            curr1d = curr1d->next;
        }
        curr = curr->down;
    }
    printf("not found\n");
    return NULL;
}

void appendAfter2D(struct Node2d *head, char *name1, char *afterName)
{

    if (find2DNoPrint(head, afterName) != NULL)
    {
        struct Node2d *curr = head;
        while (curr != NULL)
        {
            if (strcmp(curr->name, afterName) == 0)
            {
                break;
            }
            curr = curr->down;
        }
        struct Node2d *newNode = (struct Node2d *)malloc(sizeof(struct Node2d));
        strcpy(newNode->name, name1);
        newNode->down = curr->down;
        curr->down = newNode;
        newNode->first = NULL;
    }
    else
    {
        printf("Node %s does not exist. New node was not added.\n", afterName);
        return;
    }
}

void appendAfter1D(struct Node2d *head, char *name1, char *afterName)
{
    if (find1DNoPrint(head, afterName) != NULL)
    {
        struct Node2d *curr = head;
        curr = curr->down;
        struct Node1d *curr1d = NULL;
        int brkpnt = 0;
        while (curr != NULL)
        {
            curr1d = curr->first;
            while (curr1d != NULL)
            {
                if (strcmp(curr1d->name, afterName) == 0)
                {
                    brkpnt = 1;
                    break;
                }
                curr1d = curr1d->next;
            }
            if (brkpnt == 1)
            {
                break;
            }
            curr = curr->down;
        }
        if (curr1d->next == NULL)
        {
            appendRear1D(head, name1, curr->name);
        }
        else
        {
            struct Node1d *newNode = (struct Node1d *)malloc(sizeof(struct Node1d));
            strcpy(newNode->name, name1);
            newNode->next = curr1d->next;
            curr1d->next = newNode;
        }
    }
    else
    {
        printf("Node %s does not exist. New node was not added.\n", afterName);
        return;
    }
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many chars\n");
    else
        buf[bufp++] = c;
}

void printMenu()
{
    printf("--------------- Menu ---------------\n");
    printf("Press\n");
    printf("1: Create a new node and add it to the end of the 2d list \n");
    printf("2: Create a new node and add it after some already present 2d node \n");
    printf("3: Create a new node and add it to the end of a specified 1d list \n");
    printf("4: Create a new node and add it after some already present 1d node \n");
    printf("5: Prints all nodes in the list \n");
    printf("6: Prints all nodes in a specified 1d list \n");
    printf("7: Prints whether a 2d node is present in the list \n");
    printf("8: Prints whether a 1d node is present in the list \n");
    printf("0: Quits program \n");
}

int main()
{
    int brkpnt = 0;
    // system("pause");
    struct Node2d *head;
    head = (struct Node2d *)malloc(sizeof(struct Node2d));
    head->down = NULL;
    head->first = NULL;
    char name[20];
    char afterName[20];
    printf("\nThis program creates a 2d linked list.\n");
    while (brkpnt != -1)
    {
        printMenu();
        /*char num = getchar();
        if ((int)num == 48)
        {
            brkpnt = 1;
            break;
        }

        int i = (int)num;
        i -= 48;*/
        int i;
        scanf("%d", &i);
        // if (isdigit(i))
        // {
        switch (i)
        {
        case 0:
            exit(0);
        case 1:
            printf("Enter the name of the new 2d node: \n");
            getword(name, 20);
            appendRear2D(head, name);
            // printf("Added node %s\n", name);
            break;
        case 2:
            printf("Enter the name of the new 2d node: \n");
            getword(name, 20);
            printf("Enter the name of the node to insert after: \n");
            getword(afterName, 20);
            appendAfter2D(head, name, afterName);
            // printf("Added node %s after %s\n", name, afterName);
            break;
        case 3:
            printf("Enter the name of the new 1d node: \n");
            getword(name, 20);
            printf("Enter the name of the 2d node at the beginning of the 1d list: \n");
            char name2d[20];
            getword(name2d, 20);
            appendRear1D(head, name, name2d);
            // printf("Added node %s\n", name);
            break;
        case 4:
            printf("Enter the name of the new 1d node: \n");
            getword(name, 20);
            printf("Enter the name of the 1d node to insert after: \n");
            getword(afterName, 20);
            appendAfter1D(head, name, afterName);
            // printf("Added node %s after %s\n", name, afterName);
            break;
        case 5:
            printAll(head);
            break;
        case 6:
            printf("Enter the name of the 2d start pointer to the 1d list to print: \n");
            getword(name, 20);
            print1DList(head, name);
            break;
        case 7:
            printf("Enter the name of the 2d node to find: \n");
            getword(name, 20);
            find2D(head, name);
            break;
        case 8:
            printf("Enter the name of the 1d node to find: \n");
            getword(name, 20);
            find1D(head, name);
            break;
        default:
            printf("Enter in a digit from 0 to 8\n");
            exit(-1);
            continue;
        }
        printf("\n");
        // }
        // else
        // {
        //     printf("Enter in a digit from 0 to 8\n");
        //     exit(-1);
        // }
    }
    /*appendRear2D(head, "joe");
    appendRear1D(head, "xy2", "joe");
    appendRear1D(head, "sally", "joe");
    appendRear1D(head, "e342", "joe");
    appendRear2D(head, "alice");
    appendRear2D(head, "R2D2");
    appendRear1D(head, "cso", "R2D2");
    appendRear1D(head, "c3p0", "R2D2");
    system("pause");
    printAll(head);
    printf("\n");
    print1DList(head, "joe");
    find2D(head, "joe");
    find2D(head, "not joe");
    find1D(head, "c3p0");
    find1D(head, "not c3p0");
    find1D(head, "alice");
    appendAfter2D(head, "joe", "mary");
    printAll(head);
    appendAfter1D(head, "c3p0", "bob");
    printAll(head);*/
}