// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own, along with
// comments on every function and on complex code sections.
// TODO: remove this comment header

#include "encoding.h"
#include <iostream>
#include "pqueue.h"
using namespace std;
// TODO: include any other headers you need


Map<int, int> buildFrequencyTable(istream& input) {
    // TODO: implement this function
    Map<int, int> freqTable;

    int c;
    while((c = input.get()) != EOF){
        freqTable[c]++;
    }

    // add this for EOF (once per file)
    freqTable[PSEUDO_EOF]++;

    return freqTable;
}

HuffmanNode* buildEncodingTree(const Map<int, int>& freqTable) {
    // Priority queue to store our node structs
    PriorityQueue<HuffmanNode*> pq;

    // Construct pq by traversing our freqTable
    for(int c: freqTable.keys()){
        HuffmanNode *tempNode = new HuffmanNode(c, freqTable[c], NULL, NULL);
        pq.enqueue(tempNode, freqTable[c]);
    }

    cout << pq << endl;





    return NULL;   // this is just a placeholder so it will compile
}

Map<int, string> buildEncodingMap(HuffmanNode* encodingTree) {
    // TODO: implement this function
    Map<int, string> encodingMap;   // this is just a placeholder so it will compile
    return encodingMap;             // this is just a placeholder so it will compile
}

void encodeData(istream& input, const Map<int, string>& encodingMap, obitstream& output) {
    // TODO: implement this function
}

void decodeData(ibitstream& input, HuffmanNode* encodingTree, ostream& output) {
    // TODO: implement this function
}

void compress(istream& input, obitstream& output) {
    // TODO: implement this function
}

void decompress(ibitstream& input, ostream& output) {
    // TODO: implement this function
}

void freeTree(HuffmanNode* node) {
    // TODO: implement this function
}
