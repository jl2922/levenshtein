#include "./trie.h"

Node* Node::get_child(const int ch) {
  if (children.count(ch) == 1) {
    return children[ch].get();
  } else {
    Node* node = new Node(ch);
    children[ch].reset(node);
    return node;
  }
}

Trie::Trie() { root.reset(new Node(-1)); }

void Trie::add_word(const Word& word) {
  const auto& characters = word.get_characters();
  const int n_characters = characters.size();
  Node* node = root.get();
  for (int i = 0; i < n_characters; i++) {
    int next_ch = characters[i];
    node = node->get_child(next_ch);
  }
}
