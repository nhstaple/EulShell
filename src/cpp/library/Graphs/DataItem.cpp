/*
 *
 * Example Code
    DataItem i1(1), i2(2);
    i1 = i2;
    Node n(i1), m(i2);
    n.display();
    *static_cast<int*>(m.getData().get()) = 100;
    n.display();
    m.display();
 * Expected Output
    int      -> 2
    int      -> 2
    int      -> 100
*/
#include "./DataItem.h"
#include <string>
using std::string;

void DataItem::operator=( DataItem &D )
{
    this->type = D.type;
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
