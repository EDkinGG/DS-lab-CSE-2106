//log(n)
#include <bits/stdc++.h>

using namespace std;


int binary_search( int arr[], int lft, int rt, int x )
{
	while( lft <= rt )
	{
		int mid = lft + ( rt - lft ) / 2;

		if( arr[mid] == x )
		{
			return mid;
		}
		else if( x < arr[mid] )
		{
			rt = mid-1;
		}
		else if( x > arr[mid]  )
		{
			lft = mid+1;
		}  
	}
	return -1;
}


int main()
{
	int arr[] = {2,5,6,9,8,7,10,12,13,16};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+n);

	int x;
	cout<<"Enter a Number to search:\n";
	cin>>x;
	int result = binary_search(arr,0,n-1,x);

	(result == -1)? cout<<"Element is not found"
				  : cout<<"Element is at index "<<result;
	cout<<endl;

	return 0;
}