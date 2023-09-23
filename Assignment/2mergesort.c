#include <stdio.h>
#include <string.h>

char b[100][100];
void mergeSort(char arr[][100], int low, int high);
int merge(char arr[][100], int low, int mid, int high);

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    char arr[n][100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("\nStrings in Sorted Order is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s \n", arr[i]);
    }
    return 0;
}

void mergeSort(char arr[][100], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int merge(char arr[][100], int low, int mid, int high)
{
    int i = low;
    int h = low;
    int j = mid + 1;

    while ((h <= mid) && (j <= high))
    {
        if (strcmp(arr[h], arr[j]) <= 0)
        {
            strcpy(b[i], arr[h]);
            h++;
        }
        else
        {
            strcpy(b[i], arr[j]);
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
        {
            strcpy(b[i], arr[k]);
            i++;
        }
    }
    else
    {
        for (int k = h; k <= mid; k++)
        {
            strcpy(b[i], arr[k]);
            i++;
        }
    }
    for (int i = low; i <= high; i++)
    {
        strcpy(arr[i], b[i]);
    }
}
