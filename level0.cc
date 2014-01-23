#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>

#include "precomputed.c"

// I am aware that this is horrible C++.

bool cmp(const char* a, const char* b) {
  return strcmp(a, b) < 0;
}

void test(const char* x) {
  std::cout << x << std::endl;
}

int main( int argc, char *argv[] ) {
  char whitespace;

  std::cin >> std::noskipws;

  std::string current_word;

  while(!std::cin.eof()) {
    std::cin >> current_word >> whitespace;

    if(current_word.length() == 0) {
      break;
    }

    char *orig_word = strdup( current_word.c_str() );

    std::transform(current_word.begin(), current_word.end(), current_word.begin(), ::tolower);

    if(std::binary_search(words, words + WORD_COUNT, current_word.c_str(), cmp)) {
      std::cout << orig_word;
    } else {
      std::cout << "<" << orig_word << ">";
    }

    std::cout << whitespace;

    free(orig_word);
  }
}
