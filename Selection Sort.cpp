//https://www.geeksforgeeks.org/selection-sort/

// Time Complexity: O(n2) as there are two nested loops.
// Auxiliary Space: O(1) 
// The good thing about selection sort is it never makes more than O(n) swaps 
// and can be useful when memory write is a costly operation. 

#include <bits/stdc++.h>

using namespace std;

void printArray( int arr[] , int n )
{
	for( int  i = 0 ; i < n ; i++ )
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void swapping( int *val1 ,int *val2 )
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void selection_sort( int arr[] , int n )
{
	for( int i = 0 ; i < n ; i++ )
	{
		int min_idx = i;
		for( int j = i + 1 ; j < n ; j++ )
		{
			if( arr[min_idx] > arr[j] )
			{
				min_idx = j;
			}
		}
		swapping( &arr[min_idx] , &arr[i] );
	}
}

int main()
{
	int n;
	cout<<"Enter the number of Elemenets:\n";
	cin>>n;

	int arr[n+10];
	for( int  i = 0 ; i < n ; i++ )
	{
		arr[i] = rand()%10;
	}

	printArray( arr , n );
	selection_sort( arr , n );
	cout<<"Selection Sort \n";
	printArray( arr , n );

	return 0;
}
