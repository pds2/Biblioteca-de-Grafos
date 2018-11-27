#include "directed_graph.h"
#include "edges.h"
#include "constants.h"
#include "doctest.h"
#include "graph_generator.h"
#include <bits/stdc++.h>
#define aaa std::cout<<"aqui"<<std::endl;

TEST_CASE("TESTE - Construtor"){
    for(int i = 1; i <= 1000; i++){
        CHECK_NOTHROW(Directed dg(i));
        Directed dg(i);
        CHECK(dg.order() == i);
    }
    Edges ed;
    for( int i=1; i<=5; i++ ){
      for( int j=1; j<=5; j++ ){
        if( i==j )continue;
        ed.insert(i, j);
      }
    }
    CHECK_NOTHROW(Directed dg(5,ed));
}

TEST_CASE("TESTE - Adicionar arestas"){
    Directed dg(10);
    dg.add_edge(1, 1, 1);
    dg.add_edge(1, 2, 9);
    dg.add_edge(3, 2, 3);
    dg.add_edge(10, 4, 5);
    dg.add_edge(5,6);
    dg.add_edge(1,10);
    dg.add_edge(1,10,1);

    CHECK(dg.has_edge(1, 1) == 1);
    CHECK(dg.has_edge(1, 2) == 9);
    CHECK(dg.has_edge(3, 2) == 3);
    CHECK(dg.has_edge(10, 4) == 5);
    CHECK(dg.has_edge(5,6) == 1);
    CHECK(dg.has_edge(1, 3) == 0);
    CHECK(dg.has_edge(2, 1) == 0);
    CHECK(dg.has_edge(4, 10) == 0);

    CHECK_THROWS(dg.add_edge(1, 11));
    CHECK_THROWS(dg.add_edge(0, 1));
    CHECK_THROWS(dg.add_edge(11, 1));
    CHECK_THROWS(dg.add_edge(0,1));
    CHECK_THROWS(dg.add_edge(1,1,0));
    CHECK_THROWS(dg.add_edge(0,0, 10));

    dg.add_edge(1,10,-1);
    CHECK(dg.has_edge(1,10) == -1);
    dg.add_edge(1,10,1);
    CHECK(dg.has_edge(1,10) == 1);
}
TEST_CASE("TESTE - Remover arestas"){
    Directed dg(10);
    dg.add_edge(1,4);
    dg.add_edge(1,5);
    dg.add_edge(1,6);
    dg.add_edge(2,4);
    dg.add_edge(2,5);
    dg.add_edge(2,6);
    dg.add_edge(3,4);
    dg.add_edge(3,5);
    dg.add_edge(3,6);
    dg.remove_edge(3,6);
    dg.remove_edge(2,4);
    dg.remove_edge(1,5);

    CHECK(dg.has_edge(3,6) == 0);
    CHECK(dg.has_edge(2,4) == 0);
    CHECK(dg.has_edge(1,5) == 0);

    CHECK_THROWS(dg.remove_edge(1,1));
    CHECK_THROWS(dg.remove_edge(1,12));
    CHECK_THROWS(dg.remove_edge(13,1));
    CHECK_THROWS(dg.remove_edge(0,4));
    CHECK_THROWS(dg.remove_edge(5,0));
}
TEST_CASE("TESTE - Checar grau de entrada e saida"){
    Directed dg(6);
    dg.add_edge(1,4);
    dg.add_edge(1,5);
    dg.add_edge(1,6);
    dg.add_edge(2,4);
    dg.add_edge(2,5);
    dg.add_edge(2,6);
    dg.add_edge(3,4);
    dg.add_edge(3,5);
    dg.add_edge(3,6);
    dg.add_edge(4,5);
    dg.add_edge(5,5);
    dg.add_edge(4,2);

    CHECK(dg.check_degree_in(1) == 0);
    CHECK(dg.check_degree_out(1) == 3);
    CHECK(dg.check_degree_in(2) == 1);
    CHECK(dg.check_degree_out(2) == 3);
    CHECK(dg.check_degree_in(3) == 0);
    CHECK(dg.check_degree_out(3) == 3);
    CHECK(dg.check_degree_in(4) == 3);
    CHECK(dg.check_degree_out(4) == 2);
    CHECK(dg.check_degree_in(5) == 5);
    CHECK(dg.check_degree_out(5) == 1);
    CHECK(dg.check_degree_in(6) == 3);
    CHECK(dg.check_degree_out(6) == 0);

    CHECK_THROWS(dg.check_degree_in(0));
    CHECK_THROWS(dg.check_degree_in(7));
    CHECK_THROWS(dg.check_degree_out(0));
    CHECK_THROWS(dg.check_degree_out(7));
}
TEST_CASE("TESTE - Checar se um grafo tem ciclo e componentes fortemente conexos"){
    Directed dg(10);
    CHECK(dg.has_cycle() == 0);
    CHECK(dg.get_sccs() == 10);
    for(int i = 1; i <= 10; i++){
        CHECK(dg.get_component(i) == 10-i+1);
    }
    dg.add_edge(1,2); dg.add_edge(2,3);
    dg.add_edge(3,4); dg.add_edge(4,5);
    dg.add_edge(5,6); dg.add_edge(6,7);
    dg.add_edge(7,8); dg.add_edge(8,9);
    dg.add_edge(9,10);
    CHECK(dg.has_cycle() == 0);
    CHECK(dg.get_sccs() == 10);
    CHECK(dg.has_cycle() == 0);
    CHECK(dg.get_sccs() == 10);
    for(int i = 1; i <= 10; i++){
        CHECK(dg.get_component(i) == i);
    }
    dg.add_edge(10,1);
    CHECK(dg.has_cycle() == 1);
    CHECK(dg.get_sccs() == 1);
    CHECK(dg.has_cycle() == 1);
    CHECK(dg.get_sccs() == 1);
    for(int i = 1; i <= 10; i++){
        CHECK(dg.get_component(i) == 1);
    }
    dg.remove_edge(10,1);
    CHECK(dg.has_cycle() == 0);
    CHECK(dg.get_sccs() == 10);
    dg.add_edge(5,1); dg.add_edge(10,6);
    CHECK(dg.has_cycle() == 1);
    CHECK(dg.get_sccs() == 2);
    for(int i = 1; i <= 5; i++){
        CHECK(dg.get_component(i) == 1);
    }
    for(int i = 6; i <= 10; i++){
        CHECK(dg.get_component(i) == 2);
    }
    Directed dg2(4);
    dg2.add_edge(1,2);
    dg2.add_edge(2,1);
    CHECK(dg2.get_component(1) == 3);
    CHECK(dg2.get_component(2) == 3);
    CHECK(dg2.get_component(3) == 2);
    CHECK(dg2.get_component(4) == 1);
    CHECK(dg2.has_cycle() == 1);
    CHECK(dg2.get_sccs() == 3);
}
TEST_CASE("TESTE - Verificar se o grafo é conexo"){
  Directed dg(10);
  dg.add_edge(1,2); dg.add_edge(2,3);
  dg.add_edge(3,4); dg.add_edge(4,5);
  dg.add_edge(5,6); dg.add_edge(6,7);
  dg.add_edge(7,8); dg.add_edge(8,9);
  dg.add_edge(9,10);
  CHECK(dg.connected() == 0);
  dg.add_edge(10,1);
  CHECK(dg.connected() == 1);
  dg.remove_edge(10,1);
  CHECK(dg.connected() == 0);
  dg.add_edge(5,1); dg.add_edge(10,6);
  CHECK(dg.connected() == 0);
  Directed dg2(4);
  dg2.add_edge(1,2);
  dg2.add_edge(2,1);
  CHECK(dg2.connected() == 0);
}
TEST_CASE("TESTE - Reflexividade e Irreflexividade"){
  Directed r(100);
  CHECK(r.irreflexive() == 1);
  CHECK(r.reflexive() == 0);
  for(int i = 1; i <= 100; i++)
      r.add_edge(i,i);
  CHECK(r.irreflexive() == 0);
  CHECK(r.reflexive() == 1);
  r.remove_edge(30,30);
  CHECK(r.reflexive() == 0);
  CHECK(r.irreflexive() == 0);
}
TEST_CASE("TESTE - Simetria, assimetria e Antisimetria"){
  Directed sim(100);
  CHECK(sim.symmetric() == 1);
  CHECK(sim.antissymetric() == 1);
  CHECK(sim.assymetric() == 1);
  for(int i = 1; i <= 100; i++){
      sim.add_edge(i,i);
  }
  CHECK(sim.symmetric() == 1);
  CHECK(sim.antissymetric() == 1);
  CHECK(sim.assymetric() == 0);
  sim.remove_edge(2,2);
  CHECK(sim.symmetric() == 1);
  CHECK(sim.antissymetric() == 1);
  CHECK(sim.assymetric() == 0);
  sim.add_edge(1,2); sim.add_edge(2,1);
  CHECK(sim.symmetric() == 1);
  CHECK(sim.antissymetric() == 0);
  CHECK(sim.assymetric() == 0);
  sim.remove_edge(1,2);
  CHECK(sim.symmetric() == 0);
  CHECK(sim.antissymetric() == 1);
  CHECK(sim.assymetric() == 0);
  Directed asym(100);
  for(int i = 1; i <= 100; i++)
      for(int j = 1; j < i; j++)
          asym.add_edge(i,j);
  CHECK(asym.symmetric() == 0);
  CHECK(asym.antissymetric() == 1);
  CHECK(asym.assymetric() == 1);
}
TEST_CASE("TESTE - Transitividade"){
  Directed t(5);
  CHECK(t.transitive() == 1);
  t.add_edge(1,2); t.add_edge(2,3); t.add_edge(1,3);
  CHECK(t.transitive() == 1);
  t.remove_edge(1,3);
  CHECK(t.transitive() == 0);
  t.add_edge(1,3); t.remove_edge(2,3);
  CHECK(t.transitive() == 1);
}
TEST_CASE("TESTE - Ordenação Topológica"){
  Directed dg(10);
  dg.add_edge(1,3);
  dg.add_edge(3,5);
  dg.add_edge(2,4);
  dg.add_edge(2,5);
  dg.add_edge(2,7);
  dg.add_edge(1,6);
  dg.add_edge(6,9);
  CHECK_NOTHROW(dg.topological_order());
  dg.add_edge(3,1);
  CHECK_NOTHROW(dg.topological_order());
}
TEST_CASE("TESTE - Grafos Comprimidos"){
  DAG *dag;
  Directed dg1(10);
  dg1.add_edge(1,2);dg1.add_edge(2,1);
  dag = dg1.get_compressed_graph();
  CHECK(dag->order() == dg1.order()-1);
  delete dag;
  Directed dg2(4);
  dg2.add_edge(1,2); dg2.add_edge(2,1);
  dg2.add_edge(2,3); dg2.add_edge(1,4);
  dag = dg2.get_compressed_graph();
  int c1 = dg2.get_component(1);
  int c2 = dg2.get_component(3);
  int c3 = dg2.get_component(4);
  CHECK(dag->has_edge(c1,c2) == 1);
  CHECK(dag->has_edge(c1,c3) == 1);
  delete dag;
}
