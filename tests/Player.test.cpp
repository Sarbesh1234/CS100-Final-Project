#include "gtest/gtest.h"
#include "Player.hpp" 

TEST(PlayerTest, ConstructorSetsName) {
  Player player(PieceColor::WHITE, "Alice");
  EXPECT_EQ(player.getName(), "Alice");
}

TEST(PlayerTest, ConstructorSetsColor) {
  Player player(PieceColor::BLACK, "Bob");
  EXPECT_EQ(player.getColor(), BLACK);
}

TEST(PlayerTest, EmptyConstructorAllowed) {
  Player player;
  EXPECT_EQ(player.getName(), "");
  EXPECT_EQ(player.getColor(), PieceColor::WHITE);
}