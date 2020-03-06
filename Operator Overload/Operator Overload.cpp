#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;
class Complex
{
public:
    int a, b;
};
Complex  operator + (Complex& x, Complex& y)
{
    Complex z;
    z.a = (x.a + y.a);
    z.b = (x.b + y.b);
    return z;
};

ostream& operator << (ostream& out, Complex z)
{
    out << z.a << "+"<<z.b<<"i";
    return out;
};

int main()
{
    Complex x, y;
    int a1, b1;
    char ch;
    string h;
    cin >> h;
    stringstream s1(h);
    s1 >> a1 >> ch >> b1 >> ch;
    x.a = a1;
    x.b = b1;
    cin >> h;
    stringstream s2(h);
    s2 >> a1 >> ch >> b1 >> ch;
    y.a = a1;
    y.b = b1;
    Complex z = x + y;
    cout << z;
    return 0;
}
