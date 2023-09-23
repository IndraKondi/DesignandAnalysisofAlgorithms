//this program gives the correct output.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int flg;
    int dept;
    char dest[100];
} table;

void mergeSort(table arr[], int low, int high);
int merge(table arr[], int low, int mid, int high);

void qsort(table arr[], int low, int high);
int partition(table arr[], int low, int high);

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

    qsort(arr, 0, n - 1);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %s\n", arr[i].flg, arr[i].dept, arr[i].dest);
    }

    return 0;
}

// First sorting

void qsort(table arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        qsort(arr, low, p);
        qsort(arr, p + 1, high);
    }
}

int partition(table arr[], int low, int high)
{
    int pivot = arr[low].dept;
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i].dept < pivot);
        do
        {
            j--;
        } while (arr[j].dept > pivot);

        if (i >= j)
            return j;
        table t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

// Second Sorting

void mergeSort(table arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int merge(table arr[], int low, int mid, int high)
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