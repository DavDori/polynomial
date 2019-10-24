
using namespace std;

#include <iostream>
#include "polynomial.h"

/*
poly mult(poly a, poly b);
poly sumGroup(poly* p, int n);
*/
int main()
{
  vector<float> a = {1,1};
  vector<float> b = {1,1};
  Polynomial poly_a(a);
  Polynomial poly_b(b);

  Polynomial poly_1 = poly_a + poly_b;

  Polynomial poly_2 = poly_a - poly_b;

  Polynomial poly_3 = poly_a * poly_b;

  poly_a.print();
  poly_b.print();
  poly_1.print();
  poly_2.print();
  poly_3.print();

  return 0;
}

//-------------------------------------------------
/*
poly mult(poly a, poly b)
{
  poly a_ = correctSize(a);
  poly b_ = correctSize(b);
  poly* polynomials;
  int polynomialsNumber = b.size();
  polynomials = poly poly[polynomialsNumber];
  for(int i = 0; i < polynomialsNumber; i++)
  {
    polynomials[i] = shift(a, i);
    polynomials[i] = multByConst(polynomials[i], b[i]);
  }
  poly result = sumGroup(polynomials, polynomialsNumber);
  delete [] polynomials;
  return result;
}*/

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
}*/
