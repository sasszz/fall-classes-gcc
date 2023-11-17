//
//  Event.hpp
//  lab5
//
//  Created by Lucie Chevreuil on 11/16/23.
//

#ifndef EVENT_HPP
#define EVENT_HPP

#pragma once
#include <iostream>

using std::ostream;

class event
{
private:
    char eType;
    int eTime;
    int eTrans;

public:
    event();
    event(char etp, int etm, int etrn);
    void set(char etp, int etm, int etrn);
    char getEType();
    int getETime();
    int getETrans();
    bool operator==(const event second);
    bool operator<(const event second);
    bool operator>(const event second);
    bool operator!=(const event second);
    friend ostream& operator<<(ostream& out, const event& e);
};

#endif /* Event_hpp */
