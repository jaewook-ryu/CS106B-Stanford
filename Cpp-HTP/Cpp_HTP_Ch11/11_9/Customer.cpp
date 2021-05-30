#include "Customer.h"
#include <string>
using namespace std;


Customer::Customer(string name, string address, string city, string zipcode)
    : name{name}, address{address}, city{city}, zipcode{zipcode}{
    /* empty body */
}

string Customer::getName() const{
    return name;
}

string Customer::getAddress() const{
    return address;
}

string Customer::getCity() const{
    return city;
}

string Customer::getZipcode() const{
    return zipcode;
}

void Customer::setName(string name){
    this->name = name;
}

void Customer::setAddress(string address){
    this->address = address;
}

void Customer::setCity(string city){
    this->city = city;
}

void Customer::setZipcode(string zipcode){
    this->zipcode = zipcode;
}