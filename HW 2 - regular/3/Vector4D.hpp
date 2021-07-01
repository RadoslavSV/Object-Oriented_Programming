/// Radoslav Velkov, fn 62528, group 1

#pragma once
#include <vector>

// Add all other required methods and fields of the class.

class Vector4D {
    double a = 0, b = 0, c = 0, d = 0;

public:
    Vector4D(double, double, double, double);
    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;

    double& operator[](int);

    Vector4D operator+(const Vector4D&) const;
    Vector4D& operator+=(const Vector4D&);

    Vector4D operator-(const Vector4D&) const;
    Vector4D& operator-=(const Vector4D&);

    Vector4D operator*(const Vector4D&) const;
    Vector4D operator*(double) const;
    Vector4D& operator*=(const Vector4D&);
    Vector4D& operator*=(double);

    Vector4D operator/(const Vector4D&) const;
    Vector4D& operator/=(const Vector4D&);

    bool operator==(const Vector4D&) const;
    bool operator!=(const Vector4D&) const;

    bool operator<(const Vector4D&) const;
    bool operator<=(const Vector4D&) const;
    bool operator>(const Vector4D&) const;
    bool operator>=(const Vector4D&) const;

    bool operator!() const;
    Vector4D operator-() const;

    //void print();

};



