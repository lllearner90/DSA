#include <iostream>

#include "graph.h"
#include "adj_matrix_graph.h"

int main(void)
{
    std::vector<int> neigh[4] = {{1,2}, {0,2,3}, {0,1,3}, {1,2}};

    Graph *g = createGraph(4, 4, 2, neigh, Graph::GraphType::ADJ_MATRIX);

    std::cout << static_cast<AdjMatrixGraph&>(*g) ;

    return 0;
}