#include <iostream>
#include "basicgraph.h"
using namespace std;

string coolest(istream& input){
    // reading the line
    BasicGraph graph;
    string name1, name2;
    while(input >> name1 >> name2){
        graph.addVertex(name1);
        graph.addVertex(name2);

        graph.addEdge(name1, name2);
    }

    cout << graph << endl;

    // who has the most followers of followers?

    int maxFof = 0;
    string coolest = "-";
    for(string v: graph.getVertexNames()){
        int fof = 0;
        for(string neighbor : graph.getNeighborNames(v)){
            fof += graph.getNeighborNames(neighbor).size();
        }

        if(fof > maxfof){
            maxFof = fof;
            coolest = v;
        }
    }

    return coolest;
}


int main() {
    return 0;
}
