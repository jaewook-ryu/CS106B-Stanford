// heappatientqueue.cpp
// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include "HeapPatientQueue.h"
#include "strlib.h"
#include <sstream>
#include <iostream>

HeapPatientQueue::HeapPatientQueue() {
    pq = new Patient[capacity];
    size = 0;
}

HeapPatientQueue::~HeapPatientQueue() {
    delete[] pq;
}

// private member function to resize pq
void HeapPatientQueue::resize(){
    int tempCap = capacity * 2;

    Patient *pqTemp;
    pqTemp = new Patient[tempCap];

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
    size = 0;
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
    pq[index] = newPatient;
    size++;

    while(index > 1){
        if(comparePatient(pq[index], pq[index/2]) > 0){
            // tempPatient needs to come first: swap.
            Patient tempPatient = pq[index];
            pq[index] = pq[index/2];
            pq[index/2] = tempPatient;

            // assign current value of index
            index = index/2;
        } else{
            break;
        }
    }
}

string HeapPatientQueue::processPatient() {
    string tempName = frontName();

    pq[1] = pq[size];

    delete pq[size]; // delete last element
    size--; // decrement size after deletion.

    // now percolate pq[1] down.
    int index = 1;
    int swapIndex;

    while(index <= size/2){
        if(comparePatient(pq[index*2], pq[index]) > 0){
            swapIndex = index*2;
        } else if(index*2 + 1 <= size && comparePatient(pq[index*2+1], pq[index]) > 0){
            swapIndex = index*2+1;
        } else{
            // in the right place
            break;
        }

        // swap with index
        Patient temp = pq[swapIndex];
        pq[swapIndex] = pq[index];
        pq[index] = temp;

        index = index*2;
    }

    return tempName;   // this is only here so it will compile
}

void HeapPatientQueue::upgradePatient(string name, int newPriority) {
    int tempPriority = INT_FAST8_MAX;
    int indexPatient = -1;

    for(int i=1;i<size+1;i++){
        if(pq[i].name == name){
            if(pq[i].priority < tempPriority){
                indexPatient = i;
            }
        }
    }

    if(indexPatient == -1){
        throw "Patient not on queue";
    }

    if(newPriority >= pq[indexPatient].priority){
        throw "Patient already has higher priority";
    }

    // update the priority
    pq[indexPatient].priority = newPriority;

    // now we need to percolate this patient up if needed.
    int index = indexPatient;

    while(index > 1){
        if(comparePatient(pq[index], pq[index/2]) > 0){
            // tempPatient needs to come first: swap.
            Patient tempPatient = pq[index];
            pq[index] = pq[index/2];
            pq[index/2] = tempPatient;

            // assign current value of index
            index = index/2;
        } else{
            break;
        }
    }


}

string HeapPatientQueue::toString() {
    stringstream s;

    s << "{";
    for(int i=1;i<size+1;i++){
        s << pq[i].priority << ":" << pq[i].name;

        if(i != size){
            s << ", ";
        }
    }
    s << "}";

    return s.str();

    return s.str();
}
