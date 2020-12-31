#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void interleave(char *ans, char *s, char *t, int n)
{
    if (strlen(s) + strlen(t) > n)
    {
        printf("Lengths of input strings do not add to n\n");
        ans = "";
        return;
    }
    else
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 1)
            {
                ans[i] = t[j];
                j++;
            }
            else
            {
                ans[i] = s[j];
            }
        }
    }
}

int main()
{
    // Test 1
    char ans[] = "This is the answer";
    int n = 18;
    char s[] = "hhhhhhhhh";
    char t[] = "iiiiiiiii";
    interleave(ans, s, t, n);
    printf("New string: %s\n", ans);

    // Test 2
    char ans1[] = "This is most certainly the answer.";
    int n1 = 34;
    char s1[] = "Iwudmc ahrhv hsas";
    char t1[] = " ol uhrte aeti n.";
    interleave(ans1, s1, t1, n1);
    printf("New string: %s\n", ans1);
}