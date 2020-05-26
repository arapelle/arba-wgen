#include <wgen/syllabary.hpp>
#include <gtest/gtest.h>
#include <sstream>
#include <cstdlib>

TEST(syllabaray_tests, test_constructor_strv)
{
    wgen::Syllabary syllabary("tgz", "aeiou", "klr");

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
    wgen::Syllabary syllabary(std::move(consonants), std::move(vowels), std::move(codas));

    std::vector<char> expected_consonants{'t', 'z', 'g'};
    std::vector<char> expected_vowels{'a', 'e', 'i', 'u'};
    std::vector<char> expected_codas{'k', 'l', 'x'};
    ASSERT_EQ(syllabary.consonants(), expected_consonants);
    ASSERT_EQ(syllabary.vowels(), expected_vowels);
    ASSERT_EQ(syllabary.codas(), expected_codas);
}

TEST(syllabaray_tests, test_random_word_1)
{
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "";
    wgen::Syllabary syllabary(consonants, vowels, codas);

    std::string word = syllabary.random_word(5);
    ASSERT_EQ(word.length(), 5);
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[3]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[4]) != std::string_view::npos);
}

TEST(syllabaray_tests, test_random_word_2)
{
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "klx";
    wgen::Syllabary syllabary(consonants, vowels, codas);

    std::string word = syllabary.random_word(6);
    ASSERT_EQ(word.length(), 6);
    ASSERT_TRUE(consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[3]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[4]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[5]) != std::string_view::npos);
}

TEST(syllabaray_tests, test_random_word_3)
{
    std::string_view consonants = "tgz";
    std::string_view vowels = "aeiou";
    std::string_view codas = "klx";
    wgen::Syllabary syllabary(consonants, vowels, codas);

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

TEST(syllabaray_tests, test_random_word_name)
{
    wgen::Syllabary syllabary("tgz", "AEIOU");
    std::string word = syllabary.random_word(4, wgen::Syllabary::Format::Name);

    ASSERT_EQ(word.length(), 4);
    std::string_view upper_consonants = "TGZ";
    std::string_view lower_consonants = "tgz";
    std::string_view lower_vowels = "aeiou";
    ASSERT_TRUE(upper_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(lower_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_tests, test_random_word_lower)
{
    wgen::Syllabary syllabary("TGZ", "AEIOU");
    std::string word = syllabary.random_word(4, wgen::Syllabary::Format::Lower);

    ASSERT_EQ(word.length(), 4);
    std::string_view lower_consonants = "tgz";
    std::string_view lower_vowels = "aeiou";
    ASSERT_TRUE(lower_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(lower_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_tests, test_random_word_upper)
{
    wgen::Syllabary syllabary("tgz", "aeiou");
    std::string word = syllabary.random_word(4, wgen::Syllabary::Format::Upper);

    ASSERT_EQ(word.length(), 4);
    std::string_view upper_consonants = "TGZ";
    std::string_view upper_vowels = "AEIOU";
    ASSERT_TRUE(upper_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(upper_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(upper_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(upper_vowels.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_tests, test_random_name)
{
    wgen::Syllabary syllabary("tgz", "AEIOU");
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

TEST(syllabaray_tests, test_random_lowercase_word)
{
    wgen::Syllabary syllabary("TGZ", "AEIOU");
    std::string word = syllabary.random_lowercase_word(4);

    ASSERT_EQ(word.length(), 4);
    std::string_view lower_consonants = "tgz";
    std::string_view lower_vowels = "aeiou";
    ASSERT_TRUE(lower_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(lower_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(lower_vowels.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_tests, test_random_uppercase_word)
{
    wgen::Syllabary syllabary("tgz", "aeiou");
    std::string word = syllabary.random_uppercase_word(4);

    ASSERT_EQ(word.length(), 4);
    std::string_view upper_consonants = "TGZ";
    std::string_view upper_vowels = "AEIOU";
    ASSERT_TRUE(upper_consonants.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(upper_vowels.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(upper_consonants.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(upper_vowels.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_tests, test_format_word_1)
{
    wgen::Syllabary syllabary("tgz", "aeiou", "klr");
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
    ASSERT_TRUE(codas.find(word[5]) != std::string_view::npos);
}

TEST(syllabaray_tests, test_format_word_2)
{
    wgen::Syllabary syllabary("tgz", "aeiou");
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

TEST(syllabaray_tests, test_format_word_3)
{
    wgen::Syllabary syllabary("tgz", "aeiou", "klr");
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

TEST(syllabaray_tests, test_format_word_name)
{
    wgen::Syllabary syllabary("TGZ", "aeiou", "KLR");
    std::string word = syllabary.format_word("abab", 'b', 'a', wgen::Syllabary::Format::Name);

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

TEST(syllabaray_tests, test_format_word_lower)
{
    wgen::Syllabary syllabary("TGZ", "AEIOU", "KLR");
    std::string word = syllabary.format_word("ababab", 'b', 'a', wgen::Syllabary::Format::Lower);

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

TEST(syllabaray_tests, test_format_word_upper)
{
    wgen::Syllabary syllabary("tgz", "aei", "kl");
    std::string word = syllabary.format_word("abab", 'b', 'a', wgen::Syllabary::Format::Upper);

    ASSERT_EQ(word.length(), 4);
    std::string_view consonants = "TGZ";
    std::string_view vowels = "AEI";
    std::string_view codas = "KL";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_tests, test_format_name)
{
    wgen::Syllabary syllabary("TGZ", "aeiou", "KLR");
    std::string word = syllabary.format_name("vbvb", 'b');

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

TEST(syllabaray_tests, test_format_lowercase_word)
{
    wgen::Syllabary syllabary("TGZ", "AEIOU", "KLR");
    std::string word = syllabary.format_lowercase_word("ababab", 'b', 'a');

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

TEST(syllabaray_tests, test_format_uppercase_word)
{
    wgen::Syllabary syllabary("tgz", "aei", "kl");
    std::string word = syllabary.format_uppercase_word("abab", 'b', 'a');

    ASSERT_EQ(word.length(), 4);
    std::string_view consonants = "TGZ";
    std::string_view vowels = "AEI";
    std::string_view codas = "KL";
    ASSERT_TRUE(vowels.find(word[0]) != std::string_view::npos);
    ASSERT_TRUE(consonants.find(word[1]) != std::string_view::npos);
    ASSERT_TRUE(vowels.find(word[2]) != std::string_view::npos);
    ASSERT_TRUE(codas.find(word[3]) != std::string_view::npos);
}

TEST(syllabaray_tests, test_number_of_possible_words)
{
    std::string_view consonants = "tgz"; // length: 3
    std::string_view vowels = "aeiou"; // length: 5
    std::string_view codas = "klxr"; // length: 4
    wgen::Syllabary syllabary(consonants, vowels, codas);
    ASSERT_EQ(syllabary.number_of_possible_words(2), 3 * 5);
    ASSERT_EQ(syllabary.number_of_possible_words(3), 15 * (5 + 4));
    ASSERT_EQ(syllabary.number_of_possible_words(4), 15 * 15);
    ASSERT_EQ(syllabary.number_of_possible_words(5), 15 * 15 * 9);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
