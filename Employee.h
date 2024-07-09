#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
#include "string"
#include "fstream"

using namespace std;

class Employee : public Person{
private:
    double _salary;
public:

    Employee();
    Employee(string _name, string _email, string _phone, double _salary);

    void salary(double& _salary);
    double salary() const;

    };

#endif
