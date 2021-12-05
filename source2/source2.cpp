#include <iostream>
#include <string>
#include "money.h"
using namespace std;

int main() {
	cout << "Enter the first amount: " << endl;
	cout << "Enter the amount of pounds" << endl;
	Money a;
	int tempPound;
	cin >> tempPound;
	bool tempbool = (tempPound > 0);
	if (tempPound < 0)
	{
		tempPound *= -1;
	}
	a.setPositiveAmount(tempbool);
	int tempShilling;
	cout << "Enter the amount of shilling" << endl;
	cin >> tempShilling;
	double tempP;
	cout << "Enter the amount of penny" << endl;
	cin >> tempP;
	try
	{
		a.setPd(tempPound);
		a.setSh(tempShilling);
		a.setP(tempP);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return 0;
	}
	cout << "Enter the second sum:" << endl;
	cout << "pounds: " << endl;
	cin >> tempPound;
	cout << "shilling:" << endl;
	cin >> tempShilling;
	cout << "penny:" << endl;
	cin >> tempP;
	Money b;
	b.setPd(tempPound);
	try
	{
		b.setSh(tempShilling);
		b.setP(tempP);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 0;
	}
	cout << "a+b= " << a + b << endl;
	cout << "a-b= " << a - b << endl;
	cout << "-a= " << -a << endl;
	cout << "a==b: " << (a == b) << endl;
	cout << "a>b: " << (a > b) << endl;
	cout << "a<b: " << (a < b) << endl;
	a += b;
	cout << "a+=b. new amount of a is " << a << endl;
	a -= b;
	cout << "a-=b. new amount of a is " << a << endl;
}
