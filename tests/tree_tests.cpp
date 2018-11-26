#include "tree.h"
#include "doctest.h"

TEST_CASE("Arvore - Testes Basicos"){
  Edges ed;
  ed.insert(1, 2, 1);
  ed.insert(1, 3, 1);
  ed.insert(1, 4, 1);
  CHECK_NOTHROW(Tree t(4, 1, ed));
}

TEST_CASE("Arvore - Parent"){
  Edges ed;

  ed.insert(1, 2, 1);
  ed.insert(1, 3, 1);

  ed.insert(2, 4, 1);
  ed.insert(2, 5, 1);

  ed.insert(3, 6, 1);
  ed.insert(3, 7, 1);

  Tree t(7, 1, ed);

  CHECK(t.get_parent(1)==1);
  CHECK(t.get_parent(2)==1);
  CHECK(t.get_parent(3)==1);
  CHECK(t.get_parent(4)==2);
  CHECK(t.get_parent(5)==2);
  CHECK(t.get_parent(6)==3);
  CHECK(t.get_parent(7)==3);

}

TEST_CASE("Arvore - LCA"){
  Edges ed;

  ed.insert(1, 2, 1);
  ed.insert(1, 3, 1);

  ed.insert(2, 4, 1);
  ed.insert(2, 5, 1);

  ed.insert(3, 6, 1);
  ed.insert(3, 7, 1);

  Tree t(7, 1, ed);

  CHECK(t.LCA(1, 3) == 1);
  CHECK(t.LCA(1, 2) == 1);
  CHECK(t.LCA(2, 3) == 1);

  CHECK(t.LCA(2, 4) == 2);
  CHECK(t.LCA(2, 5) == 2);
  CHECK(t.LCA(4, 5) == 2);

  CHECK(t.LCA(3, 6) == 3);
  CHECK(t.LCA(3, 7) == 3);
  CHECK(t.LCA(6, 7) == 3);
}
