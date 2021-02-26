#include <iostream>
using namespace std;

int total_comparisons=0;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    total_comparisons++;

    if (r < n && arr[r] > arr[largest])
        largest = r;
    total_comparisons++;

    if (largest != i)
    {
        total_comparisons++;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout <<endl<<endl<<"Total Comparisons = "<<total_comparisons;
}

int main()
{
    int n;

    cout<<"Enter Size Of Array : ";
    cin>>n;

    int arr[n];

    cout<<"\n\nEnter Elements : ";

    for(int i=0; i<n; i++)
        cin>>arr[i];

    heapSort(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
}
