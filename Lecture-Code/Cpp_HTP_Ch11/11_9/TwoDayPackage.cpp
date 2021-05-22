#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(Customer& sender, Customer& recipient, 
                             double weight, double costPerOunce, double flatFee)
    : Package{sender, recipient, weight, costPerOunce}, flatFee{flatFee}{
        /* empty body */
}

double TwoDayPackage::getFlatFee() const{
    return flatFee;
}

double TwoDayPackage::calculateCost() const{
    return (Package::calculateCost() + flatFee);
}

void TwoDayPackage::setFlatFee(double flatFee){
    this->flatFee = flatFee;
}
