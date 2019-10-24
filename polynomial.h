#include <vector>
using namespace std;

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {
  friend Polynomial operator+ (const Polynomial&, const Polynomial&);
  friend Polynomial operator- (const Polynomial&, const Polynomial&);
  friend Polynomial pickLarger(const Polynomial&, const Polynomial&);
  friend Polynomial pickSmaller(const Polynomial&, const Polynomial&);
  friend Polynomial sumLargerWithSmaller(const Polynomial&, const Polynomial&);

  friend Polynomial operator* (const Polynomial&, const Polynomial&);
  friend Polynomial sumGroup(const Polynomial*, int sizeOfGroup);

  public:
    vector<float> polyCoefficients;
    int order;

    Polynomial(vector<float> coefficients);
    Polynomial(){};
    Polynomial& operator= (const Polynomial& r);
    void shift(int times);
    void print();

  private:
    void printFirstAndSecond();
    void correctSize();
    void multipyByConstant(float value);
};

#endif
