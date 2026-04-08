#include <stdio.h>

struct Item
{
    int weight;
    int value;
    float ratio;
};

void inputItems(struct Item item[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter value & weight of iem %d: ", i + 1);
        scanf("%d %d", &item[i].value, &item[i].weight);

        item[i].ratio = (float)item[i].value / item[i].weight;
    }
}

void sortItems(struct Item item[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                // Here we're swapping the whole structure (value,weight,ratio)
                struct Item temp;
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
}

float fknapsack(struct Item item[], int n, int capacity)
{
    float totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            capacity = capacity - item[i].weight;
            totalValue = totalValue + item[i].value;
        }
        else
        {
            totalValue=totalValue+item[i].ratio*capacity;
            break;
        }
    }
    return totalValue;
}
int main()
{
    int n;
    

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    inputItems(item,n);

    sortItems(item,n);

    int capacity;
    printf("Enter knapsack capacity: ");
    scanf("%d",&capacity);

    float result;
    result = fknapsack(item,n,capacity);

    printf("MAX PROFIT = %.2f\n", result);

    return 0;

}