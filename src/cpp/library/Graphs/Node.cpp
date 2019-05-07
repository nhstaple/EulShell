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
    void* value = this->data.get();
    if(this->data.getType() == "null") {
        str = "null";
    } else if(this->data.getType() == "int") {
        str = "int      -> ";
        str += to_string(*static_cast<int*>(value));
    } else if (this->data.getType() == "float") {
        str = "float    -> ";
        str += to_string(*static_cast<float*>(value));
    } else if (this->data.getType() == "bool") {
        str = "bool     -> ";
        str += to_string(*static_cast<int*>(value));
    } else if (this->data.getType() == "std::string") {
        str = "std::str -> ";
        str += *static_cast<string*>(value);
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
