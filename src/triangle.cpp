#include "triangle.h"

const char *triangle(int a, int b, int c, string str) {
    if ((a >= 1 && a <= 200) &&
        (b >= 1 && b <= 200) &&
        (c >= 1 && c <= 200)) {
        if ((a + b <= c) || (b + c <= a) || (a + c <= b)) {
            str = "Not a triangle";
            //strcat(str, "Not a triangle");
        } else if ((a == b) && (b == c)) {
            str = "Equilateral";
            //strcat(str, "Equilateral");
        } else if ((a == b) || (b == c) || (a == c)) {
            str = "Isosceles";
            //strcat(str, "Isosceles");
        } else {
            str = "Scalene";
            //strcat(str, "Scalene");
        }

    } else {
        str = "Out of range";
        //strcat(str, "Out of range");
    }
    return str.c_str();
}
