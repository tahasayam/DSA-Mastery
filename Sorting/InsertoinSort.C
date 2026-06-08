#include <stdio.h>

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n ; i++)
    {
        int curr = A[i];
        int prev = i - 1;

        while (prev >= 0 && A[prev] > curr)
        {
            A[prev + 1] = A[prev];
            prev--;
        }

        A[prev+1] = curr;
    }
}
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{

    int arr[] = {4, 1, 5, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    InsertionSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
}
