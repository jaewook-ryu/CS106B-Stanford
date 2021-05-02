// heappatientqueue.cpp
// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include "HeapPatientQueue.h"
#include "strlib.h"
#include <sstream>

HeapPatientQueue::HeapPatientQueue() {
    // Do nothing
}

HeapPatientQueue::~HeapPatientQueue() {
    delete[] pq;
}

// private member function to resize pq
void HeapPatientQueue::resize(){
    int tempCap = capacity * 2;
    Patient pqTemp[tempCap];

    for(int i=1;i<capacity;i++){
        pqTemp[i] = pq[i];
    }

    pq = pqTemp;
    capacity = tempCap;
}

// returns 1 if p1 comes first (higher priority) and -1 if not the case.
int HeapPatientQueue::comparePatient(Patient p1, Patient p2){
    if(p1.priority < p2.priority){
        return 1;
    } else if(p1.priority == p2.priority){
        if(p1.name < p2.name){
            return 1;
        } else{
            return -1;
        }

    } else{
        return -1;
    }
}


void HeapPatientQueue::clear() {
    delete[] pq;
    pq = new Patient[capacity];
}

string HeapPatientQueue::frontName() {
    if(isEmpty()){
        throw "Patient Queue is Empty";
    } else{
        return pq[1].name;
    }
}

int HeapPatientQueue::frontPriority() {
    if(isEmpty()){
        throw "Patient Queue is Empty";
    } else{
        return pq[1].priority;
    }
}

bool HeapPatientQueue::isEmpty() {
    return (size == 0);
}

void HeapPatientQueue::newPatient(string name, int priority) {
    // Instantiate new patient struct
    Patient newPatient(name, priority);

    // check if the pq is full or not
    if(size == capacity-1){
        resize();
    }

    // Now percolate the patient up....
    int index = size + 1;
    while(index > 1){
        if(comparePatient(newPatient, pq[index]) > 0){
            // tempPatient needs to come first: swap.
            Patient tempPatient = newPatient;
            newPatient = pq[index];
            pq[index] = tempPatient;

            // assign current value of index
            index = index/2;
        }
    }

    pq[index] = newPatient;
    size++;
}

string HeapPatientQueue::processPatient() {
    // TODO: write this function
    return "";   // this is only here so it will compile
}

void HeapPatientQueue::upgradePatient(string name, int newPriority) {
    // TODO: write this function
}

string HeapPatientQueue::toString() {
    stringstream s;

    s << "{";
    for(int i=0;i<size+1;i++){
        s << pq[i].priority << ":" << pq[i].name;

        if(i != size){
            s << ", ";
        }
    }
    s << "}";

    return s.str();

    return s.str();
}
