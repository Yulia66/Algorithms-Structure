#include <gtest.h>
#include "../lib_Bracket/Bracket.h"

TEST(TestBracketLib, correct_work_1) {
  std::string word = " ((x+y*5)*[x/6-y])+{((8+19)+|14x+56|)*[18y-65]}";

  ASSERT_NO_THROW(is_correct(word));
}




TEST(TestBracketLib, correct_work_2) {
  std::string word = "|a+b|*|3-x|";
  ASSERT_NO_THROW(is_correct(word));
}

TEST(TestBracketLib, square_bracket) {
  std::string word = "[[2c+4x]*[3-5]]";
  bool actual_result = is_correct(word);
  bool expected_result =  true;
  EXPECT_EQ(expected_result, actual_result);
}

TEST(TestBracketLib, parenthesis) {
  std::string word = "(((5-2)/2)*3)";
  bool actual_result = is_correct(word);
  bool expected_result = true;
  EXPECT_EQ(expected_result, actual_result);
}

TEST(TestBracketLib, curly_bracket) {
  std::string word = "{{23v-3}*x}";
  bool actual_result = is_correct(word);
  bool expected_result = true;
  EXPECT_EQ(expected_result, actual_result);
}



