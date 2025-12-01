#ifndef NPC_H
#define NPC_H

#include <string>
#include <memory>
#include <fstream>

class NPC {
public:
    virtual ~NPC() = default;
    
    virtual void print() const = 0;
    virtual std::string getName() const = 0;
    virtual std::string getType() const = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    
    virtual void save(std::ofstream& file) const = 0;
    virtual bool isClose(const std::shared_ptr<NPC>& other, int distance) const = 0;
    virtual bool accept(const std::shared_ptr<NPC>& visitor) const = 0;
    
    static double calculateDistance(int x1, int y1, int x2, int y2);
};

#endif