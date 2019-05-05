#include "./Node.h"
#include "../Utility/Typedata.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

// Node
void Node::display()
{
    string str;
    void* value = data.get();
    if(data.type == "null") {
        str = "null";
    } else if(data.type == "int") {
        str = "int      -> ";
        str += to_string(*static_cast<int*>(value));
    } else if (data.type == "float") {
        str = "float    -> ";
        str += to_string(*static_cast<float*>(value));
    } else if (data.type == "bool") {
        str = "bool     -> ";
        str += to_string(*static_cast<int*>(value));
    } else if (data.type == "std::string") {
        str = "std::str -> ";
        str += *static_cast<string*>(value);
    }
    cout << str << endl;
}

