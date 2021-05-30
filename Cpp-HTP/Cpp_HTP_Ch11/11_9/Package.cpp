#include "Package.h"
#include <string>
using namespace std;

Package::Package(Customer& sender, Customer& recipient, double weight, double costPerOunce)
    : sender{sender}, recipient{recipient}, weight{weight}, costPerOunce{costPerOunce}{
    /* empty body */
}

Package::Package(string nameSender, string addressSender, string citySender, string zipcodeSender, 
                 string nameRecipient, string addressRecipient, string cityRecipient, string zipcodeRecipient,
                 double weight, double costPerOunce)
    : sender{Customer{nameSender, addressSender, citySender, zipcodeSender}},
      recipient{Customer{nameRecipient, addressRecipient, cityRecipient, zipcodeRecipient}},
      weight{weight}, costPerOunce{costPerOunce}{
          /* empty body */
}

double Package::getWeight() const{
    return weight;
}

double Package::getCostPerOunce() const{
    return costPerOunce;
}

double Package::calculateCost() const{
    return (weight * costPerOunce);
}


void Package::setWeight(double weight){
    this->weight = weight;
}

void Package::setCostPerOunce(double costPerOunce){
    this->costPerOunce = costPerOunce;
}

