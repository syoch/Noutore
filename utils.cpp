#include <iostream>
#include <cstring>
#include "utils.h"

std::string input(std::string const& prompt) {
  std::string s;
  
  std::cout << prompt << ' ';
  std::getline(std::cin, s);
  
  return s;
}

int input_int(std::string const& prompt) {
  int i;
  
  while( 1 ) {
    try {
      i = std::stoi(input(prompt));
      break;
    }
    catch( ... ) {
      std::cout << "Please input a integer!\n";
    }
  }
  
  return i;
}

int randrange(int min, int max) {
  return min + rand() % (max - min);
}
