#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        char *str = argv[1];
        char *except = argv[2];
        printf("Arg1: %s\n", str);
        printf("Arg2: %s\n", except);
        printf("All letters in first arg that are not in second: ");
        for (int i = 0; i < strlen(str); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || str[i] == ' ')
            {
                if (!(strchr(except, str[i]) != NULL))
                {
                    putchar(str[i]);
                }
            }
            else
            {
                printf("This string contains an uppercase letter and is illegal.\n");
                return -1;
            }
        }
    }
    else
    {
        printf("Must contain 2 args.\n");
    }
}