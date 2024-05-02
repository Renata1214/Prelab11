// Build an undirected graph structure by parsing pairs of vertices as shown in the
// example below. Do not use pointers! Do not use operator new. Use STL containers and names
// as the addresses of the vertices. Each vertex (node) is a “struct” that may have arbitrary data.
// Add on/off flag to the “struct” in order to mark visited nodes.

#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

struct Node {
    string address;
    bool visited;

    Node (string& n) 
    {
        address=n;
        visited=false;
    }

};

struct Graph 
{
    set<Node> cities;
    map<Node, list<string>> Map;

    void Connect(string& city1, string& city2) 
    {
        Node node1(city1);
        Node node2(city2);

        cities.insert(node1);
        cities.insert(node2);
        
        Map[node1].push_back(city2);
        Map[node2].push_back(city1);
    }

    bool Adjacent(Node& city1, Node& city2) const
    {
        //Find first using the functions of map 
        auto temp = Map.find(city1);

        if (temp != Map.end()) 
        {
            const list<string>& neighbors = it->second;
            return find(neighbors.begin(), neighbors.end(), city2.name) != neighbors.end();
        }

        return false;
    }

};

int main () 
{

    ifstream infile("data.txt");
        if (!infile.is_open()) 
            throw ("Error opening file"); 

 string vertex1, vertex2;
    while (infile >> vertex1 >> vertex2) {
        graph.addConnection(vertex1, vertex2);
        infile >> vertex1;
    }

    graph.printGraph();
    infile.close();
    return 0;

}

