#ifndef IOC_GENERATORS_HPP
#define IOC_GENERATORS_HPP

//////////////////////////////////////////////////////////////////////////
// generators.hpp

// (C) Copyright 2011-2012 Guardian
// (C) Copyright 2013-2014 Yury Yakovlev <yvzmail@gmail.com>
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/size.hpp>

#include "construct.hpp"

namespace ioc
{
namespace detail
{

// forward declaration
template<typename descriptor, int dependency_count>
struct generate_resolver;

//////////////////////////////////////////////////////////////////////////
// helper

template <typename parent_descriptor, int index>
struct unpack_dependency
{
    // extract dependency
    typedef typename boost::mpl::at_c<typename parent_descriptor::dependencies, index>::type dependency_descriptor;
    // get dependency children count
    enum { dependency_count = boost::mpl::size<typename dependency_descriptor::dependencies>::value };
    // get the dependency interface type
    typedef typename dependency_descriptor::interface interface_type;

    // the dependency resolver type
    typedef generate_resolver<dependency_descriptor, dependency_count> generate_resolver_type;
};

//////////////////////////////////////////////////////////////////////////
// generators

template<typename descriptor, int dependency_count>
struct generate_resolver
{
    typedef typename descriptor::interface interface_type;
    static boost::function<interface_type(void*)> invoke();
};

template<typename descriptor>
struct generate_resolver<descriptor, 0>
{
    typedef typename descriptor::type construct_type;
    typedef typename descriptor::interface interface_type;
    typedef typename descriptor::lifestyle lifestyle_type;
    static boost::function<interface_type(void*)> invoke() 
    {
        return boost::bind(
            &construct0<
                interface_type, 
                construct_type, 
                lifestyle_type
            >::invoke,
            _1
            );
    }
};

template<typename descriptor>
struct generate_resolver<descriptor, 1>
{
    typedef typename descriptor::type construct_type;
    typedef typename descriptor::interface interface_type;
    typedef typename descriptor::lifestyle lifestyle_type;
    typedef unpack_dependency<descriptor, 0> d0;
    static boost::function<interface_type(void*)> invoke() 
    {
        return boost::bind(
            &construct1<
                interface_type, 
                construct_type, 
                lifestyle_type, 
                typename d0::interface_type
            >::invoke,
            _1,
            d0::generate_resolver_type::invoke()
            );
    }
};

template<typename descriptor>
struct generate_resolver<descriptor, 2>
{
    typedef typename descriptor::type construct_type;
    typedef typename descriptor::interface interface_type;
    typedef typename descriptor::lifestyle lifestyle_type;
    typedef unpack_dependency<descriptor, 0> d0;
    typedef unpack_dependency<descriptor, 1> d1;
    static boost::function<interface_type(void*)> invoke() 
    {
        return boost::bind(
            &construct2<
                interface_type, 
                construct_type, 
                lifestyle_type, 
                typename d0::interface_type, 
                typename d1::interface_type
            >::invoke,
            _1,
            d0::generate_resolver_type::invoke(),
            d1::generate_resolver_type::invoke()
            );
    }
};

template<typename descriptor>
struct generate_resolver<descriptor, 3>
{
    typedef typename descriptor::type construct_type;
    typedef typename descriptor::interface interface_type;
    typedef typename descriptor::lifestyle lifestyle_type;
    typedef unpack_dependency<descriptor, 0> d0;
    typedef unpack_dependency<descriptor, 1> d1;
    typedef unpack_dependency<descriptor, 2> d2;
    static boost::function<interface_type(void*)> invoke() 
    {
        return boost::bind(
            &construct3<
                interface_type, 
                construct_type, 
                lifestyle_type, 
                typename d0::interface_type, 
                typename d1::interface_type, 
                typename d2::interface_type
            >::invoke,
            _1,
            d0::generate_resolver_type::invoke(),
            d1::generate_resolver_type::invoke(),
            d2::generate_resolver_type::invoke()
            );
    }
};

template<typename descriptor>
struct generate_resolver<descriptor, 4>
{
    typedef typename descriptor::type construct_type;
    typedef typename descriptor::interface interface_type;
    typedef typename descriptor::lifestyle lifestyle_type;
    typedef unpack_dependency<descriptor, 0> d0;
    typedef unpack_dependency<descriptor, 1> d1;
    typedef unpack_dependency<descriptor, 2> d2;
    typedef unpack_dependency<descriptor, 3> d3;
    static boost::function<interface_type(void*)> invoke() 
    {
        return boost::bind(
            &construct4<
                interface_type, 
                construct_type, 
                lifestyle_type, 
                typename d0::interface_type, 
                typename d1::interface_type, 
                typename d2::interface_type, 
                typename d3::interface_type
            >::invoke,
            _1,
            d0::generate_resolver_type::invoke(),
            d1::generate_resolver_type::invoke(),
            d2::generate_resolver_type::invoke(),
            d3::generate_resolver_type::invoke()
            );
    }
};

template<typename descriptor>
struct generate_resolver<descriptor, 5>
{
    typedef typename descriptor::type construct_type;
    typedef typename descriptor::interface interface_type;
    typedef typename descriptor::lifestyle lifestyle_type;
    typedef unpack_dependency<descriptor, 0> d0;
    typedef unpack_dependency<descriptor, 1> d1;
    typedef unpack_dependency<descriptor, 2> d2;
    typedef unpack_dependency<descriptor, 3> d3;
    typedef unpack_dependency<descriptor, 4> d4;
    static boost::function<interface_type(void*)> invoke() 
    {
        return boost::bind(
            &construct5<
                interface_type, 
                construct_type, 
                lifestyle_type, 
                typename d0::interface_type, 
                typename d1::interface_type, 
                typename d2::interface_type, 
                typename d3::interface_type, 
                typename d4::interface_type
            >::invoke,
            _1,
            d0::generate_resolver_type::invoke(),
            d1::generate_resolver_type::invoke(),
            d2::generate_resolver_type::invoke(),
            d3::generate_resolver_type::invoke(),
            d4::generate_resolver_type::invoke()
            );
    }
};

template<typename descriptor>
struct generate_resolver<descriptor, 6>
{
    typedef typename descriptor::type construct_type;
    typedef typename descriptor::interface interface_type;
    typedef typename descriptor::lifestyle lifestyle_type;
    typedef unpack_dependency<descriptor, 0> d0;
    typedef unpack_dependency<descriptor, 1> d1;
    typedef unpack_dependency<descriptor, 2> d2;
    typedef unpack_dependency<descriptor, 3> d3;
    typedef unpack_dependency<descriptor, 4> d4;
    typedef unpack_dependency<descriptor, 5> d5;
    static boost::function<interface_type(void*)> invoke() 
    {
        return boost::bind(
            &construct6<
                interface_type, 
                construct_type, 
                lifestyle_type, 
                typename d0::interface_type,
                typename d1::interface_type, 
                typename d2::interface_type,
                typename d3::interface_type, 
                typename d4::interface_type, 
                typename d5::interface_type
            >::invoke,
            _1,
            d0::generate_resolver_type::invoke(),
            d1::generate_resolver_type::invoke(),
            d2::generate_resolver_type::invoke(),
            d3::generate_resolver_type::invoke(),
            d4::generate_resolver_type::invoke(),
            d5::generate_resolver_type::invoke()
            );
    }
};

template<typename descriptor>
struct generate_resolver<descriptor, 7>
{
    typedef typename descriptor::type construct_type;
    typedef typename descriptor::interface interface_type;
    typedef typename descriptor::lifestyle lifestyle_type;
    typedef unpack_dependency<descriptor, 0> d0;
    typedef unpack_dependency<descriptor, 1> d1;
    typedef unpack_dependency<descriptor, 2> d2;
    typedef unpack_dependency<descriptor, 3> d3;
    typedef unpack_dependency<descriptor, 4> d4;
    typedef unpack_dependency<descriptor, 5> d5;
    typedef unpack_dependency<descriptor, 6> d6;
    static boost::function<interface_type(void*)> invoke() 
    {
        return boost::bind(
            &construct7<
                interface_type, 
                construct_type, 
                lifestyle_type, 
                typename d0::interface_type, 
                typename d1::interface_type, 
                typename d2::interface_type, 
                typename d3::interface_type, 
                typename d4::interface_type, 
                typename d5::interface_type, 
                typename d6::interface_type
            >::invoke,
            _1,
            d0::generate_resolver_type::invoke(),
            d1::generate_resolver_type::invoke(),
            d2::generate_resolver_type::invoke(),
            d3::generate_resolver_type::invoke(),
            d4::generate_resolver_type::invoke(),
            d5::generate_resolver_type::invoke(),
            d6::generate_resolver_type::invoke()
            );
    }
};

template<typename descriptor>
struct generate_resolver<descriptor, 8>
{
    typedef typename descriptor::type construct_type;
    typedef typename descriptor::interface interface_type;
    typedef typename descriptor::lifestyle lifestyle_type;
    typedef unpack_dependency<descriptor, 0> d0;
    typedef unpack_dependency<descriptor, 1> d1;
    typedef unpack_dependency<descriptor, 2> d2;
    typedef unpack_dependency<descriptor, 3> d3;
    typedef unpack_dependency<descriptor, 4> d4;
    typedef unpack_dependency<descriptor, 5> d5;
    typedef unpack_dependency<descriptor, 6> d6;
    typedef unpack_dependency<descriptor, 7> d7;
    static boost::function<interface_type(void*)> invoke() 
    {
        return boost::bind(
            &construct8<
                interface_type, 
                construct_type, 
                lifestyle_type, 
                typename d0::interface_type, 
                typename d1::interface_type, 
                typename d2::interface_type, 
                typename d3::interface_type, 
                typename d4::interface_type, 
                typename d5::interface_type, 
                typename d6::interface_type, 
                typename d7::interface_type
            >::invoke,
            _1,
            d0::generate_resolver_type::invoke(),
            d1::generate_resolver_type::invoke(),
            d2::generate_resolver_type::invoke(),
            d3::generate_resolver_type::invoke(),
            d4::generate_resolver_type::invoke(),
            d5::generate_resolver_type::invoke(),
            d6::generate_resolver_type::invoke(),
            d7::generate_resolver_type::invoke()
            );
    }
};

}
}

#endif // IOC_GENERATORS_HPP
