#include <string>

class Soldier{
    public:
        Soldier(std::string, std::string);
        ~Soldier();

        std::string getName() const;
        std::string getStartDate() const;
        std::string getEndDate() const;
        
    private:
        std::string name;
        std::string startDate;
        std::string endDate;

        string calculateEndDate();
        void setStartDate(std::string);
        void setEndDate();
};