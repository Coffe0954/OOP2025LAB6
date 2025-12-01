#ifndef BATTLE_VISITOR_H
#define BATTLE_VISITOR_H

#include "../npc/npc.h"
#include <memory>

class BattleVisitor {
public:
    static bool fight(const std::shared_ptr<NPC>& attacker, 
                     const std::shared_ptr<NPC>& defender, 
                     int range);
};

#endif