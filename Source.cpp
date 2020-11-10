#include <iostream>
using namespace std;

unsigned long long fib0(unsigned int n) //рекурсия (долго) O(2^n)
{
	return n > 2 ? fib0(n - 1) + fib0(n - 2) : 1;
}

unsigned long long a[1000] = {0, 1, 1};
unsigned long long fib1(unsigned int n) //рекурсия с запоминанием (быстро) O(n)
{
	if (a[n])
		return a[n];
	if(a[n - 1])
		a[n] = a[n - 1] + a[n - 2];
	return n > 2 ? fib1(n - 1) + fib1(n - 2) : 1;

}

unsigned long long fib2(unsigned int n) //считаем с начала (быстро) O(n)
{
	unsigned long long* a = new unsigned long long[n];
	a[0] = 1, a[1] = 1;
	for (size_t i = 2; i < n; i++)
		a[i] = a[i - 1] + a[i - 2];
	return a[n - 1];
}

unsigned long long fib3(unsigned int n) //через формулу бине (самый быстрый, но нерабочий из за неточности) O(1)
{
	long double phi = (1 + sqrt(5)) / 2;
	phi = pow(phi, n);
	return n % 2 == 1 ? (phi - 1/phi)/sqrt(5) : (phi + 1 / phi) / sqrt(5);
}

struct Matrix //реализуем матрицу lol
{
	unsigned long long a[2][2] = { 1, 1, 1, 0 };
	Matrix& neutral()
	{
		Matrix another;
		another.a[0][0] = 1;
		another.a[0][1] = 0;
		another.a[1][0] = 0;
		another.a[1][1] = 1;
		return another;
	}
	Matrix& operator =(const Matrix& another)
	{
		for (size_t i = 0; i < 2; i++)
			for (size_t j = 0; j < 2; j++)
				this->a[i][j] = another.a[i][j];
		return *this;

	}
	Matrix& operator *=(const Matrix& another)
	{
		Matrix copy = *this;
		this->a[0][0] = copy.a[0][0] * another.a[0][0] + copy.a[0][1] * another.a[1][0];
		this->a[0][1] = copy.a[0][0] * another.a[0][1] + copy.a[0][1] * another.a[1][1];
		this->a[1][0] = copy.a[1][0] * another.a[0][0] + copy.a[1][1] * another.a[1][0];
		this->a[1][1] = copy.a[1][0] * another.a[0][1] + copy.a[1][1] * another.a[1][1];
		return *this;
	}
	Matrix& operator *(const Matrix& another)
	{
		Matrix copy = *this;
		return copy *= another;
	}
	friend ostream& operator << (ostream& out, const Matrix& another);
}; 

ostream& operator << (ostream& out, const Matrix& another)
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
			out << another.a[i][j] << " ";
		out << endl;
	}
	return out;
}

Matrix fib4(unsigned int n) //возводим матрицу в степень рекурсивно за O(n)
{
	return n ? Matrix() * fib4(n - 1) : Matrix().neutral();
}

Matrix fib5(unsigned int n) //возводим матрицу в степень циклом за O(n)
{
	Matrix ans;
	for (size_t i = 0; i < n - 1; i++)
		ans *= Matrix();
	return ans;
}

Matrix fib6(unsigned int n) //возводим матрицу в степень рекурсивно за O(log n)
{
	if (n == 0)
		return Matrix().neutral();
	if (n % 2 == 1)
	{
		return Matrix() * fib6(n - 1);
	}
	else
	{
		Matrix tmp = fib6(n / 2);
		return tmp * tmp;
	}
}

int main()
{
  return 0;
}
