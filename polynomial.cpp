#include "polynomial.h"
#include <iostream>

vector<float> multiplyVectors(const vector<float>&, const vector<float>&);
vector<float> multiplyVectorConstant(const vector<float>&, int);
vector<float> sumElements(const vector<float>* vectorsToSum, int n);
vector<float> sumVectors(const vector<float>&, const vector<float>&);
vector<float> sumVectorLargerSmaller(const vector<float>&, const vector<float>&);

//CONSTRUCTORS///////////////////////////////////////////

Polynomial::Polynomial(vector<float> numCoefficients, vector<float> denomCoefficients)
{
  initPolynomial(numCoefficients,denomCoefficients);
  this->correctSize();
}

Polynomial::Polynomial(vector<float> coefficients)
{
  initPolynomial(coefficients,{1});
  this->correctSize();
}

Polynomial::Polynomial(int size, float value)
{
  vector<float> coefficients = vector<float>(size,value);
  initPolynomial(coefficients,{1});
}

void Polynomial::initPolynomial(vector<float> numCoefficients, vector<float> denomCoefficients)
{
  numeratorCoefficient = numCoefficients;
  denominatorCoefficient = denomCoefficients;
  numeratorOrder = numCoefficients.size();
  denominatorOrder = denomCoefficients.size();
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
  vector<float> denominator = multiplyVectors(a.denominatorCoefficient, b.denominatorCoefficient);
  vector<float> numerator1 = multiplyVectors(a.numeratorCoefficient, b.denominatorCoefficient);
  vector<float> numerator2 = multiplyVectors(b.numeratorCoefficient, a.denominatorCoefficient);
  vector<float> numerator = sumVectors(numerator1, numerator2);
  Polynomial result(numerator, denominator);
  return result;
}

vector<float> multiplyVectors(const vector<float>& a, const vector<float>& b)
{
  int numberOfPolynomialsToSum = b.size();
  vector<float>* polynomialsToSum = new vector<float>[numberOfPolynomialsToSum];

  for(int i = 0; i < numberOfPolynomialsToSum; i++) //fill array
  {
    polynomialsToSum[i] = multiplyVectorConstant(a, b[i]);
    polynomialsToSum[i].insert(polynomialsToSum[i].begin(),i,0.0);
  }
  vector<float> result = sumElements(polynomialsToSum, numberOfPolynomialsToSum);

  delete[] polynomialsToSum;
  return result;
}

vector<float> multiplyVectorConstant(const vector<float>& v, int c)
{
  vector<float> result = v;
  for(int i = 0; i < v.size(); i++)
  {
    result[i] *= c;
  }
  return result;
}

vector<float> sumElements(const vector<float>* vectorsToSum, int n)
{
  vector<float> sum = vectorsToSum[0];
  for(int i = 1; i < n; i++)
  {
    sum = sumVectors(sum,vectorsToSum[i]);
  }
  return sum;
}

vector<float> sumVectors(const vector<float>& a, const vector<float>& b)
{
  vector<float> sum;
  if(a.size() >= b.size())
  {
    sum = sumVectorLargerSmaller(a,b);
  }
  else
  {
    sum = sumVectorLargerSmaller(b,a);
  }
  return sum;
}

vector<float> sumVectorLargerSmaller(const vector<float>& larger, const vector<float>& smaller)
{
  vector<float> sum = larger;
  for(int i = 0; i < smaller.size(); i++)
  {
    sum[i] = sum[i] + smaller[i];
  }
  return sum;
}

/*
Difference operation: sum the first polinomial and second which
sign has been inverted;
*/

Polynomial operator-(const Polynomial& a, const Polynomial& b)
{
  Polynomial inverted_b = b;
  inverted_b.multipyByConstant(-1.0);
  return (a + inverted_b);

}

void Polynomial::multipyByConstant(float value)
{
  for(int i = 0; i < numeratorCoefficient.size(); i++)
  {
    numeratorCoefficient[i] *= value;
  }
}

/*
Multiplication between two polynomials:
*/

Polynomial operator* (const Polynomial& a, const Polynomial& b)
{
  vector<float> num = multiplyVectors(a.numeratorCoefficient, b.numeratorCoefficient);
  vector<float> den = multiplyVectors(a.denominatorCoefficient, b.denominatorCoefficient);

  Polynomial result(num,den);
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

//RAPPRESENTATION///////////////////////////////////////////

string Polynomial::print()
{
  string result;
  result = getStrVector(numeratorCoefficient);
  if(denominatorOrder != 0)
  {
    result += " / ";
    result += getStrVector(denominatorCoefficient);
  }
  return result;
}

string Polynomial::getStrVector(vector<float> coefficient)
{
  string result = getStrFirstAndSecond(coefficient);
  if(coefficient.size() > 2)
  {
    for(int i = 2; i < coefficient.size(); i++)
    {
      result += " + "+std::to_string(int(coefficient[i]))+"x^"+std::to_string(i);
    }
  }
  return result;
}

string Polynomial::getStrFirstAndSecond(vector<float> coefficient)
{
  string result;
  if(coefficient.size() >= 1)
    result += std::to_string(int(coefficient[0]));
  if(coefficient.size() >= 2)
    result += " + " + std::to_string(int(coefficient[1])) + "x";
  return result;
}

///////////////////////////////////////////////////////////
