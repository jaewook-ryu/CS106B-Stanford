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
#include "random.h"
#include <iostream>
#include <fstream>

using namespace std;


string grammarHelper(string result, string symbol, Set<string>& leftSymbol,
                     Map<string, Vector<string>>& grammar){

    cout << symbol << endl;

    if(leftSymbol.contains(symbol)){
        Vector<string> rule = grammar.get(symbol);
        cout << "rule: " << rule << endl;


        Vector<string> choices = stringSplit(rule[1], "|");
        int randomChoice =randomInteger(0, choices.size());

        cout << randomChoice << endl;
        cout << choices[randomChoice] << endl;

        result += grammarHelper(result, choices[randomChoice], leftSymbol, grammar);

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
    Map<string, Vector<string>> grammar;
    Set<string> leftSymbol;


    string line;
    while(getline(input, line)){
        Vector<string> lineSplit;
        Vector<string> ruleSplit;

        lineSplit = stringSplit(line, "::=");
        ruleSplit = stringSplit(lineSplit[1], " ");

        cout << ruleSplit << endl;

        if(leftSymbol.contains(lineSplit[0])){
            throw("two lines for same non-terminal");
        }

        leftSymbol.add(lineSplit[0]);
        grammar.add(lineSplit[0], ruleSplit);
    }

    //cout << grammar << endl;
    //cout << leftSymbol << endl;

    for(int i=0;i<times;i++){
        string result = "";
        grammarHelper(result, symbol, leftSymbol, grammar);
        expansion.add(result);
    }

    return expansion;           // This is only here so it will compile
}


