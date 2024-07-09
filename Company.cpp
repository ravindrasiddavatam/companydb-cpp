#include "Employee.h"
#include "Company.h"
#include "Customer.h"

// Author Ravi

std::string Company::name() const {
    return this->_name;
}

Company::Company(string _name) {
    this->_name = _name;
}

void Company::add_customer(Customer _customer) {
    this->_customers.push_back(_customer);
}

void Company::add_employee(Employee _employee) {
    this->_employees.push_back(_employee);
}

vector<Employee>::iterator Company::employee_begin() {
    return this->_employees.begin();
}

vector<Customer>::iterator Company::customer_begin() {
    return this->_customers.begin();
}

vector<Customer>::iterator Company::customer_end() {
    return this->_customers.end();
}

vector<Employee>::iterator Company::employee_end() {
    return this->_employees.end();
}



