#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

void inputItems(int value[], int weight[], int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &value[i], &weight[i]);
    }
}

int knapsack(int capacity, int weight[], int value[], int n)
{
    int dp[n+1][capacity+1];

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i-1] <= w)
                dp[i][w] = max(value[i-1] + dp[i-1][w-weight[i-1]], dp[i-1][w]);

            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, capacity;

    scanf("%d", &n);

    int value[n], weight[n];

    inputItems(value, weight, n);

    scanf("%d", &capacity);

    int result = knapsack(capacity, weight, value, n);

    printf("Maximum value = %d\n", result);

    return 0;
}
