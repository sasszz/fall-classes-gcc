// Event.cpp

#include "Event.h"

event::event() : eType(' '), eTime(0), eTrans(0) {}

event::event(char etp, int etm, int etrn) : eType(etp), eTime(etm), eTrans(etrn) {}

void event::set(char etp, int etm, int etrn) {
    eType = etp;
    eTime = etm;
    eTrans = etrn;
}

char event::getEType() const {
    return eType;
}

int event::getETime() const {
    return eTime;
}

int event::getETrans() const {
    return eTrans;
}

bool event::operator==(const event second) const {
    return eTime == second.eTime;
}

bool event::operator>(const event second) const {
    return eTime > second.eTime;
}

bool event::operator<(const event second) const {
    return eTime < second.eTime;
}

bool event::operator!=(const event second) const {
    return eTime != second.eTime;
}

std::ostream& operator<<(std::ostream& out, const event& e) {
    out << e.eType << " " << e.eTime << " " << e.eTrans;
    return out;
}
