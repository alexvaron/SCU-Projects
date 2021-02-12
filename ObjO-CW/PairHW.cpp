#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    Pair (T1 a, T2 b);//constructor
    T1 getFirst();//get first
    T2 getSecond();//getter for second
    void setFirst(T1 set);//setting first
private:
    T1 first_;
    T2 second_;
};
//member fuctions
template <typename T1, typename T2>
Pair<T1,T2>::Pair (T1 a, T2 b) {
    first_ = a;//setting first
    second_ = b;//setting second
}
template <typename T1, typename T2>
T1 Pair<T1,T2>::getFirst() {
    return first_;//return first
}
template <typename T1, typename T2>
T2 Pair<T1,T2>::getSecond() {
    return second_;//return second
}
template <typename T1, typename T2>
void Pair<T1,T2>::setFirst(T1 set) {
    first_ = set;//set first to new first (set)
}

int main() {
    Pair<char,char> p ('A','A');
    //p.getFirst() should return A
    cout<< "First is " << p.getFirst() <<endl;
    p.setFirst('Z');
    cout<< "The pair is: " << p.getFirst() << ", " << p.getSecond() <<endl;
    
    Pair <int, string> p2 (34, "Bill");
    cout<< "The pair is: " << p2.getFirst() << ", " << p2.getSecond() << endl;
    return 0;
}
