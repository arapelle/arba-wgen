#include <arba/wgen/syllabary.hpp>
#include <gtest/gtest.h>
#include <sstream>
#include <cstdlib>

TEST(syllabaray_format64_tests, test_format_word64_1)
{
    wgen::syllabary syllabary("tgz", "aeiou", "klr");
    strn::string64 word = syllabary.format_word64("vcvcvq");

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

TEST(syllabaray_format64_tests, test_format_word64_2)
{
    wgen::syllabary syllabary("tgz", "aeiou");
    strn::string64 word = syllabary.format_word64("vcvcvc");

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

TEST(syllabaray_format64_tests, test_format_word64_3)
{
    wgen::syllabary syllabary("tgz", "aeiou", "klr");
    strn::string64 word = syllabary.format_word64("br..:a:", ':', '.');

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

TEST(syllabaray_format64_tests, test_format_word64_name)
{
    wgen::syllabary syllabary("TGZ", "aeiou", "KLR");
    strn::string64 word = syllabary.format_word64("abac", 'b', 'a', 'c', wgen::syllabary::format::name);

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

TEST(syllabaray_format64_tests, test_format_word64_lower)
{
    wgen::syllabary syllabary("TGZ", "AEIOU", "KLR");
    strn::string64 word = syllabary.format_word64("ababac", 'b', 'a', 'c', wgen::syllabary::format::lower);

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

TEST(syllabaray_format64_tests, test_format_word64_upper)
{
    wgen::syllabary syllabary("tgz", "aei", "kl");
    strn::string64 word = syllabary.format_word64("abac", 'b', 'a', 'c', wgen::syllabary::format::upper);

    ASSERT_EQ(word.length(), 4);
    std::string_view consonants = "TGZ";
    std::string_view vowels = "AEI";
    std::string_view codas = "KL";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_format64_tests, test_format_name64)
{
    wgen::syllabary syllabary("TGZ", "aeiou", "KLR");
    strn::string64 word = syllabary.format_name64("vbvt", 'b', wgen::syllabary::default_format_vowel, 't');

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

TEST(syllabaray_format64_tests, test_format_lowercase_word64)
{
    wgen::syllabary syllabary("TGZ", "AEIOU", "KLR");
    strn::string64 word = syllabary.format_lowercase_word64("ababac", 'b', 'a', 'c');

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

TEST(syllabaray_format64_tests, test_format_uppercase_word64)
{
    wgen::syllabary syllabary("tgz", "aei", "kl");
    strn::string64 word = syllabary.format_uppercase_word64("abac", 'b', 'a', 'c');

    ASSERT_EQ(word.length(), 4);
    std::string_view consonants = "TGZ";
    std::string_view vowels = "AEI";
    std::string_view codas = "KL";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[3]) != std::string_view::npos);
}
