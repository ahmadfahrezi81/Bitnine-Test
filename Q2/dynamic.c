#include <stdio.h>

int fibonacci(int n, int *cache)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    if (cache[n] != -1)
        return cache[n];

    int result = fibonacci(n - 3, cache) + fibonacci(n - 2, cache);
    cache[n] = result;
    return result;
}

int main()
{
    int n = 10; // Example input

    // Initialize cache with -1 values
    int cache[n + 1];
    for (int i = 0; i <= n; i++)
        cache[i] = -1;

    int result = fibonacci(n, cache);
    printf("F(%d) = %d\n", n, result);
    return 0;
}