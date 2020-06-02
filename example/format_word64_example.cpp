#include <wgen/default_syllabary.hpp>
#include <strn/io.hpp>
#include <iostream>

int main()
{
    wgen::default_syllabary syllabary;
    strn::string64 word = syllabary.format_word64("[cvcvc]");
    std::cout << word << std::endl;
    return EXIT_SUCCESS;
}
