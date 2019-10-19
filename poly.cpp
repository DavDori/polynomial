
using namespace std;

#include "polynomial.h"
#include <iostream>

poly sum(poly a, poly b);
poly pickLarger(poly a, poly b);
poly pickSmaller(poly a, poly b);
poly sumLargerWithSmaller(poly larger,poly smaller);
poly mult(poly a, poly b);
poly multByConst(poly a, float c);
poly sumGroup(poly* p, int n);
poly sq(poly a);

int main()
{
  poly a = {1,1,1,1,0};
  poly b = {1,2,1};
  Polynomial new_a(a);
  Polynomial new_b(b);
  new_a.print();
  new_b.print();
  Polynomial s = sum(new_a,new_b);
  s.print();
  return 0;
}

//-----------------------------------------------

Polynomial sum(Polynomial a, Polynomial b)
{
  a.correctSize();
  b.correctSize();
  Polynomial larger = pickLarger(a,b);
  Polynomial smaller = pickSmaller(a,b);
  Polynomial result = sumLargerWithSmaller(larger, smaller);
  return result;
}

Polynomial pickLarger(Polynomial a, Polynomial b)
{
  Polynomial result;
  a.getOrder() >= b.getOrder() ? result = a : result = b;
  return result;
}

Polynomial pickSmaller(Polynomial a, Polynomial b)
{
  Polynomial result;
  a.getOrder() <= b.getOrder() ? result = a : result = b;
  return result;
}

Polynomial sumLargerWithSmaller(Polynomial larger, Polynomial smaller)
{
  Polynomial result = larger;
  for(int i = 0; i < smaller.getOrder(); i++)
  {
    result.polynomial[i] += smaller.polynomial[i];
  }
  return result;
}

//-------------------------------------------------
/*
poly mult(poly a, poly b)
{
  poly a_ = correctSize(a);
  poly b_ = correctSize(b);
  poly* polynomials;
  int polynomialsNumber = b.size();
  polynomials = new poly[polynomialsNumber];
  for(int i = 0; i < polynomialsNumber; i++)
  {
    polynomials[i] = shift(a, i);
    polynomials[i] = multByConst(polynomials[i], b[i]);
  }
  poly result = sumGroup(polynomials, polynomialsNumber);
  delete [] polynomials;
  return result;
}

/*
sums every poly of the dynamic array
*/
/*
poly sumGroup(poly* p, int n)
{
  poly result;
  for(int i = 1; i < n; i++)
  {
    result = sum(p[0], p[i]);
  }
  return result;
}

//---------------------------------------------
poly sq(poly a)
{
  return molt(a,a);
}

void print(poly a)
{
  for(int i = 0; i < a.size(); i++)
  {
    cout << a[i] << ' ';
  }
  cout << endl;
}
*/
