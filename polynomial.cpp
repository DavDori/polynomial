#include "polyCoefficients.h"

Polynomial::Polynomial(poly coefficients)
{
  polyCoefficients = coefficients;
  order = p.size();
}

/*
OVERLOADING OPERATORS
*/

Polynomial::operator=(const Polynomial& r)
{
  polyCoefficients =  r.polyCoefficients;
  order = r.order;
}

Polynomial::operator+(const Polynomial& a, const Polynomial& b)
{
  a.correctSize();
  b.correctSize();
  Polynomial larger = pickLarger(a,b);
  Polynomial smaller = pickSmaller(a,b);
  Polynomial result = sumLargerWithSmaller(larger, smaller);
  return result;
}

Polynomial::operator-(const Polynomial& a, const Polynomial& b)
{

}

void Polynomial::shift(int times)
{
  for(int i = 0; i < times; i++)
  {
    polyCoefficients.insert(polyCoefficients.begin(), 0);
  }
}

void Polynomial::multipyByConstant(float value)
{
  for(int i = 0; i < order; i++)
  {
    polyCoefficients[i] = polyCoefficients[i] * value;
  }
}

void Polynomial::correctSize()
{
  while(polyCoefficients[order-1] == 0)
  {
      polyCoefficients.pop_back();
      order--;
  }
}

void Polynomial::print()
{
  printFirstAndSecond();
  for(int i = 2; i < order; i++)
  {
    cout << " + " << polyCoefficients[i] << "x^" << i;
  }
  cout << endl;
}

void Polynomial::printFirstAndSecond()
{
  if(order >= 1)
    cout << polyCoefficients[0];
  if(order >= 2)
    cout << " + " << polyCoefficients[1] << 'x';
}

int Polynomial::getOrder()
{
  return order;
}

Polynomial Polynomial::pickLarger(Polynomial a, Polynomial b)
{
  Polynomial result;
  a.getOrder() >= b.getOrder() ? result = a : result = b;
  return result;
}

Polynomial Polynomial::pickSmaller(Polynomial a, Polynomial b)
{
  Polynomial result;
  a.getOrder() <= b.getOrder() ? result = a : result = b;
  return result;
}
