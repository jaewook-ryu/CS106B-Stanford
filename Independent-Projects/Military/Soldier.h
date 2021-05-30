#include <string>

class Soldier{
    public:
        Soldier(std::string name, std::string StartDate);
        ~Soldier();

        std::string getName() const;
        std::string getStartDate() const;
        std::string getEndDate() const;
        
    private:
        std::string name;
        std::string startDate;
        std::string endDate;

        void calculateEndDate();
};