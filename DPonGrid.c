#include <stdio.h>

void input(int n, int val[n][n])
{
    printf("Enter the value of grid: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &val[i][j]);
    }
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int dptable(int n, int val[n][n])
{
    int dp[n][n];
    dp[0][0] = val[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;

            if (i == 0)
                dp[i][j] = dp[i][j - 1] + val[i][j];

            else if (j == 0)
                dp[i][j] = dp[i - 1][j] + val[i][j];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + val[i][j];
        }
    }
    return dp[n - 1][n - 1];
}

int main()
{
    int n;
    printf("Enter Grid Size: ");
    scanf("%d", &n);

    int val[n][n];
    input(n, val[n][n]);

    int profit;
    profit = dptable(n, val);

    printf("MAX PRODIT: %d\n", profit);

    return 0;
}