#include "money.h"
#include <exception>
using namespace std;

void Money::setP(double aX)
{
	if (aX >= 12)
	{
		throw exception("Error:penny>=12");
	}
	if (round(aX) - aX != 0.5 && round(aX) != aX)
	{
		throw exception("Error:penny with incorrect digit after , ");
	}
	if (aX < 0 && pd == 0 && sh == 0)
	{
		aX *= -1;
		PositiveAmount = false;
	}
	if (aX < 0)
	{
		throw exception("error: invalid amount of penny");
	}
	P = aX;
}
void Money::setPositiveAmount(bool x)
{
	PositiveAmount = x;
}

bool Money::getPositiveAmount() const
{
	return PositiveAmount;
}

void Money::setSh(int aX)
{
	if (aX >= 20)
	{
		throw std::exception("Error:shilling>20");
	}
	if (aX < 0 && pd == 0)
	{
		aX *= -1;
		PositiveAmount = false;
	}
	if (aX < 0)
	{
		throw exception("Error: incorrect value of shilling");
	}
	sh = aX;
}

void Money::setPd(int aX)
{
	pd = aX;
	if (pd < 0)
	{
		pd *= -1;
		PositiveAmount = false;
	}
}

double Money::getP() const
{
	return P;
}

int Money::getSh() const
{
	return sh;
}

int Money::getPd() const
{
	return pd;
}
Money::Money(int aX, int aY, double aZ, bool aA)
{
	setPd(aX);
	setSh(aY);
	setP(aZ);
	setPositiveAmount(aA);
}

Money Money::operator-() const
{
	return Money(pd, sh, P, !PositiveAmount);

}

Money Money:: operator+(const Money& a) const
{
	double sum1, sum2;
	sum1 = getSum();
	sum2 = a.getSum();
	if (!PositiveAmount) {
		sum1 *= -1;
	}
	if (!a.PositiveAmount) {
		sum2 *= -1;
	}
	double tempRes = sum1 + sum2;
	bool tempBool = tempRes > 0;
	if (!tempBool) {
		tempRes *= -1;
	}
	int tempPound = tempRes / 12 / 20;
	int tempSh = (tempRes - tempPound * 12 * 20) / 12;
	double tempPenny = tempRes - tempPound * 12 * 20 - tempSh * 12;
	return Money(tempPound, tempSh, tempPenny, tempBool);
}


Money Money::operator-(const Money& a) const
{
	Money temp2 = -a;
	Money temp1(pd, sh, P, PositiveAmount);
	return temp1 + temp2;
}
bool Money::operator == (const Money& p) const
{
	double tempSum1, tempSum2;
	tempSum1 = getSum();
	tempSum2 = p.getSum();
	if (!PositiveAmount) {
		tempSum1 *= -1;
	}
	if (!p.getPositiveAmount()) {
		tempSum2 *= -1;
	}
	return (tempSum1 == tempSum2);
}

void Money::operator+= (const Money& b)
{
	Money temp1(pd, sh, P, PositiveAmount);
	Money tempRes = temp1 + b;
	pd = tempRes.getPd();
	sh = tempRes.getSh();
	P = tempRes.getP();
	PositiveAmount = tempRes.getPositiveAmount();
}
void Money::operator-= (const Money& b)
{
	Money temp1(pd, sh, P, PositiveAmount);
	Money tempRes = temp1 - b;
	pd = tempRes.getPd();
	sh = tempRes.getSh();
	P = tempRes.getP();
	PositiveAmount = tempRes.getPositiveAmount();
}

bool Money:: operator!=(const Money& p) const
{
	return (!this -> operator==(p));
}

bool Money::operator>(const Money& p) const
{
	double tempSum1, tempSum2;
	tempSum1 = getSum();
	tempSum2 = p.getSum();
	if (!PositiveAmount)
		tempSum1 *= -1;
	if (!p.getPositiveAmount())
		tempSum2 *= -1;
	return (tempSum1 > tempSum2);
}


double Money::getSum() const
{
	return pd * 12 * 20 + sh * 12 + P;
}

bool Money:: operator<(const Money& p) const
{
	return (!this -> operator>(p) && !this->operator==(p));
}

ostream& operator << (ostream& s, const Money& p)
{
	if (!p.getPositiveAmount())
		if (!(p.getP() == 0 && p.getPd() == 0 && p.getSh() == 0)) s << "-";
	if (p.getPd() != 0) s << p.getPd() << "pd.";
	if (p.getSh() != 0) s << p.getSh() << "sh.";
	if (p.getP() != 0) s << p.getP() << "p.";
	if (p.getP() == 0 && p.getPd() == 0 && p.getSh() == 0) s << "0p.";
	return s;
}
