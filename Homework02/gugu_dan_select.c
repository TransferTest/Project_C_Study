#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    for (int j = 1; j <= 9; j++)
    {
        printf("%d X %d = %2d\n", n, j, n * j);
    }
    return 1;
}