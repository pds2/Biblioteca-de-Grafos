#include "directed_graph.h"
#include "doctest.h"
#include <bits/stdc++.h>
#define aaa std::cout<<"aqui"<<std::endl;

TEST_CASE("TESTE - Construtor"){
    for(int i = 1; i <= 1000; i++){
        CHECK_NOTHROW(Directed dg(i));
    }
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
}
TEST_CASE("TESTE - Checar se um grafo tem ciclo e componentes fortemente conexos"){
    Directed dg(10);
    CHECK(dg.has_cycle() == 0);
    CHECK(dg.get_sccs() == 10);
    dg.add_edge(1,2); dg.add_edge(2,3);
    dg.add_edge(3,4); dg.add_edge(4,5);
    dg.add_edge(5,6); dg.add_edge(6,7);
    dg.add_edge(7,8); dg.add_edge(8,9);
    dg.add_edge(9,10);
    CHECK(dg.has_cycle() == 0);
    CHECK(dg.get_sccs() == 10);
    CHECK(dg.has_cycle() == 0);
    CHECK(dg.get_sccs() == 10);
    dg.add_edge(10,1);
    CHECK(dg.has_cycle() == 1);
    CHECK(dg.get_sccs() == 1);
    CHECK(dg.has_cycle() == 1);
    CHECK(dg.get_sccs() == 1);
    dg.remove_edge(10,1);
    CHECK(dg.has_cycle() == 0);
    CHECK(dg.get_sccs() == 10);
    dg.add_edge(5,1); dg.add_edge(10,6);
    CHECK(dg.has_cycle() == 1);
    CHECK(dg.get_sccs() == 2);
    dg = Directed(4);
    dg.add_edge(1,2);
    dg.add_edge(2,1);
    aaa
    CHECK(dg.has_cycle() == 1);
    CHECK(dg.get_sccs() == 3);
}
/*
TEST_CASE("TESTE - Verificar se o grafo é conexo"){
  Directed dg(10);
  CHECK(dg.has_cycle() == 0);
  CHECK(dg.get_sccs() == 10);
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
  dg = Directed(4);
  dg.add_edge(1,2);
  dg.add_edge(2,1);
  CHECK(dg.connected() == 1);
}*/
