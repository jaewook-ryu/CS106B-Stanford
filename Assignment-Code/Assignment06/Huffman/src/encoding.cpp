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

void buildEncodingMapHelper(Map<int, string>& encodingMap, HuffmanNode* node, string& binary){
    // base case
    if(node->isLeaf()){
        encodingMap.add(node->character, binary);
    } else{
        // left traversal
        binary += "0"; // choose
        buildEncodingMapHelper(encodingMap, node->zero, binary);
        binary = binary.substr(0, binary.length()-1); // unchoose

        // right traversal
        binary += "1"; // choose
        buildEncodingMapHelper(encodingMap, node->one, binary);
        binary = binary.substr(0, binary.length()-1); // unchoose
    }
}


Map<int, string> buildEncodingMap(HuffmanNode* encodingTree) {
    Map<int, string> encodingMap;
    string binary = "";

    // call to recursive helper function
    buildEncodingMapHelper(encodingMap, encodingTree, binary);

    return encodingMap;
}

void encodeData(istream& input, const Map<int, string>& encodingMap, obitstream& output) {
    // Read file character by character
    int c;
    string encode = "";

    while((c = input.get()) != EOF){
        encode = encodingMap[c];

        for(int i=0;i<encode.length();i++){
            output.writeBit(stringToInteger(encode.substr(i, 1)));
        }
    }

    // add code for EOF
    encode = encodingMap[PSEUDO_EOF];

    for(int i=0;i<encode.length();i++){
        output.writeBit(stringToInteger(encode.substr(i, 1)));
    }
}

void decodeData(ibitstream& input, HuffmanNode* encodingTree, ostream& output) {
    // Read file character by character
    int c;
    HuffmanNode* temp;
    temp = encodingTree;

    string tempString = "";

    while(true){
        if(temp->isLeaf()){
            // leaf: we found the character.
            // Add if character is not the EOF character.

            if(temp->character != PSEUDO_EOF){
                output << char(temp->character);
                temp = encodingTree;

                //cout << tempString << endl;
                //StempString = "";
            } else{
                break;
            }

        } else{
            // Read in next chacter
            c = input.readBit();

            // not a leaf: we need to traverse further.
            if(c == 1){
                temp = temp->one;
                //StempString += "1";
            } else if (c == 0){
                temp = temp->zero;
                //tempString += "0";
            } else if (c == -1){
                break;
            } else{
                throw "Invalid File";
            }
        }
    }
}

void compress(istream& input, obitstream& output) {
    // Build Frequency Table
    Map<int, int> freqTable = buildFrequencyTable(input);

    // Build encoding tree
    HuffmanNode* front = buildEncodingTree(freqTable);

    // Build encoding map
    Map<int, string> encodingMap = buildEncodingMap(front);

    // write encodingMap into output file as a header
    output << freqTable;

    // encode data
    encodeData(input, encodingMap, output);

}

void decompress(ibitstream& input, ostream& output) {
    Map<int, int> freqTable;
    input >> freqTable;

    HuffmanNode* encodingTree = buildEncodingTree(freqTable);

    decodeData(input, encodingTree, output);
}

void freeTree(HuffmanNode* node) {
    // TODO: implement this function
}
