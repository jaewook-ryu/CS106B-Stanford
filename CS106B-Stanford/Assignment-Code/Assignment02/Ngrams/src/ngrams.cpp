// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "simpio.h"

#include "random.h"#include "set.h"
#include "map.h"
#include "queue.h"

using namespace std;

int main() {
    // Introduction
    cout << "Welcome to CS 106B Random Writer (\'N-Grams\')." << endl;
    cout << "This program makes random text based on a document." << endl;
    cout << "Give me an input file and an 'N' value for groups" << endl;
    cout << "of words, and I'll create random text for you." << endl;

    // Get files and N
    ifstream stream;
    promptUserForFile(stream, "Input File Name? ");
    int n = getInteger("Value of N? ");

    // get your maps!
    Vector<string> words;
    Map<Vector<string>, Vector<string>> m;

    string word;
    while (stream >> word) {
        // each time through this loop, word is the next word in the file
        words.add(word);
    }

    Vector<string> key;
    string nextWord;

    for(int i=0;i<n-1;i++){
        key.add(words[i%words.size()]);
    }

    //cout << words;

    Vector<string> tempVector;
    tempVector.add(words[(n-1)%(words.size())]);
    m[key] = tempVector;

    for(int i=n-1;i<words.size();i++){
        // update keys
        key.add(words[i%words.size()]);
        key.remove(0);

        // retrieve next word
        nextWord = words[(i+1)%words.size()];

        // update map
        if(m.containsKey(key)){
            m[key].add(nextWord);
        }
        else{
            Vector<string> tempVector;
            tempVector.add(nextWord);
            m[key] = tempVector;
        }
    }

    //cout << m << endl;

    int numWords;
    Vector<string> ngrams;

    do{
        numWords = getInteger("# of random words to generate (0 to quit)? ");

        int start = randomInteger(0, (m.keys().size()-1));
        key = m.keys().get(start);
        cout << key << endl;

        ngrams.addAll(key);

        string val = (m[key]).get(randomInteger(0, (m[key].size()-1)));
        ngrams.add(val);
        int count = n;


        while(count <= numWords){
            // update key
            key.add(val);
            key.remove(0);
            val = m[key].get(randomInteger(0, (m[key].size()-1)));
            cout << val << endl;
            ngrams.add(val);
            count += 1;
        }

        cout << "...";
        for(int i=0;i<numWords;i++){
            cout << ngrams[i] << " ";
        }
        cout << "..." << endl;

    } while((numWords != 0));




    cout << "Exiting." << endl;
    return 0;
}
