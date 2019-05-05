#ifndef _NODE_N_H_
#define _NODE_N_H_

#include <vector>
#include <string>
#include "./DataItem.h"

class Node {
public:
    Node(DataItem d) : data(d) {}
    Node(DataItem d, std::vector<Node*> n) : data(d), neighbors(n) {}
    Node(std::vector<Node*> n) : neighbors(n) {}
    Node() {}

    void set(DataItem d) { data = d; }
    void display();
    DataItem getData() { return data; }
    std::vector<Node*> getConnected() { return neighbors; }
private:
    DataItem data;
    std::vector<Node*> neighbors;
};


#endif


