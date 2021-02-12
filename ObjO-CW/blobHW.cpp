//alex varon
//1/29/18
//hwk3-1

#include<stdlib.h>
#include<time.h>
#include <iostream>

class Blob {
    public:
        int & operator [] (int index);
        void append(int a);
        int getSize();
    private:
        int array [100];
        int size;
};
// MEMBER FUNCTIONS
int &  Blob::operator [] (int index) {//overloading []
    return array [index];
}

void Blob::append(int a) {//apppend fuction to add to array
    static int s = 0;
    array[s] = a;
    s++;
    size =s;
}

int Blob::getSize() {//getter function for size
    return size;
}

//NON MEMBER FUNCTIONS
std::ostream& operator<<(std::ostream& out, Blob b) {//overloading printing
    out<< "{";
    for(int i = 0; i< b.getSize() - 1; i++) {
        out << b[i] << " ";
    }
    out << b[b.getSize()-1] << "}";
    return out;
}

//main
int main() {
    const int kNumElements = 10;
    Blob a;
    for(int i = 0; i < kNumElements;++i) {
        int r = rand()%100;
        a.append(r);
    }
    std::cout << a << std::endl;
    for (int i = 0; i < kNumElements;++i) {
        a[i] = 2 * a[i];
    }
    std::cout << a << std::endl;
    a.append(111);
    a.append(222);  
    std::cout << a << std::endl;
    return 0;
}