
#include "Customer.h"
#include "Purchase.h"

using namespace std;

Customer::Customer() : Person{} {}

Customer::Customer(string _name, string _email, string _phone) : Person{_name, _email, _phone} {}

vector<Purchase>::const_iterator Customer::purchase_begin() {
    return this->_history.begin();
}

vector<Purchase>::const_iterator Customer::purchase_end() {
    return this->_history.end();
}

void Customer::add_purchase(Purchase item) {
    this->_history.push_back(item);
}


