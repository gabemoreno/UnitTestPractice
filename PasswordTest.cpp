/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, repeated_leading_characters)
{
	Password my_password;
	ASSERT_EQ(3, my_password.count_leading_characters("ZZZyxz"));
}

TEST(PasswordTest, stop_when_different_character)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("ZZYYY"));
}

TEST(PasswordTest, mixed_case_returns_true)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Test"));
}

TEST(PasswordTest, all_lowercase_returns_false)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("test"));
}

TEST(PasswordTest, all_uppercase_returns_false)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("TEST"));
}

TEST(PasswordTest, numbers_ignored)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("123"));
}