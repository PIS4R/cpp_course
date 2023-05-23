#include <iostream>
using namespace std;
#include "complex.h"

int main()
{
    Complex a(0.0, 15), b(0, 13), c;
    c = 10;
    cout << c << endl;
    c = -a;
    cout << c << endl;
    c = a + b;
    c = c - Complex(10);
    cout << c << endl;
    c = 10 - a;
    (c -= b) -= 10;
    cout <<  c << endl;
    
    Complex s(2, 3), p(4, 6);
    cout << p / s << endl;
    Complex f(8, 27), g(4, 4);
    f /= s;
   
    
    cout << f << endl;
    cout << "modulus = " << s.abs() << endl;
    cout << "phase = " << s.phase() << endl;
    cout << "conj = " << s.conj() << endl;
    cout << "2 - a = " << 2 - a << endl;
    cout << "2 / g = " << 2 / g << endl;
    
    const Complex ff(4,5);
    cout << ff.conj() << endl;
}
