
using namespace std;

#include <iostream>
#include "polynomial.h"

int main()
{
  vector<float> a = {1,2,1,2,1};
  vector<float> b = {1,2,3};
  Polynomial poly_a(a);
  Polynomial poly_b(b);

  Polynomial poly_1 = poly_a + poly_b;

  Polynomial poly_2 = poly_a - poly_b;

  Polynomial poly_3 = poly_a * poly_b;

  poly_a.print();
  cout << "*" << endl;
  poly_b.print();
  cout << "=" << endl;
  poly_3.print();

  return 0;
}
