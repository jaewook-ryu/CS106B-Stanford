// heappatientqueue.h
// This is the H file you will edit and turn in. (TODO: Remove this comment!)

#pragma once

#include <iostream>
#include <string>
#include "patientnode.h"
#include "patientqueue.h"
using namespace std;



class HeapPatientQueue : public PatientQueue  {
public:

    struct Patient{
    public:
        string name;
        int priority;

        Patient(){}

        Patient(string name, int priority){
            this->name = name;
            this->priority = priority;
        }

    };

    HeapPatientQueue();
    ~HeapPatientQueue();
    string frontName();
    void clear();
    int frontPriority();
    bool isEmpty();
    void newPatient(string name, int priority);
    string processPatient();
    void upgradePatient(string name, int newPriority);
    string toString();

private:
    int capacity = 10;
    int size;
    Patient *pq;

    void resize();
    int comparePatient(Patient p1, Patient p2);
};
