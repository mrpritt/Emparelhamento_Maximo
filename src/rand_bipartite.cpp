/**
 * \file rand_bipartite.cpp
 *   \author Marcus Ritt <marcus.ritt@inf.ufrgs.br> 
 *   \date Time-stamp: <2024-07-19 13:56:32 ritt>
 */

#include <cassert>
#include <iostream>
#include <random>
#include <set>
using namespace std;

#define FMT_HEADER_ONLY
#include "fmt/format.h"

mt19937 rng;

int main(int argc, char *argv[]) {
  // (0) process commandline
  assert(argc == 5);
  unsigned n1 = atoi(argv[1]);
  unsigned n2 = atoi(argv[2]);
  double ρ = atof(argv[3]);
  unsigned seed = atoi(argv[4]);

  rng.seed(seed);
  uniform_int_distribution<> p1(0, n1 - 1);
  uniform_int_distribution<> p2(0, n2 - 1);

  set<pair<int,int>> E;

  int m = n1*n2*ρ, u, v;
  while (m-- > 0) {
    do {
      u = p1(rng);
      v = p2(rng);
    } while (E.count({u,v}));
    E.insert({u,v});
  }

  fmt::print("p edge {} {} {}\n", n1, n2, n1*n2*ρ);
  for(auto [u,v] : E)
    fmt::print("e {} {}\n", u, v);
}
