
using namespace std;

#include <iostream>
#include "polynomial.h"

typedef vector<float> poly;
/*
poly mult(poly a, poly b);
poly multByConst(poly a, float c);
poly sumGroup(poly* p, int n);
*/
int main()
{
  poly a = {1,1,1,1,0};
  poly b = {1,2,1};
  Polynomial new_a(a);
  Polynomial new_b(b);
  new_a.correctSize();
  new_b.correctSize();

  Polynomial new_c = new_a + new_b;

  new_a.print();
  new_b.print();
  new_c.print();


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
  polynomials = new poly[polynomialsNumber];
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
