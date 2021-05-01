// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include "VectorPatientQueue.h"
#include <sstream>

VectorPatientQueue::VectorPatientQueue() {
}

VectorPatientQueue::~VectorPatientQueue() {
    //DO NOTHING
}

void VectorPatientQueue::clear() {
    pq.clear();
}

string VectorPatientQueue::frontName() {
    if(pq.isEmpty()){
        throw "patient queue is empty";
    } else{
        int tempTimestamp = INT_FAST8_MAX;
        int highestPriority = frontPriority();
        int index;

        for(int i=0;i<pq.size();i++){
            if(pq[i].priority == highestPriority){
                if(pq[i].timestamp < tempTimestamp){
                    tempTimestamp = pq[i].timestamp;
                    index = i;
                }
            }
        }

        return pq[index].name;
    }
}

int VectorPatientQueue::frontPriority() {
    if(pq.isEmpty()){
        throw "patient queue is empty";
    } else{
        int tempPriority = INT_FAST8_MAX;

        for(int i=0;i<pq.size();i++){
            if(pq[i].priority < tempPriority){
                tempPriority = pq[i].priority;
            }
        }

        return tempPriority;
    }
}


bool VectorPatientQueue::isEmpty() {
    return pq.isEmpty();
}

void VectorPatientQueue::newPatient(string name, int priority) {
    Patient temp(name, priority, timeCounter++);
    pq.add(temp);
}

string VectorPatientQueue::processPatient() {
    if(pq.isEmpty()){
        throw "patient queue is empty";
    } else{
        string patientName = frontName();

        // get index of lowest priority patient
        int tempTimestamp = INT_FAST8_MAX;
        int highestPriority = frontPriority();
        int index;

        for(int i=0;i<pq.size();i++){
            if(pq[i].priority == highestPriority){
                if(pq[i].timestamp < tempTimestamp){
                    tempTimestamp = pq[i].timestamp;
                    index = i;
                }
            }
        }

        // remove patient of highest priority.
        pq.remove(index);

        return patientName;
    }

    // TODO: write this function
    return "";   // this is only here so it will compile
}

void VectorPatientQueue::upgradePatient(string name, int newPriority) {
    int tempTimestamp = INT_FAST8_MAX;
    int index = -1;

    for(int i=0;i<pq.size();i++){
        if(pq[i].name == name){
            if(pq[i].timestamp < tempTimestamp){
                tempTimestamp = pq[i].timestamp;
                index = i;
            }
        }
    }

    // if there is no such patient, throw an exception
    if(index == -1){
        throw "No such Patient Exists";
    }

    // check for exception
    if(pq[index].priority < newPriority){
        throw "patient already has higher priority";
    } else{
        pq[index].priority = newPriority;
    }
}

string VectorPatientQueue::toString() {
    stringstream s;

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
