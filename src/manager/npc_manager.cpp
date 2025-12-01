#include "npc_manager.h"
#include "../factory/npc_factory.h"
#include "../visitor/battle_visitor.h"
#include <fstream>
#include <algorithm>
#include <iostream>

void NPCManager::addNPC(const std::shared_ptr<NPC>& npc) {
    npcs.push_back(npc);
}

void NPCManager::printAll() const {
    std::cout << "NPCs in dungeon (" << npcs.size() << " total):" << std::endl;
    for (const auto& npc : npcs) {
        npc->print();
    }
}

void NPCManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
    
    for (const auto& npc : npcs) {
        npc->save(file);
    }
    
    file.close();
}

void NPCManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
    
    npcs.clear();
    while (file.peek() != EOF) {
        auto npc = NPCFactory::loadNPC(file);
        if (npc) {
            npcs.push_back(npc);
        }
    }
    
    file.close();
}

void NPCManager::battle(int range) {
    std::cout << "Starting battle with range " << range << "..." << std::endl;
    
    auto it = npcs.begin();
    while (it != npcs.end()) {
        auto it2 = it + 1;
        while (it2 != npcs.end()) {
            // 1 атакует 2
            if (BattleVisitor::fight(*it, *it2, range)) {
                notifyKill(*it, *it2);
                it2 = npcs.erase(it2);
                continue;
            }
            
            // 2 атакует 1
            if (BattleVisitor::fight(*it2, *it, range)) {
                notifyKill(*it2, *it);
                it = npcs.erase(it);
                break;
            }
            
            ++it2;
        }
        
        if (it != npcs.end()) {
            ++it;
        }
    }
    
    std::cout << "Battle finished. Survivors: " << npcs.size() << std::endl;
}

void NPCManager::addObserver(const std::shared_ptr<Observer>& observer) {
    observers.push_back(observer);
}

size_t NPCManager::getNPCCount() const {
    return npcs.size();
}

void NPCManager::notifyKill(const std::shared_ptr<NPC>& killer, 
                           const std::shared_ptr<NPC>& victim) {
    for (const auto& observer : observers) {
        observer->onKill(killer, victim);
    }
}