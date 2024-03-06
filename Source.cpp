#include <iostream>
using namespace std;

const int MIN_MONTH = 1;
const int MAX_MONTH = 12;
const int MIN_DAY = 1;
const int MAX_DAY = 31;
const int MIN_YEAR = 1980;
const int MAX_YEAR = 2107;
const int INVALID = -1;

bool isValidYear(int year);
bool isLeapYear(int year);
bool isValidMonth(int month);
int getDaysInMonth(int month, int year);
bool isValidDay(int day, int month, int year);

int main() {
	int year, month, day;
	char user_selection = 'Y';
	int num_days;

	while (user_selection == 'Y' || user_selection == 'y') {
		cout << "Enter Year (1980 - 2107)\n>> ";
		cin >> year;

		// Get the year
		if (isValidYear(year)) {
			// Get the month
			cout << "\nEnter Month (1 - 12)\n>>";
			cin >> month;

			if (isValidMonth(month)) {
				// Get the day
				cout << "Enter Day (1 - 31)\n>>";
				cin >> day;

				if (isValidDay(day, month, year)) {
					// Once the date is fully validated, we can perform the conversion to store date using Microsoft FAT system date

				}
				else {
					cout << "\nError: Invalid Day\n";
				}
			}
			else {
				cout << "\nError: Invalid Month\n";
			}
		}
		else {
			cout << "\nError: Invalid Year\n";
		}

		cout << "\nWould you like to run the program again?\nEnter 'Y' for Yes, Enter 'N' to Exit\n>>";
		cin >> user_selection;

		while (user_selection != 'Y' && user_selection != 'y' && user_selection != 'N' && user_selection != 'n') {
			cout << "\nError: Invalid Selection\n";

			cout << "\nWould you like to run the program again?\nEnter 'Y' for Yes, Enter 'N' to Exit\n>>";
			cin >> user_selection;
		}
	}
	return 0;
}

bool isValidYear(int year) {
	return (year >= MIN_YEAR && year <= MAX_YEAR);
}

bool isLeapYear(int year) {
	return year % 4 == 0;
}

bool isValidMonth(int month) {
	return (month >= 1 && month <= 12);
}

int getDaysInMonth(int month, int year) {
	int days = 0;
	switch (month) {
		case 1:
			days = 31;
			break;
		case 2:
			if (isLeapYear(year)) {
				days = 29;
			}
			else {
				days = 28;
			}
			break;
		case 3:
			days = 31;
			break;
		case 4:
			days = 30;
			break;
		case 5:
			days = 31;
			break;
		case 6:
			days = 30;
			break;
		case 7:
			days = 31;
			break;
		case 8:
			days = 31;
			break;
		case 9:
			days = 30;
			break;
		case 10:
			days = 31;
			break;
		case 11:
			days = 30;
			break;
		case 12:
			days = 31;
			break;
		default:
			days = INVALID;
			cout << "\nError: Unable To Determine Days In Specified Month/Year\n";
	}
	return days;
}

bool isValidDay(int day, int month, int year) {
	int num_days_in_given_month = getDaysInMonth(month, year);
	return (day >= MIN_DAY && day <= num_days_in_given_month);
}