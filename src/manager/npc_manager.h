#ifndef NPC_MANAGER_H
#define NPC_MANAGER_H

#include "../npc/npc.h"
#include "../observer/observer.h"
#include <vector>
#include <memory>
#include <string>

class NPCManager {
private:
    std::vector<std::shared_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void addNPC(const std::shared_ptr<NPC>& npc);
    void printAll() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void battle(int range);
    void addObserver(const std::shared_ptr<Observer>& observer);
    size_t getNPCCount() const;
    
private:
    void notifyKill(const std::shared_ptr<NPC>& killer, 
                   const std::shared_ptr<NPC>& victim);
};

#endif