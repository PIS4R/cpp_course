#include <iostream>
#include <cstring>

using namespace std;
class Poly{

    private:
        double* data = NULL;
        int size = 0;
    public:
        Poly(const Poly &p) {
            
            data = new double[p.size] {};
            size = p.size;
            std::memcpy(data, p.data, size * sizeof(double));
        }
         Poly(Poly &&p) {
            size = p.size;
            data = p.data;
            p.data = nullptr;
            p.size = 0;
        }
        
        Poly &operator=(const Poly &p) {
            if (this == &p)
            return *this;

            double* temp = new double[size]{};
            delete[] data;
            size = p.size;
            data = temp;
            std::memcpy(data, p.data, size * sizeof(double));
            return *this;
        }
        Poly &operator=(Poly &&p) {
            delete[] data;
            size = p.size;
            data = p.data;
            p.data = nullptr;
            p.size = 0;
            return *this;
        }
        double operator()(const double &value) const{
            //cout << "test" << endl;
            double result = 0;
            
            for (int i=1; i<this->size; i++){
                result = result * value + this->data[i];
            }
            return result;
        }

        Poly(double val = 0): data{new double[1]{val}}, size{1} {}
        ~Poly() { cout << "deleted" << endl; delete[] data; }

        int displ() { return this->size; }

        double &operator[](const int index) {
            if (this->size <= index){
                
                double* temp = new double[index+1] {};
                if (this->data != NULL){
                    for(int i = 0; i < this->size; i++){
                            temp[i] = this->data[i];
                        }
                }
                delete[] this->data;
                this->data = temp;
                
                this->size = index + 1;
            }
            
            return data[index];
        }
        double operator[](const int index) const {
            if (this->size < index){
                cout << "error" << endl;
            }
            
            return data[index];
        }
        friend std::ostream &operator<<(std::ostream &out, const Poly &p);
        friend Poly operator+(const Poly &, const Poly &);
        friend Poly operator-(const Poly &, const Poly &);
        friend Poly operator*(const Poly &a, const Poly &b);
        
};
inline std::ostream &operator<<(std::ostream &out, const Poly &p) {
     for(int i = p.size-1; i >= 0; i--){
        if(p.data[i] != 0 ){
            out << p.data[i] << "x^" << i << " ";
        }
       
    
    }
    out << endl;
    return out;
}

inline Poly operator+(const Poly &a, const Poly &b){
            Poly sum;

            for(int i = a.size-1; i >= 0; i--){
                sum[i] = a.data[i];
            }
            for(int i = b.size-1; i >= 0; i--){
                sum[i] += b.data[i];
            }

            
            return sum;
        }
inline Poly operator-(const Poly &a, const Poly &b){
    Poly substract;
    int sizeSum = 0;

    //cout << a << " - " << b << endl;
    if(a.size > b.size){
        sizeSum = a.size;
    }
    else{
        sizeSum = b.size;
    }
    for(int i = sizeSum-4; i >= 0; i--){
            //cout << this->values[i] << " + " << p1.values[i] << " = ";
            substract[i] = a.data[i] - b.data[i];
            //cout << sum[i] << endl;
        }
    return substract;
}
inline Poly operator*(const Poly &a, const Poly &b){
    Poly multi;
    multi[a.size + b.size - 2];

    for (int i = 0; i < a.size; ++i){

        for (int j = 0; j < b.size; ++j) {
        multi[i + j] += a[i] * b[j];
        }
    }
  return multi;

}