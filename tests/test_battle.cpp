#include <gtest/gtest.h>
#include "../src/factory/npc_factory.h" 
#include "../src/manager/npc_manager.h"
#include "../src/observer/console_observer.h"

TEST(BattleTest, BattleMechanics) {
    NPCManager manager;
    manager.addObserver(std::make_shared<ConsoleObserver>());
    
    //добавляем NPC (близко друг к другу)
    manager.addNPC(NPCFactory::createNPC("Bear", "Bear1", 10, 10));
    manager.addNPC(NPCFactory::createNPC("Werewolf", "Wolf1", 11, 11));
    
    size_t initialCount = manager.getNPCCount();
    manager.battle(5); //достаточная дальность
    
    //один должен быть убит
    EXPECT_LT(manager.getNPCCount(), initialCount);
}

TEST(BattleTest, NoBattleWhenFar) {
    NPCManager manager;
    manager.addObserver(std::make_shared<ConsoleObserver>());
    
    //добавляем NPC далеко друг от друга
    manager.addNPC(NPCFactory::createNPC("Bear", "Bear1", 10, 10));
    manager.addNPC(NPCFactory::createNPC("Werewolf", "Wolf1", 400, 400));
    
    size_t initialCount = manager.getNPCCount();
    manager.battle(10); //недостаточная дальность
    
    // Все живчики
    EXPECT_EQ(manager.getNPCCount(), initialCount);
}