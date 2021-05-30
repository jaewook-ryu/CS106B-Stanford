// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include "LinkedListPatientQueue.h"
#include <sstream>

LinkedListPatientQueue::LinkedListPatientQueue() {
    front = nullptr;
}

LinkedListPatientQueue::~LinkedListPatientQueue() {
    PatientNode* temp = front;

    while(temp != nullptr){
        PatientNode* current = temp;
        delete(current);

        temp = temp->next;
    }
}

void LinkedListPatientQueue::clear() {
    while(front != nullptr){
        PatientNode *temp = front;
        front = front->next;
        delete(temp);
    }
}

string LinkedListPatientQueue::frontName() {
    if(isEmpty()){
        throw "Patient Queue is Empty!";
    } else{
        return front->name;
    }
}

int LinkedListPatientQueue::frontPriority() {
    if(isEmpty()){
        throw "Patient Queue is Empty!";
    } else{
        return front->priority;
    }
}

bool LinkedListPatientQueue::isEmpty() {
    return (front == nullptr);
}

void LinkedListPatientQueue::newPatient(string name, int priority) {
    PatientNode *temp = new PatientNode(name, priority, nullptr);

    // no element in list
    if(front == nullptr){
        front = temp;
    } else{
        PatientNode *index = front;

        while(index != nullptr){
            if(index->priority <= priority &&
                    (index->next == nullptr || index->next->priority > priority)){
                break;
            } else{
                index = index->next;
            }
        }


        // insert new node next to index.
        temp->next = index->next;
        index->next = temp;
    }
}

string LinkedListPatientQueue::processPatient() {
    if(front == nullptr){
        throw "PatientQueue is empty.";
    } else{
        PatientNode *temp = front;
        string name = temp->name;

        front = front->next;
        delete(temp);

        return name;
    }
}

void LinkedListPatientQueue::upgradePatient(string name, int newPriority) {
    PatientNode *temp = front;

    while(temp != nullptr){
        if(temp->name == name){
            temp->priority = newPriority;
            break;
        }

        temp = temp->next;
    }

    // if no such patient is found
    if(temp == nullptr){
        throw "No such patient exists";
    }
}

string LinkedListPatientQueue::toString() {
    PatientNode *temp = front;
    stringstream s;

    s << "{";
    while(temp != nullptr){
        s << temp->priority << ":" << temp->name;

        if(temp->next != nullptr){
            s << ", ";
        }

        temp = temp->next;
    }
    s << "}";

    return s.str(); // this is only here so it will compile
}
