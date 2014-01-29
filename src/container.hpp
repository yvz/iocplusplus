#ifndef IOC_CONTAINER_HPP
#define IOC_CONTAINER_HPP

//////////////////////////////////////////////////////////////////////////
// container.hpp

// (C) Copyright 2011-2012 Guardian
// (C) Copyright 2013-2014 Yury Yakovlev <yvzmail@gmail.com>
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <boost/any.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/size.hpp>

#include "generators.hpp"
#include "dependency.hpp"
#include "any_map.hpp"
#include "error.hpp"

namespace ioc
{

class container
{
    struct registrator 
    {
        container* m_self;
        registrator(container* self) : m_self(self) {}
        template<typename T> void operator()(T){ m_self->registerType<T>(); }
    };

public:

    template<typename descriptor_vector>
    void registerTypes()
    {
        boost::mpl::for_each<descriptor_vector>( registrator(this) );
    }

    template<typename descriptor>
    void registerType()
    {
        enum { dependency_count = boost::mpl::size<typename descriptor::dependencies>::value };
        
        typedef typename detail::generate_resolver<
            descriptor, 
            dependency_count
        > resolver_type;

        std::string typeName = typeid(descriptor::type).name();
        if (!m_resolvers.get(typeName).empty())
            return;

        boost::function<typename descriptor::interface(void*)> resolver = 
            resolver_type::invoke();
        
        m_resolvers.insert(typeName, resolver);
    }

    template<typename R>
    boost::shared_ptr<R> resolve()
    {
        std::string typeName = typeid(R).name();
        boost::any resolver = m_resolvers.get(typeName);
        if (resolver.empty())
            throw unregistred_type(typeName);
        
        try
        {
            return boost::any_cast< boost::function<boost::shared_ptr<R>(void*)> >(resolver)(&m_instances); 
        }
        catch(boost::bad_any_cast&)
        {
            throw invalid_signature(typeName);
        }
    }

    template<typename R>
    bool isRegistered()
    {
        std::string typeName = typeid(R).name();
        boost::any resolver = m_resolvers.get(typeName);
        return !resolver.empty();
    }

private:
    detail::any_map m_resolvers;
    detail::any_map m_instances;
};

}

#endif // IOC_CONTAINER_HPP
