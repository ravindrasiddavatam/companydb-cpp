#ifndef PURCHASE_H
#define PURCHASE_H

#include "fstream"
#include "string"

using namespace std;

class Purchase {
private:
    string _item;
    int _qty;
    double _cost;
public:
    Purchase(std::string _item, int _qty, double _cost);

    string item() const;

    int qty() const;

    double cost() const;

    double total() const;
};

#endif
