#include <iostream>
using namespace std;

int getDataFromUser();
int getAndShowThePrimeNumbers(const int _N);
int showErrorMessage(const int _ERROR_NUMBER);

int main()
{
	getDataFromUser();
	return 0;
}

int getDataFromUser()
{
	bool isCorrect = false;
	int n = 0;

	do
	{
		cout << "Enter the number - N: ";
		cin >> n;

		if (!cin.fail())
		{

			if (n > 0)
			{
				isCorrect = true;
				getAndShowThePrimeNumbers(n);
			}

			else
			{
				showErrorMessage(1);
			}
		}

		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			showErrorMessage(2);
		}

	} while (!isCorrect);

	return 0;
}

int getAndShowThePrimeNumbers(const int _N)
{
	for (size_t i = 2; i < _N + 1; i++)
	{

		if ((i == 2) || (i == 3) || (i == 5) || (i == 7))
		{
			cout << i << " ";
		}

		if ((i % 2 != 0))
		{
			if ((i % 3 != 0) && (i % 5 != 0) && (i % 7 != 0))
			{
				cout << i << " ";
			}
		}
	}

	return 0;
}

int showErrorMessage(const int _ERROR_NUMBER)
{
	switch (_ERROR_NUMBER)
	{
	case 1: cout << "The number must be greater than 0!" << endl;
		break;
	case 2: cout << "Wrong format! Please, try again" << endl;
		break;

	default: cout << "Unknown error" << endl;
		break;
	}

	return 0;
}
