#include <iostream>
#include <iomanip>
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

void purgeInvalidInput(string error_mess);

int main() {
	int year, month, day;
	char user_selection = 'Y';
	bool is_valid_year, is_valid_month, is_valid_day;

	while (user_selection == 'Y' || user_selection == 'y') {
		cout << "Enter a month, day, and year between 1-1-1980 and 12-31-2107: ";
		cin >> month >> day >> year;

		// Check if the input operation failed and handle accordingly
		if (!cin) {
			purgeInvalidInput("\nError: Invalid Input\n");
		}
		else {
			is_valid_year = isValidYear(year);
			is_valid_month = isValidMonth(month);
			is_valid_day = isValidDay(day, month, year);

			if (is_valid_year && is_valid_month && is_valid_day) {
				// Once the date is fully validated, we can perform the conversion to store date using Microsoft FAT system date
				short int fatDate = ((year - MIN_YEAR) << 9) | (month << 5) | day;
				cout << "The hexadecimal FAT date is: " << hex << uppercase << setfill('0') << setw(4) << fatDate << endl;
			}
			else {
				if (!is_valid_month) {
					cout << "\nError: Invalid Month\n";
				}
				if (!is_valid_day) {
					cout << "\nError: Invalid Day\n";
				}
				if (!is_valid_year) {
					cout << "\nError: Invalid Year\n";
				}
			}
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

void purgeInvalidInput(string error_mess) {
	cout << error_mess << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}