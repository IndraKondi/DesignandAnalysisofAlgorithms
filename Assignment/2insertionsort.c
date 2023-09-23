#include <stdio.h>
#include <string.h>

void insertionSort(char arr[][100], int n);

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
    insertionSort(arr, n);
    printf("\nStrings in Sorted Order is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s \n", arr[i]);
    }

    return 0;
}

void insertionSort(char arr[][100], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        char key[100];
        strcpy(key, arr[i]);
        while (j >= 0 && strcmp(arr[j], key) > 0)
        {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);
    }
}