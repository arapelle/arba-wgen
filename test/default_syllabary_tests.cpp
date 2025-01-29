#include <arba/wgen/default_syllabary.hpp>

#include <gtest/gtest.h>

#include <type_traits>

static_assert(std::is_base_of_v<wgen::syllabary, wgen::default_syllabary>);

TEST(default_syllabaray_tests, test_constructor)
{
    wgen::default_syllabary syllabary;

    std::vector<char> expected_consonants{ 'b', 'd', 'f', 'g', 'k', 'l', 'm', 'n', 'p', 'r', 't', 'v', 'y', 'z' };
    std::vector<char> expected_vowels{ 'a', 'e', 'i', 'o', 'u' };
    std::vector<char> expected_codas{ 'k', 'l', 'r', 'x' };
    ASSERT_EQ(syllabary.consonants(), expected_consonants);
    ASSERT_EQ(syllabary.vowels(), expected_vowels);
    ASSERT_EQ(syllabary.codas(), expected_codas);
}
