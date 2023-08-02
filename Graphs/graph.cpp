#include "graph.h"
#include "adj_matrix_graph.h"

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

Graph createGraph(int vertices, 
                    int edges, 
                    int max_distance, 
                    std::vector<int> neigh_list,
                    Graph::GraphType graph_type)
{
    Graph g;
    switch (graph_type)
    {
    case Graph::GraphType::ADJ_MATRIX:
        g = AdjMatrixGraph(vertices, edges, neigh_list);
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
