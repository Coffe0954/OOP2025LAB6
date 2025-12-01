#include "bandit.h"
#include "bear.h"
#include <iostream>

Bandit::Bandit(const std::string& name, int x, int y) : name(name), x(x), y(y) {}

void Bandit::print() const {
    std::cout << "Bandit " << name << " at (" << x << ", " << y << ")" << std::endl;
}

std::string Bandit::getName() const { return name; }
std::string Bandit::getType() const { return "Bandit"; }
int Bandit::getX() const { return x; }
int Bandit::getY() const { return y; }

void Bandit::save(std::ofstream& file) const {
    file << "Bandit " << name << " " << x << " " << y << std::endl;
}

bool Bandit::isClose(const std::shared_ptr<NPC>& other, int distance) const {
    return calculateDistance(x, y, other->getX(), other->getY()) <= distance;
}

bool Bandit::accept(const std::shared_ptr<NPC>& visitor) const {
    //разбойники убивают медведей
    return visitor->getType() == "Bear";
}