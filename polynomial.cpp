#include "polynomial.h"
#include <iostream>

Polynomial::Polynomial(vector<float> coefficients)
{
  numeratorCoefficient = coefficients;
  this->correctSize();
  order = coefficients.size();
}

Polynomial::Polynomial(vector<float> numCoefficients, vector<float> denomCoefficients)
{
  numeratorCoefficient = numCoefficients;
  denominatorCoefficient = denomCoefficients;
  this->correctSize();
  order = numCoefficients.size() - denomCoefficients.size();
}

//MATH_OPERATIONS/////////////////////////////////////////

/*
OVERLOADING OPERATORS
*/

Polynomial& Polynomial::operator= (const Polynomial& r)
{
  numeratorCoefficient = r.numeratorCoefficient;
  denominatorCoefficient = r.denominatorCoefficient;
  order = r.order;
  return *this;
}

/*
sum operation:
*/

Polynomial operator+ (const Polynomial& a, const Polynomial& b)
{
  Polynomial result;
  if(!a.denominatorCoefficient.empty() && !b.denominatorCoefficient.empty())
  {
    Polynomial b_denom(b.denominatorCoefficient);
    Polynomial a_denom(a.denominatorCoefficient);

    Polynomial a_b_denom =
  }
  else if(!a.denominatorCoefficient.empty() && b.denominatorCoefficient.empty())
  {
    Polynomial a_denom(a.denominatorCoefficient);

  }
  else if(a.denominatorCoefficient.empty() && !b.denominatorCoefficient.empty())
  {
    Polynomial b_denom(b.denominatorCoefficient);

  }
  else
  {
    result = sumNoDenominator(a,b);
  }
  result.correctSize();
  return result;
}

Polynomial sumNoDenominator(const Polynomial& a, const Polynomial& b)
{
  Polynomial larger = pickLarger(a,b);
  Polynomial smaller = pickSmaller(a,b);
  Polynomial result = sumLargerWithSmaller(larger, smaller);
  return result;
}

void Polynomial::correctSize()//return a segmentatio fault
{
  if(numeratorCoefficient.empty() == false)
    correctCoefficientSize(numeratorCoefficient);
  if(denominatorCoefficient.empty() == false)
    correctCoefficientSize(denominatorCoefficient);
}

void Polynomial::correctCoefficientSize(vector<float> coefficients)
{
  int index = coefficients.size()-1;
  while(coefficients[index] == 0)
  {
      coefficients.pop_back();
      index--;
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
    result.numeratorCoefficient[i] += smaller.numeratorCoefficient[i];
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
    numeratorCoefficient[i] = numeratorCoefficient[i] * value;
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
    sumOfPolynomialMultiplications[i].multipyByConstant(b.numeratorCoefficient[i]);
  }
  Polynomial result = sumGroup(sumOfPolynomialMultiplications, numberOfPolynomialsToSum);

  delete [] sumOfPolynomialMultiplications;
  return result;
}

void Polynomial::shift(int times)
{
  for(int i = 0; i < times; i++)
  {
    numeratorCoefficient.insert(numeratorCoefficient.begin(), 0);
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
  string result;
  if(!numeratorCoefficient.empty())
  {
    result = getStrVector(numeratorCoefficient);
    if(!denominatorCoefficient.empty())
    {
      result += " / ";
      result += getStrVector(denominatorCoefficient);
    }
  }
  else  result = "0";
  return result;
}

string Polynomial::getStrVector(vector<float> coefficient)
{
  string result = getStrFirstAndSecond(coefficient);
  for(int i = 2; i < coefficient.size(); i++)
  {
    result += " + "+std::to_string(int(coefficient[i]))+"x^"+std::to_string(i);
  }
  return result;
}

string Polynomial::getStrFirstAndSecond(vector<float> coefficient)
{
  string result;
  if(coefficient.size() >= 1)
    result += std::to_string(int(coefficient[0]));
  if(coefficient.size() >= 2)
    result += " + " + std::to_string(int(coefficient[1])) + 'x';
  return result;
}

///////////////////////////////////////////////////////////
