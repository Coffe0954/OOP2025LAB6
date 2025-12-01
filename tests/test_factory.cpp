#include <gtest/gtest.h>
#include "../src/factory/npc_factory.h"

TEST(FactoryTest, NPCCreation) {
    auto bear = NPCFactory::createNPC("Bear", "Bear1", 10, 20);
    EXPECT_EQ(bear->getType(), "Bear");
    EXPECT_EQ(bear->getName(), "Bear1");
    
    auto wolf = NPCFactory::createNPC("Werewolf", "Wolf1", 30, 40);
    EXPECT_EQ(wolf->getType(), "Werewolf");
    
    auto bandit = NPCFactory::createNPC("Bandit", "Bandit1", 50, 60);
    EXPECT_EQ(bandit->getType(), "Bandit");
}

TEST(FactoryTest, InvalidCoordinates) {
    EXPECT_THROW(NPCFactory::createNPC("Bear", "Bear1", -1, 10), std::invalid_argument);
    EXPECT_THROW(NPCFactory::createNPC("Bear", "Bear1", 10, 600), std::invalid_argument);
}

TEST(FactoryTest, InvalidType) {
    EXPECT_THROW(NPCFactory::createNPC("Dragon", "Dragon1", 10, 10), std::invalid_argument);
}