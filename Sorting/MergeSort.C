#include <stdio.h>

void merge(int A[], int s, int mid, int e)
{
    int i = s;
    int j = mid + 1;
    int k = s;
    int B[100];

    while (i <= mid && j <= e)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    while (i <= mid)
    {
        B[k++] = A[i++];
    }

    while (j <= e)
    {
        B[k++] = A[j++];
    }

    for (i = s; i <= e; i++)
    {
        A[i] = B[i];
    }
}

void Mergesort(int A[], int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        Mergesort(A, s, mid);
        Mergesort(A, mid + 1, e);
        merge(A, s, mid, e);
    }
}

//  .............................

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    Mergesort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}