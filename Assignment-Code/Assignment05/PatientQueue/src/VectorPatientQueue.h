// This is the H file you will edit and turn in. (TODO: Remove this comment!)

#pragma once

#include <iostream>
#include <string>
#include "vector.h"
#include "patientqueue.h"
using namespace std;

// struct for patient
struct Patient{
public:
    string name;
    int priority;
    int timestamp;

    Patient(string name, int priority, int timestamp);
};

class VectorPatientQueue : public PatientQueue {
public:
    VectorPatientQueue();
    ~VectorPatientQueue();
    string frontName();
    void clear();
    int frontPriority();
    bool isEmpty();
    void newPatient(string name, int priority);
    string processPatient();
    void upgradePatient(string name, int newPriority);
    string toString();

private:
    Vector<Patient> pq;
    int timeCounter = 0;
};
