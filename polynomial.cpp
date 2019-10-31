#include "polynomial.h"
#include <iostream>
#include <string>

Polynomial::Polynomial(vector<float> coefficients)
{
  numeratorCoefficient = coefficients;
  order = coefficients.size();
  this->correctSize();
}

Polynomial::Polynomial(vector<float> numCoefficients, vector<float> denomCoefficients)
{
  numeratorCoefficient = numCoefficients;
  denominatorCoefficient = denomCoefficients;
  order = numCoefficients.size() - denomCoefficients.size();
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
  Polynomial result;
  a.order > b.order ? result = a : result = b;
  return result;
}

Polynomial pickSmaller(const Polynomial& a, const Polynomial& b)
{
  Polynomial result;
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
  Polynomial* sumOfPolynomialMultiplications;
  sumOfPolynomialMultiplications = new Polynomial[numberOfPolynomialsToSum];

  for(int i = 0; i < numberOfPolynomialsToSum; i++)
  {
    sumOfPolynomialMultiplications[i] = a;
    sumOfPolynomialMultiplications[i].shift(i);
    sumOfPolynomialMultiplications[i].multipyByConstant(b.polyCoefficients[i]);
  }
  Polynomial result = sumGroup(sumOfPolynomialMultiplications, numberOfPolynomialsToSum);

  delete [] sumOfPolynomialMultiplications;
  return result;
}

void Polynomial::shift(int times)
{
  for(int i = 0; i < times; i++)
  {
    polyCoefficients.insert(polyCoefficients.begin(), 0);
    order++;
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

string Polynomial::print()
{
  string result
  if(!numeratorCoefficient.emplty())
  {
    result = getStrVector(numeratorCoefficient);
    result += " / ";
    if(!denominatorCoefficient.emplty())
    {
      result += getStrVector(denominatorCoefficient);
    }
  }
  else  result = "0";
  return result;
}

string Polynomial::getStrVector(vector<float> coefficient)
{
  string result = printFirstAndSecond(coefficient);
  for(int i = 2; i < coefficient.size(); i++)
  {
    result += " + " + coefficient[i] + "x^" + i;
  }
  return result;
}

void Polynomial::printFirstAndSecond(vector<float> coefficient)
{
  string result;
  if(coefficient.size() >= 1)
    result += coefficient[0];
  if(coefficient.size() >= 2)
    result += " + " += coefficient[1] += 'x';
  return result
}

///////////////////////////////////////////////////////////
