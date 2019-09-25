#include<iostream>
using namespace std;
int binary_search(int*,int,int,int);
int search_right(int*,int,int,int);
int search_left(int*,int,int,int);
int righ;
int lef;			//can't use right left due to ambiguity error
main()
{
	righ=0;lef=0;
	int n;
	cout<< "Enter the size of array: ";
	cin>>n;
	int* arr = new int[n];
	cout << "Please give me sorted array(accending): ";
	for(int i=0 ; i<n ; i++)
	cin>>arr[i];
	
	int key;
	cout << "Enter the element which you want to find: ";
	cin>>key;
	int r = binary_search(arr,key,0,n-1);
	if(r!=-1)
	cout << "Rightmost occurance: " << righ <<"\nLeftmost occurance: " << lef;
	else 
	cout << "Your element is not here";
	
}

int binary_search(int* arr, int key ,int nl , int nr)
{
	int mid = (nr+nl)/2;
	if(arr[mid] == key)
	{
	if(arr[mid+1] != arr[mid] )
	return mid+1;
	else
	righ = binary_search(arr,key,mid+1,nr);
	
	return 0;
	
	}									//you read it as mid+1 on screen
	else if (arr[mid] > key)
	nr = mid-1;
	else 							// if (arr[mid] < key) gets the default condition
	nl = mid +1;
	if(nl > nr)
	return -1 ;
	return binary_search(arr,key,nl,nr);
}

//these are some functions used if there is repition.
int search_right(int* arr,int mid,int key,int nr)
{	
	cout << "right ";
	if(arr[mid+1] != arr[mid] )
	return mid+1;
	else
	return binary_search(arr,key,mid+1,nr);
}


int search_left(int* arr,int mid,int key,int nl)
{	
cout << "left ";
	if(mid==0)return mid+1;
	if(arr[mid-1] != arr[mid] )
	return mid+1;
	else
	return binary_search(arr,key,nl,mid-1);
}



