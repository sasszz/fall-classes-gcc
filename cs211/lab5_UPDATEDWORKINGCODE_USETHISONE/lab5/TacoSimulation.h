// TacoSimulation.h

#ifndef TACO_SIMULATION_H
#define TACO_SIMULATION_H

#include <iostream>
#include <fstream>
#include "Event.h"
#include "ArrayQueue.h"
#include "LinkedSortedList.h"

class TacoSimulation {
public:
    TacoSimulation(); // Constructor
    void simulate(const std::string& filename);

private:
    ArrayQueue<event> tacoLine;
    LinkedSortedList<event> eventPriorityQueue;
    bool cashierAvailable;
    int currentTime;
    int totalWaitTime;
    int numCustomers;

    void processArrival(const event& arrivalEvent, LinkedSortedList<event>& eventPriorityQueue, ArrayQueue<event>& tacoLine);
    void processDeparture(const event& departureEvent, LinkedSortedList<event>& eventPriorityQueue, ArrayQueue<event>& tacoLine);
    void addToEventPriorityQueue(const event& newEvent);
    void printOutput(const event& event, int waitTime);
};

#endif // TACO_SIMULATION_H
