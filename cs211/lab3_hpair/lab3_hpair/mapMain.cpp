//
//  mapMain.cpp
//  CSIS2
//
//  Created by Tony Biehl on 10/4/21.
//

#include <iostream>
#include "Map.hpp"

using namespace std;

int main()
{
    Map hpAir;
    string filename;

    // ask for filename
    hpAir.readCityFile(filename);
    // ask for filename
    hpAir.readFlightFile(filename);
    // ask for filename
    hpAir.readRequestFile(filename);
    /**

     */
}
