#include <iostream>
#include <string>
#include "console.h"
#include "set.h"
#include "vector.h"  // for Vector
using namespace std;


void permuteVector(Vector<string> &v);
void permuteVectorHelper(Vector<string> &v, Vector<string> &chosen, Set<Vector<string> > &printed);

int main() {
    cout << "Testing the permute function: " << endl;
    Vector<string> v;
    v.add("A");
    v.add("B");
    v.add("C");

    permuteVector(v);

    return 0;
}

void permuteVector(Vector<string>& v){
    Vector<string> chosen;
    Set<Vector<string>> printed;
    permuteVectorHelper(v, chosen, printed);
}

void permuteVectorHelper(Vector<string>& v, Vector<string>& chosen,
                         Set<Vector<string>>& printed){
    // base case

    cout << "permute v = " <<  v << ", chosen= " << chosen << endl;
    cout << endl;
    if(v.isEmpty()){
        if(!printed.contains(chosen)){
            cout << chosen << endl;
            printed.add(chosen);
        }
    } else{
        for(int i=0;i<v.size();i++){
            // choose
            string s = v.get(i);
            chosen.add(s);
            v.remove(i);

            // explore
            permuteVectorHelper(v, chosen, printed);

            // unchoose
            int x = chosen.size();
            chosen.remove(x-1);
            v.insert(i, s);

        }
    }
}
