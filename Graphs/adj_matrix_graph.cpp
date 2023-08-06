#include <cstring>
#include "adj_matrix_graph.h"

AdjMatrixGraph::AdjMatrixGraph(int vertices, int edges, std::vector<int> neigh[])
{
    this->vertices = vertices;
    this->edges = edges;
    this->graph_type = Graph::GraphType::ADJ_MATRIX;
    this->adj_matrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        // create and initialize node value list
        this->node.push_back(-1);
        this->adj_matrix[i] = new int[vertices];
    }

    for (int i = 0; i < vertices; i++)
    {
        // int neigh_list[] = neigh[0];
        for (int j = 0; j < neigh[i].size(); j++)
        {
            if (i == j)
            {
                // Distance from same node is assumed zero
                this->adj_matrix[i][j] = 0;
            }
            else
            {
                int n = neigh[i].at(j);
                this->adj_matrix[i][n] = this->adj_matrix[n][i] = 1; // Todo: get weight as input
                this->edges++;
            }
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
    if (this->getEdgeValue(start_node, end_node) <= 0)
    {
        this->adj_matrix[start_node][end_node] = this->adj_matrix[end_node][start_node] = 1;
        this->edges++;
    }
}

void AdjMatrixGraph::delEdge(int start_node, int end_node)
{
    if (this->getEdgeValue(start_node, end_node) > 0)
    {
        this->adj_matrix[start_node][end_node] = this->adj_matrix[end_node][start_node] = 0;
        if (this->edges > 0)
        {
            this->edges--;
        }
    }
}

void AdjMatrixGraph::printGraph(std::ostream &os)
{
    for (int i = 0; i < this->getVerticeCount(); i++)
    {
        os << "|\t";
        for (int j = 0; j < this->getVerticeCount(); j++)
        {
            os << this->getEdgeValue(i, j) << "\t";
        }
        os << "|\n";
    }
}
