
using namespace std;

#include <iostream>
#include "polynomial.h"

int main()
{
  vector<float> n1 = {0,1};
  vector<float> d1 = {1,1};

  vector<float> n2 = {1};
  vector<float> d2 = {1};

  Polynomial poly1(n1,d1);
  Polynomial poly2(n2,d2);
  cout << "polynomal 1 : " << poly1.print() << endl;
  cout << "polynomal 2 : " << poly2.print() << endl;
  Polynomial polyMult = poly1 * poly2;
  cout << "1 * 2 : " << polyMult.print() << endl;

  Polynomial polyAdd = (poly1 + poly2);
  cout << "1 + 2 : " << polyAdd.print() << endl;






  return 0;
}
