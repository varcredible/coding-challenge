#include <iostream>
using namespace std;

int getHoursAndMinutesFromUser(int* _ptr_hours, int* _ptr_minutes);
int calculateAndShowTheDegrees(const int* _PTR_HOURS, const int* _PTR_MINUTES);
int showErrorMessage(const int _ERRORNUMBER);

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
		cout << "Enter hours: ";
		cin >> *_ptr_hours;
		cout << "Enter minutes: ";
		cin >> *_ptr_minutes;

		if (!cin.fail())
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
				showErrorMessage(2);
			}
		}

		else
		{
			cin.clear();
			cin.ignore(32767, '\n');
			showErrorMessage(1);
		}

	} while (!isCorrectData);

	return 0;
}

int calculateAndShowTheDegrees(const int* _PTR_HOURS, const int* _PTR_MINUTES)
{
	double minutesDegrees = (double)*_PTR_MINUTES * (360 / 60); // 6 degrees per an minutes
	double hoursDegrees = ((double)*_PTR_HOURS * 30); //30 degrees per an hour
	double theDegreesBetweenHands = abs(hoursDegrees - minutesDegrees);

	cout << theDegreesBetweenHands << " degree";

	return 0;
}

int showErrorMessage(const int _ERROR_NUMBER)
{
	switch (_ERROR_NUMBER)
	{
	case 1: cout << "\nWrong input format! Only numbers! Try again" << endl;
		break;
	case 2: cout << "\nValue of hours can't be over than \"24\" and value of minutes can't be over than \"60\". Try again." << endl;
		break;

	default: cout << "Unknown error!" << endl;
		break;
	}

	return 0;
}
