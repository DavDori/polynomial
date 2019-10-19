#include "polynomial.h"

Polynomial::Polynomial(poly p)
{
  polynomial = p;
  order = p.size();
}

Polynomial::operator=(const Polynomial&)
{
  
}

Polynomial::operator+(const Polynomial&, const Polynomial&)
{

}

Polynomial::operator-(const Polynomial&, const Polynomial&)
{

}

void Polynomial::shift(int times)
{
  for(int i = 0; i < times; i++)
  {
    polynomial.insert(polynomial.begin(), 0);
  }
}

void Polynomial::multipyByConstant(float value)
{
  for(int i = 0; i < order; i++)
  {
    polynomial[i] = polynomial[i] * value;
  }
}

void Polynomial::correctSize()
{
  while(polynomial[order-1] == 0)
  {
      polynomial.pop_back();
      order--;
  }
}

void Polynomial::print()
{
  printFirstAndSecond();
  for(int i = 2; i < order; i++)
  {
    cout << " + " << polynomial[i] << "x^" << i;
  }
  cout << endl;
}

void Polynomial::printFirstAndSecond()
{
  if(order >= 1)
    cout << polynomial[0];
  if(order >= 2)
    cout << " + " << polynomial[1] << 'x';
}

int Polynomial::getOrder()
{
  return order;
}
