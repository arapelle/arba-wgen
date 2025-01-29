#include <arba/wgen/default_syllabary.hpp>
#include <arba/strn/io.hpp>
#include <iostream>

int main()
{
    wgen::default_syllabary syllabary;
    strn::string64 word = syllabary.format_word64("[cv-cvc]");
    std::cout << word << std::endl; // prints [vo-dof]
    std::cout << "TEST PACKAGE SUCCESS" << std::endl;
    return EXIT_SUCCESS;
}
