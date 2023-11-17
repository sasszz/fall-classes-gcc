// Event.h

#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class event {
public:
    event();
    event(char etp, int etm, int etrn);
    void set(char etp, int etm, int etrn);
    char getEType() const;  // Marked as const
    int getETime() const;   // Marked as const
    int getETrans() const;  // Marked as const
    bool operator==(const event second) const;  // Marked as const
    bool operator>(const event second) const;   // Marked as const
    bool operator<(const event second) const;   // Marked as const
    bool operator!=(const event second) const;  // Marked as const

    friend std::ostream& operator<<(std::ostream& out, const event& e);

private:
    char eType;
    int eTime;
    int eTrans;
};

#endif // EVENT_H
