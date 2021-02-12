//Alex Varon
//1/22/18
//HW2

#include <iostream>
using namespace std;

class Complex {
  public:
    //define costructors 
    Complex(const double real, const double imag);
    Complex();
    //getter
    double get_real() const;
    double get_imag() const;
    void operator+=(Complex rhs);
    void operator-=(Complex rhs);
    void operator*=(Complex rhs);
    void operator/=(Complex rhs);
    void operator+(){};
    void operator-();

  private:
    double real_;
    double imag_;
    
};

//addition
Complex operator+(Complex lhs, Complex rhs) {
    return Complex(lhs.get_real() + rhs.get_real(),lhs.get_imag() + rhs.get_imag());
}

//multiplication
Complex operator*(Complex lhs, Complex rhs) {
    return Complex(
        lhs.get_real() * rhs.get_real() - lhs.get_imag() * rhs.get_imag(),
        lhs.get_imag() * rhs.get_real() + lhs.get_real() * rhs.get_imag());
}

//print
std::ostream& operator<<(std::ostream& os, Complex z){
    os << z.get_real() << " + " << z.get_imag() << "i";
    return os;
}

//subtraction
Complex operator-(Complex lhs, Complex rhs){
    return Complex( lhs.get_real() - rhs.get_real(), lhs.get_imag() - rhs.get_imag() );
}

//division
Complex operator/(Complex lhs, Complex rhs){
    double m;
    m = rhs.get_real()*rhs.get_real() + rhs.get_imag()*rhs.get_imag();
    Complex d(((lhs.get_real() * rhs.get_real() + lhs.get_imag() * rhs.get_imag())/m),
        (lhs.get_imag() * rhs.get_real() + lhs.get_real() * rhs.get_imag() * -1)/m);
    return d;
}

//equal
bool operator==(Complex lhs, Complex rhs){
    if (lhs.get_real() == rhs.get_real() && lhs.get_imag() == rhs.get_imag())
        return true;
    else
        return false;
}

//not equal
bool operator!=(Complex lhs, Complex rhs){
    if (lhs.get_real() == rhs.get_real() && lhs.get_imag() == rhs.get_imag())
        return false;
    else 
        return true;
}

int main() {
    Complex z(3,2);
    Complex w(2,2);
    cout << "z = " << z << endl;
    cout << "w = " << w << endl;
    cout << "z + w = " << z+w << endl;
    cout << "z * w = " << z*w << endl;
    cout << "z - w = " << z-w << endl;
    cout << "z / w = " << z/w << endl;
    cout << "z == w " << (z == w) << endl;
    cout << "z != w " << (z != w) << endl;
    cout << "z + w == w + z " << (z+w == w+z) << endl;
    cout << "z + w != w + z " << (z+w != w+z) << endl;
    
    Complex i(0,1);
    cout << "i = " << i << endl << "i^2 = " << i*i << endl;
    
    return 0;   
}

//constructor
Complex::Complex(const double real, const double imag) {
    real_ = real;
    imag_ = imag;
}

Complex::Complex() {
    real_ = 0;
    imag_ = 0;
}

//getter
double Complex::get_real() const { return real_; }

double Complex::get_imag() const { return imag_; }


//addition
void Complex::operator+=(Complex rhs){
    double r, i;
    r = real_ + rhs.get_real();
    i = imag_ + rhs.get_imag();
    real_= r;
    imag_= i;
}

//subtraction
void Complex::operator-=(Complex rhs){
    double r, i;
    r = real_ - rhs.get_real();
    i = imag_ - rhs.get_imag();
    real_= r;
    imag_= i;
}

//multiply
void Complex::operator*=(Complex rhs){
    double r, i;
    r = (real_ * rhs.get_real() - imag_ * rhs.get_imag()),
    i = (imag_ * rhs.get_real() + real_ * rhs.get_imag());
    real_= r;
    imag_= i;
}

//divid
void Complex::operator/=(Complex rhs){
    double d,r,i;
    d = rhs.get_real()*rhs.get_real() + rhs.get_imag()*rhs.get_imag();
    r = ((real_ * rhs.get_real() + imag_ * rhs.get_imag())/d);
    i = ((imag_ * rhs.get_real() + real_ * rhs.get_imag() * -1)/d);
    real_= r;
    imag_= i;
}

//subtraction
void Complex::operator-(){
    imag_ = 0;
    real_ = 0;
}
