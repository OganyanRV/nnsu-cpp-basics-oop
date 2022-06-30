  //  Copyright by Oganyan Robert

#include <cmath>
#include "gtest.h"
#include "../include/RPolNotation.h"

TEST(RPolNotation, can_create_formula_with_size_less_than_255) {
	EXPECT_NO_THROW(RPolNotation f("2-7+(5*2)"));
}

TEST(RPolNotation, cant_create_formula_with_size_greater_than_255) {
	EXPECT_NO_THROW(RPolNotation f("2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)"));
}

TEST(RPolNotation, can_convert_correct_formula) {
  RPolNotation f("((8-3)-5/((7+8)*9)-8)+25*7");
  int n = 0;
  EXPECT_NO_THROW(f.Postfix(n));
}

TEST(RPolNotation, cant_convert_uncorrect_formula) {
  RPolNotation f("(((8-3)-5/((7+8)*9)-8)+25*7");
  int n = 0;
  EXPECT_NO_THROW(f.Postfix(n));
}

TEST(RPolNotation, can_calculate_correct_formula) {
  RPolNotation f("((8-3)-5/((7+8)*9)-8)+25*7");
  int n = 0;
  EXPECT_NO_THROW(f.Postfix(n));
}

TEST(RPolNotation, cant_calculate_uncorrect_formula) {
	RPolNotation f("(((8-3)-5/((7+8)*9)-8)+25*7");
	EXPECT_ANY_THROW(f.Calculate());
}

TEST(RPolNotation, calculator_works_right) {
	RPolNotation f("((8-3)-5/((7+8)*9)-8)+25*7");
	EXPECT_EQ((int)f.Calculate(), 171);
}

TEST(RPolNotation, test_name1)
{
  char* s = "1";
  RPolNotation P(s);
  double rez = P.Calculate();
  EXPECT_EQ(rez,1);
}

TEST(RPolNotation, test_name2)
{
  char* s = "3+4*2/(1-5)*2";
  RPolNotation P(s);
  double rez = P.Calculate();
  EXPECT_EQ(rez,-1);
}

TEST(RPolNotation, test_name6)
{
  char* s = "3*4*2/(1-5)*2";
  RPolNotation P(s);
  double rez = P.Calculate();
  EXPECT_EQ(rez,-12);
}

TEST(RPolNotation, test_name7)
{
  char* s = "(((999-99+100)*10))/10";
  RPolNotation P(s);
  double rez = P.Calculate();
  EXPECT_EQ(rez,1000);
}

TEST(RPolNotation, test_name14)
{
  char* s = "-40-(-50)";
  RPolNotation P(s);
  int l=0;
  ASSERT_NO_THROW(P.Postfix(l));
}

TEST(RPolNotation, test_name15)
{
  char* s = "-40-(-50)";
  RPolNotation P(s);
  ASSERT_NO_THROW(P.Calculate());
}

TEST(RPolNotation, test_name16)
{
  char* s = "-40-(-50)";
  RPolNotation P(s);
  EXPECT_EQ(10, P.Calculate());
}

#ifdef Undef_When_Fix
#define Undef_When_Fix

TEST(RPolNotation, test_name17)
{
  char* s1 = "3.2+4.1*2.5/(1.66-5.05)*2=";
  char* s2 = "3.2 4.1 2.5 * 1.66 5.05 - 2 * / + ";
  RPolNotation P(s1);
  int n=0;
  EXPECT_EQ(s2,P.Postfix(n));
}

TEST(RPolNotation, test_name19)
{
  char* s = "3.2+4.1*2.5/(1.66-5.05)*2";
  RPolNotation P(s);
  auto value = P.Calculate();
  EXPECT_EQ(-2.8472, std::round(value*10000)/10000);
}

TEST(RPolNotation, brackets_in_formula_is_correct) {
  RPolNotation f("((8-3)-5/((7+8)*9)-8)+25*7");
  int arr[MaxLen];
  EXPECT_EQ(f.FormulaChecker(arr, MaxLen), 0);
}

TEST(RPolNotation, brackets_is_uncorrect) {
  RPolNotation f("(())()()(((()(()))");
  int arr[MaxLen];
  EXPECT_NE(f.FormulaChecker(arr, MaxLen), 0);
}

TEST(RPolNotation, brackets_in_formula_is_uncorrect) {
  RPolNotation f("(((8-3)-5/((7+8)*9)-8)+25*7");
  int arr[MaxLen];
  EXPECT_NE(f.FormulaChecker(arr, MaxLen), 0);
}

TEST(RPolNotation, number_of_errors_is_correct_1) {
  RPolNotation f("(())()()(((()(()))");
  int arr[MaxLen];
  EXPECT_EQ(f.FormulaChecker(arr, MaxLen), 2);
}

TEST(RPolNotation, number_of_errors_is_correct_2) {
  RPolNotation f("(((8-3)-5/((7+8)*9)-8)+25*7");
  int arr[MaxLen];
  EXPECT_EQ(f.FormulaChecker(arr, MaxLen), 1);
}


TEST(RPolNotation, test_name4)
{
  char* s1 = "3+4*2/(1-5)*2";
  char* s2 = "3 4 2 * 1 5 - 2 * / + ";
  RPolNotation P(s1);
  int n=0;
  EXPECT_EQ(s2,P.Postfix(n));
}
#endif