#ifndef IOC_ANY_MAP_HPP
#define IOC_ANY_MAP_HPP

//////////////////////////////////////////////////////////////////////////
// any_map.hpp

// (C) Copyright 2011-2012 Guardian
// (C) Copyright 2013-2014 Yury Yakovlev <yvzmail@gmail.com>
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <boost/any.hpp>
#include <boost/unordered_map.hpp>

namespace ioc
{
namespace detail
{

class any_map
{
    typedef boost::unordered_map<std::string, boost::any> inner_map;

public:
    void insert(const std::string& name, const boost::any& obj)
    {
        m_innerMap.insert(std::make_pair(name, obj));
    }

    boost::any get(const std::string& name) const
    {
        inner_map::const_iterator it = m_innerMap.find(name);
        return (it != m_innerMap.end())? it->second : boost::any();
    }

private:
    inner_map m_innerMap;
};

}
}

#endif // ANY_MAP_HPP
