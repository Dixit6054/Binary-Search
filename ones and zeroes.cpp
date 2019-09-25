//this program will count zeroes; given a constraindeed array has only ones and zeroes 
//http://www.geeksforgeeks.org/find-number-zeroes/
//help yourself;
#include<iostream>
using namespace std;

int zeroes ( int start ,int end ,int n ,int*a )
{
	if(a[start]==a[end] && a[start]==1 )
	return 0;
	
	if(a[start]==a[end] && a[start]==0 )
	return n;
	
	if ( start == end-1 )
	{
		if(a[start]==1 && a[end]==0)
		return n-end;
	}
	
	int mid=(start+end)/2;
	
	if ( a[start] == a[mid] )
	return zeroes( mid , end , n,a);		// considering mid redundantly is important
	else 
	return zeroes( start , mid , n,a);
}

main()
{
	int a[10] = {1,1,1,1,1,1,0,0,0,0};
	int start=0,end=9,n=10;
	
	cout << zeroes(start,end,n,a);
}
