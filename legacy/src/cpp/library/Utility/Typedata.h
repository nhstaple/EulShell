// library/Graph/Typedata.h
// Code taken from here
// https://stackoverflow.com/a/20170989
#ifndef _TYPE_DATA_H_
#define _TYPE_DATA_H_

#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

template <class T>
std::string
type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";

    // Special case for std::string.
    if(r == "std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >") {
        r = "std::string";
    } else if (r == "std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&") {
        r = "std::string const&";
    }
    return r;
}

#endif // _TYPE_DATA_H_
