#include "directed_graph.h"
#include "undirected_graph.h"
#include "doctest.h"
#include "graph_generator.h"
#include <bits/stdc++.h>

TEST_CASE("TESTE - Checando o gerador de grafos dirigidos"){
  std::cout << "------Grafos Direcionados------" << std::endl << std::endl;
  for(int i = 0; i < 20; i++){
      std::cout << i+1 << " grafo gerado aleatoriamente" << std::endl;
      Directed *dg = generate_directed_graph();
      CHECK_NOTHROW(dg->check_degree_in(1));
      CHECK_NOTHROW(dg->check_degree_out(dg->order()));
      CHECK_NOTHROW(dg->has_cycle());
      CHECK_NOTHROW(dg->get_sccs());
      CHECK_NOTHROW(dg->connected());
      CHECK_NOTHROW(dg->reflexive());
      CHECK_NOTHROW(dg->symmetric());
      CHECK_NOTHROW(dg->assymetric());
      CHECK_NOTHROW(dg->transitive());
      delete dg;
  }
  std::cout << "-----------------------------------" << std::endl << std::endl;
}
TEST_CASE("TESTE - Checando o gerador de grafos não-dirigidos"){
  std::cout << "----Grafos não Direcionados----" << std::endl << std::endl;
  for(int i = 0; i < 20; i++){
      std::cout << i+1 << " grafo gerado aleatoriamente" << std::endl;
      Undirected *ug = generate_undirected_graph();
      CHECK_NOTHROW(ug->check_degree(1));
      CHECK_NOTHROW(ug->check_degree(ug->order()));
      CHECK_NOTHROW(ug->has_cycle());
      CHECK_NOTHROW(ug->connected());
      CHECK_NOTHROW(ug->bipartite());
      CHECK_NOTHROW(ug->euler_graph());
      delete ug;
  }
  std::cout << "-----------------------------------" << std::endl << std::endl;
}
