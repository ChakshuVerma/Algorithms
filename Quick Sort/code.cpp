#include<iostream>
using namespace std;

int Comparisons = 0;

int partition (int A[], int low, int high)
{
    int pivot = A[high];
    int i = low-1;          //Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        Comparisons++;
        // If current element is smaller than or equal to pivot
        if (A[j] <= pivot)
            swap(A[++i],A[j]);
    }
    swap(A[i + 1], A[high]);

    return i + 1;
}

void quickSort(int A[], int low, int high)
{
    Comparisons++;

    if (low < high)
    {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

void Print(int A[], int size)
{
    for (int i=0; i < size; i++)
        cout<<A[i]<<" ";
}

int main()
{
    int n,A[100];

    cout<<"Enter Size Of Array : ";
    cin>>n;

    cout<<"\nEnter Elements \n";

    for(int i=0; i<n; i++)
        cin>>A[i];

    quickSort(A, 0, n-1);

    cout<<"\nSorted array:\n";
    Print(A, n);

    cout<<"\n\nTotal Comparisons = "<<Comparisons;

    return 0;
}
