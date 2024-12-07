#include<iostream>
using namespace std;

template<class T>
void insertion(T data[],int n)
{
	for(int i = 1,j; i<n ;i++)
	{
		T temp = data[i];
		for(j=i;j>0 && temp < data[j-1];j--)
		{
			data[j] = data[j-1];
		}
		data[j] = temp;
	}
	for(int i=0;i<n;i++)
		cout<<data[i]<<"	";
	cout<<endl;
}
template<class T>
void BubbleSort(T arr[], int n) { 

	for(int i=0;i<n-1;i++)
	{ 
	    for(int j=0;j<n-i-1;j++)
		{ 
	         if(arr[j]>arr[j+1])
			 { 
				T temp = arr[j+1]; 
				arr[j+1] = arr[j];
				arr[j] = temp;
		 	}
	    }
	}
	for(int i= 0; i<n;i++)
		cout<<arr[i]<<"	";
	cout<<endl;
 }

void selectionSort(int list[], int listLength) {
//   int index;
   int smallestIndex;
   int minIndex;
   int temp;
   for (int index = 0; index < listLength; index++) 
   {
       smallestIndex = index; 
       for (minIndex = index + 1;minIndex < listLength; minIndex++)
	   {
                if (list[minIndex] < list[smallestIndex])
				{
                      smallestIndex = minIndex;
    			}
    	}
      temp = list[smallestIndex];
      list[smallestIndex] = list[index];
      list[index] = temp;
   }
   for(int i= 0; i<listLength;i++)
		cout<<list[i]<<"	";
	cout<<endl;
}

int Partition(int arr[], int s, int e){
   int pivot = arr[e];
   int pIndex = s;
 
   for(int i = s;i<e;i++){
        if(arr[i]<pivot){
             int temp = arr[i];
             arr[i] = arr[pIndex];
             arr[pIndex] = temp;
             pIndex++;
         }
 }
   int temp = arr[e];
   arr[e] = arr[pIndex];
   arr[pIndex] = temp;
 
   return pIndex;
}
 
void QuickSort(int arr[], int s, int e){
 if(s<e){
 int p = Partition(arr,s, e);
 QuickSort(arr, s, (p-1));  // recursive QS call for left partition
 QuickSort(arr, (p+1), e);  // recursive QS call for right partition
 }
}




int main()
{
	int arr[] = {2,4,7,1,3,9};
	insertion(arr,6);
	BubbleSort(arr,6);
	selectionSort(arr,6);
	QuickSort(arr,0,5);
	for(int i= 0; i<6;i++)
		cout<<arr[i]<<"	";
	return 0;
}
