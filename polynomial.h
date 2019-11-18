#include <vector>
#include <cstdio>
#include <string>

using namespace std;

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {
  friend Polynomial operator+ (const Polynomial&, const Polynomial&);
  friend Polynomial operator- (const Polynomial&, const Polynomial&);
  friend Polynomial sumNoDenominator(const Polynomial&, const Polynomial&);
  friend Polynomial pickLarger(const Polynomial&, const Polynomial&);
  friend Polynomial pickSmaller(const Polynomial&, const Polynomial&);
  friend Polynomial sumLargerWithSmaller(const Polynomial&, const Polynomial&);

  friend Polynomial operator* (const Polynomial&, const Polynomial&);
  friend Polynomial sumGroup(const Polynomial*, int sizeOfGroup);

  public:
    vector<float> numeratorCoefficient;
    vector<float> denominatorCoefficient;

    int numeratorOrder;
    int denominatorOrder;

    Polynomial(vector<float>);
    Polynomial(vector<float>, vector<float>);
    Polynomial(){};

    Polynomial& operator= (const Polynomial& r);
    void shift(int times);
    string print();

  private:
    string getStrVector(vector<float>);
    string getStrFirstAndSecond(vector<float>);
    void correctSize();
    vector<float> correctCoefficientSize(const vector<float>&);
    void multipyByConstant(float value);
};

#endif
