//  Copyright by Oganyan Robert

#include <gtest.h>
#include "TStack.h"
#include <stack>

TEST(TStack, can_create_stack_without_size) {
	EXPECT_NO_THROW(TStack<int> s(););
}

TEST(TStack, can_create_stack_with_positive_size) {
	EXPECT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, can_create_stack_with_zero_size) {
	EXPECT_NO_THROW(TStack<int> s(0));
}

TEST(TStack, cant_create_stack_with_negative_size) {
	EXPECT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, can_put_value_to_stack) {
	TStack<int> s(5);
	EXPECT_NO_THROW(s.Push(5));
}

TEST(TStack, cant_put_value_if_stack_is_full) {
	TStack<int> s(2);
	s.Push(1);
	s.Push(2);
	EXPECT_ANY_THROW(s.Push(3));
}

TEST(TStack, can_get_value_from_stack) {
	TStack<int> s(5);
	s.Push(1);
	s.Push(2);
	s.Push(3);
	EXPECT_NO_THROW(s.Pop());
}

TEST(TStack, get_value_from_stack_right) {
	TStack<int> s(5);
	s.Push(1);
	s.Push(2);
	s.Push(3);
	EXPECT_EQ(s.Pop(), 3);
}

TEST(TStack, cant_get_value_from_stack_with_zero_size) {
	TStack<int> s(0);
	EXPECT_ANY_THROW(s.Pop());
}

TEST(TStack, cant_get_value_from_empty_stack) {
	TStack<int> s(5);
	EXPECT_ANY_THROW(s.Pop());
}

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW (TStack<int> A(5));
}

TEST(TStack, throws_when_create_Stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> A(-2));
}

TEST(TStack, can_get_length)
{
  TStack<int> A(3);
  EXPECT_EQ(3, A.GetSize());
}

TEST(TStack, can_get_top)
{
  TStack<int> A(2);
  EXPECT_EQ(0, A.GetTop());
}

TEST(TStack, can_get_top_2)
{
  TStack<double> A(2);
  A.Push(1.5);
  A.Pop();
  EXPECT_EQ(0, A.GetTop());
}

TEST(TStack,can_push)
{
  TStack<int> A(5);
  ASSERT_NO_THROW(A.Push(1));
}

TEST(TStack,can_pop)
{
  TStack<char> A(5);
  A.Push('a');
  ASSERT_NO_THROW(A.Pop());
}

TEST(TStack,can_push_and_pop_right)
{
  TStack<int> A(5);
  A.Push(5);
  EXPECT_EQ(5, A.Pop());
}

TEST(TStack,can_look_right)
{
  TStack<char> A(5);
  A.Push('s');
  EXPECT_EQ('s', A.Top());
}

TEST(TStack, throws_when_full)
{
  TStack<bool> A(2);
  A.Push(true);
  A.Push(false);
  ASSERT_ANY_THROW(A.Push(true));
}
TEST(TStack, throws_when_free)
{
  TStack<int> A(2);
  ASSERT_ANY_THROW(A.Pop());
}

TEST(TStack, compare_stack_empty_return_true)
{
  TStack<int> S(2);
  EXPECT_EQ(true,S.GetTop()==0);
}

TEST(TStack, compare_with_STL_stack) {
  TStack<int> S(2);
  std::stack<int> tst;
  tst.push(1);
  tst.push(1);
  EXPECT_EQ(tst.size(), S.GetSize());
}

TEST(TStack, compare_with_STL_stack_2) {
  TStack<int> S(2);
  std::stack<int> tst;
  tst.push(1);
  tst.pop();
  EXPECT_NE(tst.size(), S.GetSize());
}

TEST(TStack, compare_with_STL_stack_3) {
  TStack<int> S(10);
  std::stack<int> tst;
  S.Push(1);
  tst.push(1);
  tst.push(3);
  S.Push(3);
  EXPECT_EQ(tst.top(), S.Top());
}

