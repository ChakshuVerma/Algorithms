#include <iostream>
using namespace std;

int count=0;
void insertion_Sort(int arr[], int n)
{
	int i,temp,j;
	for (i=1; i<n; i++)
	{
		temp=arr[i];
		j=i-1;
		while (j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
            count++;
		}
		count++;

        if(j>=0)
            if(arr[j]<temp)
                count++;
        count++;
        arr[j+1]=temp;
    }
    cout<<"Sorted Array : ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
	int size,arr[10];

	cout<<"Enter Size Of Array : ";
	cin>>size;

	cout<<"\nEnter Elements : ";
	for(int i=0; i<size; i++)
        cin>>arr[i];


	insertion_Sort(arr, size);
    cout<<"\nNo. of comparisons made : "<<count<<endl;
	return 0;
}
