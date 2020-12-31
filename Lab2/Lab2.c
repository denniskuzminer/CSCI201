#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void appendRear2D(struct Node2d *head, char *name1)
{
    struct Node2d *curr = head;
    while (curr->down != NULL)
    {
        printf("hi");
        curr = curr->down;
    }
    curr->down = (struct Node2d *)malloc(sizeof(struct Node2d));
    strcpy(curr->down->name, name1);
    curr->down->down = NULL;
    curr->down->first = NULL;
    curr->down->first->next = NULL;
}

void appendRear1D(struct Node2d *head, char *name1, char *name2d)
{
    struct Node2d *curr = head;
    while (!strcmp(curr->down->name, name2d) == 0)
    {
        // if (strcmp(curr->down->name, name2d) == 0)
        // {
        curr = curr->down;
        // }
    }
    struct Node1d *curr1d = curr->first;
    while (curr1d->next != NULL)
    {
        curr1d = curr1d->next;
    }
    curr1d->next = (struct Node1d *)malloc(sizeof(struct Node1d));
    strcpy(curr1d->next->name, name1);
    curr1d->next->next = NULL;
}

void printAll(struct Node2d *head)
{
    struct Node2d *curr = head;
    curr = curr->down;
    while (curr->down != NULL)
    {
        printf(curr->name);
        if (curr->first != NULL)
        {
            struct Node1d *curr1d = curr->first;
            while (curr1d->next != NULL)
            {
                printf(" --> ");
                printf(curr1d->name);
                curr1d = curr1d->next;
            }
        }
        printf("\n|\n");
        printf("|\n");
        curr = curr->down;
    }
}

int main()
{
    // This is the invisible "head" node
    struct Node2d *head;
    head = (struct Node2d *)malloc(sizeof(struct Node2d));
    head->down = NULL;
    head->first = NULL;
    appendRear2D(head, "joe");
    printf("%s\n", head->down->name);
    appendRear1D(head, "joe1", "joe");
    appendRear2D(head, "mary");

    printf("%s\n", head->down->first->name);
    printf("%s\n", head->down->down->name);
}