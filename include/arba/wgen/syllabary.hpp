#pragma once

#include <arba/strn/string64.hpp>

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

inline namespace arba
{
namespace wgen
{

class syllabary
{
public:
    inline static constexpr char default_format_consonant = 'c';
    inline static constexpr char default_format_vowel = 'v';
    inline static constexpr char default_format_coda = 'q';

    enum class format : uint64_t
    {
        no_format, // No format
        name,      // Name
        lower,     // lowercase
        upper,     // UPPERCASE
    };

    syllabary(const std::string_view& consonants, const std::string_view& vowels, const std::string_view& codas = "");
    syllabary(std::vector<char> consonants, std::vector<char> vowels, std::vector<char> codas = {});

    std::string random_word(unsigned word_length, format fmt = format::no_format) const;
    inline std::string random_name(unsigned word_length) const { return random_word(word_length, format::name); }
    inline std::string random_lowercase_word(unsigned word_length) const
    {
        return random_word(word_length, format::lower);
    }
    inline std::string random_uppercase_word(unsigned word_length) const
    {
        return random_word(word_length, format::upper);
    }

    strn::string64 random_word64(unsigned word_length, format fmt = format::no_format) const;
    inline strn::string64 random_name64(unsigned word_length) const { return random_word64(word_length, format::name); }
    inline strn::string64 random_lowercase_word64(unsigned word_length) const
    {
        return random_word64(word_length, format::lower);
    }
    inline strn::string64 random_uppercase_word64(unsigned word_length) const
    {
        return random_word64(word_length, format::upper);
    }

    // clang-format off
    std::string format_word(std::string_view format_str,
                            const char c_char = default_format_consonant,
                            const char v_char = default_format_vowel,
                            const char q_char = default_format_coda,
                            format fmt = format::no_format) const;
    inline std::string format_name(std::string_view format_str,
                                   const char c_char = default_format_consonant,
                                   const char v_char = default_format_vowel,
                                   const char q_char = default_format_coda) const;
    inline std::string format_lowercase_word(std::string_view format_str,
                                             const char c_char = default_format_consonant,
                                             const char v_char = default_format_vowel,
                                             const char q_char = default_format_coda) const;
    inline std::string format_uppercase_word(std::string_view format_str,
                                             const char c_char = default_format_consonant,
                                             const char v_char = default_format_vowel,
                                             const char q_char = default_format_coda) const;

    strn::string64 format_word64(std::string_view format_str,
                                 const char c_char = default_format_consonant,
                                 const char v_char = default_format_vowel,
                                 const char q_char = default_format_coda,
                                 format fmt = format::no_format) const;
    inline strn::string64 format_name64(std::string_view format_str,
                                        const char c_char = default_format_consonant,
                                        const char v_char = default_format_vowel,
                                        const char q_char = default_format_coda) const;
    inline strn::string64 format_lowercase_word64(std::string_view format_str,
                                                  const char c_char = default_format_consonant,
                                                  const char v_char = default_format_vowel,
                                                  const char q_char = default_format_coda) const;
    inline strn::string64 format_uppercase_word64(std::string_view format_str,
                                                  const char c_char = default_format_consonant,
                                                  const char v_char = default_format_vowel,
                                                  const char q_char = default_format_coda) const;
    // clang-format on

    std::size_t number_of_possible_words(unsigned word_length) const;

    inline const std::vector<char>& consonants() const { return consonants_; }
    inline const std::vector<char>& vowels() const { return vowels_; }
    inline const std::vector<char>& codas() const { return codas_; }

private:
    void random_word_(char* first, char* last, unsigned word_length, format fmt) const;
    void format_word_(char* first, char* last, std::string_view format_str, const char c_char, const char v_char,
                      const char q_char, format fmt) const;
    void format_(char* first, char* last, format fmt) const;
    char random_consonant_() const;
    char random_vowel_() const;
    char random_coda_() const;

    std::vector<char> consonants_;
    std::vector<char> vowels_;
    std::vector<char> codas_;
};

// syllabary implementation:

inline std::string syllabary::format_name(std::string_view format_str, const char c_char, const char v_char,
                                          const char q_char) const
{
    return format_word(format_str, c_char, v_char, q_char, format::name);
}

inline std::string syllabary::format_lowercase_word(std::string_view format_str, const char c_char, const char v_char,
                                                    const char q_char) const
{
    return format_word(format_str, c_char, v_char, q_char, format::lower);
}

inline std::string syllabary::format_uppercase_word(std::string_view format_str, const char c_char, const char v_char,
                                                    const char q_char) const
{
    return format_word(format_str, c_char, v_char, q_char, format::upper);
}

inline strn::string64 syllabary::format_name64(std::string_view format_str, const char c_char, const char v_char,
                                               const char q_char) const
{
    return format_word64(format_str, c_char, v_char, q_char, format::name);
}

inline strn::string64 syllabary::format_lowercase_word64(std::string_view format_str, const char c_char,
                                                         const char v_char, const char q_char) const
{
    return format_word64(format_str, c_char, v_char, q_char, format::lower);
}

inline strn::string64 syllabary::format_uppercase_word64(std::string_view format_str, const char c_char,
                                                         const char v_char, const char q_char) const
{
    return format_word64(format_str, c_char, v_char, q_char, format::upper);
}

} // namespace wgen
} // namespace arba
