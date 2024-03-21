#include "ngraph.hpp"
#include <iostream>

int main() {
  using namespace NGraph;

  Graph A;
  A.insert_edge(3, 4);
  A.insert_edge(4, 5);
  A.insert_edge(0, 1);
  A.insert_edge(5, 6);
  A.insert_edge(6, 0);
  A.insert_edge(6, 4);
  A.insert_edge(1, 4);

  std::cout << "Graph has " << A.num_vertices() << " vertices and "
            << A.num_edges() << " edges.\n";

  //  for each node in the graph...
  //
  for (Graph::const_iterator p = A.begin(); p != A.end(); p++) {
    int od = A.out_degree(p);
    int id = A.in_degree(p);
    std::cout << "Node " << p->first << " has " << od << " out-edges\n";
    std::cout << "Node " << p->first << " has " << id << " in-edges\n";

    // identify its neighbors
    //
    Graph::vertex_set Si = A.in_neighbors(p);
    Graph::vertex_set So = A.out_neighbors(p);

    // print out each out-going edge
    //
    for (Graph::vertex_set::const_iterator t = Si.begin(); t != Si.end(); t++) {
      std::cout << *t << "\n";
    }
    std::cout << "\n";
  }
}