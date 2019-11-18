#include "polynomial.h"
#include <iostream>

Polynomial::Polynomial(vector<float> coefficients)
{
  numeratorCoefficient = coefficients;
  numeratorOrder = coefficients.size();
  denominatorOrder = 0;
  this->correctSize();
}

Polynomial::Polynomial(vector<float> numCoefficients, vector<float> denomCoefficients)
{
  numeratorCoefficient = numCoefficients;
  denominatorCoefficient = denomCoefficients;
  numeratorOrder = numCoefficients.size();
  denominatorOrder = denomCoefficients.size();
  this->correctSize();
}

//MATH_OPERATIONS/////////////////////////////////////////

/*
OVERLOADING OPERATORS
*/

Polynomial& Polynomial::operator= (const Polynomial& r)
{
  numeratorCoefficient = r.numeratorCoefficient;
  denominatorCoefficient = r.denominatorCoefficient;
  numeratorOrder = r.numeratorOrder;
  denominatorOrder = r.denominatorOrder;
  return *this;
}

/*
sum operation:
*/

Polynomial operator+ (const Polynomial& a, const Polynomial& b)
{
  Polynomial result;
  if(a.denominatorOrder != 0 && b.denominatorOrder != 0)
  {
    Polynomial b_denominator(b.denominatorCoefficient);
    Polynomial a_denominator(a.denominatorCoefficient);
    result = sumNoDenominator(a * b_denominator, b * a_denominator);
  }
  else if(a.denominatorOrder != 0)
  {
    Polynomial a_denominator(a.denominatorCoefficient);
    result = sumNoDenominator(a, b * a_denominator);
  }
  else if(b.denominatorOrder != 0)
  {
    Polynomial b_denominator(b.denominatorCoefficient);
    result = sumNoDenominator(a * b_denominator, b);
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

void Polynomial::correctSize()
{
  if(numeratorOrder != 0)
  {
    numeratorCoefficient = correctCoefficientSize(numeratorCoefficient);
    numeratorOrder = numeratorCoefficient.size();
  }
  if(denominatorOrder != 0)
  {
    denominatorCoefficient = correctCoefficientSize(denominatorCoefficient);
    denominatorOrder = denominatorCoefficient.size();
  }
}

vector<float> Polynomial::correctCoefficientSize(const vector<float>& coefficients)
{
  vector<float> newCoefficients = coefficients;
  int index = newCoefficients.size()-1;
  while(newCoefficients[index] == 0)
  {
      newCoefficients.pop_back();
      index--;
  }
  return newCoefficients;
}

Polynomial pickLarger(const Polynomial& a, const Polynomial& b)
{
  Polynomial result;
  a.numeratorOrder > b.numeratorOrder ? result = a : result = b;
  return result;
}

Polynomial pickSmaller(const Polynomial& a, const Polynomial& b)
{
  Polynomial result;
  a.numeratorOrder <= b.numeratorOrder ? result = a : result = b;
  return result;
}

Polynomial sumLargerWithSmaller(const Polynomial& larger, const Polynomial& smaller)
{
  Polynomial result = larger;
  for(int i = 0; i < smaller.numeratorOrder; i++)
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
  for(int i = 0; i < numeratorOrder; i++)
  {
    numeratorCoefficient[i] = numeratorCoefficient[i] * value;
  }
}

/*
Multiplication between two polynomials:
*/

Polynomial operator* (const Polynomial& a, const Polynomial& b)
{
  int numberOfPolynomialsToSum = b.numeratorOrder;
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
    numeratorOrder++;
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
  if(numeratorOrder != 0)
  {
    result = getStrVector(numeratorCoefficient);
    if(denominatorOrder != 0)
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
