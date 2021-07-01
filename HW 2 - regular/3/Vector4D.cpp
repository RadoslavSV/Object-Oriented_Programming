/// Radoslav Velkov, fn 62528, group 1

#include "Vector4D.hpp"

Vector4D::Vector4D(double a, double b, double c, double d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

double Vector4D::getA() const
{
    return this->a;
}

double Vector4D::getB() const
{
    return this->b;
}

double Vector4D::getC() const
{
    return this->c;
}

double Vector4D::getD() const
{
    return this->d;
}

double& Vector4D::operator[](int n)
{
    if(n==0) return this->a;
    if(n==1) return this->b;
    if(n==2) return this->c;
    if(n==3) return this->d;
}

Vector4D Vector4D::operator+(const Vector4D& v) const
{
    double newA=getA();
    double newB=getB();
    double newC=getC();
    double newD=getD();
    newA += v.getA();
    newB += v.getB();
    newC += v.getC();
    newD += v.getD();
    Vector4D newV(newA, newB, newC, newD);

    return newV;
}

Vector4D& Vector4D::operator+=(const Vector4D& v)
{
    double newA=getA();
    double newB=getB();
    double newC=getC();
    double newD=getD();
    newA += v.getA();
    newB += v.getB();
    newC += v.getC();
    newD += v.getD();

    this->a=newA;
    this->b=newB;
    this->c=newC;
    this->d=newD;

    return *this;
}

Vector4D Vector4D::operator-(const Vector4D& v) const
{
    double newA=getA();
    double newB=getB();
    double newC=getC();
    double newD=getD();
    newA -= v.getA();
    newB -= v.getB();
    newC -= v.getC();
    newD -= v.getD();
    Vector4D newV(newA, newB, newC, newD);

    return newV;
}

Vector4D& Vector4D::operator-=(const Vector4D& v)
{
    double newA=getA();
    double newB=getB();
    double newC=getC();
    double newD=getD();
    newA -= v.getA();
    newB -= v.getB();
    newC -= v.getC();
    newD -= v.getD();

    this->a=newA;
    this->b=newB;
    this->c=newC;
    this->d=newD;

    return *this;
}

Vector4D Vector4D::operator*(const Vector4D& v) const
{
    double newA=getA();
    double newB=getB();
    double newC=getC();
    double newD=getD();
    newA *= v.getA();
    newB *= v.getB();
    newC *= v.getC();
    newD *= v.getD();
    Vector4D newV(newA, newB, newC, newD);

    return newV;
}

Vector4D Vector4D::operator*(double s) const
{
    double newA=getA();
    double newB=getB();
    double newC=getC();
    double newD=getD();
    newA *= s;
    newB *= s;
    newC *= s;
    newD *= s;
    Vector4D newV(newA, newB, newC, newD);

    return newV;
}

Vector4D& Vector4D::operator*=(const Vector4D& v)
{
    double newA=getA();
    double newB=getB();
    double newC=getC();
    double newD=getD();
    newA *= v.getA();
    newB *= v.getB();
    newC *= v.getC();
    newD *= v.getD();

    this->a=newA;
    this->b=newB;
    this->c=newC;
    this->d=newD;

    return *this;
}

Vector4D& Vector4D::operator*=(double s)
{
    double newA=getA();
    double newB=getB();
    double newC=getC();
    double newD=getD();
    newA *= s;
    newB *= s;
    newC *= s;
    newD *= s;

    this->a=newA;
    this->b=newB;
    this->c=newC;
    this->d=newD;

    return *this;
}

Vector4D Vector4D::operator/(const Vector4D& v) const
{
    double newA=getA();
    double newB=getB();
    double newC=getC();
    double newD=getD();
    newA /= v.getA();
    newB /= v.getB();
    newC /= v.getC();
    newD /= v.getD();
    Vector4D newV(newA, newB, newC, newD);

    return newV;
}

Vector4D& Vector4D::operator/=(const Vector4D& v)
{
    double newA=getA();
    double newB=getB();
    double newC=getC();
    double newD=getD();
    newA /= v.getA();
    newB /= v.getB();
    newC /= v.getC();
    newD /= v.getD();

    this->a=newA;
    this->b=newB;
    this->c=newC;
    this->d=newD;

    return *this;
}

bool Vector4D::operator==(const Vector4D& v) const
{
    if( this->a==v.getA() && this->b==v.getB() &&
        this->c==v.getC() && this->d==v.getD() ) return true;
    else return false;
}

bool Vector4D::operator!=(const Vector4D& v) const
{
    if( this->a!=v.getA() || this->b!=v.getB() ||
        this->c!=v.getC() || this->d!=v.getD() ) return true;
    else return false;
}

bool Vector4D::operator<(const Vector4D& v) const
{
    if( this->a>v.getA() ) return false;
    if( this->a<v.getA() ) return true;
    if( this->b>v.getB() ) return false;
    if( this->b<v.getB() ) return true;
    if( this->c>v.getC() ) return false;
    if( this->c<v.getC() ) return true;
    if( this->d>v.getD() ) return false;
    if( this->d<v.getD() ) return true;
    if( this->a==v.getA() && this->b==v.getB() &&
        this->c==v.getC() && this->d==v.getD() ) return false;
    return true;
}

bool Vector4D::operator<=(const Vector4D& v) const
{
    if( this->a>v.getA() ) return false;
    if( this->b>v.getB() ) return false;
    if( this->c>v.getC() ) return false;
    if( this->d>v.getD() ) return false;
    if( this->a==v.getA() && this->b==v.getB() &&
        this->c==v.getC() && this->d==v.getD() ) return true;
    return true;
}

bool Vector4D::operator>(const Vector4D& v) const
{
    if( this->a<v.getA() ) return false;
    if( this->a>v.getA() ) return true;
    if( this->b<v.getB() ) return false;
    if( this->b>v.getB() ) return true;
    if( this->c<v.getC() ) return false;
    if( this->c>v.getC() ) return true;
    if( this->d<v.getD() ) return false;
    if( this->d>v.getD() ) return true;
    if( this->a==v.getA() && this->b==v.getB() &&
        this->c==v.getC() && this->d==v.getD() ) return false;
    return true;
}

bool Vector4D::operator>=(const Vector4D& v) const
{
    if( this->a<v.getA() ) return false;
    if( this->b<v.getB() ) return false;
    if( this->c<v.getC() ) return false;
    if( this->d<v.getD() ) return false;
    if( this->a==v.getA() && this->b==v.getB() &&
        this->c==v.getC() && this->d==v.getD() ) return true;
    return true;
}

bool Vector4D::operator!() const
{
    if( this->a==0 && this->b==0 && this->c==0 && this->d==0 ) return true;
    return false;
}

Vector4D Vector4D::operator-() const
{
    double newA=-a, newB=-b, newC=-c, newD=-d;
    if(a==0) newA=0; if(b==0) newB=0; if(c==0) newC=0; if(d==0) newD=0;
    Vector4D newV(newA, newB, newC, newD);
    return newV;
}

//void Vector4D::print()
//{
//    std::cout<<a<<", "<<b<<", "<<c<<", "<<d<<std::endl;
//}












