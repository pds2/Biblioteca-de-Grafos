#include "tree.h"
#include "doctest.h"

TEST_CASE("Arvore - Testes Basicos"){
  Edges ed;
  ed.insert(1, 2, 1);
  ed.insert(1, 3, 1);
  ed.insert(1, 4, 1);

  Tree t(4, 1, ed);
  CHECK(t.get_root() == 1);
  CHECK(t.num_level() == 2);

  t.set_root(2);
  CHECK(t.get_root() == 2);
  CHECK(t.num_level() == 3);
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

  CHECK(t.num_level() == 3);
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

  CHECK(t.num_level() == 3);
}

TEST_CASE("Arvore - Mudando a raiz"){
  Edges ed;

  ed.insert(1, 2);
  ed.insert(1, 3);
  ed.insert(1, 4);

  ed.insert(2, 5);
  ed.insert(2, 6);

  ed.insert(4, 7);
  ed.insert(7, 8);
  ed.insert(8, 9);

  CHECK_NOTHROW(Tree t(9, 1, ed));
  Tree t(9, 1, ed);

  CHECK(t.num_level() == 5);

  CHECK(t.get_root() == 1);

  CHECK(t.get_parent(1) == 1);
  CHECK(t.get_parent(2) == 1);
  CHECK(t.get_parent(3) == 1);
  CHECK(t.get_parent(4) == 1);
  CHECK(t.get_parent(5) == 2);
  CHECK(t.get_parent(6) == 2);
  CHECK(t.get_parent(7) == 4);
  CHECK(t.get_parent(8) == 7);
  CHECK(t.get_parent(9) == 8);

  t.set_root(7);
  CHECK(t.get_root() == 7);
  CHECK(t.num_level() == 5);

  CHECK(t.get_parent(1) == 4);
  CHECK(t.get_parent(2) == 1);
  CHECK(t.get_parent(3) == 1);
  CHECK(t.get_parent(4) == 7);
  CHECK(t.get_parent(5) == 2);
  CHECK(t.get_parent(6) == 2);
  CHECK(t.get_parent(7) == 7);
  CHECK(t.get_parent(8) == 7);
  CHECK(t.get_parent(9) == 8);
}

TEST_CASE("Arvore - Distancia"){
  Edges ed;
  ed.insert(1, 2);
  ed.insert(1, 3);
  ed.insert(1, 4);

  ed.insert(2, 5);
  ed.insert(2, 6);

  ed.insert(4, 7);
  ed.insert(7, 8);
  ed.insert(8, 9);

  Tree t(9, 1, ed);

  CHECK(t.find_distance(1, 2) == 1);
  CHECK(t.find_distance(1, 3) == 1);
  CHECK(t.find_distance(1, 4) == 1);
  CHECK(t.find_distance(1, 5) == 2);
  CHECK(t.find_distance(1, 6) == 2);
  CHECK(t.find_distance(1, 7) == 2);
  CHECK(t.find_distance(1, 8) == 3);
  CHECK(t.find_distance(1, 9) == 4);

  CHECK(t.find_distance(9, 5) == 6);
  CHECK(t.find_distance(9, 6) == 6);
  CHECK(t.find_distance(1, 1) == 0);
  CHECK(t.find_distance(3, 5) == 3);
  CHECK(t.find_distance(6, 4) == 3);
  CHECK(t.find_distance(8, 7) == 1);
  CHECK(t.find_distance(3, 7) == 3);
  CHECK(t.find_distance(6, 8) == 5);
}
