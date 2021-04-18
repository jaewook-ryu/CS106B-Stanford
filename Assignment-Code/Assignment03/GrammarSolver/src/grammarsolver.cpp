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
#include "set.h"
#include "vector.h"
#include <iostream>
#include <fstream>

using namespace std;


string grammarHelper(string result, string symbol, Set<string>& leftSymbol, Map<string, string>& grammar){

    cout << symbol << endl;

    if(leftSymbol.contains(symbol)){
        string rule = grammar.get(symbol);
        Vector<string> rules = stringSplit(rule, " ");

        for(int i=0;i<rules.size();i++){
            grammarHelper(result, rules[i], leftSymbol, grammar);
        }

    } else{
        // when this is a terminal symbol (base case)
        return symbol;
    }

    return "";
}

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

    Vector<string> expansion;
    Map<string, string> grammar;
    Set<string> leftSymbol;


    string line;
    while(getline(input, line)){
        Vector<string> lineSplit;
        lineSplit = stringSplit(line, "::=");

        string key = lineSplit[0];
        string val = lineSplit[1];

        leftSymbol.add(key);
        grammar.add(key, val);
    }

    //cout << grammar << endl;
    //cout << leftSymbol << endl;

    for(int i=0;i<times;i++){
        string result;
        grammarHelper(result, symbol, leftSymbol, grammar);
        expansion.add(result);
    }

    return expansion;           // This is only here so it will compile
}


