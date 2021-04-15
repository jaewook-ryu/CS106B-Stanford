#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
using namespace std;

void sublists(Vector<string>& v);
void sublistsHelper(Vector<string>& current, Vector<string>& remaining);


int main() {
    Vector<string> v;
    v.add("Jane");
    v.add("Bob");
    v.add("Matt");
    v.add("Sara");

    sublists(v);

    return 0;
}

void sublists(Vector<string>& v){
    Vector<string> s;
    sublistsHelper(s, v);

}

void sublistsHelper(Vector<string>& current, Vector<string>& remaining){
    // Base case
    if(remaining.size() == 0){
       cout << current << endl;
    } else{
        string temp = remaining[0];
        remaining.remove(0);

        // do not include temp
        sublistsHelper(current, remaining);

        // include temp in current.
        current.insert(0, temp);
        sublistsHelper(current, remaining);

        // "unchoose"
        remaining.insert(0, temp);
        current.remove(0);

    }
}
