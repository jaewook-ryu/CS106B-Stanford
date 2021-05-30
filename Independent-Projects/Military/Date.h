#include <string>

class Date{
    static void calculateDifference();

    public:
        Date(int, int, int);
        std::string toString() const;

    private:
        int year;
        int month;
        int day;
};