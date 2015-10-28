#include <limits.h>
#include "commission.h"
#include "gtest/gtest.h"

// boundary value test(Robust)
TEST(CommissionProblem, BoundaryValueTest) {
    EXPECT_EQ(-1.0f, commission(-2, 10, 10));
    EXPECT_EQ(0.0f, commission(-1, 10, 10));
    EXPECT_EQ(-1.0f, commission(0, 10, 10));
    EXPECT_EQ(59.5f, commission(1, 10, 10));
    EXPECT_EQ(64.0f, commission(2, 10, 10));
    EXPECT_EQ(100.0f, commission(10, 10, 10));
    EXPECT_EQ(591.0f, commission(69, 10, 10));
    EXPECT_EQ(600.0f, commission(70, 10, 10));
    EXPECT_EQ(609.0f, commission(71, 10, 10));
    EXPECT_EQ(-1.0f, commission(10, 0, 10));
    EXPECT_EQ(73.0f, commission(10, 1, 10));
    EXPECT_EQ(76.0f, commission(10, 2, 10));
    EXPECT_EQ(474.0f, commission(10, 79, 10));
    EXPECT_EQ(480.0f, commission(10, 80, 10));
    EXPECT_EQ(-1.0f, commission(10, 81, 10));
    EXPECT_EQ(-1.0f, commission(10, 10, 0));
    EXPECT_EQ(77.5f, commission(10, 10, 1));
    EXPECT_EQ(80.0f, commission(10, 10, 2));
    EXPECT_EQ(455.0f, commission(10, 10, 89));
    EXPECT_EQ(460.0f, commission(10, 10, 90));
    EXPECT_EQ(465.0f, commission(10, 10, 91));
}

// equivalence class test(WeakRobust)
TEST(CommissionProblem, EquivalenceClassTest) {
    EXPECT_EQ(660.0f, commission(40, 40, 40));
    EXPECT_EQ(-1.0f, commission(-1, 10, 10));
    EXPECT_EQ(-1.0f, commission(0, 10, 10));
    EXPECT_EQ(-1.0f, commission(71, 10, 10));
    EXPECT_EQ(-1.0f, commission(10, 0, 10));
    EXPECT_EQ(-1.0f, commission(10, 81, 10));
    EXPECT_EQ(-1.0f, commission(10, 10, 0));
    EXPECT_EQ(-1.0f, commission(10, 10, 91));
}

// edge test(WeakRobust)
TEST(CommissionProblem, EdgeTest) {
    EXPECT_EQ(-1.0f, commission(-3, 10, 10));
    EXPECT_EQ(-1.0f, commission(-2, 10, 10));
    EXPECT_EQ(0.0f, commission(-1, 10, 10));
    EXPECT_EQ(-1.0f, commission(0, 10, 10));
    EXPECT_EQ(59.5f, commission(1, 10, 10));
    EXPECT_EQ(64.0f, commission(2, 10, 10));
    EXPECT_EQ(591.0f, commission(69, 10, 10));
    EXPECT_EQ(600.0f, commission(70, 10, 10));
    EXPECT_EQ(609.0f, commission(71, 10, 10));
    EXPECT_EQ(618.0f, commission(72, 10, 10));
    EXPECT_EQ(-1.0f, commission(10, -1, 10));
    EXPECT_EQ(-1.0f, commission(10, 0, 10));
    EXPECT_EQ(73.0f, commission(10, 1, 10));
    EXPECT_EQ(76.0f, commission(10, 2, 10));
    EXPECT_EQ(474.0f, commission(10, 79, 10));
    EXPECT_EQ(480.0f, commission(10, 80, 10));
    EXPECT_EQ(-1.0f, commission(10, 81, 10));
    EXPECT_EQ(492.0f, commission(10, 82, 10));
    EXPECT_EQ(-1.0f, commission(10, 10, -1));
    EXPECT_EQ(-1.0f, commission(10, 10, 0));
    EXPECT_EQ(77.5f, commission(10, 10, 1));
    EXPECT_EQ(80.0f, commission(10, 10, 2));
    EXPECT_EQ(455.0f, commission(10, 10, 89));
    EXPECT_EQ(460.0f, commission(10, 10, 90));
    EXPECT_EQ(465.0f, commission(10, 10, 91));
    EXPECT_EQ(470.0f, commission(10, 10, 92));
}

// decision table-based test (the same as equivalence class test)
TEST(CommissionProblem, DecisionTableTest) {
    EXPECT_EQ(660.0f, commission(40, 40, 40));
    EXPECT_EQ(-1.0f, commission(-1, 10, 10));
    EXPECT_EQ(-1.0f, commission(0, 10, 10));
    EXPECT_EQ(-1.0f, commission(71, 10, 10));
    EXPECT_EQ(-1.0f, commission(10, 0, 10));
    EXPECT_EQ(-1.0f, commission(10, 81, 10));
    EXPECT_EQ(-1.0f, commission(10, 10, 0));
    EXPECT_EQ(-1.0f, commission(10, 10, 91));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
