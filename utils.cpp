#include <iostream>
#include "common.h"
#include "utils.h"

i64 to_integer(std::string const& str) {
  i64 value = 0;
  i64 num = 1;
  bool negative = false;

  if( str.empty() ) goto fail;
  
  negative = str[0] == '-';

  for( auto it = str.rbegin() + (int)negative; it != str.rend(); it++ ) {
    char ch = *it;

    if( ch < '0' || ch > '9' )
      goto fail;
    
    value += num * (ch - '0');
    num *= 10;
  }

  return negative ? -value : value;

fail:
  throw "cannot convert to i64";
}

std::string input(std::string const& prompt) {
  std::string s;
  
  std::cout << prompt << ' ';
  std::getline(std::cin, s);
  
  return s;
}

i64 input_int(std::string const& prompt) {
  i64 i;
  
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

i64 randrange(i64 min, i64 max) {
  return min + rand() % (max - min);
}

