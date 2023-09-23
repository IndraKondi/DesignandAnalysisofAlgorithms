#include <stdio.h>
#include <string.h>

void selectionSort(char arr[][100], int n);

int main()
{
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    char arr[n][100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    selectionSort(arr, n);
    printf("\nStrings in Sorted Order is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s  \n", arr[i]);
    }
    return 0;
}

void selectionSort(char arr[][100], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j], arr[min]) < 0)
            {
                min = j;
            }
        }
        char t[100];
        strcpy(t, arr[min]);
        strcpy(arr[min], arr[i]);
        strcpy(arr[i], t);
    }
}
