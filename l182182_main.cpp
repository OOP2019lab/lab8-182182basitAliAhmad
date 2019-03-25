#include "Date.h"

/*
Following is the program that shows how to use the class Date
Dear Sir,
There are some minor changes in the main driver code but these are just endl in cout statements just to get a clear and understandable
output on the console. Also I changed the name of the object declared at the end because an object was declared before with same name as
"d1" so I changed it to "d4". The rest is same and  working properly.


*/

int main()
{

	/*
	Create appropriate constructors
	1)	parameterized constructor that takes, month, date, year.
	month => 1 - 12
	date  => 1 - 30 you can assume every month has 30 days
	year  => 1000 - 9999 any four digit number

	2)	default constructor that sets the date to January 1, 2000
	*/
	Date d1(12, 27, 2010); // December 27, 2010
	Date d2(13, 27, 2010); // Month cannot be greater than 12, defaults to January 1, 2000
	Date d3; // Defaults to January 1, 2000


			 // Overload the << operator to perform the following printing
	cout << "Date 1 is " << d1 << endl; // prints December 27, 2010
	cout << "Date 2 is " << d2 << endl; // prints January 1, 2000
	cout << "Date 3 is " << d3 << endl; // prints January 1, 2000

								// Overload equality operator == 
	if (d2 == d3)
	{
		cout << "Date 2 " << d2 << " and Date 3 " << d3 << " are equal";
	}
	else
	{
		cout << "Date 2 " << d2 << " and Date 3 " << d3 << " are not equal";
	}
	cout << endl << "Enter Date: (mm/dd/yyyy)" << endl; 
	// Overload the stream insertion operator >> 
	cin >> d3; // Enter todays date
	cout << "Date 3 is changed and now is " << d3 << endl;

	if (d2 == d3)
	{
		cout << "Date 2 " << d2 << " and Date 3 " << d3 << " are equal";
	}
	else
	{
		cout << "Date 2 " << d2 << " and Date 3 " << d3 << " are not equal";
	}
	cout << endl;
	// Overload the addition operator + to add days to date
	// Overload the assignment operator "=", to store the result
	d1 = d1 + 1; // This adds a day to date d1 and stores it pack in d1
	cout << "Date 1 is " << d1 << endl; // prints December 28, 2010

	d1 = d1 + 3;
	cout << "Date 1 is " << d1 << endl; // prints January, 2011

								//Overload the prefix decrement operator "--object"
	cout << " Testing the prefix decrement operator" << endl;
	cout << "d3 is " << d3 << endl;
	cout << "--d3 is " << --d3 << endl;
	cout << "d3 is " << d3 << endl;

	//Overload the postfix decrement operator "--object"
	cout << " Testing the postfix decrement operator" << endl;
	cout << "d3 is " << d3 << endl;
	cout << "d3-- is " << d3-- << endl;
	cout << "d3 is " << d3 << endl;

	//Overload the subscript operator, [], for example.

	Date d4(12, 30, 2019);

	cout << "Day " << d4[0] << endl; //return day i.e 30
	cout << "Month " << d4[1] << endl; //return month i.e 12
	cout << "Year " << d4[2] << endl; //return year i.e 2019
							 // giving Any other index should give 0 and print message that index can only be 0, 1 or 2.


	system("pause");
	return 0;
}
