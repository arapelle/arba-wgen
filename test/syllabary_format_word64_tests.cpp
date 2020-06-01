#include <wgen/syllabary.hpp>
#include <gtest/gtest.h>
#include <sstream>
#include <cstdlib>

TEST(syllabaray_format64_tests, test_format_word64_1)
{
    wgen::Syllabary syllabary("tgz", "aeiou", "klr");
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
    ASSERT_TRUE(codas.find(word[5]) != std::string_view::npos);
}

TEST(syllabaray_format64_tests, test_format_word64_2)
{
    wgen::Syllabary syllabary("tgz", "aeiou");
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
    wgen::Syllabary syllabary("tgz", "aeiou", "klr");
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
    wgen::Syllabary syllabary("TGZ", "aeiou", "KLR");
    strn::string64 word = syllabary.format_word64("abab", 'b', 'a', wgen::Syllabary::Format::Name);

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
    wgen::Syllabary syllabary("TGZ", "AEIOU", "KLR");
    strn::string64 word = syllabary.format_word64("ababab", 'b', 'a', wgen::Syllabary::Format::Lower);

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
    wgen::Syllabary syllabary("tgz", "aei", "kl");
    strn::string64 word = syllabary.format_word64("abab", 'b', 'a', wgen::Syllabary::Format::Upper);

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
    wgen::Syllabary syllabary("TGZ", "aeiou", "KLR");
    strn::string64 word = syllabary.format_name64("vbvb", 'b');

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
    wgen::Syllabary syllabary("TGZ", "AEIOU", "KLR");
    strn::string64 word = syllabary.format_lowercase_word64("ababab", 'b', 'a');

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
    wgen::Syllabary syllabary("tgz", "aei", "kl");
    strn::string64 word = syllabary.format_uppercase_word64("abab", 'b', 'a');

    ASSERT_EQ(word.length(), 4);
    std::string_view consonants = "TGZ";
    std::string_view vowels = "AEI";
    std::string_view codas = "KL";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[3]) != std::string_view::npos);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
