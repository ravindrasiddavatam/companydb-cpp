#ifndef PERSON_H
#define PERSON_H

#include "string"

using namespace std;

class Person {
private:
    string _name;
    string _email;
    string _phone;
public:
    Person();
    Person(string _name, string _email, string _phone);

    //getters
    string name() const;
    string email() const;
    string phone() const;

    //setters
    void name(string _name);
    void phone(string _phone);
    void email(string _email);
};
#endif
