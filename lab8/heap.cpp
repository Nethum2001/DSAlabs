#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int left = 2 * root +1;
   int right = 2*(root +1);
   int largest = root;
   if(left<n && arr[left]>arr[largest]){ 
      largest = left;
     }
   if(right<n && arr[right]>arr[largest]) {
      largest = right;
   }
   if(largest != root){
      swap(arr[root], arr[largest]);
      heapify(arr, n, largest);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   for(int i=n/2 -1; i>=0; i--){
      heapify(arr, n, i);
   }
   for (int i = n - 1; i > 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
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
   int val;
   vector<int> arr;
   cin >> val;
   while (getchar() != '\n')
   {
       arr.push_back(val);
       cin >> val;
   }
   arr.push_back(val);
   int vec_size = arr.size();
   int heap_arr[vec_size];
   for (int i=0;i<vec_size;i++){
       heap_arr[i] = arr[i];
   }
   //int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
   return 0;
}