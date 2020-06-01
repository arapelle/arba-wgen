#pragma once 

#include <strn/string64.hpp>
#include <string>
#include <string_view>
#include <vector>
#include <cstdint>

namespace wgen
{
class Syllabary
{
public:
    enum class Format : uint64_t
    {
        No_format, // No format
        Name,      // Name
        Lower,     // lowercase
        Upper,     // UPPERCASE
    };

    Syllabary(const std::string_view& consonants, const std::string_view& vowels, const std::string_view& codas = "");
    Syllabary(std::vector<char> consonants, std::vector<char> vowels, std::vector<char> codas = {});

    std::string random_word(unsigned word_length, Format format = Format::No_format) const;
    inline std::string random_name(unsigned word_length) const { return random_word(word_length, Format::Name); }
    inline std::string random_lowercase_word(unsigned word_length) const { return random_word(word_length, Format::Lower); }
    inline std::string random_uppercase_word(unsigned word_length) const { return random_word(word_length, Format::Upper); }

    strn::string64 random_word64(unsigned word_length, Format format = Format::No_format) const;
    inline strn::string64 random_name64(unsigned word_length) const { return random_word64(word_length, Format::Name); }
    inline strn::string64 random_lowercase_word64(unsigned word_length) const { return random_word64(word_length, Format::Lower); }
    inline strn::string64 random_uppercase_word64(unsigned word_length) const { return random_word64(word_length, Format::Upper); }

    std::string format_word(std::string_view format_str, const char c_char = 'c', const char v_char = 'v',
                            Format format = Format::No_format) const;
    inline std::string format_name(std::string_view format_str, const char c_char = 'c', const char v_char = 'v') const;
    inline std::string format_lowercase_word(std::string_view format_str, const char c_char = 'c', const char v_char = 'v') const;
    inline std::string format_uppercase_word(std::string_view format_str, const char c_char = 'c', const char v_char = 'v') const;

    strn::string64 format_word64(std::string_view format_str, const char c_char = 'c', const char v_char = 'v',
                               Format format = Format::No_format) const;
    inline strn::string64 format_name64(std::string_view format_str, const char c_char = 'c', const char v_char = 'v') const;
    inline strn::string64 format_lowercase_word64(std::string_view format_str, const char c_char = 'c', const char v_char = 'v') const;
    inline strn::string64 format_uppercase_word64(std::string_view format_str, const char c_char = 'c', const char v_char = 'v') const;

    std::size_t number_of_possible_words(unsigned word_length) const;

    inline const std::vector<char>& consonants() const { return consonants_; }
    inline const std::vector<char>& vowels() const { return vowels_; }
    inline const std::vector<char>& codas() const { return codas_; }

private:
    void format_(std::string& word, Format format) const;
    char random_consonant_() const;
    char random_vowel_() const;
    char random_coda_() const;

    std::vector<char> consonants_;
    std::vector<char> vowels_;
    std::vector<char> codas_;
};

inline std::string Syllabary::format_name(std::string_view format_str, const char c_char, const char v_char) const
{
    return format_word(format_str, c_char, v_char, Format::Name);
}

inline std::string Syllabary::format_lowercase_word(std::string_view format_str, const char c_char, const char v_char) const
{
    return format_word(format_str, c_char, v_char, Format::Lower);
}

inline std::string Syllabary::format_uppercase_word(std::string_view format_str, const char c_char, const char v_char) const
{
    return format_word(format_str, c_char, v_char, Format::Upper);
}

inline strn::string64 Syllabary::format_name64(std::string_view format_str, const char c_char, const char v_char) const
{
    return format_word64(format_str, c_char, v_char, Format::Name);
}

inline strn::string64 Syllabary::format_lowercase_word64(std::string_view format_str, const char c_char, const char v_char) const
{
    return format_word64(format_str, c_char, v_char, Format::Lower);
}

inline strn::string64 Syllabary::format_uppercase_word64(std::string_view format_str, const char c_char, const char v_char) const
{
    return format_word64(format_str, c_char, v_char, Format::Upper);
}

}
