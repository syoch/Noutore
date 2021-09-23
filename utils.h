#pragma once

#include <string>

template <class... Args>
std::string format(char const* fmt, Args... args) {
  static char buf[0x1000];
  sprintf(buf, fmt, args...);
  return buf;
}

std::string input(std::string const& prompt = "");
int input_int(std::string const& prompt = "");
int randrange(int min, int max);

