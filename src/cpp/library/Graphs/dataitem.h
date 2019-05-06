#ifndef DATAITEM_H
#define DATAITEM_H

#include <string>
#include "../Utility/Typedata.h"

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



class DataItem {
public:
    // Constructors.
    DataItem()                  {           }
    DataItem(int i)             { set(i);   }
    DataItem(float f)           { set(f);   }
    DataItem(bool b)            { set(b);   }
    DataItem(std::string str)
    {
        if(std::stoi(str))                  { set(std::stoi(str)); }
        else if(std::stof(str))             { set(std::stof(str)); }
        else if(str == "true" || str == "false" ||
                  str == "t" || str == "f") { set(std::stof(str)); }
        else                                { set(str);            }
    }

    // set functions
    void set(int i)             { type = type_name<decltype(i)>();   data = new int(i);             }
    void set(float f)           { type = type_name<decltype(f)>();   data = new float(f);           }
    void set(bool b)            { type = type_name<decltype(b)>();   data = new bool(b);            }
    void set(std::string str)   { type = type_name<decltype(str)>(); data = new std::string(str);   }

    void* get()                 { return data; }
    void* get() const           { return data; }
    std::string getType()       { return type; }

    int*         getInt();
    int*         getInt()    const;
    float*       getFloat();
    float*       getFloat()  const;
    bool*        getBool();
    bool*        getBool()   const;
    std::string* getString();
    std::string* getString() const;

    void operator=(const DataItem &D);
    void operator=(DataItem &D);
    bool operator==(const DataItem &D);

private:
    void* data = nullptr;
    std::string type;
};

#endif // DATAITEM_H
