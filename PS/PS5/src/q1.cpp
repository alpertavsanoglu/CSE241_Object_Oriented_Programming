#include <iostream>
using namespace std;

double find(double left_hs, double right_h){
    return (left_hs > right_h) ? left_hs : right_h;
}
class Polynomial
{
public:
Polynomial(){
    coef=0;
    size=0;
}
Polynomial(const Polynomial &right_h) : size(right_h.size){
    int count;
    coef = new double[right_h.size];
    count=0;
    while(count < right_h.size){
        coef[count] = right_h.coef[count]; 
        count++;
    }
}
Polynomial(double coefficient[], int newSize) : size(newSize){
    int count;
    coef = new double[size];
    count=0;
    while(count<size){
        coef[count] = coefficient[count];
        count++;
    }
}
~Polynomial(){
    delete[] coef;
}
double &operator[](int degree){
    return coef[degree];
}
const double &operator[](int degree) const{
    return coef[degree];
}
const Polynomial &operator=(const Polynomial &right_h){
    int count;
    if(right_h.coef != coef){
        delete[] coef;
        coef = new double[right_h.size];
        count=0;
        while(count < right_h.size){
            coef[count] = right_h.coef[count];
            count++;
        }
        size = right_h.size;
    }
    else{
        return right_h;
    }

    return right_h;
}
int mySize(){
    return size;
}
friend double evaluate(const Polynomial &ploy, double arg);
    friend Polynomial operator+(const Polynomial &left_hs, const Polynomial &right_h){
    int count;
    const int size_add = find(left_hs.size, right_h.size);
    double *coef_add = new double[size_add];
    count=0;
    while(count < size_add){
        coef_add[count] = left_hs.coef[count] + right_h.coef[count];
        count++;
    }
    Polynomial q(coef_add, size_add);
    delete[] coef_add;
    return q;
}
friend Polynomial operator-(const Polynomial &left_hs, const Polynomial &right_h){
    int count;
    int size_subs = find(left_hs.size, right_h.size);             
    double *coef_subs = new double[size_subs];
    count=0;
    while(count < size_subs){
        coef_subs[count] = left_hs.coef[count] - right_h.coef[count];
        count++;
    }
    Polynomial q(coef_subs, size_subs);
    delete[] coef_subs;
    return q;
}
friend Polynomial operator*(const Polynomial &left_hs, const Polynomial &right_h){
    int count_1,count_2;
    int size_mult = left_hs.size + right_h.size-1;
    double *coef_mult = new double[size_mult];
    count_1=0;
    while(count_1 < size_mult){
        coef_mult[count_1] = 0;
        count_1++;
    }
    count_1=0;
    while(count_1 < left_hs.size){
        count_2 = 0;
        while(count_2 < right_h.size){
            coef_mult[count_1 + count_2] += left_hs[count_1] * right_h[count_2];
            count_2++;
        }
        count_1++;
    }
    return Polynomial(coef_mult, size_mult);
}
private:
    double *coef;
    int size;
};
double evaluate(const Polynomial& poly, double arg){
    int count=poly.size-1;
    double resu = 0;
    while(count>=0){
        resu = poly[count] + arg * resu;
        count--;
    }
    return resu;
}
int main()
{
Polynomial empty;
double one[] = {1};
Polynomial One(one, 1);
double quad[] = {3, 2, 1};
double cubic[] = {1, 2, 0, 3};
Polynomial q(quad, 3); // q is 3 + 2*x + x*x
Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
Polynomial p = q; // test copy constructor
Polynomial r;
r = q; //test operator=
r = c;
cout << "Polynomial q " << endl;
{for(int i = 0; i < 3; i++)
cout << "term with degree " << i
<< " has coefficient " << q[i] << endl;
}
cout << "Polynomial c " << endl;
{for(int i = 0; i < 4; i++)
cout << "term with degree " << i
<< " has coefficient " << c[i] << endl;
}
cout << "value of q(2) is " << evaluate(q, 2) << endl;
cout << "value of p(2) is " << evaluate(p, 2) << endl;
cout << "value of r(2) is " << evaluate(r, 2) << endl;
cout << "value of c(2) is " << evaluate(c, 2) << endl;
r = q + c;
cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;
r = q - c;
cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;
r = q * c;
cout << "size of q*c is " << r.mySize() << endl;
cout << "Polynomial r (= q*c) " << endl;
for(int i = 0; i < r.mySize(); i++)
cout << "term with degree " << i
<< " has coefficient " << r[i] << endl;
cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
return 0;
}
