#include<iostream>
using namespace std;

bool F(int arr[], int start, int end, int K)
{
	int Mid = (start + end) / 2;
	int Sum = arr[Mid]+arr[Mid+1];
	if(Mid == start && Sum < K)
		return false;
	if(Mid == end && Sum > K)
		return false;
	if(Sum == K)
		return true;
	else if(Sum > K)
		F(arr,start,Mid,K);
	else
		F(arr,Mid,end,K);
}

int main()
{
	int arr[] = {6,8,9,10,11,15};
	cout<<F(arr,0,5,17);
	int arr2[] = {5,12,20,25,3};
	cout<<F(arr2,0,4,38);
	return 0;
}
