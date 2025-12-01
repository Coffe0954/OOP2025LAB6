#include "bear.h"
#include "werewolf.h"
#include <iostream>

Bear::Bear(const std::string& name, int x, int y) : name(name), x(x), y(y) {}

void Bear::print() const {
    std::cout << "Bear " << name << " at (" << x << ", " << y << ")" << std::endl;
}

std::string Bear::getName() const { return name; }
std::string Bear::getType() const { return "Bear"; }
int Bear::getX() const { return x; }
int Bear::getY() const { return y; }

void Bear::save(std::ofstream& file) const {
    file << "Bear " << name << " " << x << " " << y << std::endl;
}

bool Bear::isClose(const std::shared_ptr<NPC>& other, int distance) const {
    return calculateDistance(x, y, other->getX(), other->getY()) <= distance;
}

bool Bear::accept(const std::shared_ptr<NPC>& visitor) const {
    //медведи убивают оборотней
    return visitor->getType() == "Werewolf";
}