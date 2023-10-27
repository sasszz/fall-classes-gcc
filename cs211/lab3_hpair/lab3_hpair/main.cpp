//
//  mapMain.hpp
//  lab3
//
//  Created by Lucie Chevreuil on 10/19/23.
//  Created by Tony Biehl on 9/28/21. Updated 10/13/22
//

#include <iostream>
#include <string>

#include "Map.hpp"

using namespace std;
using namespace std;

int main() {
    Map map;

    string cityFile, flightFile, requestFile;

    // Read the city file
    cout << "Enter the city file name: ";
    cin >> cityFile;

    if (!map.readCityFile(cityFile)) {
        cerr << "Error reading the city file. Exiting.\n";
        return 1;
    }

    // Read the flight file
    cout << "Enter the flight file name: ";
    cin >> flightFile;

    if (!map.readFlightFile(flightFile)) {
        cerr << "Error reading the flight file. Exiting.\n";
        return 1;
    }

    // Read and check routes from the request file
    cout << "Enter the request file name: ";
    cin >> requestFile;

    if (!map.readRequestFile(requestFile)) {
        cerr << "Error reading the request file. Exiting.\n";
        return 1;
    }

    return 0;
}
