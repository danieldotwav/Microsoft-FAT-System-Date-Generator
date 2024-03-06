#include <iostream>
#include <iomanip>
using namespace std;

const int MIN_MONTH = 1;
const int MAX_MONTH = 12;
const int MIN_DAY = 1;
const int MIN_YEAR = 1980;
const int MAX_YEAR = 2107;
const int INVALID = -1;
const int WIDTH = 4;

enum MONTH { 
	JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, 
	JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, 
	DECEMBER
};

bool isValidYear(int year);
bool isLeapYear(int year);
bool isValidMonth(int month);
int getDaysInMonth(int month, int year);
bool isValidDay(int day, int month, int year);

void purgeInvalidInput(string error_mess);

int main() {
	int month, day, year;
	bool is_valid_year, is_valid_month, is_valid_day;
	
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
			cout << "The hexadecimal FAT date is: " << hex << uppercase << setfill('0') << setw(WIDTH) << fatDate << endl;
		}
		else {
			if (!is_valid_month) {
				cout << "\nError: Invalid Month";
			}
			if (!is_valid_day) {
				cout << "\nError: Invalid Day";
			}
			if (!is_valid_year) {
				cout << "\nError: Invalid Year";
			}
			cout << endl;
		}
	}

	cout << "\nTerminating Program...\n";
	return 0;
}

bool isValidYear(int year) {
	return (year >= MIN_YEAR && year <= MAX_YEAR);
}

bool isLeapYear(int year) {
	return year % 4 == 0;
}

bool isValidMonth(int month) {
	return (month >= MIN_MONTH && month <= MAX_MONTH);
}

int getDaysInMonth(int month, int year) {
	int days = 0;
	switch (month) {
		case JANUARY:
			days = 31;
			break;
		case FEBRUARY:
			if (isLeapYear(year)) {
				days = 29;
			}
			else {
				days = 28;
			}
			break;
		case MARCH:
			days = 31;
			break;
		case APRIL:
			days = 30;
			break;
		case MAY:
			days = 31;
			break;
		case JUNE:
			days = 30;
			break;
		case JULY:
			days = 31;
			break;
		case AUGUST:
			days = 31;
			break;
		case SEPTEMBER:
			days = 30;
			break;
		case OCTOBER:
			days = 31;
			break;
		case NOVEMBER:
			days = 30;
			break;
		case DECEMBER:
			days = 31;
			break;
		default:
			days = INVALID;
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