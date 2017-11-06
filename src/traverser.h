#ifndef TRAVERSER_H_
#define TRAVERSER_H_

#include <vector>
#include "./dictionary.h"
#include "./levenshtein.h"

class Traverser {
 public:
  Traverser(Dictionary* const dict, Levenshtein* const lev)
      : dict(dict), lev(lev) {}

  std::vector<int> traverse();

 private:
  Dictionary* const dict;

  Levenshtein* const lev;
};

#endif
