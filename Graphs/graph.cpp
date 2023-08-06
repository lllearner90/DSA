#include "graph.h"
#include "adj_matrix_graph.h"

Graph::~Graph()
{
}

Graph::GraphType Graph::getGraphType(void)
{
    return this->graph_type;
}

int Graph::getVerticeCount(void)
{
    return this->vertices;
}

int Graph::getEdgeCount(void)
{
    return this->edges;
}

int Graph::getNodeValue(int node)
{
    return this->node[node];
}

void Graph::setNodeValue(int node, int value)
{
    this->node[node] = value;
}

Graph *createGraph(int vertices, 
                    int edges, 
                    int max_distance, 
                    std::vector<int> neigh_list[],
                    Graph::GraphType graph_type)
{
    Graph *g;
    switch (graph_type)
    {
    case Graph::GraphType::ADJ_MATRIX:
        g = new AdjMatrixGraph(vertices, edges, neigh_list);
        break;
    
    case Graph::GraphType::ADJ_LIST:
        /* code */
        break;

    default:
        //TODO: Throw an error!
        break;
    }

    return g;
}

std::ostream &operator<<(std::ostream &os, Graph &g)
{
    g.printGraph(os);

    return os;
}