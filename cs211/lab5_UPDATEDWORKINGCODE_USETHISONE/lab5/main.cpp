//
//  main.cpp
//  lab5
//
//  Created by Lucie Chevreuil on 11/16/23.
//
//  main.cpp

#include <iostream>
#include <fstream>
#include "TacoSimulation.h"

using namespace std;

int main() {
    // Create an instance of TacoSimulation
    TacoSimulation tacoSim;

    // Specify the input file name
    string filename = "tacofryinput.txt"; // Change this to your input file name

    // Run the simulation
    tacoSim.simulate(filename);

    return 0;
}
