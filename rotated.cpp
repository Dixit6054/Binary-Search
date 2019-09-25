/*sorted array
rotated.
find the number of times array in rotated.
given : the rotated array,
using min complexity**/

#include<iostream>
using namespace std;
int rotatednumber(int*,int);
int main()
{
	int arr[9] = {11,15,22,24,4,5,7,9,10};
//check out that the index of element 2(min) will be the no. of rotations
//2 is the place where sorted behavior first breaks.--> that gives me idea for linear search O(n). not bad
// 2 is the only place,ie both sides are sorted;---> divide and conquer-->binary search
// BUT how will i divide the problem?
int ans = rotatednumber(arr,9);
if(ans!=-1)cout << "There are " << ans << " rotations";
else cout << "Array is not rotated";
}

int rotatednumber(int* arr,int n)
{
	int nl = 0;
	int nr = n-1;
	int mid =(nl+nr)/2;

if (arr[nl] <= arr[nr])
	return -1;
	
while( (arr[mid-1] < arr[mid]) && mid>0)
{	
	
	if( arr[nl] <= arr[mid] )
	{
		nl = mid + 1;
				mid = (nl+nr)/2;
		cout << " work1 ";
	}	
	
	else if (arr[mid] <= arr[nr])
	{
		nr = mid -1;
		cout << " work2 ";
		mid = (nl+nr)/2;
	}
	cout << mid << endl;
	cout << arr[nl] << " " << arr[mid] << " " << arr[nr] << endl;
	
}
	return mid;
	
		
	
	
}
