#include <iostream>
#include <iomanip>

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
void purgeInvalidInput(std::string error_mess);

int main() {
	int month, day, year;
	bool is_valid_year, is_valid_month, is_valid_day;
	
	std::cout << "Enter a month, day, and year between 1-1-1980 and 12-31-2107: ";
	std::cin >> month >> day >> year;

	// Check if the input operation failed and handle accordingly
	if (!std::cin) {
		purgeInvalidInput("\nError: Invalid Input\n");
	}
	else {
		is_valid_year = isValidYear(year);
		is_valid_month = isValidMonth(month);
		is_valid_day = isValidDay(day, month, year);

		if (is_valid_year && is_valid_month && is_valid_day) {
			// Bits 0-4: Day, Bits 5-8: Month, Bits 9-15: Year
			short int fatDate = ((year - MIN_YEAR) << 9) | (month << 5) | day;
			std::cout << "The hexadecimal FAT date is: " << std::hex << std::uppercase << std::setfill('0') << std::setw(WIDTH) << fatDate << std::endl;
		}
		else {
			if (!is_valid_month) {
				std::cout << "\nError: Invalid Month";
			}
			if (!is_valid_day) {
				std::cout << "\nError: Invalid Day";
			}
			if (!is_valid_year) {
				std::cout << "\nError: Invalid Year";
			}
			std::cout << std::endl;
		}
	}

	std::cout << "\nTerminating Program...\n";
	return 0;
}

bool isValidYear(int year) {
	return (year >= MIN_YEAR && year <= MAX_YEAR);
}

bool isLeapYear(int year) {
	// A year is a leap year if it is divisible by 4, but years divisible by 100 are not leap years unless they are also divisible by 400
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
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

void purgeInvalidInput(std::string error_mess) {
	std::cout << error_mess << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}