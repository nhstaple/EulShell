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

int* DataItem::getInt()
{
    if(this->type == "int") {
        int value = *static_cast<int*>(this->data);
        return new int(value);
    }
    return nullptr;
}

float* DataItem::getFloat()
{
    if(this->type == "float") {
        float value = *static_cast<float*>(this->data);
        return new float(value);
    }
    return nullptr;
}

bool* DataItem::getBool()
{
    if(this->type == "bool") {
        bool value = *static_cast<bool*>(this->data);
        return new bool(value);
    }
    return nullptr;
}

string* DataItem::getString()
{
    if(this->type == "string") {
        string value = *static_cast<string*>(this->data);
        return new string(value);
    }
    return nullptr;
}

int* DataItem::getInt() const
{
    if(this->type == "int") {
        int value = *static_cast<int*>(this->data);
        return new int(value);
    }
    return nullptr;
}

float* DataItem::getFloat() const
{
    if(this->type == "float") {
        float value = *static_cast<float*>(this->data);
        return new float(value);
    }
    return nullptr;
}

bool* DataItem::getBool() const
{
    if(this->type == "bool") {
        bool value = *static_cast<bool*>(this->data);
        return new bool(value);
    }
    return nullptr;
}

string* DataItem::getString() const
{
    if(this->type == "string") {
        string value = *static_cast<string*>(this->data);
        return new string(value);
    }
    return nullptr;
}

void DataItem::operator=( DataItem &D )
{
    this->type = D.type;
    if(this->data) {
        free(this->data);
        this->data = nullptr;
    }
    void *ptr = nullptr;
    if((ptr = D.getInt())) {
        this->data = ptr;
    } else if ((ptr = D.getFloat())) {
        this->data = ptr;
    } else if ((ptr = D.getBool())) {
        this->data = ptr;
    } else if ((ptr = D.getString())) {
        this->data = ptr;
    }
    // Do not free ptr because getInt mallocs a copy.
}

void DataItem::operator=(const DataItem &D )
{
    this->type = D.type;
    if(this->data) {
        free(this->data);
        this->data = nullptr;
    }
    void *ptr = nullptr;
    if((ptr = D.getInt())) {
        this->data = ptr;
    } else if ((ptr = D.getFloat())) {
        this->data = ptr;
    } else if ((ptr = D.getBool())) {
        this->data = ptr;
    } else if ((ptr = D.getString())) {
        this->data = ptr;
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
