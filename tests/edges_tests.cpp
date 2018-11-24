#include "edges.h"
#include "doctest.h"

TEST_SUITE("Arestas"){
    TEST_CASE("Construtor valido"){
        CHECK_NOTHROW(new Edges([2,3]));
    }
    TEST_CASE("Construtor invalido"){
        CHECK_THROWS(new Edges());
    }
}
