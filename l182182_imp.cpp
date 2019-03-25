#include "Date.h"

static string monthNames[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

Date::Date() // default constructor
{
	// it assigns default values
	month = 1;
	date = 1;
	year = 2000;
}

Date::Date(int m, int d, int y) // parameterized constructor
{
	this->date = d;
	this->month = m;
	this->year = y;
	// following is the check if the entered date is valid or not. if it is invalid, then it stores the default values
	if (!(this->date > 0 && this->date < 31 && this->month > 0 && this->month < 13 && this->year > 999 && this->year < 10000))
	{
		month = 1;
		date = 1;
		year = 2000;
	}
}

Date::Date(const Date& dummy) // copy constructor
{
	date = dummy.date;
	month = dummy.month;
	year = dummy.year;
}

ostream& operator << (ostream& out, const Date& dummy) // overloaded printing function
{
	out << monthNames[dummy.month] << ' ' << dummy.date << ", " << dummy.year;

	return out;
}

bool Date::operator == (const Date& that) const // overloaded relational operator
{
	return (this->date == that.date && this->month == that.month && this->year == that.year);
}

istream& operator >> (istream& in, Date& dummy) // overloaded input function
{
	char temp1, temp2;
	int bckdate = dummy.date;
	int bckmonth = dummy.month;
	int bckyear = dummy.year;

	in >> dummy.month;
	in.get(temp1);
	in >> dummy.date;
	in.get(temp2);
	in >> dummy.year;

	if (temp1 == '-' || temp1 == '/' && temp2 == '-' || temp2 == '/' && dummy.date > 0 && dummy.date < 31 && dummy.month > 0 && dummy.month < 13 && dummy.year > 999 && dummy.year < 10000)
		return in;

	dummy.month = bckmonth;
	dummy.date = bckdate;
	dummy.year = bckyear;

	return in;
}

Date& Date::operator = (const Date& dummy) // overloaded assignment operator
{
	if (this != &dummy)
	{
		this->date = dummy.date;
		this->month = dummy.month;
		this->year = dummy.year;
	}

	return *this;
}

Date Date::operator + (const int val) const // + operator that adds only to date
{
	Date buffer = *this;

	buffer.date += val;

	if (buffer.date > 30) // if date exceeds 30 after addition
	{
		int carry = buffer.date / 30;
		buffer.date = buffer.date % 30;

		buffer.month += carry;
		if (buffer.month > 12) // if month exceeds 12 after addition of carry from date
		{
			carry = buffer.month / 12;
			buffer.month = buffer.month % 12;
			
			buffer.year += carry;
		}
	}
	return buffer;
}

Date& Date::operator -- () // prefix decrement operator
{
	if (this->date == 1) // as the decrement is only 1, so we have the value on that the dates or months will exceed its limits
	{
		this->date = 30;
		if (this->month == 1)
		{
			this->month = 12;
			this->year--;
		}
		else
			this->month--;
	}
	else
		this->date--;

	return *this;
}

const Date Date::operator -- (int num) // postfix decrement operator
{
	Date buffer = *this;

	if (this->date == 1)
	{
		this->date = 30;
		if (this->month == 1)
		{
			this->month = 12;
			this->year--;
		}
		else
			this->month--;
	}
	else
		this->date--;
	
	return buffer; // return copy of date which is created before decrement
}

int Date::operator [] (int index) const
{
	switch (index)
	{
	case 0:
		return this->date;
		break;
	case 1:
		return this->month;
		break;
	case 2:
		return this->year;
		break;
	default:
		cout << "index can only be 0, 1 or 2" << endl;
		return 0;
		break;
	}
}