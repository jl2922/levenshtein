#include <cstdio>
#include <memory>
#include <vector>
#include "./dictionary.h"
#include "./levenshtein.h"
#include "./traverser.h"
#include "./word.h"

std::vector<Word> read_words(FILE* file) {
  std::vector<Word> words;
  int n_words;
  int n_letters;
  int ch;
  fscanf(file, "%d", &n_words);
  for (int i = 0; i < n_words; i++) {
    fscanf(file, "%d", &n_letters);
    Word word;
    for (int j = 0; j < n_letters; j++) {
      fscanf(file, "%d", &ch);
      word.append(ch);
    }
    words.push_back(word);
  }
  return words;
}

std::pair<std::vector<Word>, std::vector<Word>> read_input() {
  std::pair<std::vector<Word>, std::vector<Word>> res;
  FILE* file = fopen("test/input.txt", "r");
  if (file == nullptr) {
    printf("Fild not found.\n");
    exit(1);
  }
  res.first = read_words(file);
  res.second = read_words(file);
  return res;
}

void print_result(const int i, const std::vector<int>& candidates) {
  const int n_candidates = candidates.size();
  printf("Case #%d:\n", i);
  for (int j = 0; j < n_candidates; j++) {
    printf("%d", candidates[j]);
    if (j < n_candidates - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
}

int main() {
  const auto& input = read_input();
  const auto& dict_words = input.second;
  const auto& lev_words = input.first;

  std::unique_ptr<Dictionary> dict(new Dictionary(dict_words));
  printf("Dictionary constructed\n");

  const int n_lev_words = lev_words.size();
  for (int i = 0; i < n_lev_words; i++) {
    std::unique_ptr<Levenshtein> lev(new Levenshtein(lev_words[i]));
    std::unique_ptr<Traverser> traverser(new Traverser(dict.get(), lev.get()));
    const auto& candidates = traverser->traverse();
    print_result(i, candidates);
  }

  return 0;
}
