#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int leftindex = 2 * i;
    int rightindex = 2 * i + 1;

    if(leftindex <= n && arr[largest] < arr[leftindex]){
        largest = leftindex;
    }
    if(rightindex <= n && arr[largest] < arr[rightindex]){
        largest = rightindex;
    }
    if(largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){

        // Step 1
        swap(arr[size], arr[1]);
        size--;

        // Step 2
        heapify(arr, size, 1);
    }
}

int main(){
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    
    // Creation of the heap
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }

    // Performing the heap sort
    heapSort(arr, n);
    cout<<"Printing the Sorted arr"<<endl;
    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}