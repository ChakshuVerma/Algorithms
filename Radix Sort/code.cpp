#include <iostream>
using namespace std;

//Function to get the maximum element in an array
int getMax(int A[], int n)
{
    int Max = A[0];

    for (int i = 1; i < n; i++)
        if (A[i] > Max)
            Max = A[i];
    return Max;
}


//Function to do counting sort of arr[] according to the digit represented by exp.
void countSort(int A[], int n, int exp)
{
    int output[n];      //Output array
    int i,count[10]={0};

    //Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(A[i]/exp)%10]++;

    //Converting count into it's own prefix array
    for (i = 1; i < 10; i++)
        count[i]+=count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(A[i]/exp)%10]-1] = A[i];
        count[(A[i]/exp)%10]--;
    }

    for (i = 0; i < n; i++)
        A[i] = output[i];
}

void RadixSort(int A[], int n)
{
    int m = getMax(A, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(A, n, exp);
}

void Print(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}

int main()
{
    int n,A[100];

    cout<<"Enter Size Of Array : ";
    cin>>n;

    cout<<"\nEnter Elements \n";

    for(int i=0; i<n; i++)
        cin>>A[i];

    RadixSort(A,n);

    cout<<"\nSorted array:\n";
    Print(A, n);

}
