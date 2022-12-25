#include <gtest/gtest.h>
#include <vector>
#include "realisation.hpp"

TEST(MainTest, test_distance) {
    std::vector<int> a = {1, 2, 3, 4, 5};
    EXPECT_EQ(distance_(a.begin(), a.end()), a.size());
}

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

TEST(MainTest, test_equal_range) {
    const std::vector<int> data = {1, 2, 4, 5, 5, 6};
    auto res = equal_range_(data.begin(), data.end(), 4);
    EXPECT_EQ(*res.first, 4);
    EXPECT_EQ(*res.second, 4);
}

TEST(MainTest, test_merge) {
    std::vector<int> data = {1, 3, 5};
    std::vector<int> data1 = {2, 4, 6};
    std::vector<int> dst;
    merge_(data.begin(), data.end(), data1.begin(), data1.end(), std::back_inserter(dst));
    EXPECT_EQ(dst.size(), 6);
    std::vector<int> merged_vec = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < data.size() + data1.size(); ++i) {
        EXPECT_EQ(dst[i], merged_vec[i]);
    }
}