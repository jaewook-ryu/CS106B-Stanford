#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include <string>
#include "Package.h"

class TwoDayPackage : public Package{
    public:
        explicit TwoDayPackage(Customer&, Customer&, double, double, double);
        
        double getFlatFee() const;
        double calculateCost() const;
        void setFlatFee(double);

    private:
        double flatFee;
};

#endif