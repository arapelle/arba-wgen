# Concept #

The purpose is to provide functions generating random words (std::string) from a syllabary.
A syllabary has a set of consonants, a set of vowels and a set of codas (other consonants for the last letter).
A word is built as a sequence of syllables composed of a consonant and a vowel. 
If the length of the generated word is odd, then a coda is added at the end of the sequence,
or a vowel at the beginning of the sequence.

```
random_world(4) -> cvcv (ex: babe)
random_world(5) -> cvcvk (ex: total)
random_world(5) -> vcvcv (ex: akamo)
```

See [task board](https://app.gitkraken.com/glo/board/Xn4ZRDGIwwAqohS0) for future updates and features.

# Install #
## Requirements ##
Binaries:
- A C++17 compiler (ex: g++-9)
- CMake 3.16 or later

Libraries:
- [strn](https://github.com/arapelle/strn) 0.1 or later
- [Google Test](https://github.com/google/googletest) 1.10 or later (only for testing)

## Quick Install ##
There is a cmake script at the root of the project which builds the library in *Release* mode and install it (default options are used).
```
cd /path/to/wgen
cmake -P cmake_quick_install.cmake
```
Use the following to quickly install a different mode.
```
cmake -DCMAKE_BUILD_TYPE=Debug -P cmake_quick_install.cmake
```

# How to use
## Example - Generate a random word
```c++
#include <wgen/default_syllabary.hpp>
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
#include <wgen/default_syllabary.hpp>
#include <strn/io.hpp>
#include <iostream>

int main()
{
    wgen::default_syllabary syllabary;
    strn::string64 word = syllabary.format_word64("[cv-cvc]");
    std::cout << word << std::endl; // prints [vo-dof]
    return EXIT_SUCCESS;
}
```
## Example - Using *wgen* in a CMake project
See the [basic cmake project](https://github.com/arapelle/wgen/tree/master/example/basic_cmake_project) example, and more specifically the [CMakeLists.txt](https://github.com/arapelle/wgen/tree/master/example/basic_cmake_project/CMakeLists.txt) to see how to use *wgen* in your CMake projects.

# License

[MIT License](./LICENSE.md) © wgen
