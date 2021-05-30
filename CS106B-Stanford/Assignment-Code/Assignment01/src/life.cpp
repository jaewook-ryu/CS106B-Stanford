// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header!

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
#include "lifegui.h"
using namespace std;

void nextGrid(Grid<string>& grid, string wrapAround);
void printGrid(Grid<string>& grid);
void getNeighborGrid(Grid<string>& gridInput, Grid<string>& gridNeighbor, string wrapAround);
void updateGUI(Grid<string>& grid, LifeGUI& gui);

string calculateNeighborUnwrapped(Grid<string>& grid, int row, int col);
string calculateNeighborWrapped(Grid<string>& grid, int row, int col);

int main() {
    // Prompt user for a file name
    ifstream stream;
    promptUserForFile(stream, "Grid input file name? ");

    // Get parameters for grid
    string rowString, colString;
    getline(stream, rowString);
    getline(stream, colString);

    Grid<string> grid(stringToInteger(rowString), stringToInteger(colString));

    string tempRows;

    for(int i=0;i<grid.numRows();i++){
        getline(stream, tempRows);

        for(int j=0;j<grid.numCols();j++){
            grid[i][j] = tempRows[j];
        }
    }

    stream.close();
    printGrid(grid);


    // Ask if simulation should wrap around the grid
    string wrapAround;
    while(true){
        cout << "Should the simulation wrap around the grid (y/n)?";
        cin >> wrapAround;

        if(wrapAround == "y" || wrapAround == "n"){
            break;
        }
    }

    //printGrid(gridNeighbor);

    // Add GUI
    LifeGUI name;
    name.resize(grid.numRows(), grid.numCols());

    // Now simulate the animate/tick/quit part
    string nextStep;

    do{
        while(true){
            cout << "a)nimate, t)ick, q)uit? ";
            cin >> nextStep;
            nextStep = toLowerCase(nextStep);

            if(nextStep == "a" || nextStep == "t" || nextStep == "q"){
                break;
            }
        }

        if(nextStep == "a"){
            // implement here!

            string framesString;
            int frames;

            while(true){
                cout << "How many frames? ";
                cin >> framesString;

                if(stringIsInteger(framesString)){
                    frames = stringToInteger(framesString);
                    break;
                } else{
                    cout << "Illegal integer format. Try again." << endl;
                }
            }


            // now animate!
            for(int i=0;i<frames;i++){
                clearConsole();
                nextGrid(grid, wrapAround);
                printGrid(grid);
                updateGUI(grid, name);
                pause(50);
            }

        }

        if(nextStep == "t"){
            // implement here!
            nextGrid(grid, wrapAround);
            printGrid(grid);
            updateGUI(grid, name);

        }

    } while(nextStep != "q");


    cout << "Have a nice Life!" << endl;

    return 0;
}


void updateGUI(Grid<string>& grid, LifeGUI& gui){
    for(int i=0;i<grid.numRows();i++){
        for(int j=0;j<grid.numCols();j++){
            bool alive = (grid[i][j] == "X");
            gui.drawCell(i, j, alive);
        }
    }
}

void nextGrid(Grid<string>& grid, string wrapAround){
    // Calcuate grid that contains neighbor for each cell.
    Grid<string> gridNeighbor(grid.numRows(), grid.numCols());
    getNeighborGrid(grid, gridNeighbor, wrapAround);

    // Update current grid by the rules.
    for(int i=0;i<gridNeighbor.numRows();i++){
        for(int j=0;j<gridNeighbor.numCols();j++){
            // Many cases of neighbors
            int neighbor = stringToInteger(gridNeighbor[i][j]);

            if(neighbor == 0 || neighbor == 1){
                grid[i][j] = "-";
            } else if(neighbor == 2){
                continue;
            } else if(neighbor == 3){
                grid[i][j] = "X";
            } else{
                grid[i][j] = "-";
            }
        }
    }
}

// Obtain the grid of strings that contain the neighbors to each cell.
void getNeighborGrid(Grid<string>& grid, Grid<string>& gridNeighbor, string wrapAround){

    if(wrapAround == "y"){
        for(int i=0;i<grid.numRows();i++){
            for(int j=0;j<grid.numCols();j++){
                gridNeighbor[i][j] = calculateNeighborWrapped(grid, i, j);
            }
        }
    }
    else if(wrapAround == "n"){
        for(int i=0;i<grid.numRows();i++){
            for(int j=0;j<grid.numCols();j++){
                gridNeighbor[i][j] = calculateNeighborUnwrapped(grid, i, j);
            }
        }
    }
    else{
        cout << "ERROR in wrapAround parameter" << endl;
    }
}

string calculateNeighborUnwrapped(Grid<string>& grid, int row, int col){
    // Initialize sum
    int sum = 0;

    // Go through the neighbors
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1 && j==1){
                // do not include itself
                continue;
            }
            else if ((row+i-1)>=0 && (row+i-1)<grid.numRows() &&
                     (col+j-1)>=0 && (col+j-1)<grid.numCols()){
                    // use grid.inBounds()!!

                // add if only within bounds
                sum += ((grid[row+i-1][col+j-1] == "X")? 1:0);
            }
            else{
                // other non-relevant cases
                continue;
            }
        }
    }

    return integerToString(sum);
}

string calculateNeighborWrapped(Grid<string>& grid, int row, int col){
    //Initialize sum
    int sum = 0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1 && j==1){
                // do not include itself
                continue;
            } else{
                // wrap around edges and add.
                sum += ((grid[(row+(i-1)+grid.numRows())%grid.numRows()][(col+(j-1)+grid.numCols())%grid.numCols()] == "X")? 1:0);
            }
        }
    }

    return integerToString(sum);
}

void printGrid(Grid<string>& grid){
    for(int i=0;i<grid.numRows();i++){
        for(int j=0;j<grid.numCols();j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}
