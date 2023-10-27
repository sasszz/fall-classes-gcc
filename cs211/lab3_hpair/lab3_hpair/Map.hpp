//
//  Map.hpp
//  CSIS
//
//  Created by Tony Biehl on 9/28/21.
//

#include <string>

using std::string;

#ifndef Map_hpp
#define Map_hpp

typedef int City;

const City NO_CITY = -1;
const int MAX = 50;

class Map
{
private:
    bool visited[MAX];
    string cityName[MAX];
    bool flightMap[MAX][MAX];
    int numCities;
    City convert(string);
public:
    Map();
    void markVisited(City);
    void unvisitAll();
    bool isPath(City, City);
    City getNextCity(City);
    void chop(string&);
    bool isVisited(City);
    bool readCityFile(string);
    bool readFlightFile(string);
    bool readRequestFile(string);
};

#endif /* Map_hpp */

