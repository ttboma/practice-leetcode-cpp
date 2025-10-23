#include "gtest/gtest.h"
#include "solution.hpp"

TEST(copyRandomList, example1) {
    RandomList original_list({{"7", "null"}, {"13", "0"}, {"11", "4"}, {"10", "2"}, {"1", "0"}});
    auto copied_head = Solution{}.copyRandomList(original_list.getHead());
    RandomList copied_list(copied_head);
    EXPECT_EQ(original_list, copied_list);
}

TEST(copyRandomList, example2) {
    RandomList original_list({{"1", "1"}, {"2", "1"}});
    auto copied_head = Solution{}.copyRandomList(original_list.getHead());
    RandomList copied_list(copied_head);
    EXPECT_EQ(original_list, copied_list);
}

TEST(copyRandomList, example3) {
    RandomList original_list({{"3", "null"}, {"3", "0"}, {"3", "null"}});
    auto copied_head = Solution{}.copyRandomList(original_list.getHead());
    RandomList copied_list(copied_head);
    EXPECT_EQ(original_list, copied_list);
}
