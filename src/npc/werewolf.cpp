#include "werewolf.h"
#include "bandit.h"
#include <iostream>

Werewolf::Werewolf(const std::string& name, int x, int y) : name(name), x(x), y(y) {}

void Werewolf::print() const {
    std::cout << "Werewolf " << name << " at (" << x << ", " << y << ")" << std::endl;
}

std::string Werewolf::getName() const { return name; }
std::string Werewolf::getType() const { return "Werewolf"; }
int Werewolf::getX() const { return x; }
int Werewolf::getY() const { return y; }

void Werewolf::save(std::ofstream& file) const {
    file << "Werewolf " << name << " " << x << " " << y << std::endl;
}

bool Werewolf::isClose(const std::shared_ptr<NPC>& other, int distance) const {
    return calculateDistance(x, y, other->getX(), other->getY()) <= distance;
}

bool Werewolf::accept(const std::shared_ptr<NPC>& visitor) const {
    //оборотни убивают разбойников
    return visitor->getType() == "Bandit";
}