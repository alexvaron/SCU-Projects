#include "bintree.h"
#include <iostream>
using namespace std;

void heapify(int * arr, int size, int i) {
    int largest = i;  
    int left = 2*i + 1;  
    int right = 2*i + 2;  
    // If left child is larger
    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }
    // If right child is larger than largest
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heap (int * arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for (int i=size-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    //          15
    //         /  \
    //        10   18
    //       / \   / \
    //      5  12 13 20 
    int arr [7] = {15,10,18,5,12,13,20};
    cout<<"ORIGINAL:"<<endl;
    cout<<"           " << arr[0] << endl;
    cout<<"         /   | "<<endl;
    cout<<"        " << arr[1] << "   " << arr[2] << endl;
    cout<<"       / |   / | "<<endl;
    cout<<"      "<<arr[3]<<"  "<<arr[4]<<" "<<arr[5]<<" "<<arr[6]<<endl;
    heap(arr, 7);
    cout<<"HEAPIFIED:"<<endl;
    cout<<"           " << arr[0] << endl;
    cout<<"         /   | "<<endl;
    cout<<"        " << arr[1] << "   " << arr[2] << endl;
    cout<<"       / |   / | "<<endl;
    cout<<"      "<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<" "<<arr[6]<<endl;
}
