#include <arba/wgen/version.hpp>
#include <arba/wgen/default_syllabary.hpp>
#include <arba/strn/io.hpp>
#include <iostream>
#include <cstdlib>

int main()
{
    arba::wgen::default_syllabary d_syllabary;
    std::cout << d_syllabary.random_name64(6) << std::endl;
    wgen::syllabary syllabary({'t', 'g', 'b'}, {'a', 'e', 'i'}, {'k', 'x'});
    std::cout << syllabary.random_name64(6) << std::endl;
    return EXIT_SUCCESS;
}
