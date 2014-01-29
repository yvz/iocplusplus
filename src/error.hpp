#ifndef IOC_ERROR_HPP
#define IOC_ERROR_HPP

//////////////////////////////////////////////////////////////////////////
// error.hpp

// (C) Copyright 2011-2012 Guardian
// (C) Copyright 2013-2014 Yury Yakovlev <yvzmail@gmail.com>
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <exception>

namespace ioc
{

class unregistred_type : public std::exception
{
public:
    unregistred_type(const std::string& name) : m_what("ioc++: no descriptor is registered for a type " + name) {}
    virtual const char* what() const { return m_what.c_str(); }
private:
    std::string m_what;
};

class invalid_signature : public std::exception
{
public:
    invalid_signature(const std::string& name) : m_what("ioc++: signature mismatch for a type " + name) {}
    virtual const char* what() const { return m_what.c_str(); }
private:
    std::string m_what;
};

}

#endif // IOC_ERROR_HPP