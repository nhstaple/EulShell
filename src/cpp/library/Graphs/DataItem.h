#ifndef DATAITEM_H
#define DATAITEM_H
/*
 * Data Item Object
 *
 * Abstraction of a Data Element of a Node.
 *
 * Supported types are:
 *  int, float, bool, std::string
 *
 * Supported functions:
 *  set        ie data
 *  get        ie data
 *  getType()  returns the type as a string
 *  d1 == d2   returns true if the data values are equal, or if both are null
 *  d1 = d2    copies d2 into d1
*/

#include "../Utility/Typedata.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::stoi;
using std::stof;
using std::isdigit;

// Frees the void pointer with the given type.
bool freemem(void* ptr, string &type);

class DataItem {
public:
    ~DataItem();
/** Constructors. **/
    DataItem()           : data(nullptr), type("null") {}
    DataItem(int i)      : data(nullptr), type("null") { set(i); }
    DataItem(float f)    : data(nullptr), type("null") { set(f); }
    DataItem(bool b)     : data(nullptr), type("null") { set(b); }
    DataItem(string str) : data(nullptr), type("null")
    {
        bool has_only_digits = (str.find_first_not_of( "0123456789." ) == string::npos);
        if(has_only_digits && str != "." && str != ".." && str.size() > 0) {
            //
            if(std::stoi(str) || str == "0" || str == "1") { set(stoi(str)); }
            //
            else if (std::stof(str)) { set(stof(str)); }
         }
        else if(str == "true"  || str == "t") { set(true);  }
        else if(str == "false" || str == "f") { set(false); }
        else                                  { set(str);   }
    }

/** Set functions. **/
    void set(const int &i)      { if(this->data) { delete static_cast<int*>(this->data); this->data = nullptr; }
                                  type = type_name<decltype(i)>();
                                  this->data = new int(i); }

    void set(const float &f)    { if(this->data) { delete static_cast<float*>(this->data); this->data = nullptr; }
                                  type = type_name<decltype(f)>();
                                  this->data = new float(f); }

    void set(const bool &b)     { if(this->data) { delete static_cast<bool*>(this->data); this->data = nullptr; }
                                  type = type_name<decltype(b)>();
                                  this->data = new bool(b); }

    void set(const string &str) { if(this->data) { delete static_cast<string*>(this->data); this->data = nullptr; }
                                  type = type_name<decltype(str)>();
                                  this->data = new string(str); }
    /** Get functions. **/
protected:
    // Need to do type checking for the following.
    void* get()       { return data; }
    void* get() const { return data; }
public:
    // Returns the type as a string.
    string getType()  { return type; }

    // If these functions return true then this object holds that data type.
    // The variable passed as reference is then set to this value.
    bool getInt(int &var);
    bool getFloat(float &var);
    bool getBool(bool &var);
    bool getString(string &var);
    bool getInt(int &var) const;
    bool getFloat(float &var) const;
    bool getBool(bool &var) const;
    bool getString(string &var) const;

    /** Overloaded operators. **/
    void operator=(const DataItem &D);
    void operator=(DataItem &D);
    bool operator==(const DataItem &D);

private:
    void* data;
    string type;
};

#endif // DATAITEM_H
