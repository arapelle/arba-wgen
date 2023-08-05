#include <arba/wgen/default_syllabary.hpp>

inline namespace arba
{
namespace wgen
{

default_syllabary::default_syllabary()
    : syllabary({'b', 'd', 'f', 'g', 'k', 'l', 'm', 'n', 'p', 'r', 't', 'v', 'y', 'z'},
                {'a', 'e', 'i', 'o', 'u'},
                {'k', 'l', 'r', 'x'})
{}

}
}
