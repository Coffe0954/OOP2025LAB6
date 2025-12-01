#ifndef NPC_FACTORY_H
#define NPC_FACTORY_H

#include "../npc/npc.h"
#include <memory>
#include <string>

class NPCFactory {
public:
    static std::shared_ptr<NPC> createNPC(const std::string& type, 
                                         const std::string& name, 
                                         int x, int y);
    
    static std::shared_ptr<NPC> loadNPC(std::ifstream& file);
};

#endif