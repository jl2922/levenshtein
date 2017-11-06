#include "./dictionary.h"

Dictionary::Dictionary(const std::vector<Word>& words) {
  trie.reset(new Trie());
  const int n_words = words.size();
  for (int i = 0; i < n_words; i++) {
    trie->add_word(words[i]);
  }
}