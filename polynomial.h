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
  friend Polynomial operator* (const Polynomial&, float);
  friend Polynomial sumGroup(const Polynomial [], int sizeOfGroup);

  public:
    vector<float> polyCoefficients;
    int order;

    Polynomial(vector<float> coefficients);

    Polynomial& operator= (const Polynomial& r);

    void shift(int times);
    void multipyByConstant(float value);
    void correctSize();
    void print();

  private:
    void printFirstAndSecond();
};

#endif
