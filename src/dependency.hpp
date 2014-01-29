#ifndef IOC_DEPENDENCY_HPP
#define IOC_DEPENDENCY_HPP

//////////////////////////////////////////////////////////////////////////
// dependency.hpp

// (C) Copyright 2011-2012 Guardian
// (C) Copyright 2013-2014 Yury Yakovlev <yvzmail@gmail.com>
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/shared_ptr.hpp>
#include <boost/mpl/comparison.hpp>
#include <boost/mpl/copy_if.hpp>
#include <boost/mpl/vector.hpp>

#include "lifestyle.hpp"

namespace ioc
{
namespace detail
{

template<typename invalid_type, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
struct pack_args
{
    typedef typename boost::mpl::copy_if<
        boost::mpl::vector8<A0, A1, A2, A3, A4, A5, A6, A7>,
        boost::mpl::not_equal_to<boost::is_same<boost::mpl::_1, invalid_type>, boost::mpl::true_>,
        boost::mpl::back_inserter<boost::mpl::vector<>>
    >::type output_args; 
};

} // namespace detail

struct empty_dependency_t { typedef int dummy_; };

template<
    typename T,
    typename L,
    typename A0 = empty_dependency_t,
    typename A1 = empty_dependency_t,
    typename A2 = empty_dependency_t,
    typename A3 = empty_dependency_t,
    typename A4 = empty_dependency_t,
    typename A5 = empty_dependency_t,
    typename A6 = empty_dependency_t,
    typename A7 = empty_dependency_t
>
struct descriptor_t
{
    typedef T type;
    typedef L lifestyle;
    typedef boost::shared_ptr<T> interface;
    typedef typename detail::pack_args<empty_dependency_t, A0, A1, A2, A3, A4, A5, A6, A7>::output_args dependencies;
};

}

#endif // IOC_DEPENDENCY_HPP
