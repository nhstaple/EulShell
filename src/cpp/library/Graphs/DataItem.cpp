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

bool freemem(void* ptr, string type)
{
    if(ptr){
        if(type == "int")               { delete static_cast<int*>(ptr);    }
        else if (type == "float")       { delete static_cast<float*>(ptr);  }
        else if (type == "bool")        { delete static_cast<bool*>(ptr);   }
        else if (type == "std::string") { delete static_cast<string*>(ptr); }
        return true;
    }
    return false;
}

/*
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
    if(this->type == "std::string") {
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
*/

bool DataItem::getInt(int &var)
{
    if(this->type == "int") {
        var = *static_cast<int*>(this->data);
        return true;
    }
    return false;;
}

bool DataItem::getFloat(float &var)
{
    if(this->type == "float") {
        var = *static_cast<float*>(this->data);
        return true;
    }
    return false;
}

bool DataItem::getBool(bool &var)
{
    if(this->type == "bool") {
        var = *static_cast<bool*>(this->data);
        return true;
    }
    return false;
}

bool DataItem::getString(string &var)
{
    if(this->type == "std::string") {
        var = *static_cast<string*>(this->data);
        return true;
    }
    return false;
}

bool DataItem::getInt(int &var) const
{
    if(this->type == "int") {
        var = *static_cast<int*>(this->data);
        return true;
    }
    return false;;
}

bool DataItem::getFloat(float &var) const
{
    if(this->type == "float") {
        var = *static_cast<float*>(this->data);
        return true;
    }
    return false;
}

bool DataItem::getBool(bool &var) const
{
    if(this->type == "bool") {
        var = *static_cast<bool*>(this->data);
        return true;
    }
    return false;
}

bool DataItem::getString(string &var) const
{
    if(this->type == "std::string") {
        var = *static_cast<string*>(this->data);
        return true;
    }
    return false;
}

void DataItem::operator=( DataItem &D )
{
    this->type = D.type;
    if(this->data) {
        freemem(this->data, this->type);
        this->data = nullptr;
    }
    int var1;
    float var2;
    bool var3;
    string var4;
    if(D.getInt(var1)) {
        this->data = new int(var1);
    } else if (D.getFloat(var2)) {
        this->data = new float(var2);
    } else if (D.getBool(var3)) {
        this->data = new bool(var3);
    } else if (D.getString(var4)) {
        this->data = new string(var4);
    }
    // Do not free ptr because getInt mallocs a copy.
}

void DataItem::operator=(const DataItem &D )
{
    this->type = D.type;
    if(this->data) {
        freemem(this->data, this->type);
        this->data = nullptr;
    }
    int var1;
    float var2;
    bool var3;
    string var4;
    if(D.getInt(var1)) {
        this->data = new int(var1);
    } else if (D.getFloat(var2)) {
        this->data = new float(var2);
    } else if (D.getBool(var3)) {
        this->data = new bool(var3);
    } else if (D.getString(var4)) {
        this->data = new string(var4);
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
