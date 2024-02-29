#include "solution.h"

bool Solution::isValid(std::string s) {
  // Assuming s only contains "(", ")", "[", "]", "{", "}"
  // And 1 <= s.size() <= 10^4

  std::vector<char> stack;

  for (auto const &b : s) {
    if (b == ')') {
      if (stack.empty() || stack.back() != '(')
        return false;
      else
        stack.pop_back();
    } else if (b == ']') {
      if (stack.empty() || stack.back() != '[')
        return false;
      else
        stack.pop_back();
    } else if (b == '}') {
      if (stack.empty() || stack.back() != '{')
        return false;
      else
        stack.pop_back();
    } else {
      stack.push_back(b);
    }
  }
  return stack.empty();
}
