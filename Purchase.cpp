#include "Purchase.h"

using namespace std;
#include "string"

Purchase::Purchase(string _item, int _qty, double _cost) {
    this->_qty = _qty;
    this->_cost = _cost;
    this->_item = _item;
}

double Purchase::cost() const {
    return this->_cost;
}

std::ofstream& operator<<(std::ofstream& ofs, const Purchase& obj){
    ofs << obj.item() << "\n" << obj.qty() << "\n" << obj.cost() << "\n";
    return ofs;
}

string Purchase::item() const {
    return this->_item;
}

int Purchase::qty() const {
    return this->_qty;
}

double Purchase::total() const {
    return this->_cost*this->_qty;
}
