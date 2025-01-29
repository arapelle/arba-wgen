#pragma once

#include "syllabary.hpp"

inline namespace arba
{
namespace wgen
{

/**
 * @brief The default_syllabary class
 *
 * consonants = {'b', 'd', 'f', 'g', 'k', 'l', 'm', 'n', 'p', 'r', 't', 'v', 'y', 'z'}
 * vowels     = {'a', 'e', 'i', 'o', 'u'}
 * codas      = {'k', 'l', 'r', 'x'}
 */
class default_syllabary : public syllabary
{
public:
    default_syllabary();
};

} // namespace wgen
} // namespace arba
