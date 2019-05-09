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

bool freemem(void* ptr, string type);

class DataItem {
public:
    /** Constructors. **/
    DataItem()                  {         }
    DataItem(int i)             { set(i); }
    DataItem(float f)           { set(f); }
    DataItem(bool b)            { set(b); }
    DataItem(string str)
    {
        bool has_only_digits = (str.find_first_not_of( "0123456789." ) == string::npos);
        if(has_only_digits && str != "." && str != ".." && str.size() > 0) {
            if(std::stoi(str) || str == "0" || str == "1") { set(stoi(str)); }
            else if (std::stof(str)) { set(stof(str));}
         }
        else if(str == "true"  || str == "t")       { set(true);      }
        else if(str == "false" || str == "f")       { set(false);     }
        else                                        { set(str);       }
    }

    /** Set functions. **/
    void set(int i)      { type = type_name<decltype(i)>();   data = new int(i);      }
    void set(float f)    { type = type_name<decltype(f)>();   data = new float(f);    }
    void set(bool b)     { type = type_name<decltype(b)>();   data = new bool(b);     }
    void set(string str) { type = type_name<decltype(str)>(); data = new string(str); }

    /** Get functions. **/
    // Need to do type checking for the following.
    void* get()       { return data; }
    void* get() const { return data; }
    // Returns the type as a string.
    string getType()  { return type; }

    // If the pointers returned by these functions are not nullptrs,
    // then the pointer returned is a copy of the value stored in
    // this DataItem. Remember to free it after use.
    int*         getInt();
    int*         getInt()    const;
    float*       getFloat();
    float*       getFloat()  const;
    bool*        getBool();
    bool*        getBool()   const;
    std::string* getString();
    std::string* getString() const;

    /** Overloaded operators. **/
    void operator=(const DataItem &D);
    void operator=(DataItem &D);
    bool operator==(const DataItem &D);

private:
    void* data = nullptr;
    string type;
};

#endif // DATAITEM_H
