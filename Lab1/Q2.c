#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longer(char *s, char *t)
{
    if (strlen(s) > strlen(t))
    {
        printf(s);
    }
    if (strlen(s) < strlen(t))
    {
        printf(t);
    }
    if (strlen(s) == strlen(t))
    {
        printf("equal");
    }
    printf("\n");
    return strlen(s) + strlen(t);
}

int main()
{
    // Test 1
    longer("Hello", "World");
    // Test 2
    longer("Hi", "World");
    // Test 3
    longer("Nothing to see here :)", "World");
}