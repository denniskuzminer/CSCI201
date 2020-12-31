#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *mcopy(char *s, int n)
{
    char *result = (char *)malloc((strlen(s)) * (n));
    for (int i = 0; i < (strlen(s)) * (n); i++)
    {

        result[i] = '\0';
    }
    int index = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < strlen(s); j++)
        {
            result[index] = s[j];
            index++;
        }
    }
    strcat(result, s);
    return result;
}

int main(int argc, char *argv[])
{
    printf("Result: helloooooo\n");
    printf("Result: %s\n", mcopy("123def", 3));
    printf("Result: %s\n", mcopy("hello", 6));
    printf("Result: %s\n", mcopy("nooooooo", 2));
    printf("Result: %s\n", mcopy("yessssssssssss", 3));
    printf("Result: helloooooo\n");
}