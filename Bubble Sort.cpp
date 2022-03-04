//https://www.geeksforgeeks.org/bubble-sort/
// Time Complexity: O(n^2) 
// Auxiliary Space: O(1)

#include <bits/stdc++.h>

using namespace std;

void printArray( int arr[] , int  n )
{
	for( int i = 0 ; i < n ; i++ )
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void swapping( int *val1 , int *val2 )
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void Bubble_Sort( int arr[] , int  n )
{
	bool swapped = false;
	for( int  i = 0 ; i < n - 1 ; i++ )
	{
		for( int j = 0 ; j < n - i - 1  ; j++ )
		{
			if( arr[j] > arr[j+1] )
			{
				swapping( &arr[j] , &arr[j+1] );
				swapped = true;
			}
		}
		if( swapped == false )
		{
			break;
		}
	}
}

int main()
{
	int n;
	cout<<"Enter the Number of Elements:\n";
	cin>>n;

	int arr[n+10];
	for( int  i = 0 ; i < n ; i++ )
	{
		arr[i] = rand()%10;
	}

	printArray( arr , n);
	Bubble_Sort( arr , n );
	cout<<"Bubble Sort\n";
	printArray( arr , n );

	return 0;
}