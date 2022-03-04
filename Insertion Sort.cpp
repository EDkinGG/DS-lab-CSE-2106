//https://www.geeksforgeeks.org/insertion-sort/

// Time Complexity: O(n^2) 
// Auxiliary Space: O(1)

//Uses: Insertion sort is used when number of elements is small. 
//It can also be useful when input array is almost sorted, 
//only few elements are misplaced in complete big array.

#include <bits/stdc++.h>

using namespace std;

void printArray( int arr[] , int n )
{
	for( int  i = 0 ; i < n ; i++ )
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void insertion_sort( int arr[] , int n )
{

	for( int i = 1; i < n ; i++ )
	{
		int key = arr[i];
		int j = i - 1;

		while( j >= 0  && key < arr[j] )
		{
			arr[j+1] = arr[j];
			j--;
		}
		j++;
		arr[j] = key;
	}
}


int main()
{
	int n;
	cout<<"Enter the Number of Elements:\n";
	cin>>n;

	int arr[n+10];
	for( int i = 0 ; i < n ; i++ )
	{
		arr[i] = rand()%10;
	}
	printArray(arr,n);
	insertion_sort(arr,n);
	cout<<"insertion Sort\n";
	printArray(arr,n);

	return 0;
}