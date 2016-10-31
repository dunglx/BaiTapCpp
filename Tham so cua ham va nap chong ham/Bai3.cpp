/* Viet chuong trinh giup hoc sinh tieu hoc tinh nhan */

#include <iostream>
#include <cstdlib>
using namespace std;

void tinhnhan(int a, int b);

int main()
{
	int i=10;
	int a,b;
	while(i--)
	{
		a = rand() % 100 + 1;
		b = rand() % 100 + 1;
		tinhnhan(a,b);
	}
	return 0;
}

void tinhnhan(int a, int b)
{
	int kq, ans;
	cout << a << "x" << b << "= ?" << endl;
	cin >> kq;
	ans = a * b;
	while (kq!=ans)
	{
		cout << "Sai roi. Moi ban tra loi lai" << endl;
		cout << a << "x" << b << "= ?" << endl;
		cin >> kq;
	}
	cout << "Tot !" << endl; 
}
