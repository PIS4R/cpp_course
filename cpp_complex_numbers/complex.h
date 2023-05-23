#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex {
  private:
    double Real, Imag;

  public:
    //Complex() : Real(0), Imag(0){};

    //Complex(double co)
    //{
    //    Real = co;
    //    Imag = 0;
    //};

    Complex(double Real = 0, double Imag = 0)
    {
        this->Real = Real;
        this->Imag = Imag;
    };

    Complex& operator=(const Complex& s)
    {
        Real = s.Real;
        Imag = s.Imag;
        return *this;
    };

    Complex operator-() const
    {
        return Complex(-Real, -Imag);
    };

    Complex& operator=(double co)
    {
        Real = co;
        Imag = 0;
        return *this;
    };

    Complex operator+(const Complex& co) const
    {
        Complex n;
        n.Real = this->Real + co.Real;
        n.Imag = this->Imag + co.Imag;
        return n;
    };
   
    
	double abs()
    {
		double sum = pow(this->Real, 2) + pow(this->Imag, 2);
		double modulus = sqrt(sum);
		return modulus;
    };
    
    double phase() const
    {
		double phase;
		if (this->Real > 0) {
			phase = atan(this->Imag/this->Real);
		}
		else if (this->Real < 0){
			phase = atan(this->Imag/this->Real) + M_PI;
			
		}
		else{
			if (this->Imag > 0){
				phase = M_PI/2;
			}
			else if (this->Imag < 0){
				phase = (-M_PI/2);
			}
			else {
				cout << "For z = 0 the phase is undefined" << endl;
				return 0;
			}
		}
		return phase;
    };
    Complex conj() const
    {
		Complex n;
		n.Real = this->Real;
        n.Imag = this->Imag * (-1);
        return n;
    };

    Complex& operator-=(Complex co)
    {
        Real -= co.Real;
        Imag -= co.Imag;
        return *this;
    };
    
    Complex& operator/=(Complex co)
    {
        Real /= co.Real;
        Imag /= co.Imag;
        return *this;
    };
    
    friend Complex operator-(Complex, Complex);
    friend ostream& operator<<(ostream& s, const Complex& c)
    {
        s << "(" << c.Real << "," << c.Imag << ")";
        return s;
    };
    
     friend Complex operator/(Complex, Complex);
};


inline Complex operator/(Complex co1, const Complex co2)
    {
        Complex n;
        n.Real = ((co1.Real * co2.Real) + (co1.Imag * co2.Imag) / ((co2.Real * co2.Real) + (co2.Imag * co2.Imag)));
        n.Imag = ((co1.Imag * co2.Real) - (co1.Real * co2.Imag) / ((co2.Real * co2.Real) + (co2.Imag * co2.Imag)));
        return n;
    };
    
    
inline Complex operator-(Complex s1, Complex s2)
{
    Complex n(s1);
    return n -= s2;
}

#endif /* __Complex_H__ */
