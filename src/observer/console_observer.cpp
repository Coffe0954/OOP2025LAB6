#include "console_observer.h"
#include <iostream>

void ConsoleObserver::onKill(const std::shared_ptr<NPC>& killer, 
                            const std::shared_ptr<NPC>& victim) {
    std::cout << "[BATTLE] " << killer->getType() << " " << killer->getName()
              << " killed " << victim->getType() << " " << victim->getName() 
              << std::endl;
}