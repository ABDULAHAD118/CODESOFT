#include <iostream>
using namespace std;
int main()
{
	double number1, number2, answer;
	char operation, value;
	bool flag = true;
	while (flag)
	{
		cout << "Enter the First Number, operation (+,-,*,/) and Second Number" << endl;
		cin >> number1 >> operation >> number2;
		if (operation == '+')
		{
			answer = number1 + number2;
		}
		else if (operation == '-')
		{
			answer = number1 - number2;
		}
		else if (operation == '/')
		{
			answer = number1 / number2;
		}
		else if (operation == '*')
		{
			answer = number1 * number2;
		}
		cout << "The Answer is " << answer << endl;
		cout << "Do you want to continue (y/n) ";
		cin >> value;
		if (value == 'y' || value == 'Y')
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
	}
}
