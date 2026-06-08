#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[smallestindex])
            {
                smallestindex = j;
            }
        }
        swap(&A[smallestindex],&A[i]);
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

    int A[] = {64, 25, 12, 22, 11};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Original array: ");
    printArray(A, n);
    SelectionSort(A, n);
    printf("Sorted array: ");
    printArray(A, n);
    return 0;
}