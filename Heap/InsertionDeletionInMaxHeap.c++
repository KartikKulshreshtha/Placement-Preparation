#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        // Here we checking the given value to its parent value
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                int temp = arr[parent];
                arr[parent] = arr[index];
                arr[index] = temp;
            }
            else{
                return ;
            }
        }
    }

    void deletionfromheap(){
        if(size == 0){
            cout << "No elements" <<endl;
            return;
        }
        // Step-1: Replace the root element with the last element
        arr[1] = arr[size];
        
        // Step-2: Remove the last element from the array
        size--;

        // Step-3: Take the root element to its right position
        int i = 1;
        while(i < size){
            int leftindex = 2 * i;   //Left child of i
            int rightindex = 2 * i+1;     //Right child of i
            if(leftindex < size && arr[i] < arr[leftindex]){
                int temp = arr[i];
                arr[i] = arr[leftindex];
                arr[leftindex] = temp;
                i = leftindex;
            }
            else if(rightindex < size && arr[i] < arr[rightindex]){
                int temp = arr[i];
                arr[i] = arr[rightindex];
                arr[rightindex] = temp;
                i = rightindex;
            }
            else{
                return ;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    Heap h;
    h.deletionfromheap();
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletionfromheap();
    h.print();

    return 0;
}