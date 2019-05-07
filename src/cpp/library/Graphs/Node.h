#ifndef _NODE_N_H_
#define _NODE_N_H_

/*
 * Node Object
 *
 * A Graph is composed of Nodes, or "vertices." Trees also contain Nodes because
 * they are just a special case of a Graph.
 * Each Node contains an adjacency list called "neighbors", and a DataItem object.
 * See DataItem for more info- but in summary it's one of the ^following int, float, bool, std::string.
 *
 * ^ Can be expanded. Look through the code to see where you would have to add additional cases
 *   for new data types! Fork your own repo and give it a go!
*/
#include <vector>
#include <string>
#include "./DataItem.h"

using std::vector;

class Node {
public:
    Node() {}
    Node(DataItem d)                   : data(d)                  {}
    Node(DataItem d, vector<Node*> n)  : data(d), neighbors(n)    {}
    Node(vector<Node*> n)              : neighbors(n)             {}

    // Sets the data item.
    void set(DataItem d) { data = d; }

    // Prints "(type) -> (value)"
    void display();

    // Returns the data at this node.
    DataItem getData()                  { return data;      }

    // Returns the list of connected nodes.
    std::vector<Node*> getConnected()   { return neighbors; }

    // Sets the list of connected nodes.
    void setConnected(std::vector<Node*> n);
private:
    DataItem data;
    std::vector<Node*> neighbors;
};


#endif


