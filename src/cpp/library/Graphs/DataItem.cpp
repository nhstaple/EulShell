// library/Graphs/DataItem.cpp
#include "./DataItem.h"

bool freemem(void* ptr, string &type)
{
    if(ptr) {
        if(type == "int")               { delete static_cast<int*>(ptr);    }
        else if (type == "float")       { delete static_cast<float*>(ptr);  }
        else if (type == "bool")        { delete static_cast<bool*>(ptr);   }
        else if (type == "std::string") { delete static_cast<string*>(ptr); }
        return true;
    }
    return false;
}

DataItem::~DataItem()
{
    freemem(this->data, this->type);
}

bool DataItem::getInt(int &var)
{
    if(this->type == "int" || this->type == "int const&" ) {
        var = *static_cast<int*>(this->data);
        return true;
    }
    return false;;
}

bool DataItem::getInt(int &var) const
{
    if(this->type == "int" || this->type == "int const&" ) {
        var = *static_cast<int*>(this->data);
        return true;
    }
    return false;;
}

bool DataItem::getFloat(float &var)
{
    if(this->type == "float" || this->type == "float const&") {
        var = *static_cast<float*>(this->data);
        return true;
    }
    return false;
}

bool DataItem::getFloat(float &var) const
{
    if(this->type == "float" || this->type == "float const&") {
        var = *static_cast<float*>(this->data);
        return true;
    }
    return false;
}


bool DataItem::getBool(bool &var)
{
    if(this->type == "bool" || this->type == "bool const&") {
        var = *static_cast<bool*>(this->data);
        return true;
    }
    return false;
}

bool DataItem::getBool(bool &var) const
{
    if(this->type == "bool" || this->type == "bool const&") {
        var = *static_cast<bool*>(this->data);
        return true;
    }
    return false;
}

bool DataItem::getString(string &var)
{
    if(this->type == "std::string" || this->type == "std::string const&") {
        var = *static_cast<string*>(this->data);
        return true;
    }
    return false;
}

bool DataItem::getString(string &var) const
{
    if(this->type == "std::string" || this->type == "std::string const&") {
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

    if(D.getInt(var1))          { this->data = new int(var1);    }
    else if (D.getFloat(var2))  { this->data = new float(var2);  }
    else if (D.getBool(var3))   { this->data = new bool(var3);   }
    else if (D.getString(var4)) { this->data = new string(var4); }
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

    if(D.getInt(var1))          { this->data = new int(var1);    }
    else if (D.getFloat(var2))  { this->data = new float(var2);  }
    else if (D.getBool(var3))   { this->data = new bool(var3);   }
    else if (D.getString(var4)) { this->data = new string(var4); }
}

bool DataItem::operator==(const DataItem &D)
{
    if(this->type != D.type) {
        return false;
    }

    int var1;
    float var2;
    bool var3;
    string var4;

    if(this->getInt(var1)) {
        int value = *static_cast<int*>(D.data);
        if(var1 != value) {
            return false;
        }
    } else if(this->getFloat(var2)) {
        float value = *static_cast<float*>(D.data);
        if(var2 != value) {
            return false;
        }
    } else if(this->getBool(var3)) {
        bool value = *static_cast<bool*>(D.data);
        if(var3 != value) {
            return false;
        }
    } else if(this->getString(var4)) {
        string value = *static_cast<string*>(D.data);
        if(var4 != value) {
            return false;
        }
    }
    return true;
}
