#include "solution.h"

// This is an implementation of
// [Manacher’s
// Algorithm](https://medium.com/hoskiss-stand/manacher-299cf75db97e)
//
// For i = 0..(s.size()*2 + 1),
// s'[i] := '_'   , if i is even
// s'[i] := s[i/2], if is odd
std::string Solution::longestPalindrome(std::string s) {
  if (s.size() <= 1)
    return s;
  if (s.size() == 2) {
    if (s[0] == s[1])
      return s;
    else
      return s.substr(0, 1);
  }

  auto LPS = std::vector<std::size_t>(s.size() * 2 + 1, 0);

  for (std::size_t c = 0; c != s.size() * 2;) {

    // compute LPS[c]
    auto i = c + LPS[c];
    auto j = c - LPS[c];
    while (j-- != 0 && ++i != LPS.size() &&
           (!(i % 2) || s[i / 2] == s[j / 2]) // s'[i] == s'[j]
    )
      ++LPS[c];

    // fast forward to the next LPS[c'] that needed to be computed
    if (LPS[c] == 0) {
      ++c;
    } else {
      std::size_t r = 1;
      while (r < LPS[c]) {
        auto cr = c + r;
        auto cl = c - r;
        auto x = LPS[c] - r;
        LPS[cr] = std::min(x, LPS[cl]);

        if (LPS[cl] == x) { // LPS[cl] might be longer
          break;
        }
        ++r;
      }
      c += r;
    }
  }
  // Get the index of the greatest value in LPS
  auto it = std::max_element(LPS.begin(), LPS.end());
  int centor = std::distance(LPS.begin(), it);

  // s'[(centor-LPS[centor])..=(centor+LPS[centor])]
  auto pos = centor - LPS[centor];
  auto len = (LPS[centor] * 2 + 1) / 2 + (pos % 2);
  return s.substr(pos / 2, len);
}
