#include "Employee.h"
#include "Person.h"
#include "fstream"

using namespace std;

Employee::Employee():Person() {
    this->_salary = 0.0;
}

Employee::Employee(string _name, string _email, string _phone, double _salary) : Person(_name,_email,_phone) {
    this->_salary = _salary;
}

void Employee::salary(double& _salary) {
    this->_salary = _salary;
}

double Employee::salary() const {
    return this->_salary;
}
