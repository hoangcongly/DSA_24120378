#include "Header.h"


int Factorial_Caculation(int n)
{
	if (n == 0) return 1;
	return n * Factorial_Caculation(n - 1);
}
int Fibonacci_Sequence(int n)
{
	if (n == 0 || n == 1) return n;
	return Fibonacci_Sequence(n - 2) + Fibonacci_Sequence(n - 1);
}
int Sum_Of_Array_Element(int* a, int n)
{
	if (n == 0) return 0;
	return a[n - 1] + Sum_Of_Array_Element(a, n - 1);
}
int Binary_Search(int* a, int left, int right, int key)
{	
	if (left > right) return -1;
	int mid = left + (right - left) / 2;
	if (a[mid] == key) return mid;
	if (a[mid] < key) return Binary_Search(a, mid + 1, right, key);
	return Binary_Search(a, left, mid - 1, key);
}
void Tower_Of_HaNoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		cout << "Move disk 1 from rod " << A << " to_rod" << endl;
		return;
	}
	Tower_Of_HaNoi(n - 1, A, C, B);
	cout << "Move disk " << n << " from rod " << A << " to rod " << B << endl;
	Tower_Of_HaNoi(n - 1, C, B, A);
}
const int MAX = 50;
int grid[MAX][MAX];  // Ma trận lưu trạng thái
int m, n;  // Kích thước ma trận

void FloodFill(int x, int y, int oldColor, int newColor) {
	// Nếu ra ngoài biên hoặc không phải màu cũ, thoát
	if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != oldColor) return;

	// Đổi màu
	grid[x][y] = newColor;

	// Gọi đệ quy theo 4 hướng
	FloodFill(x + 1, y, oldColor, newColor); // Xuống
	FloodFill(x - 1, y, oldColor, newColor); // Lên
	FloodFill(x, y + 1, oldColor, newColor); // Phải
	FloodFill(x, y - 1, oldColor, newColor); // Trái
}
///////////POINTER///////////////////////
struct pPhanSo
{
	int tu, mau;
};
int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}
pPhanSo simplify(pPhanSo& ps)
{
	int gcd = GCD(max(ps.tu, ps.mau), min(ps.tu, ps.mau));
	ps.tu /= gcd;
	ps.mau /= gcd;
	return ps;
}
void input_Fractions(pPhanSo*& a, int& n)
{
	cout << "Nhap so luong phan so: ";
	cin >> n;
	a = new pPhanSo[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan so thu " << i + 1 << ": ";
		cin >> a[i].tu >> a[i].mau;
		simplify(a[i]);
	}
}
void print_Fractions(pPhanSo* a, int n)
{
	cout << "Danh sach phan so: ";
	for(int i=0; i<n; i++)
	{
		cout << a[i].tu << "/" << a[i].mau << "\t";
	}
	cout << endl;
}

void insert_Fraction(pPhanSo*& a, int& n, pPhanSo ps)
{
	pPhanSo* newa = new pPhanSo[n + 1];
	for (int i = 0; i < n; i++)
	{
		newa[i] = a[i];
	}
	newa[n] = ps;
	n++;
	delete[] a;
	a = newa;
}
void delete_Fraction(pPhanSo*& a, int& n)
{
	if (n == 0) return;
	pPhanSo* newa = new pPhanSo[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		newa[i] = a[i];
	}
	n--;
	delete[]a;
	a = newa;
}