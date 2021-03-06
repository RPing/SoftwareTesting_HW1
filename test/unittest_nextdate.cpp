#include <limits.h>
#include "nextdate.h"
#include "gtest/gtest.h"

// boundary value test(Robust)
TEST(NextDateProblem, BoundaryValueTest) {
    string test;
    EXPECT_STREQ("Invalid date range", nextdate(1811,6,10,test));
    EXPECT_STREQ("1812/6/11", nextdate(1812,6,10,test));
    EXPECT_STREQ("1813/6/11", nextdate(1813,6,10,test));
    EXPECT_STREQ("2011/6/11", nextdate(2011,6,10,test));
    EXPECT_STREQ("2012/6/11", nextdate(2012,6,10,test));
    EXPECT_STREQ("Invalid date range", nextdate(2013,6,10,test));
    EXPECT_STREQ("Invalid date range", nextdate(2000,0,10,test));
    EXPECT_STREQ("2000/1/11", nextdate(2000,1,10,test));
    EXPECT_STREQ("2000/2/11", nextdate(2000,2,10,test));
    EXPECT_STREQ("2000/11/11", nextdate(2000,11,10,test));
    EXPECT_STREQ("2000/12/11", nextdate(2000,12,10,test));
    EXPECT_STREQ("Invalid date range", nextdate(2000,13,10,test));
    EXPECT_STREQ("Invalid date range", nextdate(2000,2,0,test));
    EXPECT_STREQ("2000/2/2", nextdate(2000,2,1,test));
    EXPECT_STREQ("2000/2/3", nextdate(2000,2,2,test));
    EXPECT_STREQ("Invalid input date", nextdate(2000,2,30,test));
    EXPECT_STREQ("Invalid input date", nextdate(2000,2,31,test));
    EXPECT_STREQ("Invalid date range", nextdate(2000,2,32,test));
}

// equivalence class test(StrongNormal)
TEST(NextDateProblem, EquivalenceClassTest) {
    string test;
    EXPECT_STREQ("2000/4/11", nextdate(2000,4,10,test));
    EXPECT_STREQ("2000/4/30", nextdate(2000,4,29,test));
    EXPECT_STREQ("2000/5/1", nextdate(2000,4,30,test));
    EXPECT_STREQ("Invalid input date", nextdate(2000,4,31,test));
    EXPECT_STREQ("2000/3/11", nextdate(2000,3,10,test));
    EXPECT_STREQ("2000/3/30", nextdate(2000,3,29,test));
    EXPECT_STREQ("2000/3/31", nextdate(2000,3,30,test));
    EXPECT_STREQ("2000/4/1", nextdate(2000,3,31,test));
    EXPECT_STREQ("2000/2/11", nextdate(2000,2,10,test));
    EXPECT_STREQ("2000/3/1", nextdate(2000,2,29,test));
    EXPECT_STREQ("Invalid input date", nextdate(2000,2,30,test));
    EXPECT_STREQ("Invalid input date", nextdate(2000,2,31,test));

    EXPECT_STREQ("2005/4/11", nextdate(2005,4,10,test));
    EXPECT_STREQ("2005/4/30", nextdate(2005,4,29,test));
    EXPECT_STREQ("2005/5/1", nextdate(2005,4,30,test));
    EXPECT_STREQ("Invalid input date", nextdate(2005,4,31,test));
    EXPECT_STREQ("2005/3/11", nextdate(2005,3,10,test));
    EXPECT_STREQ("2005/3/30", nextdate(2005,3,29,test));
    EXPECT_STREQ("2005/3/31", nextdate(2005,3,30,test));
    EXPECT_STREQ("2005/4/1", nextdate(2005,3,31,test));
    EXPECT_STREQ("2005/2/11", nextdate(2005,2,10,test));
    EXPECT_STREQ("Invalid input date", nextdate(2005,2,29,test));
    EXPECT_STREQ("Invalid input date", nextdate(2005,2,30,test));
    EXPECT_STREQ("Invalid input date", nextdate(2005,2,31,test));
}

// edge test(WeakNormal)
TEST(NextDateProblem, EdgeTest) {
    string test;
    EXPECT_STREQ("2000/4/2", nextdate(2000,4,1,test));
    EXPECT_STREQ("2000/4/30", nextdate(2000,4,29,test));
    EXPECT_STREQ("2000/5/1", nextdate(2000,4,30,test));
    EXPECT_STREQ("Invalid input date", nextdate(2000,4,31,test));
    EXPECT_STREQ("2000/3/2", nextdate(2000,3,1,test));
    EXPECT_STREQ("2000/3/30", nextdate(2000,3,29,test));
    EXPECT_STREQ("2000/3/31", nextdate(2000,3,30,test));
    EXPECT_STREQ("2000/4/1", nextdate(2000,3,31,test));
    EXPECT_STREQ("2000/2/2", nextdate(2000,2,1,test));
    EXPECT_STREQ("2000/2/29", nextdate(2000,2,28,test));
    EXPECT_STREQ("2000/3/1", nextdate(2000,2,29,test));
    EXPECT_STREQ("Invalid input date", nextdate(2000,2,30,test));
    EXPECT_STREQ("Invalid input date", nextdate(2000,2,31,test));
}

// decision table-based test
TEST(NextDateProblem, DecisionTableTest) {
    string test;
    EXPECT_STREQ("2003/6/16", nextdate(2003,6,15,test));
    EXPECT_STREQ("2003/7/1", nextdate(2003,6,30,test));
    EXPECT_STREQ("Invalid input date", nextdate(2003,6,31,test));
    EXPECT_STREQ("2003/1/16", nextdate(2003,1,15,test));
    EXPECT_STREQ("2003/2/1", nextdate(2003,1,31,test));
    EXPECT_STREQ("2003/12/16", nextdate(2003,12,15,test));
    EXPECT_STREQ("2004/1/1", nextdate(2003,12,31,test));
    EXPECT_STREQ("2003/2/16", nextdate(2003,2,15,test));
    EXPECT_STREQ("2003/3/1", nextdate(2003,2,28,test));
    EXPECT_STREQ("Invalid input date", nextdate(2003,2,29,test));
    EXPECT_STREQ("Invalid input date", nextdate(2003,2,30,test));
    EXPECT_STREQ("2004/2/29", nextdate(2004,2,28,test));
    EXPECT_STREQ("2004/3/1", nextdate(2004,2,29,test));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
