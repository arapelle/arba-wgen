#include <arba/wgen/syllabary.hpp>
#include <gtest/gtest.h>
#include <sstream>
#include <cstdlib>

TEST(syllabaray_tests, test_constructor_strv)
{
    wgen::syllabary syllabary("tgz", "aeiou", "klr");

    std::vector<char> expected_consonants{'t', 'g', 'z'};
    std::vector<char> expected_vowels{'a', 'e', 'i', 'o', 'u'};
    std::vector<char> expected_codas{'k', 'l', 'r'};
    ASSERT_EQ(syllabary.consonants(), expected_consonants);
    ASSERT_EQ(syllabary.vowels(), expected_vowels);
    ASSERT_EQ(syllabary.codas(), expected_codas);
}

TEST(syllabaray_tests, test_constructor_vector)
{
    std::vector<char> consonants{'t', 'z', 'g'};
    std::vector<char> vowels{'a', 'e', 'i', 'u'};
    std::vector<char> codas{'k', 'l', 'x'};
    wgen::syllabary syllabary(std::move(consonants), std::move(vowels), std::move(codas));

    std::vector<char> expected_consonants{'t', 'z', 'g'};
    std::vector<char> expected_vowels{'a', 'e', 'i', 'u'};
    std::vector<char> expected_codas{'k', 'l', 'x'};
    ASSERT_EQ(syllabary.consonants(), expected_consonants);
    ASSERT_EQ(syllabary.vowels(), expected_vowels);
    ASSERT_EQ(syllabary.codas(), expected_codas);
}

TEST(syllabaray_tests, test_number_of_possible_words)
{
    std::string_view consonants = "tgz"; // length: 3
    std::string_view vowels = "aeiou"; // length: 5
    std::string_view codas = "klxr"; // length: 4
    wgen::syllabary syllabary(consonants, vowels, codas);
    ASSERT_EQ(syllabary.number_of_possible_words(2), 3 * 5);
    ASSERT_EQ(syllabary.number_of_possible_words(3), 15 * (5 + 4));
    ASSERT_EQ(syllabary.number_of_possible_words(4), 15 * 15);
    ASSERT_EQ(syllabary.number_of_possible_words(5), 15 * 15 * 9);
}

TEST(syllabaray_tests, test_random_word64_1)
{
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "";
    wgen::syllabary syllabary(consonants, vowels, codas);

    strn::string64 word = syllabary.random_word64(5);
    ASSERT_EQ(word.length(), 5);
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[3]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[4]) != std::string_view::npos);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
