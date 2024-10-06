#include < iostream>
#include <string>
#include "../lib_Stack/Stack_.h"

bool is_correct(const std::string& exp) {
  Stack<char> stack;
  for (char ch : exp) {
    // if
    if (ch == '(' || ch == '{' || ch == '[' || ch == '|') {
      stack.push(ch);

    }
    if ((ch == ')' && stack.peek() != '(') ||
      (ch == '}' && stack.peek() != '{') ||
      (ch == ']' && stack.peek() != '[') ||
      (ch == '|' && stack.peek() != '|'))
    {
      return false;
    }if (ch == ')' || ch == '}' || ch == ']' || ch == '|') {
      if (stack.isEmpty()) {
        return false;
      }
      stack.pop();
    }
  }
  return stack.isEmpty();

}