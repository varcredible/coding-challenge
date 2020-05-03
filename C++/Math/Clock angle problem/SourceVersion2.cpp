// The more accurate version //
// The hour hand is moves regarding of the minute hand //

#include <iostream>

int getHoursAndMinutesFromUser(int* _ptr_hours, int* _ptr_minutes);
int calculateAndShowTheDegrees(const int* _PTR_HOURS, const int* _PTR_MINUTES);
int showMessageError(const int _ERRORNUMBER);

int main()
{
	int hours = 0, minutes = 0, * ptr_hours = &hours, * ptr_minutes = &minutes;

	getHoursAndMinutesFromUser(ptr_hours, ptr_minutes);
	calculateAndShowTheDegrees(ptr_hours, ptr_minutes);

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

int calculateAndShowTheDegrees(const int* _PTR_HOURS, const int* _PTR_MINUTES)
{
	double minutesDegrees = (double)*_PTR_MINUTES * (360 / 60); // 6 degrees per an minutes
	double hoursDegrees = ((double)*_PTR_HOURS * 30) + ((minutesDegrees / (30 * 2.4)) * 6); //30 degree per an hour. Every 2.4 hours is 5 minutes
	double theDegreesBetweenHands = abs(hoursDegrees - minutesDegrees);

	std::cout << theDegreesBetweenHands << " degree";

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
