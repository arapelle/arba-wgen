#include <arba/wgen/default_syllabary.hpp>
#include <arba/wgen/version.hpp>

#include <iostream>

int main()
{
    arba::wgen::default_syllabary syllabary;
    std::string word = syllabary.random_word(7);
    std::cout << word << std::endl;
    return EXIT_SUCCESS;
}
