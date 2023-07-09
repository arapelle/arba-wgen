find_or_fetch_GTest()

add_cpp_library_basic_tests(GTest::gtest_main
    SHARED ${PROJECT_NAME}
    STATIC ${PROJECT_NAME}-static
    SOURCES
        default_syllabary_tests.cpp
        syllabary_format_word64_tests.cpp
        syllabary_format_word_tests.cpp
        syllabary_random_word64_tests.cpp
        syllabary_random_word_tests.cpp
        syllabary_tests.cpp
)
