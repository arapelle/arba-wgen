#include <arba/wgen/syllabary.hpp>
#include <gtest/gtest.h>
#include <sstream>
#include <cstdlib>

TEST(syllabaray_format_tests, test_format_word_1)
{
    wgen::syllabary syllabary("tgz", "aeiou", "klr");
    std::string word = syllabary.format_word("vcvcvq");

    ASSERT_EQ(word.length(), 6);
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "klr";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[3]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[4]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[5]) != std::string_view::npos);
}

TEST(syllabaray_format_tests, test_format_word_2)
{
    wgen::syllabary syllabary("tgz", "aeiou");
    std::string word = syllabary.format_word("vcvcvc");

    ASSERT_EQ(word.length(), 6);
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "klr";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[3]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[4]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[5]) == std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[5]) != std::string_view::npos);
}

TEST(syllabaray_format_tests, test_format_word_3)
{
    wgen::syllabary syllabary("tgz", "aeiou", "klr");
    std::string word = syllabary.format_word("br..:a:", ':', '.');

    ASSERT_EQ(word.length(), 7);
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "klr";
    ASSERT_EQ(word[0], 'b');
    ASSERT_EQ(word[1], 'r');
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[3]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[4]) != std::string_view::npos);
    ASSERT_EQ(word[5], 'a');
    ASSERT_TRUE(codas.find(word[5]) == std::string_view::npos);
}

TEST(syllabaray_format_tests, test_format_word_name)
{
    wgen::syllabary syllabary("TGZ", "aeiou", "KLR");
    std::string word = syllabary.format_word("abac", 'b', 'a', 'c', wgen::syllabary::format::name);

    ASSERT_EQ(word.length(), 4);
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view upper_vowels = "AEIOU";
    std::string_view codas = "klr";
    ASSERT_TRUE(upper_vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_format_tests, test_format_word_lower)
{
    wgen::syllabary syllabary("TGZ", "AEIOU", "KLR");
    std::string word = syllabary.format_word("ababac", 'b', 'a', 'c', wgen::syllabary::format::lower);

    ASSERT_EQ(word.length(), 6);
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "klr";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[3]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[4]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[5]) != std::string_view::npos);
}

TEST(syllabaray_format_tests, test_format_word_upper)
{
    wgen::syllabary syllabary("tgz", "aei", "kl");
    std::string word = syllabary.format_word("abac", 'b', 'a', 'c', wgen::syllabary::format::upper);

    ASSERT_EQ(word.length(), 4);
    std::string_view consonants = "TGZ";
    std::string_view vowels = "AEI";
    std::string_view codas = "KL";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_format_tests, test_format_name)
{
    wgen::syllabary syllabary("TGZ", "aeiou", "KLR");
    std::string word = syllabary.format_name("vbvt", 'b', wgen::syllabary::default_format_vowel, 't');

    ASSERT_EQ(word.length(), 4);
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view upper_vowels = "AEIOU";
    std::string_view codas = "klr";
    ASSERT_TRUE(upper_vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_format_tests, test_format_lowercase_word)
{
    wgen::syllabary syllabary("TGZ", "AEIOU", "KLR");
    std::string word = syllabary.format_lowercase_word("ababac", 'b', 'a', 'c');

    ASSERT_EQ(word.length(), 6);
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "klr";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[3]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[4]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[5]) != std::string_view::npos);
}

TEST(syllabaray_format_tests, test_format_uppercase_word)
{
    wgen::syllabary syllabary("tgz", "aei", "kl");
    std::string word = syllabary.format_uppercase_word("abac", 'b', 'a', 'c');

    ASSERT_EQ(word.length(), 4);
    std::string_view consonants = "TGZ";
    std::string_view vowels = "AEI";
    std::string_view codas = "KL";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[3]) != std::string_view::npos);
}
