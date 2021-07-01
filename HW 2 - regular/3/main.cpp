/// Radoslav Velkov, fn 62528, group 1

#include <iostream>
using namespace std;

#include "Vector4D.cpp"

int main()
{
    Vector4D v1 = Vector4D(3.4, 2.7, -7.5, 12.3);
    v1[0]=4;
    v1[3]=8.1;
    cout<<"v1: "; v1.print();
    Vector4D v2(1, 3, 4, 2);
    cout<<"v2: "; v2.print();
    Vector4D vSum = v1 + v2;
    cout<<"vSum: "; vSum.print();
    Vector4D vSubtract = v1 - v2;
    cout<<"vSubtract: ";vSubtract.print();
    v1 += v2;
    cout<<"v1: "; v1.print();
    vSum -= vSubtract;
    cout<<"vSum: "; vSum.print();
    Vector4D vMultiply = v1 * v2;
    cout<<"vMultiply: "; vMultiply.print();
    Vector4D vDivide = v1 / v2;
    cout<<"vDivide: "; vDivide.print();
    v1 *= v2;
    cout<<"v1: "; v1.print();
    vSum /= vSubtract;
    cout<<"vSum: "; vSum.print();
    Vector4D v3(1, 7, 3, -4);
    double sc=3;
    Vector4D vScalar = v3 *= sc;
    cout<<"vScalar: "; vScalar.print();
    bool areEqual = v1==vDivide;
    cout<<"areEqual: "<<areEqual<<endl;
    areEqual = v1==vMultiply;
    cout<<"areEqual: "<<areEqual<<endl;
    bool areDifferent = v1!=vDivide;
    cout<<"areDifferent: "<<areDifferent<<endl;
    areDifferent = v1!=vMultiply;
    cout<<"areDifferent: "<<areDifferent<<endl<<endl;

    Vector4D vL(1, 3, 4.3, 10);
    Vector4D vB(1, 3, 6, 10);
    vL.print();
    vB.print();
    bool isLess = vL < vB;
    cout<<"isLess: "<<isLess<<endl;
    bool isLessOrEqual = vL <= vB;
    cout<<"isLessOrEqual: "<<isLessOrEqual<<endl;
    bool isMore = vL > vB;
    cout<<"isMore: "<<isMore<<endl;
    bool isMoreOrEqual = vL >= vB;
    cout<<"isMoreOrEqual: "<<isMoreOrEqual<<endl<<endl;

    Vector4D vN(1, -3, 6, 0);
    Vector4D vNn(3.14, 0, -2, 0);
    Vector4D vZ(0, 0, 0, 0);
    vN.print();
    vNn.print();
    vZ.print();
    bool areAllZeros = !vN;
    cout<<"areAllZeros: "<<areAllZeros<<endl;
    areAllZeros = !vNn;
    cout<<"areAllZeros: "<<areAllZeros<<endl;
    areAllZeros = !vZ;
    cout<<"areAllZeros: "<<areAllZeros<<endl;

    Vector4D vM1 = -vN;
    Vector4D vM2 = -vNn;
    Vector4D vM3 = -vZ;
    vM1.print();
    vM2.print();
    vM3.print();


    return 0;
}
