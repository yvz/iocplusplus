#ifndef IOC_LIFESTYLE_HPP
#define IOC_LIFESTYLE_HPP

//////////////////////////////////////////////////////////////////////////
// lifestyle.hpp

// (C) Copyright 2011-2012 Guardian
// (C) Copyright 2013-2014 Yury Yakovlev <yvzmail@gmail.com>
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <boost/any.hpp>
#include "any_map.hpp"

namespace ioc
{

struct singleton_t
{
    static boost::any get(void* arg, const std::string& typeName)
    {
        if (arg == 0)
            return boost::any();

        return reinterpret_cast<detail::any_map*>(arg)->get(typeName);
    }

    static void insert(void* arg, const std::string& typeName, const boost::any& obj)
    {
        if (arg == 0)
            return;

        reinterpret_cast<detail::any_map*>(arg)->insert(typeName, obj);
    }
};

struct transient_t
{
    static boost::any get(void* /*arg*/, const std::string& /*typeName*/)
    {
        return boost::any();
    }

    static void insert(void* /*arg*/, const std::string& /*typeName*/, const boost::any& /*obj*/)
    {
    }
};

}

#endif // IOC_LIFESTYLE_HPP
