#include "nextdate.h"
#include <iostream>

void format_string(int year, int month, int day, string &str) {
    str = to_string(year) + "/" + to_string(month) + "/" + to_string(day);
}

bool IsLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if ((year % 4 == 0) && (year % 100 != 0)) {
        return true;
    } else {
        return false;
    }
}
bool IsSolarMonth(int month) {
    if (month <= 7) {
        if (month % 2 == 0)
            return false;
        else
            return true;
    } else {
        if (month % 2 == 0)
            return true;
        else
            return false;
    }
}
const char *nextdate(int year, int month, int day, string str) {
    if (year < 1812 || year > 2012)
        return "Invalid date range";
    if (month > 12 || month < 1)
        return "Invalid date range";
    if (day > 31 || day < 1)
        return "Invalid date range";
    if (IsLeapYear(year)) {
        if (month == 12 && day == 31)
            year += 1;
        if (month == 2) {
            if (day == 29) {
                month += 1;
                day = 1;
            } else if (day < 29) {
                day += 1;
            } else {
                return "Invalid input date";
            }
        } else if (IsSolarMonth(month)) {
            if (day == 31) {
                if (month == 12)
                    month = 1;
                else
                    month += 1;
                day = 1;
            } else {
                day += 1;
            }
        } else {
            if (day == 30) {
                month += 1;
                day = 1;
            } else if (day < 30) {
                day += 1;
            } else {
                return "Invalid input date";
            }
        }
    } else {
        if (month == 12 && day == 31)
            year += 1;
        if (month == 2) {
            if (day == 28) {
                month += 1;
                day = 1;
            } else if (day < 28) {
                day += 1;
            } else {
                return "Invalid input date";
            }
        } else if (IsSolarMonth(month)) {
            if (day == 31) {
                if (month == 12)
                    month = 1;
                else
                    month += 1;
                day = 1;
            } else {
                day += 1;
            }
        } else {
            if (day == 30) {
                month += 1;
                day = 1;
            } else if (day < 30) {
                day += 1;
            } else {
                return "Invalid input date";
            }
        }
    }
    format_string(year, month, day, str);
    return str.c_str();
}
