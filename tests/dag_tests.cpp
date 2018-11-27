#include "dag.h"
#include "doctest.h"
#include <iostream>

// TEST_CASE("DAG - Teste Basico"){
//   Edges ed;
//
//   ed.insert(1, 2);
//   ed.insert(1, 3);
//   ed.insert(2, 4);
//   ed.insert(3, 4);
//
//   CHECK_NOTHROW(DAG(4, ed));
//
//   CHECK_NOTHROW(DAG d(4));
//
//   DAG d(4);
//   d.add_edge(1, 2);
//   d.add_edge(1, 3);
//   d.add_edge(2, 4);
//   d.add_edge(3, 4);
//   CHECK(d.has_cycle() == 0);
// }
