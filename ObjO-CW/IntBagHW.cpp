//Alex Varon
//1/7/18
//intbag.cpp
//hwk4
#include <iostream>
#include "intbag.h"
using namespace std;

IntBag::IntBag(){ //constructor
    size_ = 0; //intializing
    array_ = new int [size_];
}

IntBag::IntBag(const IntBag& a){//copy constructor
    size_ = a.size_;//setting size
    array_ = new int [size_]; //making new array
    for (int i = 0; i < size_; ++i){
        array_[i] = a.array_[i]; 
    }
}

IntBag::~IntBag(){ //destructor
    delete [] array_;//deleting array
}

IntBag& IntBag::operator=(const IntBag& a){ //assignment operator
    int *arr = new int [size_]; //new array
    for (int i = 0; i < size_; ++i){//setting it equal
        arr[i] = a.array_[i]; 
    }
    delete [] array_; //deleting array
    array_ = arr; //setting area
    size_ = a.size_; //setting size
}
    
int IntBag::operator[](int index){ //get array item
    int *a; 
    if (index <= size_)
        a = &array_[index];//getting item
    else 
        cout<<"Size is too big"<<endl;//error
    return *a;
}

void IntBag::add(const int item){ //add item to the end of the array
    int size; 
    size = size_ +1;//adding one to size
    int* arr = new int [size];
    for (int i = 0; i < size_; ++i){
        arr[i] = array_[i]; 
    }
    arr[size-1] = item; //adding item
    delete [] array_; //deleting array
    array_ = arr; 
    size_ = size; 
}
    
int IntBag::getSize() const{ //get size of array
    return size_; //size
}

void IntBag::setSize(const int newsize){ //set size of array
    size_ = newsize; //setting size
}

void IntBag::clear(){ //clear array
    size_ = 0; 
    delete [] array_; 
    array_ = new int [size_];
}

void IntBag::delete_(int pos){ //delete array item
    int size;
    size = size_ -1; 
    int* arr = new int [size]; 
    int i;
    for (i = 0; i < pos; ++i){//setting new array up to size
            arr[i] = array_[i];
    }
    i=pos;
    for (int j = pos+1; j<size; j++) {
        arr[i] = array_[j];//setting rest of array
        i++;
    }
    arr[size-1]=array_[size_-1];
    delete [] array_; 
    array_ = arr; 
    size_ = size; 
}

void IntBag::fill(const int filler){
    for (int i = 0; i < size_; ++i)
        array_[i] = filler; 
}
