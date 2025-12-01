#include "file_observer.h"

FileObserver::FileObserver() {
    logFile.open("log.txt", std::ios::app);
}

FileObserver::~FileObserver() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void FileObserver::onKill(const std::shared_ptr<NPC>& killer, 
                         const std::shared_ptr<NPC>& victim) {
    if (logFile.is_open()) {
        logFile << "[BATTLE] " << killer->getType() << " " << killer->getName()
                << " killed " << victim->getType() << " " << victim->getName() 
                << std::endl;
    }
}