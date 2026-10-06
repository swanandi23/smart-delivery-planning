#include <stdio.h>

#define MAX 100

struct Package
{
    int id;
    float value, weight, ratio, fraction;
};

struct Package p[MAX];
int n;
float capacity;

void enterDetails()
{
    int i;

    printf("\nEnter number of packages: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("\nPackage %d\n", i + 1);

        printf("Enter value: ");
        scanf("%f", &p[i].value);

        printf("Enter weight: ");
        scanf("%f", &p[i].weight);

        p[i].ratio = p[i].value / p[i].weight;
    }

    printf("\nEnter vehicle capacity: ");
    scanf("%f", &capacity);
}

void displayDetails()
{
    int i;

    printf("\nPackage Details:\n");

    for(i = 0; i < n; i++)
    {
        printf("Package %d : Value = %.2f, Weight = %.2f, Ratio = %.2f\n",
               p[i].id, p[i].value, p[i].weight, p[i].ratio);
    }

    printf("Capacity = %.2f\n", capacity);
}

void calculateRatio()
{
    int i;

    printf("\nValue/Weight Ratio:\n");

    for(i = 0; i < n; i++)
    {
        p[i].ratio = p[i].value / p[i].weight;
        printf("Package %d = %.2f\n", p[i].id, p[i].ratio);
    }
}

void sortPackages()
{
    int i, j, max;
    struct Package temp;

    for(i = 0; i < n - 1; i++)
    {
        max = i;

        for(j = i + 1; j < n; j++)
        {
            if(p[j].ratio > p[max].ratio)
                max = j;
        }

        if(max != i)
        {
            temp = p[i];
            p[i] = p[max];
            p[max] = temp;
        }
    }

    printf("\nPackages sorted by Value/Weight ratio:\n");

    for(i = 0; i < n; i++)
    {
        printf("Package %d : Ratio = %.2f\n",
               p[i].id, p[i].ratio);
    }
}

void findMaximumValue()
{
    int i;
    float remaining = capacity;
    float totalValue = 0;
    float totalWeight = 0;

    for(i = 0; i < n; i++)
        p[i].fraction = 0;

    for(i = 0; i < n; i++)
    {
        if(remaining == 0)
            break;

        if(p[i].weight <= remaining)
        {
            p[i].fraction = 1;
            remaining -= p[i].weight;
            totalWeight += p[i].weight;
            totalValue += p[i].value;
        }
        else
        {
            p[i].fraction = remaining / p[i].weight;
            totalWeight += remaining;
            totalValue += p[i].value * p[i].fraction;
            remaining = 0;
        }
    }

    printf("\nTotal weight used = %.2f\n", totalWeight);
    printf("Maximum value = %.2f\n", totalValue);
}

void displaySelected()
{
    int i;

    printf("\nSelected Packages:\n");

    for(i = 0; i < n; i++)
    {
        if(p[i].fraction > 0)
        {
            printf("Package %d : Fraction = %.2f, Weight = %.2f, Value = %.2f\n",
                   p[i].id,
                   p[i].fraction,
                   p[i].weight * p[i].fraction,
                   p[i].value * p[i].fraction);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\nSmart Delivery Planning - Fractional Knapsack\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enterDetails();
                break;

            case 2:
                displayDetails();
                break;

            case 3:
                calculateRatio();
                break;

            case 4:
                sortPackages();
                break;

            case 5:
                findMaximumValue();
                break;

            case 6:
                displaySelected();
                break;

            case 7:
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while(choice != 7);

    return 0;
}