#include "solution.h"

std::string Solution::addBinary(std::string a, std::string b) {
  if (a[0] == '0')
    return b;

  if (b[0] == '0')
    return a;

  if (a.size() < b.size())
    std::swap(a, b);

  bool carry = false;
  auto i = a.rbegin(), j = b.rbegin();
  for (; j != b.rend(); ++i, ++j) {
    bool x = (*i != *j);
    bool d = carry ^ x;
    if (!x)
      carry = (*i == '1');
    *i = d ? '1' : '0';
  }
  for (; i != a.rend() && carry; ++i) {
    if (*i == '1')
      *i = '0';
    else {
      *i = '1';
      carry = 0;
    }
  }

  if (carry)
    a.insert(a.begin(), '1');

  return a;
}
