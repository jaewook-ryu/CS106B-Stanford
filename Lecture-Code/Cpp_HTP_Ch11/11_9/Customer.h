
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer{
    public:
        Customer(std::string, std::string, std::string, std::string);

        std::string getName() const;
        std::string getAddress() const;
        std::string getCity() const;
        std::string getZipcode() const;

        void setName();
        void setAddress();
        void setCity();
        void setZipcode();

    private:
        std::string name;
        std::string address;
        std::string city;
        std::string zipcode;

};


#endif