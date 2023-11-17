#include "TacoSimulation.h"
#include "ArrayQueue.h"
#include "LinkedSortedList.h"
#include "Event.h"

using namespace std;

TacoSimulation::TacoSimulation() : cashierAvailable(true), totalWaitTime(0), numCustomers(0) {
}

void TacoSimulation::simulate(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    cout << "Taco Fry drive-in" << endl;

    // Taco line
    ArrayQueue<event> tacoLine;

    // Event queue
    LinkedSortedList<event> eventPriorityQueue;

    cashierAvailable = true;

    // Create and add arrival to event queue
    while (!inputFile.eof()) {
        char eventType = 'A';
        int arrivalTime, transactionTime;
        inputFile >> arrivalTime >> transactionTime;
        event newArrivalEvent(eventType, arrivalTime, transactionTime);
        eventPriorityQueue.insertSorted(newArrivalEvent);
    }
    
    // Event loop
    while (!eventPriorityQueue.isEmpty()) {
        // ##################################################
        // TESTING PURPOSES
        // Print the contents of linkedSortedList
//        cout << "Linked Sorted List: ";
//        for (int i = 1; i <= eventPriorityQueue.getLength(); ++i) {
//            try {
//                event currentEvent = eventPriorityQueue.getEntry(i);
//                cout << currentEvent.getEType() << "-" << currentEvent.getETime() << "-" << currentEvent.getETrans() << " || ";
//            } catch (const PrecondViolatedExcep& e) {
//                // Handle exception (e.g., print an error message)
//                cerr << e.what() << endl;
//            }
//        }
//        cout << endl;
//        cout << endl;
        // ##################################################

        event newEvent = eventPriorityQueue.getEntry(1);
        
        // Get current time
        currentTime = newEvent.getETime();

        if (newEvent.getEType() == 'A') {
            processArrival(newEvent, eventPriorityQueue, tacoLine);
        } else {
            processDeparture(newEvent, eventPriorityQueue, tacoLine);
        }

    }
    // Print the average wait time
    cout << "Average wait time was " << static_cast<double>(totalWaitTime) / numCustomers << endl;
}

void TacoSimulation::processArrival(const event& arrivalEvent, LinkedSortedList<event>& eventPriorityQueue, ArrayQueue<event>& tacoLine) {
    cout << "new event " << arrivalEvent.getEType() << " " << arrivalEvent.getETime()
              << " " << arrivalEvent.getETrans() << endl;

    // Remove this event from the event queue
    eventPriorityQueue.remove(1);
    
    // customer = customer referenced in arrivalEvent
    event customer = arrivalEvent;

    if (tacoLine.isEmpty() && cashierAvailable) {
        int departureTime = currentTime + arrivalEvent.getETrans();
        event newDepartureEvent('D', departureTime, 0);
        eventPriorityQueue.insertSorted(newDepartureEvent);
        cashierAvailable = false;
    } else {
        tacoLine.enqueue(customer);
        // ##################################################
        // TESTING PURPOSES
        // Print the contents of arrayqueue
//        ArrayQueue<event> tempQueue = tacoLine;
//        cout << "Taco Line Array Queue: ";
//        while (!tempQueue.isEmpty()) {
//            try {
//                event currentEvent = tempQueue.peekFront();
//                cout << currentEvent.getEType() << "-" << currentEvent.getETime() << "-" << currentEvent.getETrans() << " || ";
//                tempQueue.dequeue(); // Remove the front element after printing from tempQueue
//            } catch (const PrecondViolatedExcep& e) {
//                // Handle exception (e.g., print an error message)
//                cerr << e.what() << endl;
//            }
//        }
//        cout << endl;
        // ##################################################
    }
}

void TacoSimulation::processDeparture(const event& departureEvent, LinkedSortedList<event>& eventPriorityQueue, ArrayQueue<event>& tacoLine) {
    
    // Handle Last Event
    if (tacoLine.isEmpty() && eventPriorityQueue.getLength() == 1) {
        cout << "new event " << departureEvent.getEType() << " " << currentTime << endl;
        numCustomers++;
    }
    
    // Remove this event from the event queue
    eventPriorityQueue.remove(1);

    if (!tacoLine.isEmpty()) {
        // Customer at the front of the line begins the transaction
        event customer = tacoLine.peekFront();
        tacoLine.dequeue();

        int waitTime = currentTime - customer.getETime();
        totalWaitTime += waitTime;
        numCustomers++;

        cout << "new event " << departureEvent.getEType() << " " << currentTime << endl;
        cout << "Customer at time " << customer.getETime() << " had to wait " << waitTime << endl;

        int departureTime = currentTime + customer.getETrans();
        event newDepartureEvent('D', departureTime, 0);
        eventPriorityQueue.insertSorted(newDepartureEvent);
    } else {
        cashierAvailable = true;
    }
}
