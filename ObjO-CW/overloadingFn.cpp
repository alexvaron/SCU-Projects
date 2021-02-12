#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <string>

template <typename T>
class Blob {
    public:
        Blob (int s);
        T & operator [] (int index);
        void append(T a);
        int getSize();
    private:
        T array [100];
        int size;
};
// MEMBER FUNCTIONS
template <typename T>
Blob <T>::Blob (int s) {
    size = s;
}
template <typename T>
T &  Blob<T>::operator [] (int index) {//overloading []
    return array [index];
}
template <typename T>
void Blob<T>::append(T a) {//apppend fuction to add to array
    static int s = 0;
    array[s] = a;
    s++;
    size =s;
}
template <typename T>
int Blob<T>::getSize() {//getter function for size
    return size;
}

//NON MEMBER FUNCTIONS
template <typename T>
std::ostream& operator<<(std::ostream& out, Blob<T> b) {//overloading printing
    out<< "{";
    for(int i = 0; i< b.getSize() - 1; i++) {
        out << b[i] << " ";
    }
    out << b[b.getSize()-1] << "}";
    return out;
}

//main
int main() {// for storing integers    
    Blob <int> b_int(30);
    for (int i = 0; i < 30; ++i) {
        int r = rand()%100;
        b_int.append(r);
    }
    std::cout<<b_int<<std::endl;
    
    // for storing strings    
    Blob <std::string> b_str(10);// can hold at max 10 strings    
    b_str.append("max");    
    b_str.append("min");    
    b_str.append("sum");
    b_str.append("prod");
    std::cout<< b_str << std::endl;
    return 0;
}