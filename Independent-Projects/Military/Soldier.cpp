#include "Soldier.h"

using namespace std;

Soldier::Soldier(std::string name, std::string startDate)
    :name{name}{
        setStartDate(startDate);
        setEndDate();
}

string Soldier::getStartDate() const{
    return startDate;
}

string Soldier::getEndDate() const{
    return endDate;
}

void Soldier::setStartDate(string startDate){

}

void Soldier::setEndDate(){

}

string Soldier::calculateEndDate(){
    string endDate;
    return endDate;
}