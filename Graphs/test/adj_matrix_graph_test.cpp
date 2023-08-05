#include <vector>

#include "gtest/gtest.h"
#include "adj_matrix_graph.h"


TEST(adj_matrix, Parameters)
{
    const int vertices = 4;
    const int edges = 7; // TODO: compute the edges based on the neigh list
    std::vector<int> neigh[vertices] = {{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2}};
    AdjMatrixGraph g(vertices, 0, neigh);

    EXPECT_EQ(g.getVerticeCount(), vertices);

    EXPECT_EQ(g.getEdgeCount(), edges);
    // Add an edge between existing nodes
    g.addEdge(0, 1);
    EXPECT_EQ(g.getEdgeCount(), edges);
    // Add an edge between non-existing nodes
    g.addEdge(0, 3);
    EXPECT_EQ(g.getEdgeCount(), edges + 1);

    // Delete an edge between existing nodes
    g.delEdge(0, 3);
    EXPECT_EQ(g.getEdgeCount(), edges) << "Delete an edge between existing nodes";
    // Delete an edge between non-existing node
    g.delEdge(0, 3);
    EXPECT_EQ(g.getEdgeCount(), edges);
}