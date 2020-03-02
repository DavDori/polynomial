# Polynomial library [C++]
The library is written in C++ using class template vector and allows basic polynomial operations, such as:
- sum between polynomials
- difference between polynomials
- assignment
- multiplication between polynomials
- multiplication by constant values

Moreover it allows basic polynomial representation (example: 1+0x+2x^2/1+1x)

# Usage

## Import library:
```C++
#include "polynomial.h"
```

## Call constructor
There are three ways to call it depending on the needs:
```C++
Polynomial polyName(vector<float> numerator,vector<float> denominator);
Polynomial polyName(vector<float> numerator);
Polynomial polyName(int polySize, float value);
```

- **numerator** is a vector of floats, the first value is the 0 order coefficient, the n value is the n-1 order coefficient;

- **denominator** is a vector of float and is used the same way as the numerator;

- **polySize** is an integer and represents the size of the polynomial;  

- **value** is the float value used to fill the polynomial coefficients.

## Operations
In order to work with ease operator overloading has been used.
### Assignment example
```C++
Polynomial poly2 = poly1;
```
### Addition example
```C++
Polynomial poly3 = poly2 + poly1;
```
### Subtraction example
```C++
Polynomial poly3 = poly2 - poly1;
```
### Multiplication example
```C++
Polynomial poly3 = poly2 * poly1;
