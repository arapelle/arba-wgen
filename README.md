# Concept #

The purpose is to provide functions generating random words (`std::string`) from a syllabary.
A syllabary has a set of consonants, a set of vowels and a set of codas (other consonants for the last letter).
A word is built as a sequence of syllables composed of a consonant and a vowel. 
If the length of the generated word is odd, then a coda is added at the end of the sequence,
or a vowel at the beginning of the sequence.

```
random_world(4) -> cvcv (ex: babe)
random_world(5) -> cvcvk (ex: total)
random_world(5) -> vcvcv (ex: akamo)
```

# Install #
## Requirements ##

Binaries:
- A C++20 compiler (ex: g++-13)
- CMake 3.26 or later

Libraries:
- [arba-strn](https://github.com/arapelle/arba-strn) 0.2.0 or later

Testing Libraries (optional):
- [Google Test](https://github.com/google/googletest) 1.13 or later (optional)

## Quick Install ##
There is a cmake script at the root of the project which builds the library in *Release* mode and install it (default options are used).
```
cd /path/to/arba-wgen
cmake -P cmake/scripts/quick_install.cmake
```
Use the following to quickly install a different mode.
```
cmake -P cmake/scripts/quick_install.cmake -- TESTS BUILD Debug DIR /tmp/local
```

## Uninstall ##
There is a uninstall cmake script created during installation. You can use it to uninstall properly this library.
```
cd /path/to/installed-arba-wgen/
cmake -P uninstall.cmake
```

# How to use
## Example - Generate a random word
```c++
#include <arba/wgen/default_syllabary.hpp>
#include <iostream>

int main()
{
    wgen::default_syllabary syllabary;
    std::string word = syllabary.random_word(7);
    std::cout << word << std::endl;
    return EXIT_SUCCESS;
}
```

## Example - Format a strn::string64
```c++
#include <arba/wgen/default_syllabary.hpp>
#include <arba/strn/io.hpp>
#include <iostream>

int main()
{
    wgen::default_syllabary syllabary;
    strn::string64 word = syllabary.format_word64("[cv-cvc]");
    std::cout << word << std::endl; // prints [vo-dof]
    return EXIT_SUCCESS;
}
```
## Example - Using *arba-wgen* in a CMake project
See *basic_cmake_project* example, and more specifically the *CMakeLists.txt* to see how to use *arba-wgen* in your CMake projects.

# License

[MIT License](./LICENSE.md) © arba-wgen
