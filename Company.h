#ifndef COMPANY_H
#define COMPANY_H
#include "Employee.h"
#include "Customer.h"
#include <vector>
#include "string"

using namespace std;


class Company {

private:
string _name;
vector<Employee> _employees;
vector<Customer> _customers;

public:

    Company(string _name);

    std::string name() const;

    vector<Employee>::iterator employee_begin();

    vector<Employee>::iterator employee_end();

    void add_employee(Employee _employee);

    void add_customer(Customer _customer);

    vector<Customer>::iterator customer_begin();

    vector<Customer>::iterator customer_end();

};
#endif
