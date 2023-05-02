#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int largest = root;
   int l = 2*root+1;
   int r = 2*root+2;
   if ((l<n )&& (arr[l]>arr[largest])){
      largest = l;
   }
   if ((r<n) && (arr[r]>arr[largest])){
      largest =r;
   }
   
   if (largest!=root){
      int temp = arr[root];
      arr[root]=arr[largest];
      arr[largest]=temp;
      heapify(arr,n,largest);
   }
  
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i=n/2-1;i>-1;i--){
      heapify(arr,n,i);
   }
   for (int j=n-1;j>0;j--){
      int temp = arr[0];
      arr[0]=arr[j];
      arr[j]= temp;
      heapify(arr,j,0);
   }
  
   // extracting elements from heap one by one
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n = 0 ;
   cout <<"Enter the length of the array: ";
   cin >> n;
   int heap_arr[n] ={0} ;
   for (int i = 0 ; i<n ; i++){
      cout << "Enter the element "<< i+1<<":";
      cin >> heap_arr[i];
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}