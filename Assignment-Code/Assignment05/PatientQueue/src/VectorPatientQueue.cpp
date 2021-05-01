// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include "VectorPatientQueue.h"
#include <sstream>

VectorPatientQueue::VectorPatientQueue() {
    pq = new Vector<Patient>();
}

VectorPatientQueue::~VectorPatientQueue() {
    delete[] pq;
}

void VectorPatientQueue::clear() {
    pq.clear();
}

string VectorPatientQueue::frontName() {
    int tempTimestamp = INT_FAST32_MAX;
    int highestPriority = frontPriority();
    int index;

    for(int i=0;i<pq.size();i++){
        if(pq[i].priority == highestPriority){
            if(pq[i].timestamp < highestPriority){
                highestPriority = pq[i].timestamp;
                index = i;
            }
        }
    }

    return pq[index].name;
}

int VectorPatientQueue::frontPriority() {
    int tempPriority = INT_FAST32_MAX;

    for(int i=0;i<pq.size();i++){
        if(pq[i].priority < tempPriority){
            tempPriority = pq[i].priority;
        }
    }

    return tempPriority;
}

bool VectorPatientQueue::isEmpty() {
    pq.isEmpty();
}

void VectorPatientQueue::newPatient(string name, int priority) {
    Patient temp = new Patient(name, priority, timeCounter++);
    pq.add(temp);
}

string VectorPatientQueue::processPatient() {
    // TODO: write this function
    return "";   // this is only here so it will compile
}

void VectorPatientQueue::upgradePatient(string name, int newPriority) {
    // TODO: write this function
}

string VectorPatientQueue::toString() {
    std::sstream s;

    s << "{";
    for(int i=0;i<pq.size();i++){
        s << pq[i].priority << ":" << pq[i].name;

        if(i != pq.size()-1){
            s << ", ";
        }
    }
    s << "}";

    return s.str();
}
