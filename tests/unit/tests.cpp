#include <gtest/gtest.h>
#include <vector>
#include "realisation.hpp"

TEST(MainTest, test_advance) {
    std::vector<int> a = {1, 2, 3, 4, 5};
    EXPECT_EQ(advance_(a.begin(), 1), a.begin()+1);
}

TEST(MainTest, test_lower_bound) {
    const std::vector<int> data = {1, 2, 4, 5, 5, 6};
    auto lower = lower_bound_(data.begin(), data.end(), 0);
    EXPECT_EQ(*lower, 1);
}

TEST(MainTest, test_upper_bound) {
    const std::vector<int> data = {1, 2, 4, 5, 5, 6};
    auto upper = upper_bound_(data.begin(), data.end(), 0);
    EXPECT_EQ(*upper, 1);
}

TEST(MainTest, test_binary_search) {
    const std::vector<int> data = {1, 2, 4, 5, 5, 6};
    EXPECT_EQ(binary_search_(data.begin(), data.end(), 4),1);
}