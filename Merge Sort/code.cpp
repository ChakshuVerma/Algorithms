#include <iostream>
using namespace std;

int total_comparisons=0;

void merge(int arr[], int l, int m, int r)
{
    int n1=m - l + 1;
    int n2=r - m;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i],total_comparisons++;
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j],total_comparisons++;

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        total_comparisons++;
        if(L[i]<=R[j])
            arr[k]=L[i],i++;
        else
            arr[k]=R[j],j++;
        k++;
    }

    while (i < n1)
    {
        total_comparisons++;
        arr[k]=L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        total_comparisons++;
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r){
    total_comparisons++;
    if(l>=r)
        return;

    int m=l+(r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout<<"\nTotal Comparisons : "<<total_comparisons<<endl;
}

int main()
{
    int arr_size;

    cout<<"Enter The Size Of Array : ";
    cin>>arr_size;

    int arr[arr_size+2];

    cout<<"\nEnter Elements : ";
    for(int i=0; i<arr_size; i++)
        cin>>arr[i];

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted Array Is : ";
    printArray(arr, arr_size);
    return 0;
}
