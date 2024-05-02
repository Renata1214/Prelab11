#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

struct Graph {
    map<string, list<string>> Map;

    void Connection(const string& v1, const string& v2)
    {
        Map[v1].push_back(v2);
        Map[v2].push_back(v1);
    }

    bool Adjacent(string& city1,  string& city2) const 
    {
        auto it = Map.find(city1);
        if (it != Map.end()) 
        {
            return find(it->second.begin(), it->second.end(), city2) != it->second.end();
        }
        return false;
    }
};

int main() {
    Graph graph;
    ifstream infile("data.txt");
    if (!infile.is_open()) 
        throw ("Error opening file"); 

    string vert1, vert2;
    while (infile >> vert1 >> vert2) {
        graph.Connection(vert1, vert2);
        infile >> vert1;
    }

    //Printing
       for (pair<const string, list<string>>& pair : graph.Map) {
            cout << "City: " << pair.first << "  -> ";
            for (const string& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    infile.close();
    return 0;
}