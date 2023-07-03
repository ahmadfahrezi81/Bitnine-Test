#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return fibonacci(n - 3) + fibonacci(n - 2);
}

int main()
{
    int n = 10; // Example input
    int result = fibonacci(n);
    printf("F(%d) = %d\n", n, result);
    return 0;
}