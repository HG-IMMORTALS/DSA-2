#include <stdio.h>

void input(int arr[20][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void output(int arr[20][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
}

void Add(int arr[20][20], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
    }
    printf("Sum of all elements: %d\n", sum);
}

void AddDiagnol(int arr[20][20], int n)
{
    int sumL = 0, sumR = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                sumL += arr[i][j];
            if (i + j == n - 1)
                sumR += arr[i][j];
        }
    }
    printf("Sum of all diagnols: %d\n", sumL + sumR);
}

void countOdd(int arr[20][20], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[i][j]) % 2 != 0)
                count++;
        }
    }
    printf("No of odd elements\n", count);
}

void largestElement(int arr[20][20], int n)
{
    int maxi = arr[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] >= maxi)
                maxi = arr[i][j];
        }
    }
    printf("Largest Element in array: %d \n", maxi);
}
int main()
{
    int n, arr[20][20], ch;
    printf("Enter the m X n range for matrix\n");
    scanf("%d", &n);

    while (1)
    {
        printf("Enter your choice:\n");
        printf("1.Input\n");
        printf("2.Output\n");
        printf("3.Add All Elements\n");
        printf("4.Add Diagnol Elements\n");
        printf("5.Count no of odd elements\n");
        printf("6.Largest Element\n");
        printf("7.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            input(arr, n);
            break;
        case 2:
            output(arr, n);
            break;
        case 3:
            Add(arr, n);
            break;
        case 4:
            AddDiagnol(arr, n);
            break;
        case 5:
            countOdd(arr, n);
            break;
        case 6:
            largestElement(arr, n);
            break;
        case 7:
            return 0;
        }
    }
    return 0;
}