#include <gtest/gtest.h>
#include "../src/npc/bear.h"
#include "../src/npc/werewolf.h"
#include "../src/npc/bandit.h"

TEST(NPCTest, CreationAndProperties) {
    Bear bear("Bear1", 10, 20);
    EXPECT_EQ(bear.getName(), "Bear1");
    EXPECT_EQ(bear.getType(), "Bear");
    EXPECT_EQ(bear.getX(), 10);
    EXPECT_EQ(bear.getY(), 20);
    
    Werewolf wolf("Wolf1", 30, 40);
    EXPECT_EQ(wolf.getName(), "Wolf1");
    EXPECT_EQ(wolf.getType(), "Werewolf");
    
    Bandit bandit("Bandit1", 50, 60);
    EXPECT_EQ(bandit.getName(), "Bandit1");
    EXPECT_EQ(bandit.getType(), "Bandit");
}

TEST(NPCTest, DistanceCalculation) {
    Bear bear("Bear1", 0, 0);
    Werewolf wolf("Wolf1", 3, 4);
    
    EXPECT_TRUE(bear.isClose(std::make_shared<Werewolf>(wolf), 5));
    EXPECT_FALSE(bear.isClose(std::make_shared<Werewolf>(wolf), 4));
}

TEST(NPCTest, BattleRules) {
    //медведи убивают оборотней
    Bear bear("Bear1", 0, 0);
    Werewolf wolf("Wolf1", 1, 1);
    EXPECT_TRUE(bear.accept(std::make_shared<Werewolf>(wolf)));
    
    //ооротни убивают разбойников
    Werewolf wolf2("Wolf2", 0, 0);
    Bandit bandit("Bandit1", 1, 1);
    EXPECT_TRUE(wolf2.accept(std::make_shared<Bandit>(bandit)));
    
    //разбойники убивают медведей
    Bandit bandit2("Bandit2", 0, 0);
    Bear bear2("Bear2", 1, 1);
    EXPECT_TRUE(bandit2.accept(std::make_shared<Bear>(bear2)));
}