#include <vector>

#include "gtest/gtest.h"
#include "adj_matrix_graph.h"

class AdjMatrixTestFixture : public ::testing::Test
{
protected:
    int vertices = 4;
    int edges = 7; // TODO: compute the edges based on the neigh list
    AdjMatrixGraph *g;
    std::vector<int> node_value;
    // TODO: find way to use vertices instead of hardcoded number
    std::vector<int> neigh[4] = {{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2}};

    virtual void SetUp()
    {
        // neigh = {{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2}};
        g = new AdjMatrixGraph(vertices, 0, neigh);
        node_value = {2, 1, 3, 0};
        for (int i = 0; i < vertices; i++)
        {
            g->setNodeValue(i, node_value[i]);
        }
    }

    virtual void TearDown()
    {
        delete g;
    }
};

TEST_F(AdjMatrixTestFixture, VerticeCount)
{
    EXPECT_EQ(g->getVerticeCount(), vertices) << "Vertice count mismatch!";
}

TEST_F(AdjMatrixTestFixture, EdgeCount)
{
    EXPECT_EQ(g->getEdgeCount(), edges) << "Edge count mismatch!";
}

TEST_F(AdjMatrixTestFixture, AddEdgeBetweenExistingNode)
{
    g->addEdge(0, 1);
    EXPECT_EQ(g->getEdgeCount(), edges) << "Failed since node added between existing nodes";
}

TEST_F(AdjMatrixTestFixture, AddEdgeBetweenNonExistingNode)
{
    g->addEdge(0, 3);
    EXPECT_EQ(g->getEdgeCount(), edges + 1) << "Failed to Add an edge between non-existing nodes";
}

TEST_F(AdjMatrixTestFixture, DelEdgeBetweenExistingNode)
{
    g->delEdge(0, 3);
    EXPECT_EQ(g->getEdgeCount(), edges) << "Failed to Delete an edge between existing nodes";
}

TEST_F(AdjMatrixTestFixture, DelEdgeBetweenNonExistingNode)
{
    g->delEdge(0, 3);
    EXPECT_EQ(g->getEdgeCount(), edges) << "Failed since edge deleted between existing nodes";
}

TEST_F(AdjMatrixTestFixture, TestNodeValue)
{
    for (int i = 0; i < vertices; i++)
    {
        EXPECT_EQ(g->getNodeValue(i), node_value[i]);
    }
}

TEST_F(AdjMatrixTestFixture, TestEdgeValue)
{
    for (int i = 0; i < vertices; i++)
    {
        for (auto it : neigh[i])
        {
            EXPECT_GE(g->getEdgeValue(i, it), true) << "Neighbour but edge value is less than 1!";
        }
    }
}

TEST_F(AdjMatrixTestFixture, TestNeigbours)
{
    for (int i = 0; i < vertices; i++)
    {
        EXPECT_EQ(g->getNeighbours(i), neigh[i]);
    }
}