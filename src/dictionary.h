#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <vector>
#include "./trie.h"
#include "./word.h"

class Dictionary {
 public:
  Dictionary(const std::vector<Word>& words);

 private:
  std::unique_ptr<Trie> trie;
};

#endif
