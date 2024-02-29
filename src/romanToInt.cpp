#include "solution.h"

namespace syc {
template <typename CharDescriptor> int numeral(CharDescriptor i) {
  switch (*i) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  default:
    return 0;
  }
}
} // namespace syc

int Solution::romanToInt(std::string s) {
  auto value = int(0);
  auto buffer = syc::numeral(s.rbegin());

  for (auto i = s.rbegin(), i_end = s.rend(); ++i != i_end;) {
    auto n = syc::numeral(i);
    if (n < buffer) {
      value -= n;
    } else {
      value += buffer;
      if (n > buffer) {
        buffer = n;
      }
    }
  }
  value += buffer;

  return value;
}
