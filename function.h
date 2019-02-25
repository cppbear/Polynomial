#pragma once
#include"struct.h"
Polynomial* InitPolynomial(char* a);
void PrintPolynomial(Polynomial* poly);
Polynomial* Add(Polynomial* a, Polynomial* b);
Polynomial* Minus(Polynomial* a, Polynomial* b);
Polynomial* Multiply(Polynomial* a, Polynomial* b);
Polynomial* Power(Polynomial* poly, int index);
void sortList(Polynomial* poly);
void mixPoly(Polynomial* poly);