#ifndef __ADJ_MATRIX_GRAPH_H__
#define __ADJ_MATRIX_GRAPH_H__

#include <ostream>

#include "graph.h"


class AdjMatrixGraph : public Graph
{
public:
    AdjMatrixGraph(int vertices, int edges, std::vector<int> neigh);
    ~AdjMatrixGraph();

    int getEdgeValue(int node1, int node2) override;
    std::vector<int> getNeighbours(int node) override;
    friend std::ostream& operator<<(std::ostream& os, Graph &g);
private:
    int **adj_matrix = nullptr;
};


#endif // __ADJ_MATRIX_GRAPH_H__