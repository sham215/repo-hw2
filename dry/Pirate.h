
#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    int Bounty ;
public:
    Pirate(const string& name , int bounty);
    Pirate() = default;
    ~Pirate() = default;

    void setName(const string& name);
    void setBounty (int bounty);
    string getName();
     int getBounty();
    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);

};
