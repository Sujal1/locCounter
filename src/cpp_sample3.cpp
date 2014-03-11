/*
*
* This file serves as a test for the lab number 2
* It contains 7 LOC.
*
*/

// pre-processing

#include <stdio>

int main()  1
{
	int i;    2
	return 0; 3
}

class MyClass{
public:
	double a; 5
private:
	float b; 6
	double sum(int a, int b); 7
};


class calculate
{
   	double hours; 9
    	double total; 10
  public:
	calculate(int); 11
	void findTotal(); 12
};


void calculate::findTotal(void)
{
	while (hours > 0) 17
	{
		total += 1.2; 18
		hours--; 19
	}
	cout << "You owe: $" << total << endl; 20
}
