#include <arba/wgen/syllabary.hpp>
#include <gtest/gtest.h>
#include <sstream>
#include <cstdlib>

TEST(syllabaray_random_tests, test_random_word_1)
{
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "";
    wgen::syllabary syllabary(consonants, vowels, codas);

    std::string word = syllabary.random_word(5);
    ASSERT_EQ(word.length(), 5);
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[3]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[4]) != std::string_view::npos);
}

TEST(syllabaray_random_tests, test_random_word_2)
{
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "klx";
    wgen::syllabary syllabary(consonants, vowels, codas);

    std::string word = syllabary.random_word(6);
    ASSERT_EQ(word.length(), 6);
    ASSERT_TRUE(consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[3]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[4]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[5]) != std::string_view::npos);
}

TEST(syllabaray_random_tests, test_random_word_3)
{
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "klx";
    wgen::syllabary syllabary(consonants, vowels, codas);

    std::string word = syllabary.random_word(5);
    ASSERT_EQ(word.length(), 5);
    if (consonants.find(word[0]) != std::string_view::npos)
    {
        ASSERT_TRUE(vowels.find(word[1]) != std::string_view::npos);
        ASSERT_TRUE(consonants.find(word[2]) != std::string_view::npos);
        ASSERT_TRUE(vowels.find(word[3]) != std::string_view::npos);
        ASSERT_TRUE(codas.find(word[4]) != std::string_view::npos);
    }
    else
    {
        ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
        ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
        ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
        ASSERT_TRUE(consonants.find(word[3]) != std::string_view::npos);
        ASSERT_TRUE(vowels.find(word[4]) != std::string_view::npos);
    }
}

TEST(syllabaray_random_tests, test_random_word_name)
{
    wgen::syllabary syllabary("tgz", "AEIOU");
    std::string word = syllabary.random_word(4, wgen::syllabary::format::name);

    ASSERT_EQ(word.length(), 4);
    std::string_view upper_consonants = "TGZ";
    std::string_view lower_consonants = "tgz";
    std::string_view lower_vowels = "aeiou";
    ASSERT_TRUE(upper_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(lower_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_random_tests, test_random_word_lower)
{
    wgen::syllabary syllabary("TGZ", "AEIOU");
    std::string word = syllabary.random_word(4, wgen::syllabary::format::lower);

    ASSERT_EQ(word.length(), 4);
    std::string_view lower_consonants = "tgz";
    std::string_view lower_vowels = "aeiou";
    ASSERT_TRUE(lower_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(lower_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_random_tests, test_random_word_upper)
{
    wgen::syllabary syllabary("tgz", "aeiou");
    std::string word = syllabary.random_word(4, wgen::syllabary::format::upper);

    ASSERT_EQ(word.length(), 4);
    std::string_view upper_consonants = "TGZ";
    std::string_view upper_vowels = "AEIOU";
    ASSERT_TRUE(upper_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(upper_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(upper_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(upper_vowels.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_random_tests, test_random_name)
{
    wgen::syllabary syllabary("tgz", "AEIOU");
    std::string word = syllabary.random_name(4);

    ASSERT_EQ(word.length(), 4);
    std::string_view upper_consonants = "TGZ";
    std::string_view lower_consonants = "tgz";
    std::string_view lower_vowels = "aeiou";
    ASSERT_TRUE(upper_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(lower_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_random_tests, test_random_lowercase_word)
{
    wgen::syllabary syllabary("TGZ", "AEIOU");
    std::string word = syllabary.random_lowercase_word(4);

    ASSERT_EQ(word.length(), 4);
    std::string_view lower_consonants = "tgz";
    std::string_view lower_vowels = "aeiou";
    ASSERT_TRUE(lower_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(lower_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_random_tests, test_random_uppercase_word)
{
    wgen::syllabary syllabary("tgz", "aeiou");
    std::string word = syllabary.random_uppercase_word(4);

    ASSERT_EQ(word.length(), 4);
    std::string_view upper_consonants = "TGZ";
    std::string_view upper_vowels = "AEIOU";
    ASSERT_TRUE(upper_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(upper_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(upper_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(upper_vowels.find(word[3]) != std::string_view::npos);
}
