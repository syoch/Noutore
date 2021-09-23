#pragma once

#include <string>

template <class... Args>
std::string format(char const* fmt, Args... args) {
  static char buf[0x1000];
  sprintf(buf, fmt, args...);
  return buf;
}

i64 to_integer(std::string const& str);

std::string input(std::string const& prompt = "");
i64 input_int(std::string const& prompt = "");

i64 randrange(i64 min, i64 max);

