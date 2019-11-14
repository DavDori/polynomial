
using namespace std;

#include <iostream>
#include "polynomial.h"

int main()
{
  vector<float> a = {1,2,1,2,1};
  vector<float> b = {1,2,3};

  Polynomial poly_a(a);
  Polynomial poly_b(b);
  Polynomial poly_ab(a,b);
  cout << "numerator: " << poly_a.print() << endl;
  cout << "denominator: " << poly_b.print() << endl;
  cout << "result: " <<poly_ab.print() << endl;

  return 0;
}
