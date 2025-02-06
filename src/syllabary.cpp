#include <arba/wgen/syllabary.hpp>

#include <experimental/random>

#include <algorithm>
#include <locale>
#include <random>

namespace wgen
{
////////////////////////////////////////////////////////////////////////////////

syllabary::syllabary(const std::string_view& consonants, const std::string_view& vowels, const std::string_view& codas)
    : consonants_(consonants.begin(), consonants.end()), vowels_(vowels.begin(), vowels.end()),
      codas_(codas.begin(), codas.end())
{
}

syllabary::syllabary(std::vector<char> consonants, std::vector<char> vowels, std::vector<char> codas)
    : consonants_(std::move(consonants)), vowels_(std::move(vowels)), codas_(std::move(codas))
{
}

std::string syllabary::random_word(unsigned word_length, format fmt) const
{
    std::string word;
    word.resize(word_length);

    random_word_(&*word.begin(), &*word.end(), word_length, fmt);

    return word;
}

strn::string64 syllabary::random_word64(unsigned word_length, format fmt) const
{
    strn::string64 word;
    word_length = std::min<unsigned>(word_length, word.max_length());
    random_word_(&*word.begin(), &*std::next(word.begin(), word_length), word_length, fmt);
    return word;
}

std::string syllabary::format_word(std::string_view format_str, const char c_char, const char v_char, const char q_char,
                                   format fmt) const
{
    std::string word(format_str.length(), '?');
    format_word_(&*word.begin(), &*word.end(), format_str, c_char, v_char, q_char, fmt);
    return word;
}

strn::string64 syllabary::format_word64(std::string_view format_str, const char c_char, const char v_char,
                                        const char q_char, format fmt) const
{
    strn::string64 word;
    std::size_t word_length = std::min(format_str.size(), word.max_length());
    format_str = format_str.substr(0, word_length);
    format_word_(&*word.begin(), &*std::next(word.begin(), word_length), format_str, c_char, v_char, q_char, fmt);
    return word;
}

std::size_t syllabary::number_of_possible_words(unsigned word_length) const
{
    if (word_length > 0)
    {
        std::size_t nos2 = consonants_.size() * vowels_.size();
        std::size_t result = 1;
        for (std::size_t number_of_syllables = word_length / 2; number_of_syllables > 0; --number_of_syllables)
            result *= nos2;
        if (word_length & 1)
            result *= codas_.size() + vowels_.size();
        return result;
    }
    return 0;
}

// private

void syllabary::random_word_(char* first, char* last, unsigned word_length, format fmt) const
{
    if (word_length > 0)
    {
        char* iter = first;

        if ((word_length & 1) && (codas_.empty() || std::experimental::randint(0, 1) == 1))
        {
            *iter++ = random_vowel_();
        }
        for (std::size_t i = 0, end_i = word_length / 2; i < end_i; ++i)
        {
            *iter++ = random_consonant_();
            *iter++ = random_vowel_();
        }
        if (iter != last)
        {
            *iter++ = codas_.empty() ? random_consonant_() : random_coda_();
        }

        format_(first, last, fmt);
    }
}

void syllabary::format_word_(char* first, char* last, std::string_view format_str, const char c_char, const char v_char,
                             const char q_char, format fmt) const
{
    if (format_str.length() > 0)
    {
        char* iter = first;

        auto fmt_iter = format_str.begin();
        for (auto fmt_end_iter = codas_.empty() ? format_str.end() : format_str.end() - 1; fmt_iter < fmt_end_iter;
             ++fmt_iter)
        {
            char ch = *fmt_iter;
            if (ch == c_char)
                *iter = random_consonant_();
            else if (ch == v_char)
                *iter = random_vowel_();
            else if (ch == q_char)
                *iter = random_coda_();
            else
                *iter = ch;
            ++iter;
        }
        if (fmt_iter != format_str.end())
        {
            char ch = *fmt_iter;
            if (ch == c_char)
                *iter = random_consonant_();
            else if (ch == v_char)
                *iter = random_vowel_();
            else if (ch == q_char)
                *iter = random_coda_();
            else
                *iter = ch;
        }

        format_(first, last, fmt);
    }
}

void syllabary::format_(char* first, char* last, format fmt) const
{
    auto& facet = std::use_facet<std::ctype<std::string::value_type>>(std::locale());
    switch (fmt)
    {
    case format::name:
    {
        char& first_ch = *first;
        first_ch = facet.toupper(first_ch);
        std::for_each(std::next(first), last, [&facet](std::string::value_type& ch) { ch = facet.tolower(ch); });
        break;
    }
    case format::lower:
    {
        std::for_each(first, last, [&facet](std::string::value_type& ch) { ch = facet.tolower(ch); });
        break;
    }
    case format::upper:
    {
        std::for_each(first, last, [&facet](std::string::value_type& ch) { ch = facet.toupper(ch); });
        break;
    }
    case format::no_format:
    default:;
    }
}

char syllabary::random_consonant_() const
{
    std::size_t idx = std::experimental::randint<std::size_t>(0, consonants_.size() - 1);
    return consonants_[idx];
}

char syllabary::random_vowel_() const
{
    std::size_t idx = std::experimental::randint<std::size_t>(0, vowels_.size() - 1);
    return vowels_[idx];
}

char syllabary::random_coda_() const
{
    std::size_t idx = std::experimental::randint<std::size_t>(0, codas_.size() - 1);
    return codas_[idx];
}

} // namespace wgen
