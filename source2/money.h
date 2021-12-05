#pragma once
#include <iostream>
using namespace std;


class Money
{
public:
	void setP(double aX);
	void setSh(int aX);
	void setPd(int aX);
	void setPositiveAmount(bool);
	bool getPositiveAmount() const;
	double getP() const;
	int getSh() const;
	int getPd() const;
	double getSum() const;
	Money(int pd = 0, int sh = 0, double p = 0, bool PositiveAmount = 1);
	Money operator - () const;
	Money operator + (const Money&) const;
	Money operator - (const Money&) const;
	bool operator == (const Money&) const;
	bool operator != (const Money&) const;
	bool operator > (const Money&) const;
	bool operator < (const Money&) const;
	void operator +=(const Money&);
	void operator -=(const Money&);
	friend ostream& operator << (ostream&, const Money&);
private:
	double P;
	int sh;
	int pd;
	bool PositiveAmount;
};