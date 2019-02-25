#include<iostream>
#include"struct.h"
using namespace std;
void sortList(Polynomial* poly);
void mixPoly(Polynomial* poly);
Polynomial* InitPolynomial(char* a)
{
	Polynomial* head = new Polynomial;
	head->next = NULL;
	Polynomial* tail = head;
	for (int i = 0; a[i] != 0; i++)
	{
		int j;
		Polynomial* p = new Polynomial;
		char m[15]{};
		int t;
		for (j = i, t = 0; a[j] != 'x'; j++, t++)
			m[t] = a[j];
		p->coe = atoi(m);
		char n[15]{};
		for (j = j + 2, t = 0; a[j] != '+' && a[j] != '-' && a[j] != 0; j++, t++)
			n[t] = a[j];
		p->index = atoi(n);
		p->next = NULL;
		tail->next = p;
		tail = p;
		i = j - 1;
	}
	sortList(head);
	mixPoly(head);
	return head;
}
void PrintPolynomial(Polynomial * poly)
{
	Polynomial* p = poly->next;
	while (p)
	{
		if (p->coe > 0)
			cout << '+' << p->coe << "x^" << p->index;
		else if (p->coe < 0)
			cout << p->coe << "x^" << p->index;
		p = p->next;
	}
	cout << endl;
}
Polynomial* Add(Polynomial * a, Polynomial * b)
{
	Polynomial* head = new Polynomial;
	head->next = NULL;
	Polynomial* tail = head;
	for (Polynomial* t = a->next; t != NULL; t = t->next)
	{
		Polynomial* p = new Polynomial;
		p->coe = t->coe;
		p->index = t->index;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	for (Polynomial* t = b->next; t != NULL; t = t->next)
	{
		Polynomial* p = new Polynomial;
		p->coe = t->coe;
		p->index = t->index;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	sortList(head);
	mixPoly(head);
	return head;
}
Polynomial* Minus(Polynomial * a, Polynomial * b)
{
	Polynomial* h = new Polynomial;
	Polynomial* t = b->next;
	while (t)
	{
		t->coe = -t->coe;
		t = t->next;
	}
	h = Add(a, b);
	return h;
}
Polynomial* Multiply(Polynomial * a, Polynomial * b)
{
	return nullptr;
}
Polynomial* Power(Polynomial * poly, int index)
{
	return nullptr;
}
void sortList(Polynomial * poly)
{
	if (poly->next == NULL || poly->next->next == NULL)
		return;
	for (Polynomial* pi = poly->next; pi->next != NULL; pi = pi->next)
	{
		Polynomial* p_max = pi;
		for (Polynomial* pj = pi->next; pj != NULL; pj = pj->next)
			if (p_max->index < pj->index)
				p_max = pj;
		if (p_max != pi)
		{
			int tempCoe = pi->coe;
			pi->coe = p_max->coe;
			p_max->coe = tempCoe;
			int tempIndex = pi->index;
			pi->index = p_max->index;
			p_max->index = tempIndex;
		}
	}
}
void mixPoly(Polynomial * poly)
{
	Polynomial* p = new Polynomial;
	p = poly->next;
	while (p && p->next)
	{
		Polynomial* q = new Polynomial;
		q = p->next;
		while (q != NULL && q->index == p->index)
		{
			p->coe += q->coe;
			p->next = q->next;
			q = q->next;
		}
		p = p->next;
	}
}