#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char c = getchar();
    if (c >= 'A' && c <= 'Z')
    {
        putchar(c + 32);
    }
    else
    {
        if (c >= 'a' && c <= 'z')
        {
            putchar('L');
        }
        else
        {
            if (isdigit(c))
            {
                putchar('D');
                putchar('I');
                putchar('G');
                putchar('I');
                putchar('T');
            }
            else
            {
                printf("Invalid input. Input letter or digit.\n");
                return -1;
            }
        }
    }
}