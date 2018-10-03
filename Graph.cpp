#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
struct vertex {
    typedef std::pair<int, vertex*> ve;
    std::vector<ve> adj; //cost of edge, destination vertex
    std::string name;
    vertex(std::string s) : name(s) {}
};

class graph
{
public:
    typedef std::map<std::string, vertex *> vmap;
    vmap work;
    void addvertex(const std::string&);
    void addedge(const std::string& from, const std::string& to, double cost);
};

void graph::addvertex(const std::string &name)
{
    vmap::iterator itr = work.find(name);
    if (itr == work.end())
    {
        vertex *v;
        v = new vertex(name);
        work[name] = v;
        return;
    }
    std::cout << "\nVertex already exists!";
}