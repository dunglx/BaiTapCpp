/* Viet chuong trinh chuyen doi ki hieu thoi gian 24 tieng thanh ki hieu thoi gian 12 tieng */

#include <iostream>
using namespace std;

// Khai bao nguyen mau ham
void nhap(int* a, int* b);
void xuat(int a, int b, char c);
void chuyendoi(int *a, int *b, char *c);

// Ham main()
int main() {
// your code goes here
	int a,b;
	char c,ans;
	do {
		nhap(&a, &b);
		chuyendoi(&a,&b,&c);
		xuat(a,b,c);
		cout << "Test again ? (y/n)";
		cin >> ans;
		cout << endl;
	} while (ans=='y'|| ans =='Y');
	return 0;
}

// Cac ham su dung
void nhap(int* a, int* b)
{
	int c,d;
	cout << "nhap vao hai so nguyen:";
	cin >> *a >> *b;
}


void xuat(int a, int b, char c)
{
	if(c=='A') cout << a << ":" << b << "A.M" << endl;
	else if (c=='P') cout << a << ":" << b << "P.M" << endl;
}

void chuyendoi(int *a, int *b, char *c)
{
	if(*a >= 12) {*a -= 12; *c = 'P';}
	else *c = 'A';
}
