#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

int frogJump(int n, int h[])
{
    int dp[n];

    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        int jump1 = dp[i-1] + abs(h[i] - h[i-1]);

        if(i > 1)
        {
            int jump2 = dp[i-2] + abs(h[i] - h[i-2]);
            dp[i] = min(jump1, jump2);
        }
        else
        {
            dp[i] = jump1;
        }
    }

    return dp[n-1];
}

int main()
{
    int n;
    scanf("%d",&n);

    int h[n];

    for(int i=0;i<n;i++)
        scanf("%d",&h[i]);

    printf("%d\n", frogJump(n,h));

    return 0;
}