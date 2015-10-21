#include <limits.h>
#include "triangle.h"
#include "gtest/gtest.h"

// boundary value test
TEST(BoundaryValueTest, NormalRobust) {
    EXPECT_STREQ("Out of range", triangle(50,50,0));
    EXPECT_STREQ("Isosceles", triangle(50,50,1));
    EXPECT_STREQ("Isosceles", triangle(50,50,2));
    EXPECT_STREQ("Equilateral", triangle(50,50,50));
    EXPECT_STREQ("Not a triangle", triangle(50,50,199));
    EXPECT_STREQ("Not a triangle", triangle(50,50,200));
    EXPECT_STREQ("Out of range", triangle(50,50,201));
    EXPECT_STREQ("Out of range", triangle(50,0,50));
    EXPECT_STREQ("Isosceles", triangle(50,1,50));
    EXPECT_STREQ("Isosceles", triangle(50,2,50));
    EXPECT_STREQ("Equilateral", triangle(50,50,50));
    EXPECT_STREQ("Not a triangle", triangle(50,199,50));
    EXPECT_STREQ("Not a triangle", triangle(50,200,50));
    EXPECT_STREQ("Out of range", triangle(50,201,50));
    EXPECT_STREQ("Out of range", triangle(0,50,50));
    EXPECT_STREQ("Isosceles", triangle(1,50,50));
    EXPECT_STREQ("Isosceles", triangle(2,50,50));
    EXPECT_STREQ("Equilateral", triangle(50,50,50));
    EXPECT_STREQ("Not a triangle", triangle(199,50,50));
    EXPECT_STREQ("Not a triangle", triangle(200,50,50));
    EXPECT_STREQ("Out of range", triangle(201,50,50));
}

// equivalence class test
TEST(EquivalenceClassTest, StrongRobust) {
    EXPECT_STREQ("Equilateral", triangle(50,50,50));
    EXPECT_STREQ("Isosceles", triangle(50,50,40));
    EXPECT_STREQ("Isosceles", triangle(50,40,50));
    EXPECT_STREQ("Isosceles", triangle(40,50,50));
    EXPECT_STREQ("Scalene", triangle(40,50,30));
    EXPECT_STREQ("Scalene", triangle(30,50,40));
    EXPECT_STREQ("Scalene", triangle(50,40,30));
    EXPECT_STREQ("Scalene", triangle(50,30,40));
    EXPECT_STREQ("Scalene", triangle(30,40,50));
    EXPECT_STREQ("Scalene", triangle(40,30,50));
    EXPECT_STREQ("Not a triangle", triangle(20,10,10));
    EXPECT_STREQ("Not a triangle", triangle(10,20,10));
    EXPECT_STREQ("Not a triangle", triangle(10,10,20));
    EXPECT_STREQ("Out of range", triangle(0,50,50));
    EXPECT_STREQ("Out of range", triangle(50,0,50));
    EXPECT_STREQ("Out of range", triangle(50,50,0));
    EXPECT_STREQ("Out of range", triangle(0,0,50));
    EXPECT_STREQ("Out of range", triangle(0,50,0));
    EXPECT_STREQ("Out of range", triangle(50,0,0));
    EXPECT_STREQ("Out of range", triangle(0,0,0));
    EXPECT_STREQ("Out of range", triangle(201,50,50));
    EXPECT_STREQ("Out of range", triangle(50,201,50));
    EXPECT_STREQ("Out of range", triangle(50,50,201));
    EXPECT_STREQ("Out of range", triangle(201,201,50));
    EXPECT_STREQ("Out of range", triangle(201,50,201));
    EXPECT_STREQ("Out of range", triangle(50,201,201));
    EXPECT_STREQ("Out of range", triangle(201,201,201));
}

// edge test
TEST(EdgeTest, WeakNormal) {
    EXPECT_STREQ("Equilateral", triangle(1,1,1));
    EXPECT_STREQ("Equilateral", triangle(200,200,200));
    EXPECT_STREQ("Isosceles", triangle(2,2,1));
    EXPECT_STREQ("Isosceles", triangle(2,1,2));
    EXPECT_STREQ("Isosceles", triangle(1,2,2));
    EXPECT_STREQ("Isosceles", triangle(1,200,200));
    EXPECT_STREQ("Isosceles", triangle(199,200,200));
    EXPECT_STREQ("Scalene", triangle(2,6,7));
    EXPECT_STREQ("Scalene", triangle(2,199,200));
    EXPECT_STREQ("Scalene", triangle(199,2,200));
    EXPECT_STREQ("Scalene", triangle(199,200,2));
    EXPECT_STREQ("Scalene", triangle(199,200,1));
    EXPECT_STREQ("Not a triangle", triangle(1,1,2));
    EXPECT_STREQ("Not a triangle", triangle(1,1,8));
    EXPECT_STREQ("Not a triangle", triangle(1,199,200));
    EXPECT_STREQ("Not a triangle", triangle(199,1,200));
    EXPECT_STREQ("Not a triangle", triangle(199,200,1));
    EXPECT_STREQ("Not a triangle", triangle(1,2,200));
}

// decision table-based test
TEST(DecisionTableTest, DecisionTableTest) {
    // TODO
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
