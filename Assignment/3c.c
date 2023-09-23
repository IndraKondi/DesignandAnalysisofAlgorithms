#include <stdio.h>
#include <string.h>

typedef struct
{
    int flg;
    int dept;
    char dest[100];
} table;

void mergeSortInt(table arr[], int low, int high);
void mergeInt(table arr[], int low, int mid, int high);

void mergeSortString(table arr[], int low, int high);
void mergeString(table arr[], int low, int mid, int high);

table b[100];

int main()
{
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    table arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Flight no: ");
        scanf("%d", &arr[i].flg);
        printf("Enter Depature time: ");
        scanf("%d", &arr[i].dept);
        printf("Enter Destination: ");
        scanf("%s", arr[i].dest);
    }

    mergeSortInt(arr, 0, n - 1);
    mergeSortString(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %s\n", arr[i].flg, arr[i].dept, arr[i].dest);
    }

    return 0;
}

// First sorting
void mergeSortInt(table arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSortInt(arr, low, mid);
        mergeSortInt(arr, mid + 1, high);
        mergeInt(arr, low, mid, high);
    }
}

void mergeInt(table arr[], int low, int mid, int high)
{
    int i = low;
    int h = low;
    int j = mid + 1;

    while ((h <= mid) && (j <= high))
    {
        if (arr[h].dept <= arr[j].dept)
        {
            b[i] = arr[h];
            h++;
        }
        else
        {
            b[i] = arr[j];
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (int k = h; k <= mid; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}

// Second Sorting

void mergeSortString(table arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSortString(arr, low, mid);
        mergeSortString(arr, mid + 1, high);
        mergeString(arr, low, mid, high);
    }
}

void mergeString(table arr[], int low, int mid, int high)
{
    int i = low;
    int h = low;
    int j = mid + 1;

    while ((h <= mid) && (j <= high))
    {
        if (strcmp(arr[h].dest, arr[j].dest) <= 0)
        {
            b[i] = arr[h];
            h++;
        }
        else
        {
            b[i] = arr[j];
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (int k = h; k <= mid; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}