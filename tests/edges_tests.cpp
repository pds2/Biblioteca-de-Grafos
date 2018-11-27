#include "edges.h"
#include "doctest.h"

TEST_CASE("Edges - Teste Basico"){
  Edges ed;
  CHECK_NOTHROW(ed.insert(1, 2, 1));
  CHECK_NOTHROW(ed.insert(1, 3, 2));
  CHECK_NOTHROW(ed.insert(1, 4, 3));

  CHECK(ed.get_size() == 3);

  CHECK(ed[0].first == 1);
  CHECK(ed[0].second.first == 2);
  CHECK(ed[0].second.second == 1);

  CHECK(ed[1].first == 1);
  CHECK(ed[1].second.first == 3);
  CHECK(ed[1].second.second == 2);

  CHECK(ed[2].first == 1);
  CHECK(ed[2].second.first == 4);
  CHECK(ed[2].second.second == 3);
}

TEST_CASE("Edges - Sort"){
  Edges ed;
  ed.insert(1, 2, 4);
  ed.insert(1, 3, 3);
  ed.insert(1, 4, 2);
  ed.insert(1, 5, 1);

  CHECK(ed[0].first == 1);
  CHECK(ed[0].second.first == 2);
  CHECK(ed[0].second.second == 4);

  CHECK(ed[1].first == 1);
  CHECK(ed[1].second.first == 3);
  CHECK(ed[1].second.second == 3);

  CHECK(ed[2].first == 1);
  CHECK(ed[2].second.first == 4);
  CHECK(ed[2].second.second == 2);

  CHECK(ed[3].first == 1);
  CHECK(ed[3].second.first == 5);
  CHECK(ed[3].second.second == 1);

  ed.sort();

  CHECK(ed[0].first == 1);
  CHECK(ed[0].second.first == 5);
  CHECK(ed[0].second.second == 1);

  CHECK(ed[1].first == 1);
  CHECK(ed[1].second.first == 4);
  CHECK(ed[1].second.second == 2);

  CHECK(ed[2].first == 1);
  CHECK(ed[2].second.first == 3);
  CHECK(ed[2].second.second == 3);

  CHECK(ed[3].first == 1);
  CHECK(ed[3].second.first == 2);
  CHECK(ed[3].second.second == 4);
}

TEST_CASE("Edges - Excecoes"){
  Edges ed;
  CHECK_THROWS(ed.insert(-1, 1, 1));
  CHECK_THROWS(ed.insert(1, 1001, 1));

  ed.insert(1, 2);
  ed.insert(2, 3);

  CHECK_THROWS(ed[5]);
  CHECK_THROWS(ed[-1]);
}
