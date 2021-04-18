/*
 * File: grammarsolver.cpp
 * --------------------------
 * Name:
 * Section leader:
 * This file contains grammar generating code for CS106B.
 */

#include "grammarsolver.h"

#include "stdio.h"
#include "strlib.h"
#include "map.h"
#include "vector.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Generates grammar for a given symbol a certain number of times given
 * a BNF input file.
 *
 * This will be called by grammarmain.cpp.
 *
 * @param input - Input stream of BNF file.
 * @param symbol - Symbol to generate
 * @param times - Number of times grammar is generated
 * @return Vector of strings of size times with random generations of symbol
 */
Vector<string> grammarGenerate(ifstream& input, string symbol, int times) {
    // Part 1: Read all of the inputs
    string line;
    Map<string, Vector<string>> grammar;

    while(getline(input, line)){
        Vector<string> lineSplit;
        lineSplit = stringSplit(line, " ");
        cout << lineSplit << endl;
    }

    return {};           // This is only here so it will compile
}
