#ifndef HEADER.H
#define HEADER.H

#include <iostream>
#include <algorithm>
using namespace std;

struct pPhanSo
{
	int tu, mau;
};

int Factorial_Caculation(int n);
int Fibonacci_Sequence(int n);
int Sum_Of_Array_Element(int* a, int n);
int Binary_Search(int* a, int left, int right, int key);
void Tower_Of_HaNoi(int n, char A, char B, char C);
void FloodFill(int x, int y, int oldColor, int newColor);
int GCD(int a, int b);
pPhanSo simplify(pPhanSo& ps);
void input_Fractions(pPhanSo*& a, int& n);
void print_Fractions(pPhanSo* a, int n);
void insert_Fraction(pPhanSo*& a, int& n, pPhanSo ps);
void delete_Fraction(pPhanSo*& a, int& n);

#endif // !HEADER.H
