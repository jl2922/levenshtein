#ifndef TRIE_H_
#define TRIE_H_

#include <memory>
#include <unordered_map>
#include "./word.h"

class Node {
 public:
  Node(const int ch) : data(ch){};

  Node* get_child(const int ch);

 private:
  int data;
  std::unordered_map<int, std::unique_ptr<Node>> children;
};

class Trie {
 public:
  Trie();

  void add_word(const Word& word);

 private:
  std::unique_ptr<Node> root;
};

#endif
