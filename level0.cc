#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>

// I am aware that this is horrible C++.

int main( int argc, char *argv[] ) {
  const char *words_path = argc > 1 ? argv[1] : "/usr/share/dict/words";

  std::vector<std::string> words;
  words.reserve(250000);

  std::ifstream words_file;
  words_file.open(words_path);

  std::string current_word;

  int n = 0;

  while(!words_file.eof()) {
    getline(words_file, current_word);

    // downcase everything, caps mean it won't be sorted by default
    std::transform(current_word.begin(), current_word.end(), current_word.begin(), ::tolower);

    words.push_back(current_word);
  }

  char whitespace;

  std::cin >> std::noskipws;

  while(!std::cin.eof()) {
    std::cin >> current_word >> whitespace;

    if(current_word.length() == 0) {
      break;
    }

    char *orig_word = strdup( current_word.c_str() );

    std::transform(current_word.begin(), current_word.end(), current_word.begin(), ::tolower);

    if(std::binary_search(words.begin(), words.end(), current_word)) {
      std::cout << orig_word;
    } else {
      std::cout << "<" << orig_word << ">";
    }

    std::cout << whitespace;

    free(orig_word);
  }
}
