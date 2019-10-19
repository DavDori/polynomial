#include <iostream>
#include <vector>
typedef vector<float> poly;


class Polynomial {
  public:
    poly polynomial;
    Polynomial(poly p){ polynomial = p; order = p.size();}

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
};
