#include "gtest/gtest.h"
#include "Player.hpp" 

TEST(PlayerTest, ConstructorSetsName) {
  Player player("White", "Alice");
  EXPECT_EQ(player.name, "Alice");
}

TEST(PlayerTest, ConstructorSetsColor) {
  Player player("Black", "Bob");
  EXPECT_EQ(player.color, "Black");
}

TEST(PlayerTest, EmptyConstructorAllowed) {
  Player player;
  EXPECT_TRUE(player.name.empty());
  EXPECT_TRUE(player.color.empty());
}