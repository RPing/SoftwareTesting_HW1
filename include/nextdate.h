#ifndef NEXTDATE_H_
#define NEXTDATE_H_

#include <string>
using namespace std;
void format_string(int year, int month, int day, string &str);
bool IsLeapYear(int year);
bool IsSolarMonth(int month);
const char *nextdate(int year, int month, int day, string str);

#endif  // NEXTDATE_H_
