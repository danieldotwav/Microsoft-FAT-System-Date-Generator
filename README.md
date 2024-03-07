## Overview

This C++ program validates a user-entered date to ensure it falls within the range of January 1, 1980, to December 31, 2107. It also converts valid dates into a FAT (File Allocation Table) date format, represented in hexadecimal.

## Features

- Validates year, month, and day input by the user.
- Checks for leap years to ensure accurate day validation for February.
- Converts valid dates into FAT date format (Hexadecimal representation).

## How It Works

1. **Input**: The user is prompted to enter a date comprising a month, day, and year.
2. **Validation**: The program checks if the entered year is between 1980 and 2107, if the month is between 1 and 12, and if the day is valid for the given month and year.
3. **FAT Date Conversion**: If the date is valid, it is converted into FAT date format. This format encodes the date as a short integer where bits 0-4 represent the day, bits 5-8 represent the month, and bits 9-15 represent the year offset from 1980.
4. **Output**: Displays the FAT date in hexadecimal format or an error message for invalid inputs.

## Functions

- `bool isValidYear(int year)`: Validates if the year is within the allowable range.
- `bool isLeapYear(int year)`: Checks if the year is a leap year.
- `bool isValidMonth(int month)`: Validates if the month is within the allowable range.
- `int getDaysInMonth(int month, int year)`: Determines the number of days in the given month and year, taking into account leap years.
- `bool isValidDay(int day, int month, int year)`: Validates if the day is within the allowable range for the given month and year.
- `void purgeInvalidInput(std::string error_mess)`: Clears the input buffer and displays an error message in case of invalid input.

## Limitations

- This program is specifically designed to work with dates between January 1, 1980, and December 31, 2107.
- It does not account for time zones or historical changes in the calendar system.
