#include "adj_matrix_graph.h"


AdjMatrixGraph::AdjMatrixGraph(int vertices, int edges, std::vector<int>)
{
    this->vertices = vertices;
    this->edges = edges;
    this->graph_type = Graph::GraphType::ADJ_MATRIX;

    this->adj_matrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        *(this->adj_matrix) = new int[vertices];
    }
}

AdjMatrixGraph::~AdjMatrixGraph()
{
    if (nullptr != adj_matrix)
    {
        delete[] adj_matrix;
    }
}
