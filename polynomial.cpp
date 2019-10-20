#include "polynomial.h"
#include <iostream>

Polynomial::Polynomial(vector<float> coefficients)
{
  polyCoefficients = coefficients;
  order = coefficients.size();
  this->correctSize();
}

//MATH_OPERATIONS/////////////////////////////////////////

/*
OVERLOADING OPERATORS
*/

Polynomial& Polynomial::operator= (const Polynomial& r)
{
  polyCoefficients = r.polyCoefficients;
  order = r.order;
  return *this;
}

/*
sum operation: in order to sum two polinomials, it's necessary
to iter the coefficients sum over the larger vector
*/

Polynomial operator+ (const Polynomial& a, const Polynomial& b)
{
  Polynomial tmp_a = a;
  Polynomial tmp_b = b;
  tmp_a.correctSize();
  tmp_b.correctSize();

  Polynomial larger = pickLarger(tmp_a, tmp_b);
  Polynomial smaller = pickSmaller(tmp_a, tmp_b);
  Polynomial result = sumLargerWithSmaller(larger, smaller);
  result.correctSize();
  return result;
}

void Polynomial::correctSize()
{
  while(polyCoefficients[order-1] == 0)
  {
      polyCoefficients.pop_back();
      order--;
  }
}

Polynomial pickLarger(const Polynomial& a, const Polynomial& b)
{
  Polynomial result({0});
  a.order >= b.order ? result = a : result = b;
  return result;
}

Polynomial pickSmaller(const Polynomial& a, const Polynomial& b)
{
  Polynomial result({0});
  a.order <= b.order ? result = a : result = b;
  return result;
}

Polynomial sumLargerWithSmaller(const Polynomial& larger, const Polynomial& smaller)
{
  Polynomial result = larger;
  for(int i = 0; i < smaller.order; i++)
  {
    result.polyCoefficients[i] += smaller.polyCoefficients[i];
  }
  return result;
}

/*
Difference operation: sums the first polinomial with the second
inverted of sign; size correction is not needed since it's already
provided by the sum operator
*/

Polynomial operator-(const Polynomial& a, const Polynomial& b)
{
  Polynomial inverted_b = b;
  inverted_b.multipyByConstant(-1);
  return (a + inverted_b);

}


void Polynomial::multipyByConstant(float value)
{
  for(int i = 0; i < order; i++)
  {
    polyCoefficients[i] = polyCoefficients[i] * value;
  }
}

/*
Multiplication:
*/

void Polynomial::shift(int times)
{
  for(int i = 0; i < times; i++)
  {
    polyCoefficients.insert(polyCoefficients.begin(), 0);
  }
}

//RAPPRESENTATION///////////////////////////////////////////

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

///////////////////////////////////////////////////////////
