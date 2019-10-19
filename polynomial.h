#include <iostream>
#include <vector>



class Polynomial {
  public:
    vector<float> polyCoefficients;
    Polynomial(vector<float> coefficients){ polyCoefficients = coefficients; order = p.size();}

    Polynomial operator=(const Polynomial&);
    Polynomial operator+(const Polynomial&, const Polynomial&);
    Polynomial operator-(const Polynomial&, const Polynomial&);

    void shift(int times);
    void multipyByConstant(float value);
    void correctSize();
    void print();
    int getOrder();

  private:
    int order;
    void printFirstAndSecond();
    Polynomial pickLarger(const Polynomial&, const Polynomial&);
    Polynomial pickSmaller(const Polynomial&, const Polynomial&);
};
