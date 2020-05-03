// The most accurate version //
// The hour hand is moves regarding of the minute hand //

#include <iostream>

int getHoursAndMinutesFromUser(int* _ptr_hours, int* _ptr_minutes);
int calculateAndShowTheDegreesBetweenHands(const int* _PTR_HOURS, const int* _PTR_MINUTES);
int showMessageError(const int _ERRORNUMBER);

int main()
{
	int hours = 0, minutes = 0, * ptr_hours = &hours, * ptr_minutes = &minutes;

	getHoursAndMinutesFromUser(ptr_hours, ptr_minutes); // -> Input, for example: 2 hours and 43 minutes
	calculateAndShowTheDegreesBetweenHands(ptr_hours, ptr_minutes); // -> Output: 193.5 degrees

	return 0;
}

int getHoursAndMinutesFromUser(int* _ptr_hours, int* _ptr_minutes)
{
	bool isCorrectData = false;

	do
	{
		std::cout << "Enter hours: ";
		std::cin >> *_ptr_hours;
		std::cout << "Enter minutes: ";
		std::cin >> *_ptr_minutes;

		if (!std::cin.fail())
		{
			if (*_ptr_hours <= 24 && *_ptr_minutes <= 60)
			{
				if (*_ptr_hours > 12) *_ptr_hours -= 12;

				if (*_ptr_hours == 12) *_ptr_hours = 0;
				if (*_ptr_minutes == 60) *_ptr_minutes = 0;

				isCorrectData = true;
			}

			else
			{
				showMessageError(2);
			}
		}

		else
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			showMessageError(1);
		}

	} while (!isCorrectData);

	return 0;
}

int calculateAndShowTheDegreesBetweenHands(const int* _PTR_HOURS, const int* _PTR_MINUTES)
{
	double minutesDegrees = (double)*_PTR_MINUTES * (360 / 60);
	double hoursDegrees = (minutesDegrees / 6) * ((2.4 / 5) + 1.02);
	double theDegreesBetweenHands = abs(hoursDegrees - minutesDegrees);

	std::cout << theDegreesBetweenHands << " degrees";

	return 0;
}

int showMessageError(const int _ERROR_NUMBER)
{
	switch (_ERROR_NUMBER)
	{
	case 1: std::cout << "\nWrong input format! Only numbers! Try again" << std::endl;
		break;
	case 2: std::cout << "\nValue of hours can't be over than \"24\" and value of minutes can't be over than \"60\". Try again." << std::endl;
		break;

	default: std::cout << "Unknown error!" << std::endl;
		break;
	}

	return 0;
}
