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

    /*
    for(HuffmanNode* t : pq){
        cout << t->character << " " << t->count << endl;
    }
    */

    while(pq.size() >= 2){
        // Remove two nodes from the beginning of the pq
        HuffmanNode* node1 = pq.dequeue();
        HuffmanNode* node2 = pq.dequeue();

        // Join two nodes
        HuffmanNode* node3 = new HuffmanNode();
        node3->count = node1->count + node2->count;

        // Place original nodes as children of new node
        node3->zero = node1;
        node3->one = node2;

        // Re-insert into pq
        pq.enqueue(node3, node3->count);
    }

    // return the only node (which is in the front)
    return pq.front();
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
