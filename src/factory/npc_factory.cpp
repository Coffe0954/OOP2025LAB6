#include "npc_factory.h"
#include "../npc/bear.h"
#include "../npc/werewolf.h"
#include "../npc/bandit.h"
#include <sstream>

std::shared_ptr<NPC> NPCFactory::createNPC(const std::string& type, 
                                          const std::string& name, 
                                          int x, int y) {
    if (x < 0 || x > 500 || y < 0 || y > 500) {
        throw std::invalid_argument("Coordinates must be in range 0-500");
    }
    
    if (type == "Bear") {
        return std::make_shared<Bear>(name, x, y);
    } else if (type == "Werewolf") {
        return std::make_shared<Werewolf>(name, x, y);
    } else if (type == "Bandit") {
        return std::make_shared<Bandit>(name, x, y);
    }
    
    throw std::invalid_argument("Unknown NPC type: " + type);
}

std::shared_ptr<NPC> NPCFactory::loadNPC(std::ifstream& file) {
    std::string type, name;
    int x, y;
    
    if (file >> type >> name >> x >> y) {
        return createNPC(type, name, x, y);
    }
    
    return nullptr;
}