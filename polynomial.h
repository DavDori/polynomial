#include <vector>
#include <cstdio>
#include <string>

using namespace std;

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {
  friend Polynomial operator+ (const Polynomial&, const Polynomial&);
  friend Polynomial operator- (const Polynomial&, const Polynomial&);
  friend Polynomial operator* (const Polynomial&, const Polynomial&);
  public:
    vector<float> numeratorCoefficient;
    vector<float> denominatorCoefficient;

    int numeratorOrder;
    int denominatorOrder;

    Polynomial(vector<float>, vector<float>); //num,denum
    Polynomial(vector<float>);  //num only
    Polynomial(int, float); //size,value
    Polynomial(){};

    Polynomial& operator= (const Polynomial& r);
    void shift(int times);
    string print();

  private:
    void initPolynomial(vector<float>, vector<float>);
    string getStrVector(vector<float>);
    string getStrFirstAndSecond(vector<float>);
    void correctSize();
    vector<float> correctCoefficientSize(const vector<float>&);
    void multipyByConstant(float);
};

#endif
