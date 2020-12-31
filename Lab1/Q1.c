#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vowels(char *str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            count++;
            str[i] = '@';
        }
    }
    return count;
}

int main()
{
    // Test 1
    char str[] = "Hello World";
    printf("Original string: %s\n", str);
    int numVowels = vowels(str);
    printf("Edited string: %s\n", str);
    printf("There are %i vowels in your string.\n", numVowels);

    // Test 2
    char str1[] = "abc3@U";
    printf("Original string: %s\n", str1);
    numVowels = vowels(str1);
    printf("Edited string: %s\n", str1);
    printf("There are %i vowels in your string.\n", numVowels);
}