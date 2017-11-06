#ifndef WORD_H_
#define WORD_H_

#include <vector>

class Word {
 public:
  void append(const int ch) { characters.push_back(ch); }

  std::vector<int> get_characters() const { return characters; }

 private:
  std::vector<int> characters;
};

#endif
