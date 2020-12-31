#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct box3
{
    int factor1;
    int factor2;
    struct box3 *next;
} box3;

int evalList(struct box3 *start)
{
    int sum = 0;
    struct box3 *curr = start;
    curr = curr->next;
    while (curr != NULL)
    {
        sum += (curr->factor1 * curr->factor2);
        curr = curr->next;
    }
    return sum;
}

int main(int argc, char *argv[])
{
    system("pause");
    struct box3 *start = (struct box3 *)malloc(sizeof(struct box3));
    start->next = (struct box3 *)malloc(sizeof(struct box3));
    start->next->factor1 = -1;
    start->next->factor2 = -4;
    start->next->next = (struct box3 *)malloc(sizeof(struct box3));
    start->next->next->factor1 = -3;
    start->next->next->factor2 = 2;
    start->next->next->next = (struct box3 *)malloc(sizeof(struct box3));
    start->next->next->next->factor1 = 1;
    start->next->next->next->factor2 = 5;
    start->next->next->next->next = (struct box3 *)malloc(sizeof(struct box3));
    start->next->next->next->next->factor1 = 2;
    start->next->next->next->next->factor2 = 4;
    start->next->next->next->next->next = NULL;
    printf("%i", evalList(start));
}