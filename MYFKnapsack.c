#include <stdio.h>

struct Info
{
    int weight;
    int value;
    float ratio;
};

void input(struct Info info[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Entr weight and value of item %d: ", i + 1);
        scanf("%d %d", &info[i].weight, &info[i].value);

        info[i].ratio = (float)info[i].value / info[i].weight;
    }
}

void sort(struct Info info[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (info[i].ratio < info[j].ratio)
            {
                struct Info temp;
                temp = info[i];
                info[i] = info[j];
                info[j] = temp;
            }
        }
    }
}

float maxprofit(struct Info info[], int capacity, int n)
{
    float profit = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (capacity >= info[i].weight)
        {
            capacity = capacity - info[i].weight;
            profit = profit + info[i].value;
        }
        else
        {
            profit = profit + (capacity * info[i].ratio);
            break;
        }
    }
    return profit;
}

int main()
{
    int n;
    printf("Entr how many items: ");
    scanf("%d", &n);
    struct Info info[n];

    input(info, n);

    sort(info, n);

    int capacity;
    printf("Enter knapsack capacity : ");
    scanf("%d ", &capacity);

    float result;
    result = maxprofit(info, capacity, n);

    printf("TOTAL PROFIT: %.2f\n", result);
    return 0;
}