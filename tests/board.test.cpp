#include "gtest/gtest.h"

#include "../header/Board.hpp"

TEST(BoardTest, HelloWorld) {
  EXPECT_EQ(1, 1);
}

TEST(BoardTest, FailTest) {
  EXPECT_EQ(12, 1);
}