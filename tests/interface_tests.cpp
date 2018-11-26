#include "undirected_graph.h"
#include "edges.h"
#include "doctest.h"

  TEST_CASE("Id de um grafo sem arestas"){
   Undirected u(10);
   CHECK(u.get_id(5) == 5);
  }

TEST_CASE("Interface Base - Testes Basiscos"){
  Edges ed;

  for( int i=1; i<=5; i++ ){
    for( int j=1; j<=5; j++ ){
      if( i==j )continue;
      ed.insert(i, j);
    }
  }

  CHECK_NOTHROW(Undirected(5, ed));

  Undirected u(5, ed);

  CHECK(u.size() == 10);
  CHECK(u.order() == 5);

  for( int i=1; i<=5; i++ ){
    for( int j=1; j<=5; j++ ){
      if( i==j )continue;
      CHECK(u.has_edge(i, j));
    }
  }

  CHECK(u.complete());
  CHECK(u.regular());

  CHECK(u.in_degree(2) == 4);
  CHECK(u.out_degree(3) == 4);

}

TEST_CASE("Interface Base - Subgrafo"){

  Edges ed1;
  for( int i=1; i<=5; i++ ){
    for( int j=1; j<=5; j++ ){
      if( i==j )continue;
      ed1.insert(i, j);
    }
  }

  Edges ed2;
  ed2.insert(1, 2);
  ed2.insert(1, 3);
  ed2.insert(1, 4);
  ed2.insert(1, 5);

  Undirected u1(5, ed1);
  Undirected u2(5, ed2);

  CHECK(u1.subgraph(u2));
  CHECK(!u2.subgraph(u1));

  Edges ed3;
  ed3.insert(2, 3);
  ed3.insert(4, 3);

  Undirected u3(5, ed3);

  CHECK(!u2.subgraph(u3));
}
