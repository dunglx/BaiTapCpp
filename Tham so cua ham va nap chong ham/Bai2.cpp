/* Viet 1 ham computeTriangle su dung de tinh dien tich va chu vi cua tam giac */

#include <iostream>
#include <math.h>
using namespace std;

void computeTriangle(double a, double b, double c, double* area, double* perimeter);

int main()
{
	double a,b,c;
	double cv,dt;
	char ans;
	
	do {
	dt = 0;
	cv = 0;
	cout << "Nhap vao 3 do dai: " << endl;
	cin >> a >> b >> c;
	computeTriangle(a,b,c,&dt,&cv);
	if (cv) {cout << "Chu vi la: "<< cv << endl;}
	if (dt) {cout << "Dien tich la: " << dt << endl;}
	cout << "Test again ? (y/n)";
	cin >> ans;
	cout << endl;
	} while (ans=='y'|| ans =='Y');
	
	return 0;
}

void computeTriangle(double a, double b, double c, double* area, double* perimeter)
{
	double s,dt,cv;
	if ((a>=(b+c)) || (b>=(a+c)) || (c>=(a+b)))	 {cout << a << b << c << "khong phai la ba canh cua mot tam giac" << endl; return;}
	else 
	{
		s = (a+b+c)/2;
		cv = 2*s;
		dt = sqrt(s*(s-a)*(s-b)*(s-c));
		*area = dt;
		*perimeter = cv;
		return;
	}
}

