#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPrime(const int n)
{
    int factors = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            factors++;
    return (factors == 2) ? 1 : 0;
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        int arg1 = atoi(argv[1]);
        int arg2 = atoi(argv[2]);
        if (arg1 <= arg2)
        {
            printf("IsPrime from %i to %i\n=====================\n", arg1, arg2);
            for (int i = arg1; i <= arg2; i++)
            {
                printf("%i: %i\n", i, isPrime(i));
            }
        }
        else
        {
            printf("arg1 must be less than or equal to arg2.\n");
            return -1;
        }
    }
    else
    {
        printf("argc must be equal to 3.\n");
        return -1;
    }
}
