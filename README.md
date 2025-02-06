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
- A C++20 compiler (ex: g++-14)
- CMake 3.26 or later

Testing Libraries (optional):
- [Google Test](https://github.com/google/googletest) 1.14 or later (optional)

## Clone

```
git clone https://github.com/arapelle/arba-wgen
```

## Use with `conan`

Create the conan package.
```
conan create . --build=missing -c
```
Add a requirement in your conanfile project file.
```python
    def requirements(self):
        self.requires("arba-wgen/0.3.0")
```

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

# License

[MIT License](./LICENSE.md) © arba-wgen
