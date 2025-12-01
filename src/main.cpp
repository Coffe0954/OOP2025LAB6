#include <iostream>
#include <memory>
#include "manager/npc_manager.h"
#include "factory/npc_factory.h"
#include "observer/console_observer.h"
#include "observer/file_observer.h"

void demonstrate() {
    NPCManager manager;
    
    //наблюдатели
    manager.addObserver(std::make_shared<ConsoleObserver>());
    manager.addObserver(std::make_shared<FileObserver>());
    
    std::cout << "=== Dungeon Editor for Balagur Fate 3 ===" << std::endl;

    //NPC
    std::cout << "\n1. Adding NPCs..." << std::endl;
    manager.addNPC(NPCFactory::createNPC("Bear", "Bear1", 10, 10));
    manager.addNPC(NPCFactory::createNPC("Werewolf", "Wolf1", 15, 15));
    manager.addNPC(NPCFactory::createNPC("Bandit", "Bandit1", 20, 20));
    manager.addNPC(NPCFactory::createNPC("Bear", "Bear2", 100, 100));
    manager.addNPC(NPCFactory::createNPC("Werewolf", "Wolf2", 200, 200));
    manager.addNPC(NPCFactory::createNPC("Bandit", "Bandit2", 300, 300));
    
    manager.printAll();
    
    std::cout << "\n2. Saving to file..." << std::endl;
    manager.saveToFile("dungeon.txt");
    
    std::cout << "\n3. Loading from file..." << std::endl;
    NPCManager manager2;
    manager2.addObserver(std::make_shared<ConsoleObserver>());
    manager2.addObserver(std::make_shared<FileObserver>());
    manager2.loadFromFile("dungeon.txt");
    manager2.printAll();
    
    //бой с маленькой дальностью
    std::cout << "\n4. Battle with range 10..." << std::endl;
    manager2.battle(10);
    manager2.printAll();
    
    //бой с большой дальностью
    std::cout << "\n5. Battle with range 500..." << std::endl;
    NPCManager manager3;
    manager3.addObserver(std::make_shared<ConsoleObserver>());
    manager3.addObserver(std::make_shared<FileObserver>());
    manager3.loadFromFile("dungeon.txt");
    manager3.battle(500);
    manager3.printAll();
}

int main() {
    try {
        demonstrate();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}