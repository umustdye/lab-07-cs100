#include "gtest/gtest.h"

#include "base_factory.hpp"
#include "base.hpp"


TEST(baseFactoryTest, emptyvalue)
{
    BaseFactory factory;
    char **test = new char*[1];
    test[0] = new char[1];
    strcpy(test[0], "");
    Base *base = factory.parse(test, 1);
    EXPECT_EQ(base, nullptr);
    delete [] test[0];
    delete [] test;
}

TEST(baseFactoryTest, correctInput)
{
    BaseFactory factory;
    char **test = new char*[4];
    test[0] = new char[5];
    test[1] = new char[2];
    test[2] = new char[2];
    test[3] = new char[2];
    strcpy(test[0], "Waka");
    strcpy(test[1], "5");
    strcpy(test[2], "+");
    strcpy(test[3], "5");
    Base *base = factory.parse(test, 4);
    EXPECT_EQ(base->stringify(), "(5+5)");
    EXPECT_EQ(base->evaluate(), 10);
    delete [] test[0];
    delete [] test[1];
    delete [] test[2];
    delete [] test[3];
    delete [] test;
}


TEST(baseFactoryTest, correctInput2)
{
    BaseFactory factory;
    char **test = new char*[6];
    test[0] = new char[5];
    test[1] = new char[2];
    test[2] = new char[2];
    test[3] = new char[2];
    test[4] = new char[2];
    test[5] = new char[2];
    strcpy(test[0], "Waka");
    strcpy(test[1], "3");
    strcpy(test[2], "+");
    strcpy(test[3], "2");
    strcpy(test[4], "*");
    strcpy(test[5], "6");
    Base *base = factory.parse(test, 6);
    EXPECT_EQ(base->stringify(), "((3+2)*6)");
    EXPECT_EQ(base->evaluate(), 30);
    delete [] test[0];
    delete [] test[1];
    delete [] test[2];
    delete [] test[3];
    delete [] test[4];
    delete [] test[5];
    delete [] test;
}

TEST(baseFactoryTest, incorrectInput)
{
    BaseFactory factory;
    char **test = new char*[4];
    test[0] = new char[5];
    test[1] = new char[2];
    test[2] = new char[2];
    test[3] = new char[2];
    strcpy(test[0], "Waka");
    strcpy(test[1], "5");
    strcpy(test[2], "");
    strcpy(test[3], "5");
    Base *base = factory.parse(test, 4);
    EXPECT_EQ(base, nullptr);
    delete [] test[0];
    delete [] test[1];
    delete [] test[2];
    delete [] test[3];
    delete [] test;
}

TEST(baseFactoryTest, incorrectInput2)
{
    BaseFactory factory;
    char **test = new char*[4];
    test[0] = new char[5];
    test[1] = new char[2];
    test[2] = new char[2];
    test[3] = new char[2];
    strcpy(test[0], "Waka");
    strcpy(test[1], "a");
    strcpy(test[2], "+");
    strcpy(test[3], "5");
    Base *base = factory.parse(test, 4);
    EXPECT_EQ(base, nullptr);
    delete [] test[0];
    delete [] test[1];
    delete [] test[2];
    delete [] test[3];
    delete [] test;
}

TEST(baseFactoryTest, correctInput3)
{
    BaseFactory factory;
    char **test = new char*[6];
    test[0] = new char[5];
    test[1] = new char[2];
    test[2] = new char[2];
    test[3] = new char[2];
    test[4] = new char[2];
    test[5] = new char[2];
    strcpy(test[0], "Waka");
    strcpy(test[1], "8");
    strcpy(test[2], "-");
    strcpy(test[3], "2");
    strcpy(test[4], "/");
    strcpy(test[5], "6");
    Base *base = factory.parse(test, 6);
    EXPECT_EQ(base->stringify(), "((8-2)/6)");
    EXPECT_EQ(base->evaluate(), 1);
    delete [] test[0];
    delete [] test[1];
    delete [] test[2];
    delete [] test[3];
    delete [] test[4];
    delete [] test[5];
    delete [] test;
}

TEST(baseFactoryTest, correctInput4)
{
    BaseFactory factory;
    char **test = new char*[6];
    test[0] = new char[5];
    test[1] = new char[2];
    test[2] = new char[2];
    test[3] = new char[2];
    test[4] = new char[2];
    test[5] = new char[2];
    strcpy(test[0], "Waka");
    strcpy(test[1], "3");
    strcpy(test[2], "**");
    strcpy(test[3], "2");
    strcpy(test[4], "-");
    strcpy(test[5], "1");
    Base *base = factory.parse(test, 6);
    EXPECT_EQ(base->stringify(), "((3**2)-1)");
    EXPECT_EQ(base->evaluate(), 8);
    delete [] test[0];
    delete [] test[1];
    delete [] test[2];
    delete [] test[3];
    delete [] test[4];
    delete [] test[5];
    delete [] test;
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
