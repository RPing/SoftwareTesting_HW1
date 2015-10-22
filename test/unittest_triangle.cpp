#include <limits.h>
#include "triangle.h"
#include "gtest/gtest.h"

// boundary value test
TEST(BoundaryValueTest, NormalRobust) {
    string test;
    EXPECT_STREQ("Out of range", triangle(50,50,0,test));
    EXPECT_STREQ("Isosceles", triangle(50,50,1,test));
    EXPECT_STREQ("Isosceles", triangle(50,50,2,test));
    EXPECT_STREQ("Equilateral", triangle(50,50,50,test));
    EXPECT_STREQ("Not a triangle", triangle(50,50,199,test));
    EXPECT_STREQ("Not a triangle", triangle(50,50,200,test));
    EXPECT_STREQ("Out of range", triangle(50,50,201,test));
    EXPECT_STREQ("Out of range", triangle(50,0,50,test));
    EXPECT_STREQ("Isosceles", triangle(50,1,50,test));
    EXPECT_STREQ("Isosceles", triangle(50,2,50,test));
    EXPECT_STREQ("Equilateral", triangle(50,50,50,test));
    EXPECT_STREQ("Not a triangle", triangle(50,199,50,test));
    EXPECT_STREQ("Not a triangle", triangle(50,200,50,test));
    EXPECT_STREQ("Out of range", triangle(50,201,50,test));
    EXPECT_STREQ("Out of range", triangle(0,50,50,test));
    EXPECT_STREQ("Isosceles", triangle(1,50,50,test));
    EXPECT_STREQ("Isosceles", triangle(2,50,50,test));
    EXPECT_STREQ("Equilateral", triangle(50,50,50,test));
    EXPECT_STREQ("Not a triangle", triangle(199,50,50,test));
    EXPECT_STREQ("Not a triangle", triangle(200,50,50,test));
    EXPECT_STREQ("Out of range", triangle(201,50,50,test));
}

// equivalence class test
TEST(EquivalenceClassTest, StrongRobust) {
    string test;
    EXPECT_STREQ("Equilateral", triangle(50,50,50,test));
    EXPECT_STREQ("Isosceles", triangle(50,50,40,test));
    EXPECT_STREQ("Isosceles", triangle(50,40,50,test));
    EXPECT_STREQ("Isosceles", triangle(40,50,50,test));
    EXPECT_STREQ("Scalene", triangle(40,50,30,test));
    EXPECT_STREQ("Scalene", triangle(30,50,40,test));
    EXPECT_STREQ("Scalene", triangle(50,40,30,test));
    EXPECT_STREQ("Scalene", triangle(50,30,40,test));
    EXPECT_STREQ("Scalene", triangle(30,40,50,test));
    EXPECT_STREQ("Scalene", triangle(40,30,50,test));
    EXPECT_STREQ("Not a triangle", triangle(20,10,10,test));
    EXPECT_STREQ("Not a triangle", triangle(10,20,10,test));
    EXPECT_STREQ("Not a triangle", triangle(10,10,20,test));
    EXPECT_STREQ("Out of range", triangle(0,50,50,test));
    EXPECT_STREQ("Out of range", triangle(50,0,50,test));
    EXPECT_STREQ("Out of range", triangle(50,50,0,test));
    EXPECT_STREQ("Out of range", triangle(0,0,50,test));
    EXPECT_STREQ("Out of range", triangle(0,50,0,test));
    EXPECT_STREQ("Out of range", triangle(50,0,0,test));
    EXPECT_STREQ("Out of range", triangle(0,0,0,test));
    EXPECT_STREQ("Out of range", triangle(201,50,50,test));
    EXPECT_STREQ("Out of range", triangle(50,201,50,test));
    EXPECT_STREQ("Out of range", triangle(50,50,201,test));
    EXPECT_STREQ("Out of range", triangle(201,201,50,test));
    EXPECT_STREQ("Out of range", triangle(201,50,201,test));
    EXPECT_STREQ("Out of range", triangle(50,201,201,test));
    EXPECT_STREQ("Out of range", triangle(201,201,201,test));
}

// edge test
TEST(EdgeTest, WeakNormal) {
    string test;
    EXPECT_STREQ("Equilateral", triangle(1,1,1,test));
    EXPECT_STREQ("Equilateral", triangle(200,200,200,test));
    EXPECT_STREQ("Isosceles", triangle(2,2,1,test));
    EXPECT_STREQ("Isosceles", triangle(2,1,2,test));
    EXPECT_STREQ("Isosceles", triangle(1,2,2,test));
    EXPECT_STREQ("Isosceles", triangle(1,200,200,test));
    EXPECT_STREQ("Isosceles", triangle(199,200,200,test));
    EXPECT_STREQ("Scalene", triangle(2,6,7,test));
    EXPECT_STREQ("Scalene", triangle(2,199,200,test));
    EXPECT_STREQ("Scalene", triangle(199,2,200,test));
    EXPECT_STREQ("Scalene", triangle(199,200,2,test));
    EXPECT_STREQ("Not a triangle", triangle(199,200,1,test));
    EXPECT_STREQ("Not a triangle", triangle(1,1,2,test));
    EXPECT_STREQ("Not a triangle", triangle(1,1,8,test));
    EXPECT_STREQ("Not a triangle", triangle(1,199,200,test));
    EXPECT_STREQ("Not a triangle", triangle(199,1,200,test));
    EXPECT_STREQ("Not a triangle", triangle(199,200,1,test));
    EXPECT_STREQ("Not a triangle", triangle(1,2,200,test));
}

// decision table-based test
TEST(DecisionTableTest, DecisionTableTest) {
    string test;
    EXPECT_STREQ("Not a triangle", triangle(3,1,2,test));
    EXPECT_STREQ("Not a triangle", triangle(1,3,2,test));
    EXPECT_STREQ("Not a triangle", triangle(1,2,3,test));
    EXPECT_STREQ("Equilateral", triangle(4,4,4,test));
    EXPECT_STREQ("Isosceles", triangle(198,198,199,test));
    EXPECT_STREQ("Isosceles", triangle(198,199,198,test));
    EXPECT_STREQ("Isosceles", triangle(199,198,198,test));
    EXPECT_STREQ("Scalene", triangle(4,5,6,test));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
