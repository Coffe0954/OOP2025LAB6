#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "npc.h"

class Werewolf : public NPC {
private:
    std::string name;
    int x, y;

public:
    Werewolf(const std::shared_ptr<NPC>& other, int x, int y);
    Werewolf(const std::string& name, int x, int y);
    
    void print() const override;
    std::string getName() const override;
    std::string getType() const override;
    int getX() const override;
    int getY() const override;
    
    void save(std::ofstream& file) const override;
    bool isClose(const std::shared_ptr<NPC>& other, int distance) const override;
    bool accept(const std::shared_ptr<NPC>& visitor) const override;
};

#endif