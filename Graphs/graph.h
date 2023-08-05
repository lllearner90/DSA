#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <ostream>

class Graph
{
public:
    enum class GraphType
    {
        ADJ_MATRIX,
        ADJ_LIST
    };
    // Graph(int vertices, int edges);
    virtual ~Graph();
    GraphType getGraphType(void);
    int getVerticeCount(void);
    int getEdgeCount(void);
    int getNodeValue(int node);
    virtual int getEdgeValue(int node1, int node2) = 0;
    virtual std::vector<int> getNeighbours(int node1) = 0;
    virtual void addEdge(int start_node, int end_node) = 0;
    virtual void delEdge(int start_node, int end_node) = 0;
    virtual void printGraph(std::ostream& os) = 0;
    friend std::ostream& operator<<(std::ostream& os, Graph &g);
protected:
    int vertices;
    int edges;
    GraphType graph_type;
    std::vector<int> node;
};

Graph *createGraph(int vertices, 
                    int edges, 
                    int max_distance, 
                    std::vector<int> neigh_list[],
                    Graph::GraphType graph_type);


#endif // __GRAPH_H__