//
//  Map.cpp
//  CSIS
//
//  Created by Tony Biehl on 9/28/21. Updated 10/13/22
//

#include "Map.hpp"
#include "ArrayStack.hpp"


#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Map::Map() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            flightMap[i][j] = false;
    unvisitAll();
    numCities = 0;
}

void Map::unvisitAll() {
    for (int i = 0; i < MAX; i++)
        visited[i] = false;
}

City Map::getNextCity(City cur){
    City nextCity = NO_CITY;
    for (int i = 0; nextCity == NO_CITY && i < MAX; i++){
        if (!isVisited(i) && flightMap[cur][i]){
            nextCity = i;
            markVisited(i);
        }
    }
    return nextCity;
}

void Map::markVisited(City visit){
    if (visit >= 0 && visit < MAX)
        visited[visit] = true;
}

bool Map::isVisited(City visit) {
    if (visit >= 0 && visit < MAX)
        return visited[visit];
    return false;
}

void Map::chop(string& c){
    int len = c.length();
    if (len > 0 && c[len-1] < ' ')
        c = c.substr(0,len-1);
}

bool Map::isPath(City originCity, City destinationCity){
    ArrayStack<City> cityStack;
    
    unvisitAll();
    
    cityStack.push(originCity);
    markVisited(originCity);
    
    City topCity = cityStack.peek();
    
    while (!cityStack.isEmpty() && (topCity != destinationCity)) {
        City nextCity = getNextCity(topCity);
        
        if (nextCity == NO_CITY)
            cityStack.pop();
        else {
            cityStack.push(nextCity);
            markVisited (nextCity);
        }
        if (!cityStack.isEmpty())
            topCity = cityStack.peek();
    }
    return !cityStack.isEmpty();
}

City Map::convert(string city){
    for (City i = 0; i < numCities; i++) {
        if (cityName[i] == city) {
            return i;
        }
    }
    return NO_CITY;
}

bool Map::readCityFile(string cityFile){
    // read list of cities
    ifstream infile(cityFile);  // Open the input file
    if (!infile.is_open()) {
        cerr << "Error: Unable to open the city file" << endl;
        return false;
    }
    
    numCities = 0;  // Initialize the number of cities to 0
    
    // Read cities from the file and assign them an index in ArrayStack
    string city;
    while (getline(infile, city)) {
        chop(city);  // Remove leading/trailing white spaces
//        cout << city << endl;
        // Add the city to the ArrayStack and assign an index
        cityName[numCities] = city;
        numCities++;
    }
    
    infile.close();  // Close the input file
    return true;
}


bool Map::readFlightFile(string flightFile){
    // read parse pairs and commas - create map
    /**
     while(getline(infile>>ws, city1, ',')){
     getline(infile>>ws, city2);
     chop(city2);
     ... do something with city1 and city2
     }
     */
    
    ifstream infile(flightFile);  // Open the flight file
    if (!infile.is_open()) {
        cerr << "Error: Unable to open the flight file" << endl;
        return false;
    }
    
    // Read and parse pairs of cities separated by commas
    string city1, city2;
    while (getline(infile, city1, ',')) {
        getline(infile >> ws, city2); // removes whitespace
        chop(city2);  // Remove leading/trailing white spaces
        
        // Check if the cities are valid (i.e., in your cityName array)
        City index1 = convert(city1);
        City index2 = convert(city2);
        
        if (index1 != NO_CITY && index2 != NO_CITY) {
            // Add the flight route to the flightMap
            flightMap[index1][index2] = true;
        } else {
            cout << city1 << " " << city2 << endl;
            cerr << "Error: Invalid city names in the flight file" << endl;
        }
    }
    
    infile.close();  // Close the flight file
    return true;
}


bool Map::readRequestFile(string requestFile) {
    ifstream infile(requestFile);  // Open the request file
    if (!infile.is_open()) {
        cerr << "Error: Unable to open the request file" << endl;
        return false;
    }

    // Read and parse pairs of cities in the request file
    string city1, city2;
    while (getline(infile, city1, ',')) {
        getline(infile >> ws, city2);
        chop(city2);  // Remove leading/trailing white spaces

        // Check if the cities are valid (i.e., in your cityName array)
        City index1 = convert(city1);
        City index2 = convert(city2);

        if (index1 != NO_CITY && index2 != NO_CITY) {
            // Check if there is a valid flight route between the cities
            if (isPath(index1, index2)) {
                cout << city1 << " to " << city2 << " is a valid route." << endl;
            } else {
                cout << city1 << " to " << city2 << " is not a valid route." << endl;
            }
        } else {
            cerr << "Error: Invalid city names in the request file" << endl;
        }
    }

    infile.close();  // Close the request file
    return true;
}
