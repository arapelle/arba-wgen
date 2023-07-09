#include <arba/wgen/version.hpp>
#include <wgen/default_syllabary.hpp>
#include <arba/strn/io.hpp>
#include <iostream>
#include <cstdlib>

int main()
{
    wgen::default_syllabary syllabary;
    std::cout << syllabary.random_name64(6) << std::endl;
    return EXIT_SUCCESS;
}
