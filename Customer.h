#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Purchase.h"
#include "vector"
#include "Person.h"
#include "string"
#include "fstream"


using namespace std;

class Customer : public Person{
private:
    vector<Purchase> _history;
public:

    Customer();

    Customer(std::string _name, std::string _email, std::string _phone);

    void add_purchase(Purchase item);

    vector<Purchase>::const_iterator purchase_begin();

    vector<Purchase>::const_iterator purchase_end();

};
#endif
