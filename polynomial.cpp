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
sum operation:
*/

Polynomial operator+ (const Polynomial& a, const Polynomial& b)
{
  Polynomial larger = pickLarger(a,b);
  Polynomial smaller = pickSmaller(a,b);

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
Difference operation: sums the first polinomial and second which
sign has been inverted; size correction is not needed since it's
already provided by the sum operatorn
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
Multiplication between two polynomials:
*/

Polynomial operator* (const Polynomial& a, const Polynomial& b)
{
  int numberOfPolynomialsToSum = b.order;
  Polynomial* sumOfPolinomialMultiplications;
  sumOfPolinomialMultiplications = new Polynomial[numberOfPolynomialsToSum];

  for(int i = 0; i < numberOfPolynomialsToSum; i++)
  {
    sumOfPolinomialMultiplications[i] = a;
    sumOfPolinomialMultiplications[i].shift(i);
    sumOfPolinomialMultiplications[i].multipyByConstant(b.polyCoefficients[i]);
  }
  Polynomial result = sumGroup(sumOfPolinomialMultiplications, numberOfPolynomialsToSum);
  delete [] sumOfPolinomialMultiplications;
  return result;
}

void Polynomial::shift(int times)
{
  for(int i = 0; i < times; i++)
  {
    polyCoefficients.insert(polyCoefficients.begin(), 0);
  }
}

Polynomial sumGroup(const Polynomial* groupToSum, int sizeOfGroup)
{
  Polynomial result = groupToSum[0];
  for(int i = 1; i < sizeOfGroup; i++)
  {
    result = result + groupToSum[i];
  }
  return result;
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
