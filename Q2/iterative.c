#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int a = 0, b = 1, c = 2;
    int i;
    for (i = 3; i <= n; i++)
    {
        int temp = c;
        c = b + a;
        a = b;
        b = temp;
    }

    return c;
}

int main()
{
    int n = 10; // Example input
    int result = fibonacci(n);
    printf("F(%d) = %d\n", n, result);
    return 0;
}