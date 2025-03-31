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
int FibonacciAvc(int n)
{
	if(n==0) return 1;
	if(n==1) return 2;
	return 2*FibonacciAvc(n-1)+3*FibonacciAvc(n-2);
}
int sodaonguoc(int n, int reversed)
{//// 42156 4215 rvs= 6, 421 rvs= 65, 42 rvs= 651, 4 rvs=6542, 
if(n==0) return reversed;
return sodaonguoc(n/10, reversed*10+n%10);
}
int sum_even(int n, int sum)
{
	if(n==0) return sum;
	if(n%2==0) return sum+n%10;
	return sum_even(n/10, sum);
}
int dem_so_cach_len_cauthang(int n=4)
{
	// 4. 1-1-1-1 .1-1-2 .1-2-1 .2-1-1 .1-3. 3-1 .2-2
	if(n==0) return 1;
	if(n<0) return 0;
	return dem_so_cach_len_cauthang(n-1)+dem_so_cach_len_cauthang(n-2)+dem_so_cach_len_cauthang(n-3);
}
int GCD(int a, int b)
{
	if(b==0) return a;
	return GCD(b,a%b);
}
bool isPrime(int n, int i=2)
{
	if(n<2) return false;
	if(i*i>n) return true;
	if(n%i==0) return false;
	return isPrime(n,i+1);
}
void toBinary(int n)
{
	if(n==0) return;
	toBinary(n/2);
	cout << n%2;
}
int countDigit(int n, int d)
{
	if(n==0) return 0;
	if(n%10==d) return 1+ countDigit(n/10,d);
	else return countDigit(n/10,d);
}
int maxElement(int *a, int n)
{
    // Điều kiện dừng: Nếu mảng chỉ còn một phần tử, trả về phần tử đó
    if (n == 1)
        return a[0];

    // Tìm giá trị lớn nhất giữa phần tử đầu tiên và giá trị lớn nhất của phần còn lại
    int maxOfRest = maxElement(a + 1, n - 1); // Đệ quy để tìm giá trị lớn nhất của phần còn lại
    return (a[0] > maxOfRest) ? a[0] : maxOfRest; // Trả về giá trị lớn hơn
}
