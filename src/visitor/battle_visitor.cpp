#include "battle_visitor.h"

bool BattleVisitor::fight(const std::shared_ptr<NPC>& attacker, 
                         const std::shared_ptr<NPC>& defender, 
                         int range) {
    // проверяем расстояние
    if (!attacker->isClose(defender, range)) {
        return false;
    }
    
    // проверяем, может ли атакующий убить защитника
    if (attacker->accept(defender)) {
        return true;
    }
    
    return false;
}