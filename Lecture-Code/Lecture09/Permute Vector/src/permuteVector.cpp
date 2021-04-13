#include <iostream>
#include <string>
#include "console.h"
#include "vector.h"  // for Vector
using namespace std;


void permuteVector(Vector<string> &v);
void permuteVectorHelper(Vector<string> &v, Vector<string> &remaining);

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
    permuteVectorHelper(v, chosen);
}

void permuteVectorHelper(Vector<string>& v, Vector<string>& chosen){
    // base case

    cout << "permute v = " <<  v << ", chosen= " << chosen << endl;
    cout << endl;
    if(v.isEmpty()){
        cout << chosen << endl;
    } else{
        for(int i=0;i<v.size();i++){
            // choose
            string s = v.get(i);
            chosen.add(s);
            v.remove(i);

            // explore
            permuteVectorHelper(v, chosen);

            // unchoose
            int x = chosen.size();
            chosen.remove(x-1);
            v.insert(i, s);

        }
    }
}
