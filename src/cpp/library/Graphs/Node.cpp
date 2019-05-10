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
    string type = this->data.getType();
    string str;
    if(type == "null") {
        str = "null";
    } else if(type == "int") {
        str = "int      -> ";
        int var;
        if(this->data.getInt(var)) { str += to_string(var); }
    } else if (type == "float") {
        str = "float    -> ";
        float var;
        if(this->data.getFloat(var)) { str += to_string(var); }
    } else if (type == "bool") {
        str = "bool     -> ";
        bool var;
        if(this->data.getBool(var)) { str += to_string(var); }
    } else if (type == "std::string") {
        str = "std::str -> ";
        string var;
        if(this->data.getString(var)) { str += var; }
    }
    cout << str << endl;
}

void Node::setConnected(std::vector<Node *> n)
{
   this->neighbors.clear();
   for(Node* n : n) {
       this->neighbors.push_back(n);
   }
}
