#include <iostream>

int getDataFromUser();
int getAndShowThePrimeNumbers(const int _N);
int showEror(const int _ERRORNUMBER);

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
		std::cout << "Enter the number - N: ";
		std::cin >> n;

		if (!std::cin.fail())
		{

			if (n > 0)
			{
				isCorrect = true;
				getAndShowThePrimeNumbers(n);
			}

			else
			{
				showEror(1);
			}
		}

		else
		{
			std::cin.clear();
			std::cin.ignore(999, '\n');
			showEror(2);
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
			std::cout << i << " ";
		}

		if ((i % 2 != 0))
		{
			if ((i % 3 != 0) && (i % 5 != 0) && (i % 7 != 0))
			{
				std::cout << i << " ";
			}
		}
	}

	return 0;
}

int showEror(const int _ERROR_NUMBER)
{
	switch (_ERROR_NUMBER)
	{
	case 1: std::cout << "The number must be greater than 0!" << std::endl;
		break;
	case 2: std::cout << "Wrong format! Please, try again" << std::endl;
		break;

	default: std::cout << "Unknown error" << std::endl;
		break;
	}

	return 0;
}
