#include "undirected_graph.h"
#include "doctest.h"



TEST_CASE("TESTE - Construtor"){
    CHECK_NOTHROW(Undirected u(1));
}

TEST_CASE("TESTE - Destrutor"){
    Undirected *u = new Undirected(1);
    CHECK_NOTHROW(delete u);
}
