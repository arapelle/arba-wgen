#pragma once 

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
    std::size_t number_of_possible_words(unsigned word_length) const;

    inline const std::vector<char>& consonants() const { return consonants_; }
    inline const std::vector<char>& vowels() const { return vowels_; }
    inline const std::vector<char>& codas() const { return codas_; }

private:
    void format_(std::string& word, Format format) const;
    std::string random_syllable_() const;

    std::vector<char> consonants_;
    std::vector<char> vowels_;
    std::vector<char> codas_;
};

}
