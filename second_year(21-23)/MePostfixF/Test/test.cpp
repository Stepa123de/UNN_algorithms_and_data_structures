#include "pch.h"
#include "gtest/gtest.h"
#include "..\MePostfixF\PostfixExpression.h"
#include "..\MePostfixF\ExpressionValidation.h"

TEST(PostfixExpression, PostfixExpressionPro1) {
	std::string expected = "6 4.5 + ab 2 * x sin * 3 / - x -";
	std::string expression = "6+4.5-ab2*sin(x)/3-x";
	std::string ans = PostfixExpression(expression).GetStrAns();
	EXPECT_EQ(ans, expected);
	EXPECT_TRUE(true);
}

TEST(PostfixExpression, PostfixExpressionPro2) {
	std::string expected = "a 75 x * 4 y * + sin * 23 t * /";
	std::string expression = "a*sin(75x+4y)/(23t)";
	std::string ans = PostfixExpression(expression).GetStrAns();
	EXPECT_EQ(ans, expected);
	EXPECT_TRUE(true);
}

TEST(PostfixExpression, PostfixExpressionPro3) {
	std::string expected = "a 12 x 1 ^ * 12 sin * ^";
	std::string expression = "a^(12x^((1))*sin(12))";
	std::string ans = PostfixExpression(expression).GetStrAns();
	EXPECT_EQ(ans, expected);
	EXPECT_TRUE(true);
}
TEST(PostfixExpression, PostfixExpressionPro4) {
	std::string expected = "4 7 y * + 4 x ctg * tg -";
	std::string expression = "4+7*y-tg(4*ctg(x))";
	std::string ans = PostfixExpression(expression).GetStrAns();
	EXPECT_EQ(ans, expected);
	EXPECT_TRUE(true);
}

TEST(PostfixExpression, PostfixExpressionPro5) {
	std::string expected = "a 5 a sin b sin + * +";
	std::string expression = "a+5(sin(a)+sin(b))";
	std::string ans = PostfixExpression(expression).GetStrAns();
	EXPECT_EQ(ans, expected);
	EXPECT_TRUE(true);
}

TEST(ExpressionValidation, ExpressionValidation1) {
	bool expected = true;
	std::string expression = "(1)+2";
	bool ans = ExpressionValidation().ExpVal(expression);
	EXPECT_EQ(ans, expected);
	EXPECT_TRUE(true);
}
TEST(ExpressionValidation, ExpressionValidation2) {
	bool expected = false;
	std::string expression = ")))4(((";
	bool ans = ExpressionValidation().ExpVal(expression);
	EXPECT_EQ(ans, expected);
	EXPECT_TRUE(true);
}
TEST(ExpressionValidation, ExpressionValidation3) {
	bool expected = false;
	std::string expression = "a+()+b";
	bool ans = ExpressionValidation().ExpVal(expression);
	EXPECT_EQ(ans, expected);
	EXPECT_TRUE(true);
}
TEST(ExpressionValidation, ExpressionValidation4) {
	bool expected = false;
	std::string expression = "cos(7)a";
	bool ans = ExpressionValidation().ExpVal(expression);
	EXPECT_EQ(ans, expected);
	EXPECT_TRUE(true);
}

TEST(PostfixExpression, PostfixExpressionPro6) {
	int expected = NAN;
	std::string expression = "5/0";
	int ans = PostfixExpression(expression).GetTrueAns();
	EXPECT_EQ(ans, expected);
	EXPECT_TRUE(true);
}
