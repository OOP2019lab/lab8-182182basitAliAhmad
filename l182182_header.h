#include<iostream>
#include<string>
using namespace std;

class Date
{
	int month;
	int date;
	int year;
	static string monthNames[13];

public:
	Date();
	Date(int, int, int);
	Date(const Date&);

	friend ostream& operator << (ostream&, const Date&);
	bool operator == (const Date&) const;
	friend istream& operator >> (istream&, Date&);
	Date& operator = (const Date&);
	Date operator + (const int) const;
	Date& operator -- ();
	const Date operator -- (int );

	int operator [] (int) const;

};