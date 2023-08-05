#include <cstring>
#include "adj_matrix_graph.h"


AdjMatrixGraph::AdjMatrixGraph(int vertices, int edges, std::vector<int> neigh)
{
    this->vertices = vertices;
    this->edges = edges;
    this->graph_type = Graph::GraphType::ADJ_MATRIX;

    this->adj_matrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        this->adj_matrix[i] = new int[vertices];
    }

    // Size of memory chunck = size  of an int * total number of int
    // total number of int in this case is vertices squared!
    std::memset(this->adj_matrix, 0, sizeof(int) * vertices * vertices);

    for (int i = 0; i < neigh.size(); i++)
    {
        // int neigh_list[] = neigh[0];
        for (int j = 0; j < neigh[i].size(); j++)
        {
            int neigh = neigh[i][j];
            adj_matrix[i][neigh] = adj_matrix[neigh][i] = 1; // Todo: get weight as input
        }
    }
}

AdjMatrixGraph::~AdjMatrixGraph()
{
    if (nullptr != adj_matrix)
    {
        delete[] adj_matrix;
    }
}

int AdjMatrixGraph::getEdgeValue(int node1, int node2)
{
    return this->adj_matrix[node1][node2];
}

std::vector<int> AdjMatrixGraph::getNeighbours(int node)
{
    std::vector<int> neigh;
    
    for (int i = 0; i < this->getVerticeCount(); i++)
    {
        if (this->adj_matrix[node][i] > 0)
        {
            neigh.push_back(i);
        }
    }
    return neigh;
}

void AdjMatrixGraph::addEdge(int start_node, int end_node)
{
    this->adj_matrix[start_node][end_node] = this->adj_matrix[end_node][start_node] = 1;
}

void AdjMatrixGraph::delEdge(int start_node, int end_node)
{
    this->adj_matrix[start_node][end_node] = this->adj_matrix[end_node][start_node] = 0;
}

std::ostream &operator<<(std::ostream &os, Graph &g)
{
    for (int i = 0; i < g.getVerticeCount(); i++)
    {
        os << "|\t";
        for (int j = 0; j < g.getVerticeCount(); j++)
        {
            os << g.getEdgeValue(i, j) << "\t";
        }
        os << "|\n";
    }
}
