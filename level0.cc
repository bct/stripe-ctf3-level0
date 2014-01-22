#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <string.h>

// I am aware that this is horrible C++.

int main( int argc, char *argv[] ) {
  const char *words_path = argc > 1 ? argv[1] : "/usr/share/dict/words";

  std::unordered_set<std::string> words_set;

  std::ifstream words_file;
  words_file.open(words_path);

  std::string current_word;

  while(!words_file.eof()) {
    getline(words_file, current_word);

//    std::cout << current_word << std::endl;

    words_set.insert(current_word);
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

    if(words_set.find(current_word) != words_set.end()) {
      std::cout << orig_word;
    } else {
      std::cout << "<" << orig_word << ">";
    }

    std::cout << whitespace;

    free(orig_word);
  }
}
