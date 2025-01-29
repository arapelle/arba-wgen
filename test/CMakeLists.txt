include(cmtk/CppLibraryTests)
include(GoogleTest)

find_package(GTest 1.14 CONFIG REQUIRED)

add_cpp_library_basic_tests(${PROJECT_TARGET_NAME} GTest::gtest_main
    SOURCES
        project_version_tests.cpp
        default_syllabary_tests.cpp
        syllabary_format_word64_tests.cpp
        syllabary_format_word_tests.cpp
        syllabary_random_word64_tests.cpp
        syllabary_random_word_tests.cpp
        syllabary_tests.cpp
)
