#ifndef INTBAG_H
#define INTBAG_H

#include <iostream>

class IntBag {
  const static int CAPACITY = 128; //initial size of array memory (elements)
  const static int MULT = 2; //multiplier (enlarge array memory MULT times)
  public:
    IntBag(); //constructor
    IntBag(const IntBag&); //copy constructor
    ~IntBag(); //destructor
    IntBag & operator = (const IntBag&); //assignment operator
    int operator [] (int index); //get array item
    void add(const int item); //add item to end of array
    int getSize() const; //get size of array (elements)
    void setSize(int newSize); //set size of array (elements)
    void clear(); //clear array
    void delete_(int pos); //delete array item
    void fill(const int filler); 
  private:
    int* array_; //pointer for array's memory
    int size_; //size of array (elements)
};

#endif