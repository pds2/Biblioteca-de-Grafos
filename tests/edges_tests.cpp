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
