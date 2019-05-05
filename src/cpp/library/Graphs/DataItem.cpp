/*
 * Potential issue... make get() a protected function??
 * Example Code
    DataItem i1(1), i2(2);
    i1 = i2;
    Node n(i1), m(i2);
    n.display();
    *static_cast<int*>(m.getData().get()) = 100;
    n.display();
    m.display();
    cout << (i1 == i2) << endl;
    cout << (i1 == i1) << endl;
 * Expected Output
    int      -> 2
    int      -> 2
    int      -> 100
    0
    1
*/
#include "./DataItem.h"
#include <string>
using std::string;

void DataItem::operator=( DataItem &D )
{
    this->type = D.type;
    if(this->data) {
        free(this->data);
        this->data = nullptr;
    }
    if(this->type == "int") {
        int value = *static_cast<int*>(D.data);
        this->data = new int(value);
    } else if (this->type == "float") {
        float value = *static_cast<float*>(D.data);
        this->data = new float(value);
    } else if (this->type == "bool") {
        bool value = *static_cast<bool*>(D.data);
        this->data = new bool(value);
    } else if (this->type == "std::string") {
        string value = *static_cast<string*>(D.data);
        this->data = new string(value);
    }
}

void DataItem::operator=(const DataItem &D )
{
    this->type = D.type;
    if(this->data) {
        free(this->data);
        this->data = nullptr;
    }
    if(this->type == "int") {
        int value = *static_cast<int*>(D.data);
        this->data = new int(value);
    } else if (this->type == "float") {
        float value = *static_cast<float*>(D.data);
        this->data = new float(value);
    } else if (this->type == "bool") {
        bool value = *static_cast<bool*>(D.data);
        this->data = new bool(value);
    } else if (this->type == "std::string") {
        string value = *static_cast<string*>(D.data);
        this->data = new string(value);
    }
}

bool DataItem::operator==(const DataItem &D)
{
    if(this->type != D.type) {
        return false;
    }
    if(this->type == "int") {
        int value = *static_cast<int*>(D.data);
        if(*static_cast<int*>(this->data) != value) {
            return false;
        }
    } else if (this->type == "float") {
        float value = *static_cast<float*>(D.data);
        if(*static_cast<float*>(this->data) != value) {
            return false;
        }
    } else if (this->type == "bool") {
        bool value = *static_cast<bool*>(D.data);
        if(*static_cast<bool*>(this->data) != value) {
            return false;
        }
    } else if (this->type == "std::string") {
        string value = *static_cast<string*>(D.data);
        if(*static_cast<string*>(this->data) != value) {
            return false;
        }
    }
    return true;
}
