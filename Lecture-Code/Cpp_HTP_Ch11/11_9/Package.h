#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include "Customer.h"

class Package{
    
    public:
        explicit Package(Customer&, Customer&, double, double);
        explicit Package(std::string, std::string, std::string, std::string,
                         std::string, std::string, std::string, std::string,
                         double, double);
        
        double getWeight() const;
        double getCostPerOunce() const;

        double calculateCost() const;

        void setWeight(double);
        void setCostPerOunce(double);
    private:
        Customer sender;
        Customer recipient;

        double weight; // in counces
        double costPerOunce; // in cost per ounce

};

#endif