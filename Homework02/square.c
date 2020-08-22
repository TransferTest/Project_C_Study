#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    for (int i = n; i <= 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 2 * n + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 2 * n - 2; i >= n; i--)
    {
        for (int j = 0; j < 2 * n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 2 * n + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 1;
}