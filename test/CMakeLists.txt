add_cpp_library_tests(SHARED ${PROJECT_NAME}
                      STATIC ${PROJECT_NAME}-static
                      SOURCES
                      default_syllabary_tests.cpp
                      syllabary_format_word64_tests.cpp
                      syllabary_format_word_tests.cpp
                      syllabary_random_word64_tests.cpp
                      syllabary_random_word_tests.cpp
                      syllabary_tests.cpp
                      )
