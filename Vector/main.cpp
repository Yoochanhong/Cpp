#include <iostream>
#include <math.h>

using namespace std;

class CVector {
public:
    double _x;
    double _y;
    double _z;

    CVector(double x, double y, double z);

    void print() const;

    CVector operator+(CVector &vector);

    CVector operator-(CVector &vector);

    CVector operator+();

    CVector operator-();

    double operator*(CVector &vector);

    CVector operator*(double num);

    CVector operator%(CVector &vector);

    friend CVector operator*(double num, CVector &vector);

    CVector operator/(double num);

    CVector operator/(CVector &vector);

    CVector operator++();

    CVector operator--();

    CVector operator++(int num);

    CVector operator--(int num);
};

CVector::CVector(double x, double y, double z)
        : _x(x), _y(y), _z(z) {
}

void CVector::print() const {
    std::cout << "[ x : " << _x << ", y : " << _y << ", z : " << _z << " ]" << std::endl;
}


CVector CVector::operator+() {
    return *this;
}

CVector CVector::operator-(CVector &vector) {
    CVector result = CVector(this->_x - vector._x, this->_y - vector._y, this->_z - vector._z);
    return result;
}

CVector CVector::operator+(CVector &vector) {
    CVector result = CVector(this->_x + vector._x, this->_y + vector._y, this->_z + vector._z);
    return result;
}


CVector CVector::operator-() {
    return CVector(-_x, -_y, -_z);
}

CVector CVector::operator*(double num) {
    CVector result = CVector(this->_x * num, this->_y * num, this->_z * num);
    return result;
}

//CVector CVector::operator*(double num, CVector &vector) {
//    return vector * num;
//}

CVector CVector::operator--(int num) {
    CVector result = *this;
    --*this;
    return result;
}

double CVector::operator*(CVector &vector) {
    return _x * vector._x + _y * vector._y + _z * vector._z;
}


CVector CVector::operator/(CVector &vector) {
    CVector result = CVector(this->_x / vector._x, this->_y / vector._y, this->_z / vector._z);
    return result;
}

CVector CVector::operator++() {
    double mag = sqrt(_x * _x + _y * _y + _z * _z);
    CVector unit(_x / mag, _y / mag, _z / mag);
    *this = *this + unit;
    return *this;
}

CVector CVector::operator++(int num) {
    CVector result = *this;
    ++*this;
    return result;
}

CVector CVector::operator--() {
    double mag = sqrt(_x * _x + _y * _y + _z * _z);
    CVector unit(_x / mag, _y / mag, _z / mag);
    *this = *this - unit;
    return *this;
}


CVector CVector::operator/(double num) {
    CVector result = CVector(this->_x / num, this->_y / num, this->_z / num);
    return result;
}

int main() {
    CVector v0{0, 1, 2};
    CVector v1{1, 2, 3};

    cout << "v0 : ";
    v0.print();
    cout << "v1 : ";
    v1.print();

    CVector v2 = v0 + v1;   // CVector v2 = v0.operator+(v1);
    cout << "v2 : ";
    v2.print();
    v0.print();
    v1.print();

    CVector v3 = -v1;       // CVector v3 = v1.operator-();
    cout << "v3 : ";
    v3.print();

    CVector v4 = +v0;             // CVector v4 = v0.operator+();
    cout << "v4 : ";
    v4.print();

    CVector v5 = -v0;             // CVector v5 = v0.operator-();
    cout << "v5 : ";
    v5.print();

    CVector v6 = v0 + v1;         // CVector v6 = v0.operator+(v1);
    cout << "v6 : ";
    v6.print();

    CVector v7 = v0 - v1;         // CVector v7 = v0.operator-(v1);
    cout << "v7 : ";
    v7.print();

    double res = v0 * v1;         // res = v0.operator*(v1);
    //v0._x * v1._x + v0._y * v1._y + v0._z * v1._z;
    cout << "res : " << res << endl;

    CVector v9 = v0 * 3.0;          // CVector v9 = v0.operator*(3.0);
    cout << "v9 : ";
    v9.print();

    CVector v10 = v0 / 3.0;         // CVector v10 = v0.operator/(3.0);
    cout << "v10 : ";
    v10.print();

    v10 = { 1.0, 2.0, 3.0 };
    CVector v11 = ++v10;            // CVector v11 = v10.operator++();
    cout << "v10 : ";
    v10.print();
    cout << "v11 : ";
    v11.print();     //

    v10 = { 1.0, 2.0, 3.0 };
    CVector v12 = v10++;            // CVector v12 = v10.operator++(int);
    cout << "v10 : ";
    v10.print();
    cout << "v12 : ";
    v12.print();

    //CVector v13 = --v10;            // CVector v13 = v10.operator--();
    //cout << "v10 : ";
    //v10.print();
    //cout << "v13 : ";
    //v13.print();

    //CVector v14 = v10--;            // CVector v14 = v10.operator--(int);
    //cout << "v10 : ";
    //v10.print();
    //cout << "v14 : ";
    //v14.print();


    return 0;
}