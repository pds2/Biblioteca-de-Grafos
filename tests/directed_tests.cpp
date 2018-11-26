#include "directed_graph.h"
#include "doctest.h"
#include <bits/stdc++.h>


TEST_CASE("TESTE - Construtor"){
    for(int i = 1; i <= 1000; i++){
        Directed dg(i);
    }
}

TEST_CASE("TESTE - Adicionar arestas"){
    Directed dg(10);
    dg.add_edge(1, 1, 1);
    dg.add_edge(1, 2, 9);
    dg.add_edge(3, 2, 3);
    dg.add_edge(10, 4, 5);
    CHECK(dg.has_edge(1, 1) == 1);
    CHECK(dg.has_edge(1, 2) == 9);
    CHECK(dg.has_edge(3, 2) == 3);
    CHECK(dg.has_edge(10, 4) == 5);
    CHECK(dg.has_edge(1, 3) == 0);
    CHECK(dg.has_edge(2, 1) == 0);
    CHECK(dg.has_edge(4, 10) == 0);
}
