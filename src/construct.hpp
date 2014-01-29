#ifndef IOC_CONSTRUCT_HPP
#define IOC_CONSTRUCT_HPP

//////////////////////////////////////////////////////////////////////////
// construct.hpp

// (C) Copyright 2011-2012 Guardian
// (C) Copyright 2013-2014 Yury Yakovlev <yvzmail@gmail.com>
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <boost/any.hpp>
#include <boost/function.hpp>

namespace ioc
{
namespace detail
{
//////////////////////////////////////////////////////////////////////////
// constructors
template<typename I, typename T, typename L>
struct construct0
{
    static I invoke(void* arg) 
    {
        std::string typeName = typeid(I).name();
        boost::any lookup = L::get(arg, typeName);
        if (!lookup.empty())
            return boost::any_cast<I>(lookup);

        I obj = I(new T());

        L::insert(arg, typeName, obj);
        return obj;
    }
};

template<typename I, typename T, typename L, typename A0>
struct construct1
{
    static I invoke(
        void* arg,
        boost::function<A0(void*)> a0)
    {
        std::string typeName = typeid(I).name();
        boost::any lookup = L::get(arg, typeName);
        if (!lookup.empty())
            return boost::any_cast<I>(lookup);

        I obj = I(new T(a0(arg)));

        L::insert(arg, typeName, obj);
        return obj;
    }
};

template<typename I, typename T, typename L, typename A0, typename A1>
struct construct2
{
    static I invoke(
        void* arg,
        boost::function<A0(void*)> a0, 
        boost::function<A1(void*)> a1) 
    { 
        std::string typeName = typeid(I).name();
        boost::any lookup = L::get(arg, typeName);
        if (!lookup.empty())
            return boost::any_cast<I>(lookup);

        I obj = I(new T(a0(arg), a1(arg)));

        L::insert(arg, typeName, obj);
        return obj;
    }
};

template<typename I, typename T, typename L, typename A0, typename A1, typename A2>
struct construct3
{
    static I invoke(
        void* arg,
        boost::function<A0(void*)> a0, 
        boost::function<A1(void*)> a1, 
        boost::function<A2(void*)> a2) 
    { 
        std::string typeName = typeid(I).name();
        boost::any lookup = L::get(arg, typeName);
        if (!lookup.empty())
            return boost::any_cast<I>(lookup);

        I obj = I(new T(a0(arg), a1(arg), a2(arg)));

        L::insert(arg, typeName, obj);
        return obj;
    }
};

template<typename I, typename T, typename L, typename A0, typename A1, typename A2, typename A3>
struct construct4
{
    static I invoke(
        void* arg,
        boost::function<A0(void*)> a0, 
        boost::function<A1(void*)> a1, 
        boost::function<A2(void*)> a2, 
        boost::function<A3(void*)> a3) 
    { 
        std::string typeName = typeid(I).name();
        boost::any lookup = L::get(arg, typeName);
        if (!lookup.empty())
            return boost::any_cast<I>(lookup);

        I obj = I(new T(a0(arg), a1(arg), a2(arg), a3(arg)));

        L::insert(arg, typeName, obj);
        return obj;
    }
};

template<typename I, typename T, typename L, typename A0, typename A1, typename A2, typename A3, typename A4>
struct construct5
{
    static I invoke(
        void* arg,
        boost::function<A0(void*)> a0, 
        boost::function<A1(void*)> a1, 
        boost::function<A2(void*)> a2, 
        boost::function<A3(void*)> a3, 
        boost::function<A4(void*)> a4) 
    { 
        std::string typeName = typeid(I).name();
        boost::any lookup = L::get(arg, typeName);
        if (!lookup.empty())
            return boost::any_cast<I>(lookup);

        I obj = I(new T(a0(arg), a1(arg), a2(arg), a3(arg), a4(arg)));

        L::insert(arg, typeName, obj);
        return obj;
    }
};

template<typename I, typename T, typename L, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
struct construct6
{
    static I invoke(
        void* arg,
        boost::function<A0(void*)> a0, 
        boost::function<A1(void*)> a1, 
        boost::function<A2(void*)> a2, 
        boost::function<A3(void*)> a3,
        boost::function<A4(void*)> a4, 
        boost::function<A5(void*)> a5) 
    { 
        std::string typeName = typeid(I).name();
        boost::any lookup = L::get(arg, typeName);
        if (!lookup.empty())
            return boost::any_cast<I>(lookup);

        I obj = I(new T(a0(arg), a1(arg), a2(arg), a3(arg), a4(arg), a5(arg)));

        L::insert(arg, typeName, obj);
        return obj;
    }
};

template<typename I, typename T, typename L, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
struct construct7
{
    static I invoke(
        void* arg,
        boost::function<A0(void*)> a0, 
        boost::function<A1(void*)> a1, 
        boost::function<A2(void*)> a2, 
        boost::function<A3(void*)> a3, 
        boost::function<A4(void*)> a4, 
        boost::function<A5(void*)> a5, 
        boost::function<A6(void*)> a6) 
    {
        std::string typeName = typeid(I).name();
        boost::any lookup = L::get(arg, typeName);
        if (!lookup.empty())
            return boost::any_cast<I>(lookup);

        I obj = I(new T(a0(arg), a1(arg), a2(arg), a3(arg), a4(arg), a5(arg), a6(arg)));

        L::insert(arg, typeName, obj);
        return obj;
    }
};

template<typename I, typename T, typename L, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
struct construct8
{
    static I invoke(
        void* arg,
        boost::function<A0(void*)> a0, 
        boost::function<A1(void*)> a1, 
        boost::function<A2(void*)> a2, 
        boost::function<A3(void*)> a3, 
        boost::function<A4(void*)> a4, 
        boost::function<A5(void*)> a5, 
        boost::function<A6(void*)> a6, 
        boost::function<A7(void*)> a7) 
    {
        std::string typeName = typeid(I).name();
        boost::any lookup = L::get(arg, typeName);
        if (!lookup.empty())
            return boost::any_cast<I>(lookup);

        I obj = I(new T(a0(arg), a1(arg), a2(arg), a3(arg), a4(arg), a5(arg), a6(arg), a7(arg)));

        L::insert(arg, typeName, obj);
        return obj;
    }
};

}
}

#endif // IOC_CONSTRUCT_HPP
