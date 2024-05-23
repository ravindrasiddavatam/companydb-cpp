
#include "Person.h"
#include "string"

using namespace std;


Person::Person(string _name, string _email, string _phone) {
    this->_name = _name;
    this->_email = _email;
    this->_phone = _phone;
}

Person::Person() {
    this->_name = "";
    this->_email = "";
    this->_phone = "";
}

string Person::email() const {
    return this->_email;
}

string Person::phone() const {
    return this->_phone;
}

void Person::phone(string _phone) {
    this->_phone = _phone;
}


void Person::email(string _email) {
    this->_email = _email;
}


string Person::name() const {
    return this->_name;
}

void Person::name(string _name) {
    this->_name = _name;
}


