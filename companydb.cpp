#include "string"
#include "vector"
#include <iomanip>

#include "Company.h"
#include "Employee.h"
#include "Purchase.h"
#include "Customer.h"
#include "vector"
#include "fstream"
#include "iostream"

using namespace std;

void getDatafromdat(Company& com, string fileName);
ofstream file_stream_op(string name);

int main(){

    string temp;
    string name;
    cout << "Company Name: ";

    getline(cin, name);

    Company company_database(name);

    string datF = company_database.name() + ".dat";

    getDatafromdat(company_database,datF);

    while (true){
        
        cout << "    MAIN MENU\n"
                "1.) Employees\n"
                "2.) Sales\n"
                "3.) Quit\n\n";
        
        cout << "Choice? ";
        
        char action;
        
        getline(cin, temp);
        action = temp[0];
        if(action=='1') {
            while (1) {

                auto emp_begin = company_database.employee_begin();
                auto emp_end = company_database.employee_end();

                for (auto i = emp_begin; i < emp_end; i++) {
                    cout << i->name() << " <" << i->email() << "> " << "Phone: " << i->phone() << " Salary: "
                         << "$" << fixed << setprecision(2) << i->salary() << "\n";
                }

                cout << "(A)dd Employee or (M)ain Menu? ";

                char employee_choice;
                getline(cin, temp);
                employee_choice = temp[0];
                
                if (employee_choice == 'A' || employee_choice == 'a') {
                    
                    string name;
                    string email;
                    string phone;
                    double salary;
                    
                    cout << "Name: ";
                    getline(cin, name);
                    cout << "Email: ";
                    getline(cin, email);
                    cout << "Phone: ";
                    getline(cin, phone);
                    cout << "Salary: ";
                    getline(cin, temp);
                    salary = stod(temp);
                    
                    Employee emp(name, email, phone, salary);
                    
                    company_database.add_employee(emp);
                    
                } else if(employee_choice=='M' || employee_choice=='m') {
                    break;
                }
            }
        } else if(action=='2'){
            while(1){
                cout << "(A)dd Customer, Enter a (S)ale, (V)iew Customer, or (M)ain Menu? ";
                
                char sales_choice;
                getline(cin, temp);
                sales_choice = temp[0];
                if(sales_choice=='A' || sales_choice=='a'){

                    string name, email, phone;
                    cout << "Name: ";
                    getline(cin, name);
                    cout << "Email: ";
                    getline(cin, email);
                    cout << "Phone: ";
                    getline(cin, phone);
                    Customer cust_obj(name, email, phone);
                    company_database.add_customer(cust_obj);

                } else if(sales_choice == 'V' || sales_choice == 'v') {
                    auto cus_begin = company_database.customer_begin();
                    auto cus_end = company_database.customer_end();
                    if (cus_end - cus_begin == 0) {
                        cout << "Error: No Customers. " << "\n";
                    }
                    else{
                    for (auto i = cus_begin; i < cus_end; i++) {
                        cout << (i - cus_begin) + 1 << ". )";
                        cout << i->name() << endl;
                    }

                    int cust_choice;
                    cout << "Choice? ";
                    getline(cin, temp);
                    cust_choice = stoi(temp);
                    Customer customer_choice = *(cus_begin + cust_choice - 1);
                    cout << customer_choice.name() << " <" << customer_choice.email() << "> " << "Phone: "
                         << customer_choice.phone();
                    cout << "\n";
                    cout << "Order History\n"
                            "Item                   Price  Quantity   Total\n";
                    for (auto i = customer_choice.purchase_begin(); i != customer_choice.purchase_end(); i++) {
                        cout << i->item() << "     " << i->cost() << "    " << i->qty() << "    " << i->total() << "\n";
                    }
                }
                } else if(sales_choice=='S' || sales_choice=='s'){
                    auto cus_begin = company_database.customer_begin();
                    auto cus_end = company_database.customer_end();
                    if(cus_end-cus_begin==0){
                        cout << "Error: No Customers. " << "\n";
                    }
                    else {
                        for (auto i = cus_begin; i < cus_end; i++) {
                            cout << (i - cus_begin) + 1 << ". )";
                            cout << i->name() << endl;
                        }

                        int cust_choice;
                        cout << "Choice? ";
                        getline(cin, temp);
                        cust_choice = stoi(temp);
                        int counter = 0;
                        for (auto i = company_database.customer_begin(); i != company_database.customer_end(); i++) {
                            if (cust_choice - 1 == counter) {
                                cout << "Item: ";
                                string item;
                                getline(cin, item);
                                cout << "Quantity: ";
                                int _qty;
                                getline(cin, temp);
                                _qty = stoi(temp);
                                double _cost;
                                cout << "Cost: ";
                                getline(cin, temp);
                                _cost = stod(temp);
                                Purchase p(item, _qty, _cost);
                                i->add_purchase(p);
                                break;
                            }
                            counter++;
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
        else{
            break;
        }
    }

    ofstream opFile = file_stream_op(name+".dat");

    auto emp_start = company_database.employee_begin();

    auto emp_end = company_database.employee_end();

    int n_emp = emp_end - emp_start;

    opFile << n_emp << "\n";


    for(auto i=emp_start;i<emp_end;i++){
        opFile << i->name() << endl;
        opFile << i->email() << endl;
        opFile << i->phone() << endl;
        opFile << i->salary() << endl;
    }

    auto start = company_database.customer_begin();
    auto end = company_database.customer_end();
    opFile << end-start << endl;
    for(auto i=start;i<end;i++){
        opFile << i->name() << endl;
        opFile << i->email() << endl;
        opFile << i->phone() << endl;
        Customer c = *i;
        int n_p = 0;
        for(auto j=c.purchase_begin();j!=c.purchase_end();j++){
            n_p++;
        }
        opFile << n_p << endl;
        for(auto j=c.purchase_begin();j!=c.purchase_end();j++){
            opFile << j->item() << endl;
            opFile << j->qty() << endl;
            opFile << j->cost() << endl;
        }
    }
}

ofstream file_stream_op(string name){
    ofstream outputfile(name);
    return outputfile;
}

void getDatafromdat(Company& com, string fileName) {
    ifstream data_file(fileName);
    if(data_file){
        string temp;
        getline(data_file, temp);
        int cn = stoi(temp);
        for (int i = 0; i < cn; i++) {
            Employee e;
            getline(data_file, temp);
            e.name(temp);
            getline(data_file, temp);
            e.email(temp);
            getline(data_file, temp);
            e.phone(temp);
            getline(data_file, temp);
            double s = stod(temp);
            e.salary(s);
            com.add_employee(e);
        }
        getline(data_file, temp);
        cn = stoi(temp);
        for (int i = 0; i < cn; i++) {
            Customer c;
            getline(data_file, temp);
            c.name(temp);
            getline(data_file, temp);
            c.email(temp);
            getline(data_file, temp);
            c.phone(temp);
            getline(data_file, temp);
            int cn1 = stoi(temp);
            while (cn1 > 0) {
                getline(data_file, temp);
                string item;
                item = temp;
                getline(data_file, temp);
                int quantiity = stoi(temp);
                getline(data_file, temp);
                double cost = stod(temp);
                Purchase p(item, quantiity, cost);
                c.add_purchase(p);
                cn1--;
            }
            com.add_customer(c);
        }
    }
    else{
        ofstream createFile(fileName);
    }
}