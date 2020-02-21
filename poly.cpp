
using namespace std;

#include <iostream>
#include "polynomial.h"

int main()
{
  vector<float> a = {2,1};
  vector<float> b1 = {0,2};
  vector<float> b2 = {0,0,0,1}; //problema con sumGroup, non gli piace x^1 = 0 e x^0 = 0
  vector<float> b3 = {3,0};

  Polynomial poly_a(a);
  Polynomial poly_b1(b1);
  Polynomial poly_b2(b2);
  Polynomial poly_b3(b3);
  //Polynomial poly_ba(b,a);
  //Polynomial poly_ab(a,b);


  cout << "a    : " << poly_a.print() << endl;
  cout << "b1    : " << poly_b1.print() << endl;
  cout << "b2    : " << poly_b2.print() << endl;
  //cout << "ba   : " << poly_ba.print() << endl;
  //cout << "ab   : " << poly_ab.print() << endl;

  cout << "a * b1: " << (poly_a * poly_b1).print() << endl;
  cout << "a * b2: " << (poly_a * poly_b2).print() << endl;

  return 0;
}
