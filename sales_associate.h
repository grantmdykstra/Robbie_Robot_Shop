#ifndef __SALES_ASSOCIATE
#define __SALES_ASSOCIATE 2016

#include <vector>
#include <string>


class SalesAssociate {
    private:
        std::string name;
        int employeeNumber;
        
    public:
        SalesAssociate(std::string employ, int number) :
            name(employ), employeeNumber(number) { }
        std::string getName() {return name;};
        int getNumber() {return employeeNumber;};

};

#endif
