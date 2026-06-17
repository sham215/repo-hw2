
#include "Pirate.h"


Pirate::Pirate(const string& name , int bounty): name(name), Bounty(bounty) {}


void Pirate::setName(const string& name){
    this->name = name;
}


std::string Pirate::getName(){
    return name;
}
void Pirate::setBounty(int bounty){
  Bounty = bounty;
}
int Pirate::getBounty(){
  return Bounty;
}
std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name << " (Bounty: " << pirate.Bounty << ")";

    return os;
}
