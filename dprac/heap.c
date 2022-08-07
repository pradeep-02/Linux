#include<stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;  
	*a = *b;
	*b = temp;
}
void maxHeap(int arr[], int n,int i)
{
    // Initialize largest as root
    int largest = i; 
  // left = 2*i + 1
    int l = 2 * i + 1; 
  // right = 2*i + 2
    int r = 2 * i + 2; 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    // If right child is larger than largest 
    // so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected 
        // sub-tree
        maxHeap(arr, n, largest);
    }  
}

void heapSort(int arr[], int n) {
  
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    maxHeap(arr, n, i);
  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
    // Heapify root element to get highest element at root again
    maxHeap(arr, i, 0);
  
  }
  
}

int main()
{
	int arr[] = {81,89,9,11,14,76,54,22};
	
	int size = sizeof(arr)/sizeof(int)-1;
	
	heapSort(arr,size); 
	
	for(int i=1;i<=size;i++)
	{
		printf("%d ",arr[i]);
	}
}
