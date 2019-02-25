#include<iostream>
#include<stdlib.h>
#include<cstring>
#include"struct.h"
#include"function.h"
using namespace std;

int main()
{
	const int nMaxLen = 200;
	char str1[nMaxLen], str2[nMaxLen], str3[nMaxLen], str4[nMaxLen];
	cin >> str1 >> str2 >> str3 >> str4;
	Polynomial* poly1 = InitPolynomial(str1);
	Polynomial* poly2 = InitPolynomial(str2);
	Polynomial* poly3 = InitPolynomial(str3);
	Polynomial* poly4 = InitPolynomial(str4);
	cout << endl;
	PrintPolynomial(poly1);
	PrintPolynomial(poly2);
	PrintPolynomial(poly3);
	PrintPolynomial(poly4);
	cout << endl;
	PrintPolynomial(Add(poly1, poly2));
	PrintPolynomial(Minus(poly1, poly2));
	PrintPolynomial(Add(poly3, poly4));
	PrintPolynomial(Minus(poly3, poly4));
	return 0;
}