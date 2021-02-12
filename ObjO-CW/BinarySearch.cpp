#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int elem_to_find);

int binarySearch(int arr[], int len, int elem_to_find);

//main function to test functions
int main() {
    int arr[] = {1, 3, 10, 20, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = 10;
    if(binarySearch(arr, n, j) == -1) {
        cout << "Element is not in arry" << endl;
    } else {
        cout << "Element is in array at index: " << binarySearch(arr, n, j) << endl;
    }
    return 0;
}

int binarySearch(int arr[], int left, int right, int elem_to_find) {
    int middle = (right+left)/ 2; //middle index
    if(arr[middle] == elem_to_find) {
        return middle;
    } else if (arr[middle] > elem_to_find) {
        return binarySearch(arr, left, middle - 1, elem_to_find);
    } else {
        return binarySearch(arr, middle + 1, right, elem_to_find);
    }
    return -1;
}

//overloaded binary search function

int binarySearch(int arr[], int len, int elem_to_find) {
    return binarySearch(arr, 0, len - 1, elem_to_find);
}