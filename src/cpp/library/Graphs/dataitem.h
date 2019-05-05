#ifndef DATAITEM_H
#define DATAITEM_H

#include <string>

#include "../Utility/Typedata.h"

class DataItem {
public:
    DataItem(int i) { set(i); }
    DataItem(float f) { set(f); }
    DataItem(bool b) { set(b); }
    DataItem(std::string str) { set(str); }
    DataItem() {}

    void set(int i) { type = type_name<decltype(i)>(); data = new int(i); }
    void set(float f) { type = type_name<decltype(f)>(); data = new float(f); }
    void set (bool b) { type = type_name<decltype(b)>(); data = new bool(b); }
    void set(std::string str) { type = type_name<decltype(str)>(); data = new std::string(str); }
    void* get() { return data; }
    void* get() const { return data; }

    std::string type;

    void operator = (const DataItem &D );

    void operator = (DataItem &D );

// private:
    void* data = nullptr;
};

#endif // DATAITEM_H
