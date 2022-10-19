#include <iostream>
using namespace std;

class Complex114{
    double real;
    double imag;
public:
    Complex114() {real = imag = 0.;}
    Complex114(double re, double im) {real = re; imag = im;}
    void showme();
    Complex114 operator + (Complex114& c);
    Complex114 operator - (Complex114& c);
    Complex114 operator * (Complex114& c);
    Complex114 operator / (Complex114& c);
};

Complex114 Complex114::operator + (Complex114& c){
    Complex114 result(real + c.real, imag + c.imag);
    return result;
}
Complex114 Complex114:: operator - (Complex114& c){
    Complex114 result(real - c.real, imag - c.imag);
    return result;
}
Complex114 Complex114:: operator * (Complex114& c){
    Complex114 result(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    return result;
}
Complex114 Complex114:: operator / (Complex114& c){
    double mo = c.real * c.real + c.imag * c.imag;
    Complex114 result(real/mo, imag/mo);
    Complex114 conju(c.real, - c.imag);
    return result.operator * (conju);
}

void Complex114::showme(){
    cout << "( " << real << ", " << imag << "i ) \n\n";
}
int main(){
    Complex114 result;
    Complex114 c1(9, 7);
    Complex114 c2(7, 1);
    cout << "c1 = "; c1.showme();
    cout << "c2 = "; c2.showme();
    result = c1 + c2;
    cout << "c1 + c2 = "; result.showme();
    result = c1 - c2;
    cout << "c1 - c2 = "; result.showme();
    result = c1 * c2;
    cout << "c1 * c2 = "; result.showme();
    result = c1 / c2;
    cout << "c1 / c2 = "; result.showme();
}